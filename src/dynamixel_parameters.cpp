#include "dynamixel_parameters.h"
#include <math.h>

// dynamixel x
DynamixelParameter id_x(7, TYPE_UINT8);
DynamixelParameter baudrate_x(8, TYPE_UINT8);
DynamixelParameter return_deray_time_x(9, TYPE_UINT8);
DynamixelParameter operating_mode_x(11, TYPE_UINT8);
DynamixelParameter homing_offset_x(20, TYPE_INT32, M_PI/2048.0);
DynamixelParameter current_limit_xw(38, TYPE_UINT16, 2.69);
DynamixelParameter current_limit_xv(38, TYPE_UINT16, 1.34);
DynamixelParameter acceleration_limit_x(40, TYPE_UINT32, 214.577*2.0*M_PI/3600.0);
DynamixelParameter velocity_limit_x(44, TYPE_UINT32, 0.229*2.0*M_PI/60.0 );
DynamixelParameter max_position_limit_x(48, TYPE_UINT32, M_PI/2048.0);
DynamixelParameter min_position_limit_x(52, TYPE_UINT32, M_PI/2048.0);
DynamixelParameter external_port_mode_1_x(56, TYPE_UINT8);
DynamixelParameter external_port_mode_2_x(57, TYPE_UINT8);
DynamixelParameter external_port_mode_3_x(58, TYPE_UINT8);
DynamixelParameter shutdown_x(63, TYPE_UINT8);
DynamixelParameter torque_enable_x(64, TYPE_UINT8);
DynamixelParameter led_x(65, TYPE_UINT8);
DynamixelParameter status_return_level_x(68, TYPE_UINT8);
DynamixelParameter velocity_i_gain_x(76, TYPE_UINT16);
DynamixelParameter velocity_p_gain_x(78, TYPE_UINT16);
DynamixelParameter position_d_gain_x(80, TYPE_UINT16);
DynamixelParameter position_i_gain_x(82, TYPE_UINT16);
DynamixelParameter position_p_gain_x(84, TYPE_UINT16);
DynamixelParameter goal_current_xw(102, TYPE_INT16, 2.69/1000.0);
DynamixelParameter goal_current_xv(102, TYPE_INT16, 1.34/1000.0);
DynamixelParameter profile_acceleration_x(108, TYPE_INT32, 214.577*2.0*M_PI/3600.0); // unit 214.577 [rpm^2]
DynamixelParameter profile_velocity_x(112, TYPE_INT32, 0.229*2.0*M_PI/60.0 );// unit 0.229  [rpm]
DynamixelParameter goal_position_xh540v(104, TYPE_INT32, 1.0/128.0);
DynamixelParameter goal_position_x(116, TYPE_INT32, M_PI/2048.0);
DynamixelParameter present_current_xw(126, TYPE_INT16, 2.69);
DynamixelParameter present_current_xv(126, TYPE_INT16, 1.34);
DynamixelParameter present_velocity_x(128, TYPE_INT32, M_PI/180.0*0.229);
DynamixelParameter present_position_x(132, TYPE_INT32, M_PI/2048.0);
DynamixelParameter present_input_voltage_x(144, TYPE_UINT16, 0.1);
DynamixelParameter present_temperture_x(146, TYPE_UINT8);
DynamixelParameter external_port_data_1_x(152, TYPE_UINT16);
DynamixelParameter external_port_data_2_x(154, TYPE_UINT16);
DynamixelParameter external_port_data_3_x(156, TYPE_UINT16);
DynamixelParameter hardware_error_status_x(70, TYPE_UINT8);

// dynamixel pro plus
DynamixelParameter id_pp(7, TYPE_UINT8);
DynamixelParameter baudrate_pp(8, TYPE_UINT8);
DynamixelParameter return_deray_time_pp(9, TYPE_UINT8);
DynamixelParameter drive_mode_pp(10, TYPE_UINT8);
DynamixelParameter operating_mode_pp(11, TYPE_UINT8);
DynamixelParameter homing_offset_pp42(20, TYPE_INT32, M_PI/303750);
DynamixelParameter homing_offset_pp54(20, TYPE_INT32, M_PI/501923);
DynamixelParameter current_limit_pp(38, TYPE_UINT16, 0.001);
DynamixelParameter acceleration_limit_pp(38, TYPE_UINT32, 58000*2.0*M_PI/3600.0); //unit 58000 [rpm^2]
DynamixelParameter velocity_limit_pp(38, TYPE_UINT32, 0.01*2.0*M_PI/60.0); //unit 0.01 [rpm]
DynamixelParameter max_position_limit_pp42(48, TYPE_INT32, M_PI/303750);
DynamixelParameter max_position_limit_pp54(48, TYPE_INT32, M_PI/501923);
DynamixelParameter min_position_limit_pp42(52, TYPE_INT32, M_PI/303750);
DynamixelParameter min_position_limit_pp54(52, TYPE_INT32, M_PI/501923);
DynamixelParameter external_port_mode_1_pp(56, TYPE_UINT8);
DynamixelParameter external_port_mode_2_pp(57, TYPE_UINT8);
DynamixelParameter external_port_mode_3_pp(58, TYPE_UINT8);
DynamixelParameter external_port_mode_4_pp(59, TYPE_UINT8);
DynamixelParameter shutdown_pp(63, TYPE_UINT8);
DynamixelParameter torque_enable_pp(512, TYPE_UINT8);
DynamixelParameter led_red_pp(513, TYPE_UINT8);
DynamixelParameter led_green_pp(514, TYPE_UINT8);
DynamixelParameter led_blue_pp(515, TYPE_UINT8);
DynamixelParameter velocity_i_gain_pp(524, TYPE_UINT16);
DynamixelParameter velocity_p_gain_pp(526, TYPE_UINT16);
DynamixelParameter position_d_gain_pp(528, TYPE_UINT16);
DynamixelParameter position_i_gain_pp(530, TYPE_UINT16);
DynamixelParameter position_p_gain_pp(532, TYPE_UINT16);
DynamixelParameter goal_current_pp(550, TYPE_INT16, 0.001);
DynamixelParameter goal_velocity_pp(552, TYPE_INT32, 0.01*2.0*M_PI/60.0);
DynamixelParameter profile_acceleration_pp(556, TYPE_UINT32, 1.0*2.0*M_PI/3600.0);// unit 1 [rpm^2]
DynamixelParameter profile_velocity_pp(560, TYPE_UINT32, 0.01*2.0*M_PI/60.0);// unit 0.01 [rpm]
DynamixelParameter goal_position_pp42(564, TYPE_INT32, M_PI/303750);
DynamixelParameter goal_position_pp54(564, TYPE_INT32, M_PI/501923);
DynamixelParameter present_current_pp(574, TYPE_INT16, 0.001);
DynamixelParameter present_velocity_pp(576, TYPE_INT32, 0.01*2.0*M_PI/60.0);
DynamixelParameter present_position_pp42(580, TYPE_INT32, M_PI/303750);
DynamixelParameter present_position_pp54(580, TYPE_INT32, M_PI/501923);
DynamixelParameter present_input_voltage_pp(592, TYPE_UINT16, 0.1);
DynamixelParameter present_temperture_pp(594, TYPE_UINT8, 1.0);
DynamixelParameter external_port_data_1_pp(600, TYPE_UINT16);
DynamixelParameter external_port_data_2_pp(602, TYPE_UINT16);
DynamixelParameter external_port_data_3_pp(604, TYPE_UINT16);
DynamixelParameter external_port_data_4_pp(606, TYPE_UINT16);
DynamixelParameter status_return_level_pp(516, TYPE_UINT8);
DynamixelParameter hardware_error_status_pp(518, TYPE_UINT8);

