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

class DynamixelParameter {
 public:
  DynamixelParameter( uint16_t address, DynamixelDataType data_type ) {
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
    extern DynamixelParameter model_number          ;
    extern DynamixelParameter id                    ;
    extern DynamixelParameter baudrate              ;
    extern DynamixelParameter return_delay_time     ;

namespace dyn_x {
    extern DynamixelParameter drive_mode            ;
    extern DynamixelParameter operating_mode        ;
    extern DynamixelParameter shadow_id             ;
    extern DynamixelParameter homing_offset         ;
    extern DynamixelParameter homing_threshold      ;
    extern DynamixelParameter temperature_limit     ;
    extern DynamixelParameter max_voltage_limit     ;
    extern DynamixelParameter min_voltage_limit     ;
    extern DynamixelParameter pwm_limit             ;
    extern DynamixelParameter current_limit         ;
    extern DynamixelParameter acceleration_limit    ;
    extern DynamixelParameter velocity_limit        ;
    extern DynamixelParameter max_position_limit    ;
    extern DynamixelParameter min_position_limit    ;
    extern DynamixelParameter external_port_mode_1  ;
    extern DynamixelParameter external_port_mode_2  ;
    extern DynamixelParameter external_port_mode_3  ;
    extern DynamixelParameter shutdown              ;
    extern DynamixelParameter torque_enable         ;
    extern DynamixelParameter led                   ;
    extern DynamixelParameter status_return_level   ;
    extern DynamixelParameter registered_instruction;
    extern DynamixelParameter hardware_error_status ;
    extern DynamixelParameter velocity_i_gain       ;
    extern DynamixelParameter velocity_p_gain       ;
    extern DynamixelParameter position_d_gain       ;
    extern DynamixelParameter position_i_gain       ;
    extern DynamixelParameter position_p_gain       ;
    extern DynamixelParameter feedforward_acc_gain  ;
    extern DynamixelParameter feedforward_vel_gain  ;
    extern DynamixelParameter bus_watchbdog         ;
    extern DynamixelParameter goal_pwm              ;
    extern DynamixelParameter goal_current          ;
    extern DynamixelParameter goal_velocity         ;
    extern DynamixelParameter profile_acceleration  ;
    extern DynamixelParameter profile_velocity      ;
    extern DynamixelParameter goal_position         ;
    extern DynamixelParameter realtime_tick         ;
    extern DynamixelParameter moving                ;
    extern DynamixelParameter moving_status         ;
    extern DynamixelParameter present_pwm           ;
    extern DynamixelParameter present_current       ;
    extern DynamixelParameter present_velocity      ;
    extern DynamixelParameter present_position      ;
    extern DynamixelParameter velocity_trajectory   ;
    extern DynamixelParameter position_trajectory   ;
    extern DynamixelParameter present_input_voltage ;
    extern DynamixelParameter present_temperture    ;
    extern DynamixelParameter external_port_data_1  ;
    extern DynamixelParameter external_port_data_2  ;
    extern DynamixelParameter external_port_data_3  ;

    // velocity_unit
    // acceleration_unit
    // position_unit
    // current_unit
    // return_delay_time_unit // デフォルト値をそれ以外の定義をする必要がある
} 

namespace dyn_p{
    extern DynamixelParameter drive_mode           ;
    extern DynamixelParameter operating_mode       ;
    extern DynamixelParameter homing_offset        ;
    extern DynamixelParameter current_limit        ;
    extern DynamixelParameter acceleration_limit   ;
    extern DynamixelParameter velocity_limit       ;
    extern DynamixelParameter max_position_limit   ;
    extern DynamixelParameter min_position_limit   ;
    extern DynamixelParameter external_port_mode_1 ;
    extern DynamixelParameter external_port_mode_2 ;
    extern DynamixelParameter external_port_mode_3 ;
    extern DynamixelParameter external_port_mode_4 ;
    extern DynamixelParameter shutdown             ;
    extern DynamixelParameter torque_enable        ;
    extern DynamixelParameter led_red              ;
    extern DynamixelParameter led_green            ;
    extern DynamixelParameter led_blue             ;
    extern DynamixelParameter velocity_i_gain      ;
    extern DynamixelParameter velocity_p_gain      ;
    extern DynamixelParameter position_d_gain      ;
    extern DynamixelParameter position_i_gain      ;
    extern DynamixelParameter position_p_gain      ;
    extern DynamixelParameter goal_current         ;
    extern DynamixelParameter goal_velocity        ;
    extern DynamixelParameter profile_acceleration ;
    extern DynamixelParameter profile_velocity     ;
    extern DynamixelParameter goal_position        ;
    extern DynamixelParameter present_current      ;
    extern DynamixelParameter present_velocity     ;
    extern DynamixelParameter present_position     ;
    extern DynamixelParameter present_input_voltage;
    extern DynamixelParameter present_temperture   ;
    extern DynamixelParameter external_port_data_1 ;
    extern DynamixelParameter external_port_data_2 ;
    extern DynamixelParameter external_port_data_3 ;
    extern DynamixelParameter external_port_data_4 ;
    extern DynamixelParameter status_return_level  ;
    extern DynamixelParameter hardware_error_status;
}

#endif /* DYNAMIXEL_PARAMETERS_H_ */
