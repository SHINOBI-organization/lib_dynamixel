#include "dynamixel_communicator.h"
#include <stdio.h>

#include <chrono>
#include <thread>
using namespace std::chrono_literals;

vector<uint8_t> DynamixelComunicator::Scan(uint8_t id_max) {   
    vector<uint8_t> id_list_tmp;
    for (int id = 1; id <= id_max; id++) {
        bool is_found = false;
        for (size_t i = 0; i < 5; i++) if ( !is_found ) {
            if (this->Ping(id)) is_found = true;
            std::this_thread::sleep_for(0.01s);   
        }
        if (is_found) {
            id_list_tmp.push_back(id);
            printf(" * Servo id [%d] is found (id range 1 to [%d])\n", id, id_max);
        }
    }
    return id_list_tmp;
}

bool DynamixelComunicator::ClearError(uint8_t id, DynamixelTorquePermission after_state){
    auto present_pos = this->Read(id, dyn_x::present_position);
    int present_rotation = present_pos / 2048; // 整数値に丸める
    if (present_pos < 0) present_rotation--;

        this->Reboot(id);
        std::this_thread::sleep_for(0.5s);

    this->Write(id, dyn_x::homing_offset, present_rotation * 2048);
    this->Write(id, dyn_x::torque_enable, after_state);
    return this->Read(id, dyn_x::hardware_error_status) == 0; // 0 is no error
}

bool DynamixelComunicator::TorqueEnable(uint8_t id){
    this->Write(id, dyn_x::torque_enable, TORQUE_ENABLE);
    std::this_thread::sleep_for(0.01s);
    return this->Read(id, dyn_x::torque_enable) != TORQUE_ENABLE;
}

bool DynamixelComunicator::TorqueDisable(uint8_t id){
    this->Write(id, dyn_x::torque_enable, TORQUE_DISABLE);
    std::this_thread::sleep_for(0.01s);
    return this->Read(id, dyn_x::torque_enable) != TORQUE_DISABLE;
}