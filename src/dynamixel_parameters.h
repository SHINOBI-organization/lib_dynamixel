#ifndef DYNAMIXEL_PARAMETERS_H_
#define DYNAMIXEL_PARAMETERS_H_

#include <stdint.h>

enum FactoryResetLevel {
  FACTORY_RESET_EXCLUDE_ID          = 0x01,
  FACTORY_RESET_EXCLUDE_ID_BAUDRATE = 0x02,
  FACTORY_RESET_ALL                 = 0xFF,
};
enum DynamixelBaudrateIndex {
  BAUDRATE_INDEX_9600   = 0,
  BAUDRATE_INDEX_57600  = 1,
  BAUDRATE_INDEX_115200 = 2,
  BAUDRATE_INDEX_1M     = 3,
  BAUDRATE_INDEX_2M     = 4,
  BAUDRATE_INDEX_3M     = 5,
  BAUDRATE_INDEX_4M     = 6,
  BAUDRATE_INDEX_4M5    = 7,
  BAUDRATE_INDEX_10M5   = 8,
};
enum DynamixelOperatingMode {
  OPERATING_MODE_TORQUE                = 0,
  OPERATING_MODE_VELOCITY              = 1,
  OPERATING_MODE_POSITION              = 3,
  OPERATING_MODE_EXTENDED_POSITION     = 4,
  OPERATING_MODE_CURRENT_BASE_POSITION = 5,
  OPERATING_MODE_PWM                   = 16,
};
enum DynamixelExternalPortMode {
  EXTERNAL_PORT_MODE_AIN           = 0,
  EXTERNAL_PORT_MODE_DOUT_NOPULL   = 1,
  EXTERNAL_PORT_MODE_DOUT_PULLUP   = 2,
  EXTERNAL_PORT_MODE_DOUT_PULLDOWN = 3,
};
enum DynamixelTorquePermission {
  TORQUE_DISABLE = 0,
  TORQUE_ENABLE  = 1,
};
enum DynamixelStatusReturnLevel {
  STATUS_RETURN_LEVEL_PING_ONLY = 0,
  STATUS_RETURN_LEVEL_READ_ONLY = 1,
  STATUS_RETURN_LEVEL_ALL       = 2,
};
enum DynamixelHardwareErrorIndex {
  HARDWARE_ERROR_INPUT_VOLTAGE      = 0,
  HARDWARE_ERROR_MOTOR_HALL_SENSOR  = 1,
  HARDWARE_ERROR_OVERHEATING        = 2,
  HARDWARE_ERROR_MOTOR_ENCODER      = 3,
  HARDWARE_ERROR_ELECTRONICAL_SHOCK = 4,
  HARDWARE_ERROR_OVERLOAD           = 5,
};
enum DynamixelDataType {
  TYPE_INT8,
  TYPE_UINT8,
  TYPE_INT16,
  TYPE_UINT16,
  TYPE_INT32,
  TYPE_UINT32,
};

class DynamixelAddress {
 public:
  DynamixelAddress( uint16_t address, DynamixelDataType data_type ) {
    address_ = address;
    data_type_ = data_type;
	switch (data_type_) {
        case TYPE_INT8:
        case TYPE_UINT8:  size_ = 1; break;
        case TYPE_INT16:
        case TYPE_UINT16: size_ = 2; break;
        case TYPE_INT32:
        case TYPE_UINT32: size_ = 4; break;
    }
  }

  uint16_t address() const { return address_; }
  DynamixelDataType data_type() const { return data_type_; }
  uint16_t size() const { return size_; }

 private:
  uint16_t address_;
  uint8_t size_;
  DynamixelDataType data_type_;
};

// 他のファイルから参照するための宣言
    extern DynamixelAddress model_number          ;
    extern DynamixelAddress id                    ;
    extern DynamixelAddress baudrate              ;
    extern DynamixelAddress return_delay_time     ;

