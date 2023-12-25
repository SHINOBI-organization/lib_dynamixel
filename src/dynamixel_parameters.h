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

enum DynamixelPhysicalUnit {
  NOUNIT,
  UNIT_POSITION,
  UNIT_VELOCITY,
  UNIT_ACCELERATION,
  UNIT_CURRENT,
  UNIT_VOLTAGE,
  UNIT_TEMPERATURE,
  UNIT_PWM,
  UNIT_RETURN_DELAY_TIME,
  UNIT_BUS_WATCHDOG,
  UNIT_REALTIME_TICK,
};


class DynamixelAddress {
 public:
  DynamixelAddress( uint16_t address, DynamixelDataType data_type, DynamixelPhysicalUnit physical_unit = NOUNIT ):
    address_(address), data_type_(data_type), physical_unit_(physical_unit) {
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
  DynamixelPhysicalUnit physical_unit_;
};

// dynamixel common
inline DynamixelAddress model_number          (  0, TYPE_UINT16);
inline DynamixelAddress id                    (  7, TYPE_UINT8 );
inline DynamixelAddress baudrate              (  8, TYPE_UINT8 );
inline DynamixelAddress return_delay_time     (  9, TYPE_UINT8 , UNIT_RETURN_DELAY_TIME);

// dynamixel X series   
namespace dyn_x {
    inline DynamixelAddress drive_mode            ( 10, TYPE_UINT8 );
    inline DynamixelAddress operating_mode        ( 11, TYPE_UINT8 );
    inline DynamixelAddress shadow_id             ( 12, TYPE_UINT8 );
    inline DynamixelAddress homing_offset         ( 20, TYPE_INT32 , UNIT_POSITION);
    inline DynamixelAddress homing_threshold      ( 24, TYPE_UINT32); 
    inline DynamixelAddress temperature_limit     ( 31, TYPE_UINT8 , UNIT_TEMPERATURE);
    inline DynamixelAddress max_voltage_limit     ( 32, TYPE_UINT16, UNIT_VOLTAGE);
    inline DynamixelAddress min_voltage_limit     ( 34, TYPE_UINT16, UNIT_VOLTAGE);
    inline DynamixelAddress pwm_limit             ( 36, TYPE_UINT16, UNIT_PWM);
    inline DynamixelAddress current_limit         ( 38, TYPE_UINT16, UNIT_CURRENT);
    inline DynamixelAddress acceleration_limit    ( 40, TYPE_UINT32, UNIT_ACCELERATION);
    inline DynamixelAddress velocity_limit        ( 44, TYPE_UINT32, UNIT_VELOCITY);
    inline DynamixelAddress max_position_limit    ( 48, TYPE_UINT32, UNIT_POSITION);
    inline DynamixelAddress min_position_limit    ( 52, TYPE_UINT32, UNIT_POSITION);
    inline DynamixelAddress external_port_mode_1  ( 56, TYPE_UINT8 );
    inline DynamixelAddress external_port_mode_2  ( 57, TYPE_UINT8 );
    inline DynamixelAddress external_port_mode_3  ( 58, TYPE_UINT8 );
    inline DynamixelAddress shutdown              ( 63, TYPE_UINT8 );
    inline DynamixelAddress torque_enable         ( 64, TYPE_UINT8 );
    inline DynamixelAddress led                   ( 65, TYPE_UINT8 );
    inline DynamixelAddress status_return_level   ( 68, TYPE_UINT8 );
    inline DynamixelAddress registered_instruction( 69, TYPE_UINT8 );
    inline DynamixelAddress hardware_error_status ( 70, TYPE_UINT8 );
    inline DynamixelAddress velocity_i_gain       ( 76, TYPE_UINT16); // 型番によってデフォルト値が異なる
    inline DynamixelAddress velocity_p_gain       ( 78, TYPE_UINT16); // 型番によってデフォルト値が異なる
    inline DynamixelAddress position_d_gain       ( 80, TYPE_UINT16); // 型番によってデフォルト値が異なる
    inline DynamixelAddress position_i_gain       ( 82, TYPE_UINT16); // 型番によってデフォルト値が異なる
    inline DynamixelAddress position_p_gain       ( 84, TYPE_UINT16); // 型番によってデフォルト値が異なる
    inline DynamixelAddress feedforward_acc_gain  ( 88, TYPE_UINT16);
    inline DynamixelAddress feedforward_vel_gain  ( 90, TYPE_UINT16);
    inline DynamixelAddress bus_watchbdog         ( 98, TYPE_INT8  , UNIT_BUS_WATCHDOG);
    inline DynamixelAddress goal_pwm              (100, TYPE_INT16 , UNIT_PWM);
    inline DynamixelAddress goal_current          (102, TYPE_INT16 , UNIT_CURRENT);
    inline DynamixelAddress goal_velocity         (104, TYPE_INT32 , UNIT_VELOCITY);
    inline DynamixelAddress profile_acceleration  (108, TYPE_INT32 , UNIT_ACCELERATION);
    inline DynamixelAddress profile_velocity      (112, TYPE_INT32 , UNIT_VELOCITY);
    inline DynamixelAddress goal_position         (116, TYPE_INT32 , UNIT_POSITION);
    inline DynamixelAddress realtime_tick         (120, TYPE_UINT16, UNIT_REALTIME_TICK);
    inline DynamixelAddress moving                (122, TYPE_UINT8 );
    inline DynamixelAddress moving_status         (123, TYPE_UINT8 );
    inline DynamixelAddress present_pwm           (124, TYPE_INT16 , UNIT_PWM);
    inline DynamixelAddress present_current       (126, TYPE_INT16 , UNIT_CURRENT); 
    inline DynamixelAddress present_velocity      (128, TYPE_INT32 , UNIT_VELOCITY);
    inline DynamixelAddress present_position      (132, TYPE_INT32 , UNIT_POSITION);
    inline DynamixelAddress velocity_trajectory   (136, TYPE_INT32 );
    inline DynamixelAddress position_trajectory   (140, TYPE_INT32 );
    inline DynamixelAddress present_input_voltage (144, TYPE_UINT16, UNIT_VOLTAGE);
    inline DynamixelAddress present_temperture    (146, TYPE_UINT8 , UNIT_TEMPERATURE);
    inline DynamixelAddress external_port_data_1  (152, TYPE_UINT16);
    inline DynamixelAddress external_port_data_2  (154, TYPE_UINT16);
    inline DynamixelAddress external_port_data_3  (156, TYPE_UINT16);
}// 以後Indirect Address, うまく実装して取り込みたい．

// dynamixel P series (old: pro plus)
namespace dyn_p {
    inline DynamixelAddress drive_mode            ( 10, TYPE_UINT8 );
    inline DynamixelAddress operating_mode        ( 11, TYPE_UINT8 );
    inline DynamixelAddress shadow_id             ( 12, TYPE_UINT8 );
    inline DynamixelAddress homing_offset         ( 20, TYPE_INT32 , UNIT_POSITION);
    inline DynamixelAddress homing_threshold      ( 24, TYPE_UINT32);
    inline DynamixelAddress temperature_limit     ( 31, TYPE_UINT8 , UNIT_TEMPERATURE);
    inline DynamixelAddress max_voltage_limit     ( 32, TYPE_UINT16, UNIT_VOLTAGE);
    inline DynamixelAddress min_voltage_limit     ( 34, TYPE_UINT16, UNIT_VOLTAGE);
    inline DynamixelAddress pwm_limit             ( 36, TYPE_UINT16, UNIT_PWM);
    inline DynamixelAddress current_limit         ( 38, TYPE_UINT16, UNIT_CURRENT);
    inline DynamixelAddress acceleration_limit    ( 38, TYPE_UINT32, UNIT_ACCELERATION);
    inline DynamixelAddress velocity_limit        ( 38, TYPE_UINT32, UNIT_VELOCITY);
    inline DynamixelAddress max_position_limit    ( 48, TYPE_INT32 , UNIT_POSITION);
    inline DynamixelAddress min_position_limit    ( 52, TYPE_INT32 , UNIT_POSITION);
    inline DynamixelAddress external_port_mode_1  ( 56, TYPE_UINT8 );
    inline DynamixelAddress external_port_mode_2  ( 57, TYPE_UINT8 );
    inline DynamixelAddress external_port_mode_3  ( 58, TYPE_UINT8 );
    inline DynamixelAddress external_port_mode_4  ( 59, TYPE_UINT8 );
    inline DynamixelAddress shutdown              ( 63, TYPE_UINT8 );
    inline DynamixelAddress torque_enable         (512, TYPE_UINT8 );
    inline DynamixelAddress led_red               (513, TYPE_UINT8 );
    inline DynamixelAddress led_green             (514, TYPE_UINT8 );
    inline DynamixelAddress led_blue              (515, TYPE_UINT8 );
    inline DynamixelAddress status_return_level   (516, TYPE_UINT8 );
    inline DynamixelAddress registered_instruction(517, TYPE_UINT8 );
    inline DynamixelAddress hardware_error_status (518, TYPE_UINT8 );
    inline DynamixelAddress velocity_i_gain       (524, TYPE_UINT16);
    inline DynamixelAddress velocity_p_gain       (526, TYPE_UINT16);
    inline DynamixelAddress position_d_gain       (528, TYPE_UINT16);
    inline DynamixelAddress position_i_gain       (530, TYPE_UINT16);
    inline DynamixelAddress position_p_gain       (532, TYPE_UINT16);
    inline DynamixelAddress bus_watchbdog         (546, TYPE_UINT8 , UNIT_BUS_WATCHDOG);
    inline DynamixelAddress goal_pwm              (548, TYPE_INT16 , UNIT_PWM);
    inline DynamixelAddress goal_current          (550, TYPE_INT16 , UNIT_CURRENT);
    inline DynamixelAddress goal_velocity         (552, TYPE_INT32 , UNIT_VELOCITY);
    inline DynamixelAddress profile_acceleration  (556, TYPE_UINT32, UNIT_ACCELERATION);
    inline DynamixelAddress profile_velocity      (560, TYPE_UINT32, UNIT_VELOCITY);
    inline DynamixelAddress goal_position         (564, TYPE_INT32 , UNIT_POSITION);
    inline DynamixelAddress realtime_tick         (568, TYPE_UINT16, UNIT_REALTIME_TICK);
    inline DynamixelAddress moving                (570, TYPE_UINT8 );
    inline DynamixelAddress moving_status         (571, TYPE_UINT8 );
    inline DynamixelAddress present_pwm           (572, TYPE_INT16 , UNIT_PWM);
    inline DynamixelAddress present_current       (574, TYPE_INT16 , UNIT_CURRENT); 
    inline DynamixelAddress present_velocity      (576, TYPE_INT32 , UNIT_VELOCITY);
    inline DynamixelAddress present_position      (580, TYPE_INT32 , UNIT_POSITION);
    inline DynamixelAddress velocity_trajectory   (584, TYPE_INT32 );
    inline DynamixelAddress position_trajectory   (588, TYPE_INT32 );
    inline DynamixelAddress present_input_voltage (592, TYPE_UINT16, UNIT_VOLTAGE);
    inline DynamixelAddress present_temperture    (594, TYPE_UINT8 , UNIT_TEMPERATURE);
    inline DynamixelAddress external_port_data_1  (600, TYPE_UINT16);
    inline DynamixelAddress external_port_data_2  (602, TYPE_UINT16);
    inline DynamixelAddress external_port_data_3  (604, TYPE_UINT16);
    inline DynamixelAddress external_port_data_4  (606, TYPE_UINT16);
}



#endif /* DYNAMIXEL_PARAMETERS_H_ */