// dynamixel pro
DynamixelParameter id_pro(7, TYPE_UINT8);
DynamixelParameter baudrate_pro(8, TYPE_UINT8);
DynamixelParameter return_deray_time_pro(9, TYPE_UINT8);
DynamixelParameter drive_mode_pro(10, TYPE_UINT8);
DynamixelParameter operating_mode_pro(11, TYPE_UINT8);
DynamixelParameter homing_offset_pro42(13, TYPE_INT32, M_PI/151875);
DynamixelParameter homing_offset_pro54(13, TYPE_INT32, M_PI/250961.5);
DynamixelParameter torque_limit_pro(30, TYPE_UINT16);
DynamixelParameter max_position_limit_pro42(36, TYPE_INT32, M_PI/151875);
DynamixelParameter max_position_limit_pro54(36, TYPE_INT32, M_PI/250961.5);
DynamixelParameter min_position_limit_pro42(40, TYPE_INT32, M_PI/151875);
DynamixelParameter min_position_limit_pro54(40, TYPE_INT32, M_PI/250961.5);
DynamixelParameter external_port_mode_1_pro(44, TYPE_UINT8);
DynamixelParameter external_port_mode_2_pro(45, TYPE_UINT8);
DynamixelParameter external_port_mode_3_pro(46, TYPE_UINT8);
DynamixelParameter external_port_mode_4_pro(47, TYPE_UINT8);
DynamixelParameter shutdown_pro(48, TYPE_UINT8);
DynamixelParameter torque_enable_pro(562, TYPE_UINT8);
DynamixelParameter led_red_pro(563, TYPE_UINT8);
DynamixelParameter led_green_pro(564, TYPE_UINT8);
DynamixelParameter led_blue_pro(565, TYPE_UINT8);
DynamixelParameter velocity_i_gain_pro(586, TYPE_UINT16);
DynamixelParameter velocity_p_gain_pro(588, TYPE_UINT16);
DynamixelParameter position_p_gain_pro(594, TYPE_UINT16);
DynamixelParameter goal_position_pro42(596, TYPE_INT32, M_PI/151875);
DynamixelParameter goal_position_pro54(596, TYPE_INT32, M_PI/250961.5);
DynamixelParameter goal_velocity_pro42(600, TYPE_INT32, M_PI/180.0*0.00199234);
DynamixelParameter goal_velocity_pro54(600, TYPE_INT32, M_PI/180.0*0.00329218);
DynamixelParameter goal_torque_pro(604, TYPE_INT16);
DynamixelParameter present_position_pro42(611, TYPE_INT32, M_PI/151875);
DynamixelParameter present_position_pro54(611, TYPE_INT32, M_PI/250961.5);
DynamixelParameter present_velocity_pro42(615, TYPE_INT32, M_PI/180.0*0.00199234);
DynamixelParameter present_velocity_pro54(615, TYPE_INT32, M_PI/180.0*0.00329218);
DynamixelParameter present_current_pro(621, TYPE_INT16);
DynamixelParameter present_input_voltage_pro(623, TYPE_UINT16, 0.1);
DynamixelParameter present_temperture_pro(625, TYPE_UINT8);
DynamixelParameter external_port_data_1_pro(626, TYPE_UINT16);
DynamixelParameter external_port_data_2_pro(628, TYPE_UINT16);
DynamixelParameter external_port_data_3_pro(630, TYPE_UINT16);
DynamixelParameter external_port_data_4_pro(632, TYPE_UINT16);
DynamixelParameter status_return_level_pro(891, TYPE_UINT8);
DynamixelParameter hardware_error_status_pro(892, TYPE_UINT8);
