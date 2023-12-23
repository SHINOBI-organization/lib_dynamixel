#include "dynamixel_parameters.h"

// dynamixel common
    DynamixelAddress model_number          (  0, TYPE_UINT16);
    DynamixelAddress id                    (  7, TYPE_UINT8 );
    DynamixelAddress baudrate              (  8, TYPE_UINT8 );
    DynamixelAddress return_delay_time     (  9, TYPE_UINT8 );

// dynamixel X series   
namespace dyn_x {
    DynamixelAddress drive_mode            ( 10, TYPE_UINT8 );
    DynamixelAddress operating_mode        ( 11, TYPE_UINT8 );
    DynamixelAddress shadow_id             ( 12, TYPE_UINT8 );
    DynamixelAddress homing_offset         ( 20, TYPE_INT32 ); // M_PI/2048.0);
    DynamixelAddress homing_threshold      ( 24, TYPE_UINT32); 
    DynamixelAddress temperature_limit     ( 31, TYPE_UINT8 ); // 1~100
    DynamixelAddress max_voltage_limit     ( 32, TYPE_UINT16); // 1~100
    DynamixelAddress min_voltage_limit     ( 34, TYPE_UINT16); // 1~100
    DynamixelAddress pwm_limit             ( 36, TYPE_UINT16); //, 100.0/885 /*%*/);
    DynamixelAddress current_limit         ( 38, TYPE_UINT16); //, def: 2.69/*mA*/, xh430v: 1.34/*mA*/ x_330_: 1.00/*mA*/
    DynamixelAddress acceleration_limit    ( 40, TYPE_UINT32); //, 214.577*2.0*M_PI/3600.0);
    DynamixelAddress velocity_limit        ( 44, TYPE_UINT32); //, 0.229*2.0*M_PI/60.0/*rad/s*/  XL330: /*rad/s*/
    DynamixelAddress max_position_limit    ( 48, TYPE_UINT32); //, M_PI/2048.0);
    DynamixelAddress min_position_limit    ( 52, TYPE_UINT32); //, M_PI/2048.0);
    DynamixelAddress external_port_mode_1  ( 56, TYPE_UINT8 );
    DynamixelAddress external_port_mode_2  ( 57, TYPE_UINT8 );
    DynamixelAddress external_port_mode_3  ( 58, TYPE_UINT8 );
    DynamixelAddress shutdown              ( 63, TYPE_UINT8 );
    DynamixelAddress torque_enable         ( 64, TYPE_UINT8 );
    DynamixelAddress led                   ( 65, TYPE_UINT8 );
    DynamixelAddress status_return_level   ( 68, TYPE_UINT8 );
    DynamixelAddress registered_instruction( 69, TYPE_UINT8 );
    DynamixelAddress hardware_error_status ( 70, TYPE_UINT8 );
    DynamixelAddress velocity_i_gain       ( 76, TYPE_UINT16); // 型番によってデフォルト値が異なる
    DynamixelAddress velocity_p_gain       ( 78, TYPE_UINT16); // 型番によってデフォルト値が異なる
    DynamixelAddress position_d_gain       ( 80, TYPE_UINT16); // 型番によってデフォルト値が異なる
    DynamixelAddress position_i_gain       ( 82, TYPE_UINT16); // 型番によってデフォルト値が異なる
    DynamixelAddress position_p_gain       ( 84, TYPE_UINT16); // 型番によってデフォルト値が異なる
    DynamixelAddress feedforward_acc_gain  ( 88, TYPE_UINT16);
    DynamixelAddress feedforward_vel_gain  ( 90, TYPE_UINT16);
    DynamixelAddress bus_watchbdog         ( 98, TYPE_INT8  );
    DynamixelAddress goal_pwm              (100, TYPE_INT16 ); 
    DynamixelAddress goal_current          (102, TYPE_INT16 ); //, def: 2.69/*mA*/, xh430v: 1.34/*mA*/ x_330_: 1.00/*mA*/
    DynamixelAddress goal_velocity         (104, TYPE_INT32 ); //, 0.229*2.0*M_PI/60.0);
    DynamixelAddress profile_acceleration  (108, TYPE_INT32 ); //, 214.577*2.0*M_PI/3600.0); // unit 214.577 [rpm^2]
    DynamixelAddress profile_velocity      (112, TYPE_INT32 ); //, 0.229*2.0*M_PI/60.0 );    // unit 0.229  [rpm]
    DynamixelAddress goal_position         (116, TYPE_INT32 ); //, M_PI/2048.0);
    DynamixelAddress realtime_tick         (120, TYPE_UINT16);
    DynamixelAddress moving                (122, TYPE_UINT8 );
    DynamixelAddress moving_status         (123, TYPE_UINT8 );
    DynamixelAddress present_pwm           (124, TYPE_INT16 );
    DynamixelAddress present_current       (126, TYPE_INT16 ); //, def: 2.69/*mA*/, xh430v: 1.34/*mA*/ x_330_: 1.00/*mA*/
    DynamixelAddress present_velocity      (128, TYPE_INT32 ); //, M_PI/180.0*0.229);
    DynamixelAddress present_position      (132, TYPE_INT32 ); //, M_PI/2048.0);
    DynamixelAddress velocity_trajectory   (136, TYPE_INT32 );
    DynamixelAddress position_trajectory   (140, TYPE_INT32 );
    DynamixelAddress present_input_voltage (144, TYPE_UINT16); //, 0.1);
    DynamixelAddress present_temperture    (146, TYPE_UINT8 );
    DynamixelAddress external_port_data_1  (152, TYPE_UINT16);
    DynamixelAddress external_port_data_2  (154, TYPE_UINT16);
    DynamixelAddress external_port_data_3  (156, TYPE_UINT16);
}
// 以後Indirect Address, うまく実装して取り込みたい．

