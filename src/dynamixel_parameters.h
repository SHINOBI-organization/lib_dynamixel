#ifndef DYNAMIXEL_PARAMETERS_H_
#define DYNAMIXEL_PARAMETERS_H_

#include <cassert>
#include <stdint.h>
#include <cmath>

enum DynamixelModelNumber {
  // Dynamixel X series
  MODEL_XL330_M077	= 1190,
  MODEL_XL330_M288	= 1200,
  MODEL_XC330_T181	= 1210,
  MODEL_XC330_T288	= 1220,
  MODEL_XC330_M181	= 1230,
  MODEL_XC330_M288	= 1240,
  MODEL_XL430_W250	= 1060,
  MODEL_XC430_W150	= 1070, // MODEL_XC430_W150BB と同じ
  MODEL_XC430_W240	= 1080, // MODEL_XC430_W240BB と同じ
  MODEL_2XL430_W250	= 1090,
  MODEL_2XC430_W250	= 1160,
  MODEL_XM430_W210	= 1030,
  MODEL_XH430_W210	= 1010,
  MODEL_XH430_V210	= 1050,
  MODEL_XD430_T210	= 1011,
  MODEL_XM430_W350	= 1020,
  MODEL_XH430_W350	= 1000,
  MODEL_XH430_V350	= 1040,
  MODEL_XD430_T350	= 1001,
  MODEL_XW430_T200	= 1280,
  MODEL_XW430_T333	= 1270,
  MODEL_XM540_W150	= 1130,
  MODEL_XH540_W150	= 1110,
  MODEL_XD540_T150  = 1111,
  MODEL_XH540_V150	= 1150,
  MODEL_XM540_W270	= 1120,
  MODEL_XH540_W270	= 1100,
  MODEL_XD540_T270  = 1101,
  MODEL_XH540_V270	= 1140,
  MODEL_XW540_T140	= 1180,
  MODEL_XW540_T260	= 1170,
  // Dynamixel P series
  MODEL_PH54_200_S500 = 2020,
  MODEL_PH54_100_S500 = 2010,
  MODEL_PH42_020_S300 = 2000,
  MODEL_PM54_060_S250 = 2120,
  MODEL_PM54_040_S250 = 2110,
  MODEL_PM42_010_S260 = 2100,
  // Dynamixel Pro plus series
  MODEL_H54_200_S500_A = 54025,
  MODEL_H54_100_S500_A = 53769,
  MODEL_H42_020_S300_A = 51201,
  MODEL_M54_060_S250_A = 46353,
  MODEL_M54_040_S250_A = 46097,
  MODEL_M42_010_S260_A = 43289,
  // Dynamixel Pro series 
  MODEL_H54_200_S500 = 54024,
  MODEL_H54_100_S500 = 53768,
  MODEL_H42_020_S300 = 51200,
  MODEL_M54_060_S250 = 46352,
  MODEL_M54_040_S250 = 46096,
  MODEL_M42_010_S260 = 43288,
  MODEL_L54_050_S290 = 38176,
  MODEL_L54_050_S500 = 38152,
  MODEL_L54_030_S400 = 37928,
  MODEL_L54_030_S500 = 37896,
  MODEL_L42_010_S300 = 35072
};

enum DynamixelSeries {
  SERIES_UNKNOWN,
  SERIES_X,
  SERIES_P,
  SERIES_PRO,
  SERIES_PRO_PLUS = SERIES_P // ProPlusはPと同じ扱い
};

