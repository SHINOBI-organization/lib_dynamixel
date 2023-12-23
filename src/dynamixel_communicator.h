#ifndef DYNAMIXEL_COMMUNICATOR_H_
#define DYNAMIXEL_COMMUNICATOR_H_

#include <map>
using std::map;
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

  string port_name(){ return string(port_name_); }

  bool error_last_read(){ return error_last_read_; }

  bool OpenPort();
  bool ClosePort();
  void Reboot(uint8_t servo_id);
  void FactoryReset(uint8_t servo_id, FactoryResetLevel level);
  bool Ping(uint8_t servo_id);
  // パラメータ1つ
  void Write        (DynamixelAddress dp, uint8_t                servo_id,      int64_t                data_int     );
  void SyncWrite    (DynamixelAddress dp, const vector<uint8_t>& servo_id_list, const vector<int64_t>& data_int_list);
  void SyncWrite    (DynamixelAddress dp, const map<uint8_t, int64_t>& id_data_int_map);
  int64_t               Read         (DynamixelAddress dp, uint8_t                servo_id     );
  map<uint8_t, int64_t> SyncRead     (DynamixelAddress dp, const vector<uint8_t>& servo_id_list);
  map<uint8_t, int64_t> SyncRead_fast(DynamixelAddress dp, const vector<uint8_t>& servo_id_list);
  // 複数パラメータ同時
//   void Write        (const vector<DynamixelAddress>& dp_list, uint8_t                servo_id,      const vector<int64_t>&               data_int_list);
//   void SyncWrite    (const vector<DynamixelAddress>& dp_list, const vector<uint8_t>& servo_id_list, const vector<vector<int64_t>>&       data_int_list);
//   void SyncWrite    (const vector<DynamixelAddress>& dp_list, const map<uint8_t, vector<int64_t>>& id_data_int_map);
  vector<int64_t>               Read         (const vector<DynamixelAddress>& dp_list, uint8_t                servo_id     );
//   map<uint8_t, vector<int64_t>> SyncRead     (const vector<DynamixelAddress>& dp_list, const vector<uint8_t>& servo_id_list);
//   map<uint8_t, vector<int64_t>> SyncRead_fast(const vector<DynamixelAddress>& dp_list, const vector<uint8_t>& servo_id_list);
  
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