// dynamixel P series (old: pro plus)
namespace dyn_p {
    DynamixelAddress drive_mode           ( 10, TYPE_UINT8 );
    DynamixelAddress operating_mode       ( 11, TYPE_UINT8 );
    DynamixelAddress homing_offset        ( 20, TYPE_INT32 ); //, 42: M_PI/303750 54: M_PI/501923
    DynamixelAddress current_limit        ( 38, TYPE_UINT16); //, 0.001);
    DynamixelAddress acceleration_limit   ( 38, TYPE_UINT32); //, 58000*2.0*M_PI/3600.0); //unit 58000 [rpm^2]
    DynamixelAddress velocity_limit       ( 38, TYPE_UINT32); //, 0.01*2.0*M_PI/60.0); //unit 0.01 [rpm]
    DynamixelAddress max_position_limit   ( 48, TYPE_INT32 ); //, 42: M_PI/303750 54: M_PI/501923
    DynamixelAddress min_position_limit   ( 52, TYPE_INT32 ); //, 42: M_PI/303750 54: M_PI/501923
    DynamixelAddress external_port_mode_1 ( 56, TYPE_UINT8 );
    DynamixelAddress external_port_mode_2 ( 57, TYPE_UINT8 );
    DynamixelAddress external_port_mode_3 ( 58, TYPE_UINT8 );
    DynamixelAddress external_port_mode_4 ( 59, TYPE_UINT8 );
    DynamixelAddress shutdown             ( 63, TYPE_UINT8 );
    DynamixelAddress torque_enable        (512, TYPE_UINT8 );
    DynamixelAddress led_red              (513, TYPE_UINT8 );
    DynamixelAddress led_green            (514, TYPE_UINT8 );
    DynamixelAddress led_blue             (515, TYPE_UINT8 );
    DynamixelAddress velocity_i_gain      (524, TYPE_UINT16);
    DynamixelAddress velocity_p_gain      (526, TYPE_UINT16);
    DynamixelAddress position_d_gain      (528, TYPE_UINT16);
    DynamixelAddress position_i_gain      (530, TYPE_UINT16);
    DynamixelAddress position_p_gain      (532, TYPE_UINT16);
    DynamixelAddress goal_current         (550, TYPE_INT16 ); //, 0.001);
    DynamixelAddress goal_velocity        (552, TYPE_INT32 ); //, 0.01*2.0*M_PI/60.0);
    DynamixelAddress profile_acceleration (556, TYPE_UINT32); //, 1.0*2.0*M_PI/3600.0);// unit 1 [rpm^2]
    DynamixelAddress profile_velocity     (560, TYPE_UINT32); //, 0.01*2.0*M_PI/60.0);// unit 0.01 [rpm]
    DynamixelAddress goal_position        (564, TYPE_INT32 ); //, 42: M_PI/303750 54: M_PI/501923
    DynamixelAddress present_current      (574, TYPE_INT16 ); //, 0.001);
    DynamixelAddress present_velocity     (576, TYPE_INT32 ); //, 0.01*2.0*M_PI/60.0);
    DynamixelAddress present_position     (580, TYPE_INT32 ); //, 42: M_PI/303750 54: M_PI/501923
    DynamixelAddress present_input_voltage(592, TYPE_UINT16); //, 0.1);
    DynamixelAddress present_temperture   (594, TYPE_UINT8 ); //, 1.0);
    DynamixelAddress external_port_data_1 (600, TYPE_UINT16);
    DynamixelAddress external_port_data_2 (602, TYPE_UINT16);
    DynamixelAddress external_port_data_3 (604, TYPE_UINT16);
    DynamixelAddress external_port_data_4 (606, TYPE_UINT16);
    DynamixelAddress status_return_level  (516, TYPE_UINT8 );
    DynamixelAddress hardware_error_status(518, TYPE_UINT8 );
}
