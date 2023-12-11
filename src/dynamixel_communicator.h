#ifndef DYNAMIXEL_COMMUNICATOR_H_
#define DYNAMIXEL_COMMUNICATOR_H_

#include <vector>
using std::vector;
#include <string>
using std::string;
#include <cmath>

#include "../download/port_handler.h"
#include "dynamixel_parameters.h"


class DynamixelComunicator {
 public:
  DynamixelComunicator() {
    status_return_level_ = 2;
  }
  DynamixelComunicator(const char *port_name, int baudrate) {
    GetPortHandler(port_name);
    set_baudrate(baudrate);
    status_return_level_ = 2;
  }

  void GetPortHandler(const char *port_name) {
    port_name_ = port_name;
    port_handler_ = PortHandler::getPortHandler(port_name);
  }

  void set_baudrate(int baudrate) { baudrate_ = baudrate; }

  void set_status_return_level(int level) { status_return_level_ = level; }

  bool error_last_read(){ return error_last_read_; }

  string port_name(){ return string(port_name_); }

  bool OpenPort();
  bool ClosePort();
  void Reboot(uint8_t servo_id);
  void FactoryReset(uint8_t servo_id, FactoryResetLevel level);
  bool Ping(uint8_t servo_id);

  void Write(uint8_t servo_id, DynamixelParameter dp, int64_t data_int);
  int64_t Read(uint8_t servo_id, DynamixelParameter dp);
  void SyncWrite(const vector<uint8_t>& servo_id_list, DynamixelParameter dp, const vector<int64_t>& data_int_list);
  uint8_t SyncRead(const vector<uint8_t>& servo_id_list, DynamixelParameter dp, vector<int64_t>& data_int_list, vector<uint8_t>& read_id_list);
  uint8_t SyncRead_fast(const vector<uint8_t>& servo_id_list, DynamixelParameter dp, vector<int64_t>& data_int_list, vector<uint8_t>& read_id_list);
//   void BulkWrite(const vector<uint8_t>& servo_id_list, const vector<DynamixelParameter>& dp_list, const vector<int64_t>& data_int_list);
// uint8_t BulkRead(const vector<uint8_t>& servo_id_list, const vector<DynamixelParameter>& dp_list, vector<int64_t>& data_int_list, vector<uint8_t>& read_id_list);
	// ここまではDynamixelSDKと同じ関数の独自実装，これ以降は独自関数
// void RangeWrite(uint8_t servo_id, const vector<DynamixelParameter>& dp_list, const vector<int64_t>& data_int_list);
  void RangeRead(uint8_t servo_id, const vector<DynamixelParameter>& dp_list, vector<int64_t>& data_int_list);
//   void SyncRangeWrite(const vector<uint8_t>& servo_id_list, const vector<DynamixelParameter>& dp_list, const vector<vector<int64_t>>& data_int_list);
//   uint8_t SyncRangeRead(const vector<uint8_t>& servo_id_list, const vector<DynamixelParameter>& dp_list, vector<vector<int64_t>>& data_int_list, vector<uint8_t>& read_id_list);
//   uint8_t SyncRangeRead_fast(const vector<uint8_t>& servo_id_list, const vector<DynamixelParameter>& dp_list, vector<vector<int64_t>>& data_int_list, vector<uint8_t>& read_id_list);
//   void BulkRangeWrite(const vector<uint8_t>& servo_id_list, const vector<DynamixelParameter>& dp_list, const vector<vector<int64_t>>& data_int_list);
//   uint8_t BulkRangeRead(const vector<uint8_t>& servo_id_list, const vector<DynamixelParameter>& dp_list, vector<vector<int64_t>>& data_int_list, vector<uint8_t>& read_id_list);

 private:
  uint16_t CalcChecksum(uint8_t data[], uint8_t length);
  void EncodeDataWrite(DynamixelDataType type, int64_t data_int);
  int64_t DecodeDataRead(DynamixelDataType type);

  const char *port_name_;
  PortHandler *port_handler_;
  uint32_t baudrate_;
  uint8_t status_return_level_;
  double time_per_byte_;
  uint8_t  data_write_[4];
  uint8_t  data_read_[4];
  bool error_last_read_;
};

// 以下のようにして，良い感じに関数を作る
// namespace dyn_x {
//   void SetTorqueEnable(const vector<uint8_t>& servo_id_list, bool enable);
//   void SetTorqueEnable(uint8_t servo_id, bool enable);
//   void SetLed(const vector<uint8_t>& servo_id_list, bool enable);
//   void SetLed(uint8_t servo_id, bool enable);
//   void SetGoalPosition(const vector<uint8_t>& servo_id_list, const vector<int64_t>& data_int_list);
//   void SetGoalPosition(uint8_t servo_id, int64_t data_int);
//   void SetGoalVelocity(const vector<uint8_t>& servo_id_list, const vector<int64_t>& data_int_list);
//   void SetGoalVelocity(uint8_t servo_id, int64_t data_int);
//   void SetGoalCurrent(const vector<uint8_t>& servo_id_list, const vector<int64_t>& data_int_list);
//   void SetGoalCurrent(uint8_t servo_id, int64_t data_int);
//   void SetProfileAcceleration(const vector<uint8_t>& servo_id_list, const vector<int64_t>& data_int_list);
//   void SetProfileAcceleration(uint8_t servo_id, int64_t data_int);
//   void SetProfileVelocity(const vector<uint8_t>& servo_id_list, const vector<int64_t>& data_int_list);
//   void SetProfileVelocity(uint8_t servo_id, int64_t data_int);
//   void SetPositionPgain(const vector<uint8_t>& servo_id_list, const vector<int64_t>& data_int_list);
//   void SetPositionPgain(uint8_t servo_id, int64_t data_int);
//   void SetPositionIgain(const vector<uint8_t>& servo_id_list, const vector<int64_t>& data_int_list);
//   void SetPositionIgain(uint8_t servo_id, int64_t data_int);
//   void SetPositionDgain(const vector<uint8_t>& servo_id_list, const vector<int64_t>& data_int_list);
//   void SetPositionDgain(uint8_t servo_id, int64_t data_int);
//   void SetVelocityPgain(const vector<uint8_t>& servo_id_list, const vector<int64_t>& data_int_list);
//   void SetVelocityPgain(uint8_t servo_id, int64_t data_int);
//   void SetVelocityIgain(const vector<uint8_t
// }


#endif /* DYNAMIXEL_COMMUNICATOR_H_ */