inline DynamixelSeries dynamixel_series(uint16_t model_num){ 
    return (1000  <= model_num && model_num < 2000 )                      ? SERIES_X
          :(2000  <= model_num && model_num < 3000 )                      ? SERIES_P 
          :(30000 <= model_num && model_num < 40000)                      ? SERIES_PRO      // L
          :(46353 == model_num || 46097== model_num || 43289== model_num) ? SERIES_PRO_PLUS // M plus
          :(40000 <= model_num && model_num < 50000)                      ? SERIES_PRO      // M
          :(54025 == model_num || 53769== model_num || 51201== model_num) ? SERIES_PRO_PLUS // H plus
          :(50000 <= model_num && model_num < 60000)                      ? SERIES_PRO      // H
          :                                                                 SERIES_UNKNOWN; 
}

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
  BAUDRATE_INDEX_6M     = 8,
  BAUDRATE_INDEX_10M5   = 9,
};
enum DynamixelOperatingMode {
  OPERATING_MODE_CURRENT               = 0,
  OPERATING_MODE_VELOCITY              = 1,
  OPERATING_MODE_POSITION              = 3,
  OPERATING_MODE_EXTENDED_POSITION     = 4,
  OPERATING_MODE_CURRENT_BASE_POSITION = 5,
  OPERATING_MODE_PWM                   = 16,
};
enum DynamixelExternalPortMode {
  EXTERNAL_PORT_MODE_AIN          = 0,
  EXTERNAL_PORT_MODE_DOUT         = 1,
  EXTERNAL_PORT_MODE_DIN_PULLUP   = 2,
  EXTERNAL_PORT_MODE_DIN_PULLDOWN = 3,
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

enum DynamixelPhysicalUnit { // これは型番によって変わるので，識別のために使う
  NOUNIT,
  UNIT_POSITION,
  UNIT_POSITION_OFFSET, // Xシリーズの0点ズレを考慮したもの, 0.0 deg = 2048 pulse
  UNIT_VELOCITY,
  UNIT_ACCELERATION,
  UNIT_CURRENT,
  UNIT_VOLTAGE,           // 常に0.1V
  UNIT_TEMPERATURE,
  UNIT_PWM,
  UNIT_RETURN_DELAY_TIME, //　常に2us
  UNIT_BUS_WATCHDOG,      // 常に20ms
  UNIT_REALTIME_TICK,     // 常に1ms
};

class DynamixelAddress {
 public:
  DynamixelAddress( uint16_t address, DynamixelDataType data_type, DynamixelPhysicalUnit physical_unit = NOUNIT ):
    is_dummy_(false) , address_(address), data_type_(data_type), physical_unit_(physical_unit){
	  switch (data_type_) {
      case TYPE_INT8:
      case TYPE_UINT8:  size_ = 1; break;
      case TYPE_INT16:
      case TYPE_UINT16: size_ = 2; break;
      case TYPE_INT32:
      case TYPE_UINT32: size_ = 4; break;
    }
  }

  bool                  is_dummy() const { return is_dummy_; }
  uint16_t              size() const { return size_; }
  uint16_t              address() const { return address_; }
  DynamixelDataType     data_type() const { return data_type_; }
  DynamixelPhysicalUnit physical_unit() const { return physical_unit_; }
  DynamixelAddress      make_dummy() const { 
     auto addr = DynamixelAddress( address_, data_type_, physical_unit_ );
     addr.is_dummy_ = true; 
     return addr;
  }

  int64_t val2pulse(const double val, const uint16_t model_num) const { 
    assert(dynamixel_series(model_num) != SERIES_UNKNOWN); // 未対応のシリーズの場合はエラー
    double pulse;
    switch (physical_unit_) {
      case UNIT_POSITION:         pulse=       val /*rad*/  / (2*M_PI) * pos_resolution(model_num); break;
      case UNIT_POSITION_OFFSET:  pulse= (M_PI+val)/*rad*/  / (2*M_PI) * pos_resolution(model_num); break;
      case UNIT_VELOCITY:         pulse=       val/*rad_s*/ / vel_factor(model_num); break;
      case UNIT_ACCELERATION:     pulse=       val/*rad_ss*// acc_factor(model_num); break;
      case UNIT_CURRENT:          pulse=       val/*mA*/    / cur_factor(model_num); break;
      case UNIT_VOLTAGE:          pulse=       val/*V*/     / 0.1/*V*/; break;
      case UNIT_TEMPERATURE:      pulse=       val/*degC*/  / 1.0/*degC*/; break;
      case UNIT_PWM:              pulse=       val/*%*/     / 100.0 * pwm_resolution(model_num)/*degC*/; break;
      case UNIT_RETURN_DELAY_TIME:pulse=       val/*us*/    / 2.0 /*us*/; break;
      case UNIT_BUS_WATCHDOG:     pulse=       val/*ms*/    / 20.0/*ms*/; break;
      case UNIT_REALTIME_TICK:    pulse=       val/*ms*/    / 1.0 /*ms*/; break;
      default:                    pulse=       val; break;
    }
    return pulse>0 ? ceil(pulse) : floor(pulse);
  }
  double pulse2val(const int64_t pulse, const uint16_t model_num ) const {
    assert(dynamixel_series(model_num) != SERIES_UNKNOWN); // 未対応のシリーズの場合はエラー
    if ( is_dummy_ ) return std::numeric_limits<double>::quiet_NaN();
    switch (physical_unit_) {
      case UNIT_POSITION:         return pulse * (2*M_PI) / pos_resolution(model_num)       /*rad*/;
      case UNIT_POSITION_OFFSET:  return pulse * (2*M_PI) / pos_resolution(model_num) - M_PI/*rad*/;
      case UNIT_VELOCITY:         return pulse * vel_factor(model_num) /*rad_s*/;
      case UNIT_ACCELERATION:     return pulse * acc_factor(model_num) /*rad_ss*/;
      case UNIT_CURRENT:          return pulse * cur_factor(model_num) /*mA*/;
      case UNIT_VOLTAGE:          return pulse * 0.1 /*V*/;
      case UNIT_TEMPERATURE:      return pulse * 1.0 /*degC*/;
      case UNIT_PWM:              return pulse * 100.0 / pwm_resolution(model_num) /*%*/;
      case UNIT_RETURN_DELAY_TIME:return pulse * 2.0 /*us*/;
      case UNIT_BUS_WATCHDOG:     return pulse * 20.0/*ms*/;
      case UNIT_REALTIME_TICK:    return pulse * 1.0 /*ms*/;
      default:                    return pulse;
    }
  }

