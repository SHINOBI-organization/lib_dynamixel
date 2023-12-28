#ifndef DYNAMIXEL_COMMUNICATOR_H_
#define DYNAMIXEL_COMMUNICATOR_H_

#include <map>
using std::map;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <cmath>
#include <algorithm>

#include "../download/port_handler.h"
#include "dynamixel_parameters.h"


class DynamixelComunicator {
 public:
  DynamixelComunicator() {
    status_return_level_ = 2;
    num_try_ = 5;
    msec_interval_ = 5;
  }
  DynamixelComunicator(const char *port_name, int baudrate) {
    GetPortHandler(port_name);
    set_baudrate(baudrate);
    status_return_level_ = 2;
    num_try_ = 5;
    msec_interval_ = 5;
  }

  void GetPortHandler(const char *port_name) {
    port_name_ = port_name;
    port_handler_ = PortHandler::getPortHandler(port_name);
  }

  void set_baudrate(int baudrate) { baudrate_ = baudrate; }

  void set_status_return_level(int level) { status_return_level_ = level; }

  string port_name(){ return string(port_name_); }

  bool error_last_read(){ return error_last_read_; }

  void set_retry_config(int num_try, int msec_interval){
    num_try_ = std::max(num_try, 1);
    msec_interval_ = std::max(msec_interval, 1);
  }

  bool OpenPort();
  bool ClosePort();
  void Reboot(uint8_t servo_id);
  void FactoryReset(uint8_t servo_id, FactoryResetLevel level);
  bool Ping(uint8_t servo_id);

  // パラメータ1つ
  bool Write    (DynamixelAddress, uint8_t               , int64_t               );
  bool SyncWrite(DynamixelAddress, const vector<uint8_t>&, const vector<int64_t>&);
  bool SyncWrite(DynamixelAddress, const map<uint8_t, int64_t>&);
  int64_t               Read         (DynamixelAddress, uint8_t               );
  map<uint8_t, int64_t> SyncRead     (DynamixelAddress, const vector<uint8_t>&);
  map<uint8_t, int64_t> SyncRead_fast(DynamixelAddress, const vector<uint8_t>&);
  // 複数パラメータ同時
  bool Write    (const vector<DynamixelAddress>&, uint8_t               , const vector<int64_t>&        );
  bool SyncWrite(const vector<DynamixelAddress>&, const vector<uint8_t>&, const vector<vector<int64_t>>&);
  bool SyncWrite(const vector<DynamixelAddress>&, const map<uint8_t, vector<int64_t>>&);
  vector<int64_t>               Read         (const vector<DynamixelAddress>&, uint8_t               );
  map<uint8_t, vector<int64_t>> SyncRead     (const vector<DynamixelAddress>&, const vector<uint8_t>&);
  map<uint8_t, vector<int64_t>> SyncRead_fast(const vector<DynamixelAddress>&, const vector<uint8_t>&);
  // Retry付
  bool            tryPing (uint8_t servo_id);
  bool            tryWrite(DynamixelAddress, uint8_t, int64_t);
  int64_t         tryRead (DynamixelAddress, uint8_t);
  bool            tryWrite(const vector<DynamixelAddress>&, uint8_t, const vector<int64_t>&);
  vector<int64_t> tryRead (const vector<DynamixelAddress>&, uint8_t);
  
 private:
  uint16_t CalcChecksum(uint8_t data[], uint8_t length);
  void   EncodeDataWrite(DynamixelDataType type, int64_t data_int);
  int64_t DecodeDataRead(DynamixelDataType type);

  const char *port_name_;
  PortHandler *port_handler_;
  uint32_t baudrate_;
  uint8_t status_return_level_;
  double time_per_byte_;
  uint8_t  data_write_[4];
  uint8_t  data_read_[4];
  bool error_last_read_;

  uint8_t num_try_;
  uint8_t msec_interval_;
};

#endif /* DYNAMIXEL_COMMUNICATOR_H_ */