namespace dyn_x {
    extern DynamixelAddress drive_mode            ;
    extern DynamixelAddress operating_mode        ;
    extern DynamixelAddress shadow_id             ;
    extern DynamixelAddress homing_offset         ;
    extern DynamixelAddress homing_threshold      ;
    extern DynamixelAddress temperature_limit     ;
    extern DynamixelAddress max_voltage_limit     ;
    extern DynamixelAddress min_voltage_limit     ;
    extern DynamixelAddress pwm_limit             ;
    extern DynamixelAddress current_limit         ;
    extern DynamixelAddress acceleration_limit    ;
    extern DynamixelAddress velocity_limit        ;
    extern DynamixelAddress max_position_limit    ;
    extern DynamixelAddress min_position_limit    ;
    extern DynamixelAddress external_port_mode_1  ;
    extern DynamixelAddress external_port_mode_2  ;
    extern DynamixelAddress external_port_mode_3  ;
    extern DynamixelAddress shutdown              ;
    extern DynamixelAddress torque_enable         ;
    extern DynamixelAddress led                   ;
    extern DynamixelAddress status_return_level   ;
    extern DynamixelAddress registered_instruction;
    extern DynamixelAddress hardware_error_status ;
    extern DynamixelAddress velocity_i_gain       ;
    extern DynamixelAddress velocity_p_gain       ;
    extern DynamixelAddress position_d_gain       ;
    extern DynamixelAddress position_i_gain       ;
    extern DynamixelAddress position_p_gain       ;
    extern DynamixelAddress feedforward_acc_gain  ;
    extern DynamixelAddress feedforward_vel_gain  ;
    extern DynamixelAddress bus_watchbdog         ;
    extern DynamixelAddress goal_pwm              ;
    extern DynamixelAddress goal_current          ;
    extern DynamixelAddress goal_velocity         ;
    extern DynamixelAddress profile_acceleration  ;
    extern DynamixelAddress profile_velocity      ;
    extern DynamixelAddress goal_position         ;
    extern DynamixelAddress realtime_tick         ;
    extern DynamixelAddress moving                ;
    extern DynamixelAddress moving_status         ;
    extern DynamixelAddress present_pwm           ;
    extern DynamixelAddress present_current       ;
    extern DynamixelAddress present_velocity      ;
    extern DynamixelAddress present_position      ;
    extern DynamixelAddress velocity_trajectory   ;
    extern DynamixelAddress position_trajectory   ;
    extern DynamixelAddress present_input_voltage ;
    extern DynamixelAddress present_temperture    ;
    extern DynamixelAddress external_port_data_1  ;
    extern DynamixelAddress external_port_data_2  ;
    extern DynamixelAddress external_port_data_3  ;

    // velocity_unit
    // acceleration_unit
    // position_unit
    // current_unit
    // return_delay_time_unit // デフォルト値をそれ以外の定義をする必要がある
} 

namespace dyn_p{
    extern DynamixelAddress drive_mode           ;
    extern DynamixelAddress operating_mode       ;
    extern DynamixelAddress homing_offset        ;
    extern DynamixelAddress current_limit        ;
    extern DynamixelAddress acceleration_limit   ;
    extern DynamixelAddress velocity_limit       ;
    extern DynamixelAddress max_position_limit   ;
    extern DynamixelAddress min_position_limit   ;
    extern DynamixelAddress external_port_mode_1 ;
    extern DynamixelAddress external_port_mode_2 ;
    extern DynamixelAddress external_port_mode_3 ;
    extern DynamixelAddress external_port_mode_4 ;
    extern DynamixelAddress shutdown             ;
    extern DynamixelAddress torque_enable        ;
    extern DynamixelAddress led_red              ;
    extern DynamixelAddress led_green            ;
    extern DynamixelAddress led_blue             ;
    extern DynamixelAddress velocity_i_gain      ;
    extern DynamixelAddress velocity_p_gain      ;
    extern DynamixelAddress position_d_gain      ;
    extern DynamixelAddress position_i_gain      ;
    extern DynamixelAddress position_p_gain      ;
    extern DynamixelAddress goal_current         ;
    extern DynamixelAddress goal_velocity        ;
    extern DynamixelAddress profile_acceleration ;
    extern DynamixelAddress profile_velocity     ;
    extern DynamixelAddress goal_position        ;
    extern DynamixelAddress present_current      ;
    extern DynamixelAddress present_velocity     ;
    extern DynamixelAddress present_position     ;
    extern DynamixelAddress present_input_voltage;
    extern DynamixelAddress present_temperture   ;
    extern DynamixelAddress external_port_data_1 ;
    extern DynamixelAddress external_port_data_2 ;
    extern DynamixelAddress external_port_data_3 ;
    extern DynamixelAddress external_port_data_4 ;
    extern DynamixelAddress status_return_level  ;
    extern DynamixelAddress hardware_error_status;
}

#endif /* DYNAMIXEL_PARAMETERS_H_ */