 private:
  bool is_dummy_;
  uint16_t address_;
  uint8_t size_;
  DynamixelDataType data_type_;
  DynamixelPhysicalUnit physical_unit_;
  uint32_t pos_resolution(uint16_t model_num) const {
    switch (model_num) {
      // Pシリーズ
      case MODEL_PH54_200_S500:
      case MODEL_PH54_100_S500: return 1003846;
      case MODEL_PH42_020_S300: return 607500;
      case MODEL_PM54_060_S250: 
      case MODEL_PM54_040_S250: return 502834;
      case MODEL_PM42_010_S260: return 526374;
      // ProPlusシリーズ
      case MODEL_H54_200_S500_A:
      case MODEL_H54_100_S500_A: return 1003846;
      case MODEL_H42_020_S300_A: return 607500;
      case MODEL_M54_060_S250_A:
      case MODEL_M54_040_S250_A: return 502834;
      case MODEL_M42_010_S260_A: return 526375;
      // Proシリーズ
      case MODEL_H54_200_S500:
      case MODEL_H54_100_S500: return 501923;
      case MODEL_H42_020_S300: return 303750;
      case MODEL_M54_060_S250:
      case MODEL_M54_040_S250: return 251417;
      case MODEL_M42_010_S260: return 263187;
      case MODEL_L54_050_S290: return 207692;
      case MODEL_L54_050_S500: return 361384;
      case MODEL_L54_030_S400: return 288395;
      case MODEL_L54_030_S500: return 316384;
      case MODEL_L42_010_S300: return 4096;
      // Xシリーズのデフォルト値
      default:                  return 4096; 
    }
  }
  uint16_t pwm_resolution(uint16_t model_num) const {
    if      ( dynamixel_series(model_num) == SERIES_P ) return 2009;
    else if ( dynamixel_series(model_num) == SERIES_X ) return 885;
    else   /*dynamixel_series(model_num) == SERIES_PRO*/ assert(false); // 旧ProシリーズではPWM制御できないはず．
  }
  double cur_factor(uint16_t model_num) const {
    if (dynamixel_series(model_num) == SERIES_P) return 1.00;
    else // dynamixel_series(model_num) == SERIES_X || SERIES_PRO
      switch (model_num) {
        // Proシリーズ
        case MODEL_H42_020_S300:
        case MODEL_M42_010_S260: 
        case MODEL_L42_010_S300: return 8250.0/2048.0;
        case MODEL_H54_200_S500:
        case MODEL_H54_100_S500:
        case MODEL_M54_060_S250:
        case MODEL_M54_040_S250:
        case MODEL_L54_050_S290:
        case MODEL_L54_050_S500:
        case MODEL_L54_030_S400:
        case MODEL_L54_030_S500: return 33000.0/2048.0;
        // Xシリーズ
        case MODEL_XL330_M077:
        case MODEL_XL330_M288:
        case MODEL_XC330_M181:
        case MODEL_XC330_M288:
        case MODEL_XC330_T181:
        case MODEL_XC330_T288:    return 1.00;
        case MODEL_XH430_V210:
        case MODEL_XH430_V350:    return 1.34;
        default:                  return 2.69; /*mA*/
    } 
  }
  double vel_factor(uint16_t model_num) const {
    if      ( dynamixel_series(model_num) == SERIES_P ) return 0.010/*rev/min*/ / 60.0 * (2*M_PI);
    else if ( dynamixel_series(model_num) == SERIES_X ) return 0.229/*rev/min*/ / 60.0 * (2*M_PI);
    else    /*dynamixel_series(model_num) == SERIES_PRO*/
      switch (model_num) { //
        case MODEL_H54_200_S500:
        case MODEL_H54_100_S500: return 1/501.923;
        case MODEL_H42_020_S300: return 1/303.750;
        case MODEL_M54_060_S250:
        case MODEL_M54_040_S250: return 1/251.417;
        case MODEL_L54_050_S290: return 1/288.461;
        case MODEL_L54_050_S500:
        case MODEL_L54_030_S500: return 1/501.923;
        case MODEL_L54_030_S400: return 1/400.550;
        case MODEL_L42_010_S300: return 1/303.8;
        default:                 return 1/100.0; // 適当な値
      }
  }
  double acc_factor(uint16_t model_num) const {
    if     (  dynamixel_series(model_num) == SERIES_P   ) return 1.0    /*rev/min^2*// 60.0 / 60.0 * (2*M_PI); // ベステクの数値は間違ってる
    else if ( dynamixel_series(model_num) == SERIES_X   ) return 214.577/*rev/min^2*// 60.0 / 60.0 * (2*M_PI);
    else    /*dynamixel_series(model_num) == SERIES_PRO*/ 
      switch (model_num) { // 
        case MODEL_H54_200_S500:
        case MODEL_H54_100_S500: return 58000.0/501.923/*rev/min^2*// 60.0 / 60.0 * (2*M_PI);
        case MODEL_H42_020_S300: return 58000.0/303.750/*rev/min^2*// 60.0 / 60.0 * (2*M_PI);
        case MODEL_M54_060_S250:
        case MODEL_M54_040_S250: return 58000.0/251.417/*rev/min^2*// 60.0 / 60.0 * (2*M_PI);
        case MODEL_L54_050_S290: return 58000.0/288.461/*rev/min^2*// 60.0 / 60.0 * (2*M_PI);
        case MODEL_L54_050_S500:
        case MODEL_L54_030_S500: return 58000.0/501.923/*rev/min^2*// 60.0 / 60.0 * (2*M_PI);
        case MODEL_L54_030_S400: return 58000.0/400.550/*rev/min^2*// 60.0 / 60.0 * (2*M_PI);
        case MODEL_L42_010_S300: return 58000.0/303.8/*rev/min^2*// 60.0 / 60.0 * (2*M_PI);
        default:                 return 58000.0/100.0/*rev/min^2*// 60.0 / 60.0 * (2*M_PI); // 適当な値
      }
  }
};

// dynamixel common
struct AddrCommon {
    static inline DynamixelAddress model_number      {  0, TYPE_UINT16};
    static inline DynamixelAddress id                {  7, TYPE_UINT8 };
};

// dynamixel X series   
struct AddrX : AddrCommon{
    static inline DynamixelSeries series() { return SERIES_X;}
    static inline DynamixelAddress baudrate          {  8, TYPE_UINT8 };
    static inline DynamixelAddress return_delay_time {  9, TYPE_UINT8 , UNIT_RETURN_DELAY_TIME};
    static inline DynamixelAddress drive_mode        { 10, TYPE_UINT8 }; 
    static inline DynamixelAddress operating_mode    { 11, TYPE_UINT8 };
    static inline DynamixelAddress shadow_id         { 12, TYPE_UINT8 }; 
    static inline DynamixelAddress homing_offset         { 20, TYPE_INT32 , UNIT_POSITION       };
    static inline DynamixelAddress moving_threshold      { 24, TYPE_UINT32, UNIT_VELOCITY       }; 
    static inline DynamixelAddress temperature_limit     { 31, TYPE_UINT8 , UNIT_TEMPERATURE    };
    static inline DynamixelAddress max_voltage_limit     { 32, TYPE_UINT16, UNIT_VOLTAGE        };
    static inline DynamixelAddress min_voltage_limit     { 34, TYPE_UINT16, UNIT_VOLTAGE        };
    static inline DynamixelAddress pwm_limit             { 36, TYPE_UINT16, UNIT_PWM            };
    static inline DynamixelAddress current_limit         { 38, TYPE_UINT16, UNIT_CURRENT        };
    static inline DynamixelAddress velocity_limit        { 44, TYPE_UINT32, UNIT_VELOCITY       };
    static inline DynamixelAddress max_position_limit    { 48, TYPE_UINT32, UNIT_POSITION_OFFSET};
    static inline DynamixelAddress min_position_limit    { 52, TYPE_UINT32, UNIT_POSITION_OFFSET};
    static inline DynamixelAddress external_port_mode_1  { 56, TYPE_UINT8 };
    static inline DynamixelAddress external_port_mode_2  { 57, TYPE_UINT8 };
    static inline DynamixelAddress external_port_mode_3  { 58, TYPE_UINT8 };
    static inline DynamixelAddress shutdown              { 63, TYPE_UINT8 };
    static inline DynamixelAddress torque_enable         { 64, TYPE_UINT8 };
    static inline DynamixelAddress led                   { 65, TYPE_UINT8 };
    static inline DynamixelAddress status_return_level   { 68, TYPE_UINT8 };
    static inline DynamixelAddress registered_instruction{ 69, TYPE_UINT8 };
    static inline DynamixelAddress hardware_error_status { 70, TYPE_UINT8 };
    static inline DynamixelAddress velocity_i_gain       { 76, TYPE_UINT16}; // 型番によってデフォルト値が異なる
    static inline DynamixelAddress velocity_p_gain       { 78, TYPE_UINT16}; // 型番によってデフォルト値が異なる
    static inline DynamixelAddress position_d_gain       { 80, TYPE_UINT16}; // 型番によってデフォルト値が異なる
    static inline DynamixelAddress position_i_gain       { 82, TYPE_UINT16}; // 型番によってデフォルト値が異なる
    static inline DynamixelAddress position_p_gain       { 84, TYPE_UINT16}; // 型番によってデフォルト値が異なる
    static inline DynamixelAddress feedforward_2nd_gain  { 88, TYPE_UINT16};
    static inline DynamixelAddress feedforward_1st_gain  { 90, TYPE_UINT16};
    static inline DynamixelAddress bus_watchdog          { 98, TYPE_INT8  , UNIT_BUS_WATCHDOG   };
    static inline DynamixelAddress goal_pwm              {100, TYPE_INT16 , UNIT_PWM            };
    static inline DynamixelAddress goal_current          {102, TYPE_INT16 , UNIT_CURRENT        };
    static inline DynamixelAddress goal_velocity         {104, TYPE_INT32 , UNIT_VELOCITY       };
    static inline DynamixelAddress profile_acceleration  {108, TYPE_INT32 , UNIT_ACCELERATION   };
    static inline DynamixelAddress profile_velocity      {112, TYPE_INT32 , UNIT_VELOCITY       };
    static inline DynamixelAddress goal_position         {116, TYPE_INT32 , UNIT_POSITION_OFFSET};
    static inline DynamixelAddress realtime_tick         {120, TYPE_UINT16, UNIT_REALTIME_TICK  };
    static inline DynamixelAddress moving                {122, TYPE_UINT8 };
    static inline DynamixelAddress moving_status         {123, TYPE_UINT8 };
    static inline DynamixelAddress present_pwm           {124, TYPE_INT16 , UNIT_PWM            };
    static inline DynamixelAddress present_current       {126, TYPE_INT16 , UNIT_CURRENT        }; 
    static inline DynamixelAddress present_velocity      {128, TYPE_INT32 , UNIT_VELOCITY       };
    static inline DynamixelAddress present_position      {132, TYPE_INT32 , UNIT_POSITION_OFFSET};
    static inline DynamixelAddress velocity_trajectory   {136, TYPE_INT32 , UNIT_VELOCITY       };
    static inline DynamixelAddress position_trajectory   {140, TYPE_INT32 , UNIT_POSITION_OFFSET};
    static inline DynamixelAddress present_input_voltage {144, TYPE_UINT16, UNIT_VOLTAGE        };
    static inline DynamixelAddress present_temperature   {146, TYPE_UINT8 , UNIT_TEMPERATURE    };
    static inline DynamixelAddress external_port_data_1  {152, TYPE_UINT16};
    static inline DynamixelAddress external_port_data_2  {154, TYPE_UINT16};
    static inline DynamixelAddress external_port_data_3  {156, TYPE_UINT16};
    // 共通化のための小細工
    static inline auto acceleration_limit = DynamixelAddress(40, TYPE_UINT32, UNIT_ACCELERATION ).make_dummy(); // e-manualには存在しない．Pシリーズとの一貫性のため，また，なぜか読み書きできるため，追加した． UNIT_NANにし他方がいいかも...
};// 以後Indirect Address, うまく実装して取り込みたい．

// dynamixel P series (old: pro plus)
struct AddrP : AddrCommon {
    static inline DynamixelSeries series() { return SERIES_P;}
    static inline DynamixelAddress baudrate          {  8, TYPE_UINT8 };
    static inline DynamixelAddress return_delay_time {  9, TYPE_UINT8 , UNIT_RETURN_DELAY_TIME};
    static inline DynamixelAddress drive_mode        { 10, TYPE_UINT8 }; 
    static inline DynamixelAddress operating_mode    { 11, TYPE_UINT8 };
    static inline DynamixelAddress shadow_id         { 12, TYPE_UINT8 }; 
    static inline DynamixelAddress homing_offset         { 20, TYPE_INT32 , UNIT_POSITION    };
    static inline DynamixelAddress moving_threshold      { 24, TYPE_UINT32, UNIT_VELOCITY    };
    static inline DynamixelAddress temperature_limit     { 31, TYPE_UINT8 , UNIT_TEMPERATURE };
    static inline DynamixelAddress max_voltage_limit     { 32, TYPE_UINT16, UNIT_VOLTAGE     };
    static inline DynamixelAddress min_voltage_limit     { 34, TYPE_UINT16, UNIT_VOLTAGE     };
    static inline DynamixelAddress pwm_limit             { 36, TYPE_UINT16, UNIT_PWM         };
    static inline DynamixelAddress current_limit         { 38, TYPE_UINT16, UNIT_CURRENT     };
    static inline DynamixelAddress acceleration_limit    { 40, TYPE_UINT32, UNIT_ACCELERATION};
    static inline DynamixelAddress velocity_limit        { 44, TYPE_UINT32, UNIT_VELOCITY    };
    static inline DynamixelAddress max_position_limit    { 48, TYPE_INT32 , UNIT_POSITION    };
    static inline DynamixelAddress min_position_limit    { 52, TYPE_INT32 , UNIT_POSITION    };
    static inline DynamixelAddress external_port_mode_1  { 56, TYPE_UINT8 };
    static inline DynamixelAddress external_port_mode_2  { 57, TYPE_UINT8 };
    static inline DynamixelAddress external_port_mode_3  { 58, TYPE_UINT8 };
    static inline DynamixelAddress external_port_mode_4  { 59, TYPE_UINT8 };
    static inline DynamixelAddress shutdown              { 63, TYPE_UINT8 };
    // == Indirect Address ==
    static inline DynamixelAddress torque_enable         {512, TYPE_UINT8 };
    static inline DynamixelAddress led_red               {513, TYPE_UINT8 };
    static inline DynamixelAddress led_green             {514, TYPE_UINT8 };
    static inline DynamixelAddress led_blue              {515, TYPE_UINT8 };
    static inline DynamixelAddress status_return_level   {516, TYPE_UINT8 };
    static inline DynamixelAddress registered_instruction{517, TYPE_UINT8 };
    static inline DynamixelAddress hardware_error_status {518, TYPE_UINT8 };
    static inline DynamixelAddress velocity_i_gain       {524, TYPE_UINT16};
    static inline DynamixelAddress velocity_p_gain       {526, TYPE_UINT16};
    static inline DynamixelAddress position_d_gain       {528, TYPE_UINT16};
    static inline DynamixelAddress position_i_gain       {530, TYPE_UINT16};
    static inline DynamixelAddress position_p_gain       {532, TYPE_UINT16};
    static inline DynamixelAddress feedforward_2nd_gain  {536, TYPE_UINT16};
    static inline DynamixelAddress feedforward_1st_gain  {538, TYPE_UINT16};
    static inline DynamixelAddress bus_watchdog          {546, TYPE_UINT8 , UNIT_BUS_WATCHDOG };
    static inline DynamixelAddress goal_pwm              {548, TYPE_INT16 , UNIT_PWM          };
    static inline DynamixelAddress goal_current          {550, TYPE_INT16 , UNIT_CURRENT      };
    static inline DynamixelAddress goal_velocity         {552, TYPE_INT32 , UNIT_VELOCITY     };
    static inline DynamixelAddress profile_acceleration  {556, TYPE_UINT32, UNIT_ACCELERATION };
    static inline DynamixelAddress profile_velocity      {560, TYPE_UINT32, UNIT_VELOCITY     };
    static inline DynamixelAddress goal_position         {564, TYPE_INT32 , UNIT_POSITION     };
    static inline DynamixelAddress realtime_tick         {568, TYPE_UINT16, UNIT_REALTIME_TICK};
    static inline DynamixelAddress moving                {570, TYPE_UINT8 };
    static inline DynamixelAddress moving_status         {571, TYPE_UINT8 };
    static inline DynamixelAddress present_pwm           {572, TYPE_INT16 , UNIT_PWM        };
    static inline DynamixelAddress present_current       {574, TYPE_INT16 , UNIT_CURRENT    }; 
    static inline DynamixelAddress present_velocity      {576, TYPE_INT32 , UNIT_VELOCITY   };
    static inline DynamixelAddress present_position      {580, TYPE_INT32 , UNIT_POSITION   };
    static inline DynamixelAddress velocity_trajectory   {584, TYPE_INT32 , UNIT_VELOCITY   };
    static inline DynamixelAddress position_trajectory   {588, TYPE_INT32 , UNIT_POSITION   };
    static inline DynamixelAddress present_input_voltage {592, TYPE_UINT16, UNIT_VOLTAGE    };
    static inline DynamixelAddress present_temperature   {594, TYPE_UINT8 , UNIT_TEMPERATURE};
    static inline DynamixelAddress external_port_data_1  {600, TYPE_UINT16};
    static inline DynamixelAddress external_port_data_2  {602, TYPE_UINT16};
    static inline DynamixelAddress external_port_data_3  {604, TYPE_UINT16};
    static inline DynamixelAddress external_port_data_4  {606, TYPE_UINT16};
    // == Indirect Address ==
};

// dynamixel Pro series
struct AddrPro : AddrCommon {
    static inline DynamixelSeries series() { return SERIES_PRO;}    
    static inline DynamixelAddress baudrate          {  8, TYPE_UINT8 };
    static inline DynamixelAddress return_delay_time {  9, TYPE_UINT8 , UNIT_RETURN_DELAY_TIME};
    static inline DynamixelAddress operating_mode    { 11, TYPE_UINT8 };
    static inline DynamixelAddress homing_offset         { 13, TYPE_INT32 , UNIT_POSITION    };
    static inline DynamixelAddress moving_threshold      { 17, TYPE_UINT32, UNIT_VELOCITY    };
    static inline DynamixelAddress temperature_limit     { 21, TYPE_UINT8 , UNIT_TEMPERATURE };
    static inline DynamixelAddress max_voltage_limit     { 22, TYPE_UINT16, UNIT_VOLTAGE     };
    static inline DynamixelAddress min_voltage_limit     { 24, TYPE_UINT16, UNIT_VOLTAGE     };
    static inline DynamixelAddress acceleration_limit    { 26, TYPE_UINT32, UNIT_ACCELERATION};
    static inline DynamixelAddress torque_limit          { 30, TYPE_UINT16, UNIT_CURRENT     };
    static inline DynamixelAddress velocity_limit        { 32, TYPE_UINT32, UNIT_VELOCITY    };
    static inline DynamixelAddress max_position_limit    { 36, TYPE_INT32 , UNIT_POSITION    };
    static inline DynamixelAddress min_position_limit    { 40, TYPE_INT32 , UNIT_POSITION    };
    static inline DynamixelAddress external_port_mode_1  { 44, TYPE_UINT8 };
    static inline DynamixelAddress external_port_mode_2  { 45, TYPE_UINT8 };
    static inline DynamixelAddress external_port_mode_3  { 46, TYPE_UINT8 };
    static inline DynamixelAddress external_port_mode_4  { 47, TYPE_UINT8 };
    static inline DynamixelAddress shutdown              { 48, TYPE_UINT8 };
    // == Indirect Address ==
    static inline DynamixelAddress torque_enable         {562, TYPE_UINT8 };
    static inline DynamixelAddress led_red               {563, TYPE_UINT8 };
    static inline DynamixelAddress led_green             {564, TYPE_UINT8 };
    static inline DynamixelAddress led_blue              {565, TYPE_UINT8 };
    static inline DynamixelAddress velocity_i_gain       {586, TYPE_UINT16};
    static inline DynamixelAddress velocity_p_gain       {588, TYPE_UINT16};
    static inline DynamixelAddress position_p_gain       {594, TYPE_UINT16};
    static inline DynamixelAddress goal_position         {596, TYPE_INT32 , UNIT_POSITION    };
    static inline DynamixelAddress goal_velocity         {600, TYPE_INT32 , UNIT_VELOCITY    };
    static inline DynamixelAddress goal_torque           {604, TYPE_INT16 , UNIT_CURRENT     };
    static inline DynamixelAddress goal_acceleration     {606, TYPE_INT32 , UNIT_ACCELERATION};
    static inline DynamixelAddress moving                {610, TYPE_UINT8 };
    static inline DynamixelAddress present_position      {611, TYPE_INT32 , UNIT_POSITION    };
    static inline DynamixelAddress present_velocity      {615, TYPE_INT32 , UNIT_VELOCITY    };
    static inline DynamixelAddress present_current       {621, TYPE_INT16 , UNIT_CURRENT     };
    static inline DynamixelAddress present_input_voltage {623, TYPE_UINT16, UNIT_VOLTAGE     };
    static inline DynamixelAddress present_temperature   {625, TYPE_UINT8 , UNIT_TEMPERATURE };
    static inline DynamixelAddress external_port_data_1  {626, TYPE_UINT16};
    static inline DynamixelAddress external_port_data_2  {628, TYPE_UINT16};
    static inline DynamixelAddress external_port_data_3  {630, TYPE_UINT16};
    static inline DynamixelAddress external_port_data_4  {632, TYPE_UINT16};
    // == Indirect Address ==
    static inline DynamixelAddress registered_instruction{890, TYPE_UINT8 };
    static inline DynamixelAddress status_return_level   {891, TYPE_UINT8 };
    static inline DynamixelAddress hardware_error_status {892, TYPE_UINT8 };
    // 共通化のための小細工
    static inline auto pwm_limit            = torque_limit.make_dummy();
    static inline auto current_limit        = torque_limit;
    static inline auto goal_current         = goal_torque;
    static inline auto goal_pwm             = goal_torque.make_dummy();
    static inline auto profile_velocity     = goal_velocity.make_dummy();
    static inline auto profile_acceleration = goal_acceleration;
    static inline auto present_pwm          = present_position.make_dummy();
    static inline auto velocity_trajectory  = present_velocity.make_dummy();
    static inline auto position_trajectory  = present_position.make_dummy();
    static inline auto position_d_gain      = position_p_gain.make_dummy();
    static inline auto position_i_gain      = position_p_gain.make_dummy();
    static inline auto feedforward_2nd_gain = position_p_gain.make_dummy();
    static inline auto feedforward_1st_gain = position_p_gain.make_dummy();
    static inline auto bus_watchdog         = DynamixelAddress(  0, TYPE_UINT8 , UNIT_BUS_WATCHDOG ).make_dummy();
};

inline bool has_external_port(uint16_t model_num) {
    switch (model_num) {
      // XH540 
      case MODEL_XH540_W150:
      case MODEL_XH540_V150:
      case MODEL_XH540_W270:
      case MODEL_XH540_V270:
      // XD540
      case MODEL_XD540_T150:
      case MODEL_XD540_T270:
      // Pシリーズ
      case MODEL_PH54_200_S500:
      case MODEL_PH54_100_S500:
      case MODEL_PH42_020_S300:
      case MODEL_PM54_060_S250:
      case MODEL_PM54_040_S250:
      case MODEL_PM42_010_S260: 
      case MODEL_H54_200_S500_A:
      case MODEL_H54_100_S500_A:
      case MODEL_H42_020_S300_A:
      case MODEL_M54_060_S250_A:
      case MODEL_M54_040_S250_A:
      case MODEL_M42_010_S260_A:
      // 旧Proシリーズ
      case MODEL_H54_200_S500:
      case MODEL_H54_100_S500:
      case MODEL_H42_020_S300:
      case MODEL_M54_060_S250:
      case MODEL_M54_040_S250:
      case MODEL_L54_050_S290:
      case MODEL_L54_050_S500:
      case MODEL_L54_030_S400:
      case MODEL_L54_030_S500:
      case MODEL_L42_010_S300:
               return true;
      default: return false;
    }
}

// あとでちゃんと調べる．
inline bool has_current_sensor(uint16_t model_num) {
    switch (model_num) { 
        case MODEL_XL430_W250:
        case MODEL_2XL430_W250:
        case MODEL_XC430_W150:
        case MODEL_XC430_W240:
        case MODEL_2XC430_W250:
                 return false;
        default: return true;
    }
}

#endif /* DYNAMIXEL_PARAMETERS_H_ */
