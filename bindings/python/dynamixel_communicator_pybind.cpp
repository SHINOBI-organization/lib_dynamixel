#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <string>
#include <vector>
#include <map>

#include "dynamixel_communicator.h"

namespace py = pybind11;

PYBIND11_MODULE(_mylib_dynamixel, m) {
  m.doc() = "pybind11 bindings for mylib_dynamixel";

  py::enum_<DynamixelSeries>(m, "DynamixelSeries")
      .value("SERIES_UNKNOWN", SERIES_UNKNOWN)
      .value("SERIES_X", SERIES_X)
      .value("SERIES_P", SERIES_P)
      .value("SERIES_PRO", SERIES_PRO)
      .value("SERIES_PRO_PLUS", SERIES_PRO_PLUS)
      .export_values();

  py::enum_<FactoryResetLevel>(m, "FactoryResetLevel")
      .value("FACTORY_RESET_EXCLUDE_ID", FACTORY_RESET_EXCLUDE_ID)
      .value("FACTORY_RESET_EXCLUDE_ID_BAUDRATE", FACTORY_RESET_EXCLUDE_ID_BAUDRATE)
      .value("FACTORY_RESET_ALL", FACTORY_RESET_ALL)
      .export_values();

  py::enum_<DynamixelBaudrateIndex>(m, "DynamixelBaudrateIndex")
      .value("BAUDRATE_INDEX_9600", BAUDRATE_INDEX_9600)
      .value("BAUDRATE_INDEX_57600", BAUDRATE_INDEX_57600)
      .value("BAUDRATE_INDEX_115200", BAUDRATE_INDEX_115200)
      .value("BAUDRATE_INDEX_1M", BAUDRATE_INDEX_1M)
      .value("BAUDRATE_INDEX_2M", BAUDRATE_INDEX_2M)
      .value("BAUDRATE_INDEX_3M", BAUDRATE_INDEX_3M)
      .value("BAUDRATE_INDEX_4M", BAUDRATE_INDEX_4M)
      .value("BAUDRATE_INDEX_4M5", BAUDRATE_INDEX_4M5)
      .value("BAUDRATE_INDEX_6M", BAUDRATE_INDEX_6M)
      .value("BAUDRATE_INDEX_10M5", BAUDRATE_INDEX_10M5)
      .export_values();

  py::enum_<DynamixelOperatingMode>(m, "DynamixelOperatingMode")
      .value("OPERATING_MODE_CURRENT", OPERATING_MODE_CURRENT)
      .value("OPERATING_MODE_VELOCITY", OPERATING_MODE_VELOCITY)
      .value("OPERATING_MODE_POSITION", OPERATING_MODE_POSITION)
      .value("OPERATING_MODE_EXTENDED_POSITION", OPERATING_MODE_EXTENDED_POSITION)
      .value("OPERATING_MODE_CURRENT_BASE_POSITION", OPERATING_MODE_CURRENT_BASE_POSITION)
      .value("OPERATING_MODE_PWM", OPERATING_MODE_PWM)
      .export_values();

  py::enum_<DynamixelExternalPortMode>(m, "DynamixelExternalPortMode")
      .value("EXTERNAL_PORT_MODE_AIN", EXTERNAL_PORT_MODE_AIN)
      .value("EXTERNAL_PORT_MODE_DOUT", EXTERNAL_PORT_MODE_DOUT)
      .value("EXTERNAL_PORT_MODE_DIN_PULLUP", EXTERNAL_PORT_MODE_DIN_PULLUP)
      .value("EXTERNAL_PORT_MODE_DIN_PULLDOWN", EXTERNAL_PORT_MODE_DIN_PULLDOWN)
      .export_values();

  py::enum_<DynamixelTorquePermission>(m, "DynamixelTorquePermission")
      .value("TORQUE_DISABLE", TORQUE_DISABLE)
      .value("TORQUE_ENABLE", TORQUE_ENABLE)
      .export_values();

  py::enum_<DynamixelStatusReturnLevel>(m, "DynamixelStatusReturnLevel")
      .value("STATUS_RETURN_LEVEL_PING_ONLY", STATUS_RETURN_LEVEL_PING_ONLY)
      .value("STATUS_RETURN_LEVEL_READ_ONLY", STATUS_RETURN_LEVEL_READ_ONLY)
      .value("STATUS_RETURN_LEVEL_ALL", STATUS_RETURN_LEVEL_ALL)
      .export_values();

  py::enum_<DynamixelHardwareErrorIndex>(m, "DynamixelHardwareErrorIndex")
      .value("HARDWARE_ERROR_INPUT_VOLTAGE", HARDWARE_ERROR_INPUT_VOLTAGE)
      .value("HARDWARE_ERROR_MOTOR_HALL_SENSOR", HARDWARE_ERROR_MOTOR_HALL_SENSOR)
      .value("HARDWARE_ERROR_OVERHEATING", HARDWARE_ERROR_OVERHEATING)
      .value("HARDWARE_ERROR_MOTOR_ENCODER", HARDWARE_ERROR_MOTOR_ENCODER)
      .value("HARDWARE_ERROR_ELECTRONICAL_SHOCK", HARDWARE_ERROR_ELECTRONICAL_SHOCK)
      .value("HARDWARE_ERROR_OVERLOAD", HARDWARE_ERROR_OVERLOAD)
      .export_values();

  py::enum_<DynamixelDataType>(m, "DynamixelDataType")
      .value("TYPE_INT8", TYPE_INT8)
      .value("TYPE_UINT8", TYPE_UINT8)
      .value("TYPE_INT16", TYPE_INT16)
      .value("TYPE_UINT16", TYPE_UINT16)
      .value("TYPE_INT32", TYPE_INT32)
      .value("TYPE_UINT32", TYPE_UINT32)
      .export_values();

  py::enum_<DynamixelPhysicalUnit>(m, "DynamixelPhysicalUnit")
      .value("NOUNIT", NOUNIT)
      .value("UNIT_POSITION", UNIT_POSITION)
      .value("UNIT_POSITION_OFFSET", UNIT_POSITION_OFFSET)
      .value("UNIT_VELOCITY", UNIT_VELOCITY)
      .value("UNIT_ACCELERATION", UNIT_ACCELERATION)
      .value("UNIT_CURRENT", UNIT_CURRENT)
      .value("UNIT_VOLTAGE", UNIT_VOLTAGE)
      .value("UNIT_TEMPERATURE", UNIT_TEMPERATURE)
      .value("UNIT_PWM", UNIT_PWM)
      .value("UNIT_RETURN_DELAY_TIME", UNIT_RETURN_DELAY_TIME)
      .value("UNIT_BUS_WATCHDOG", UNIT_BUS_WATCHDOG)
      .value("UNIT_REALTIME_TICK", UNIT_REALTIME_TICK)
      .export_values();

  py::class_<DynamixelAddress>(m, "DynamixelAddress")
      .def(py::init<uint16_t, DynamixelDataType, DynamixelPhysicalUnit>(),
           py::arg("address"),
           py::arg("data_type"),
           py::arg("physical_unit") = NOUNIT)
      .def("is_dummy", &DynamixelAddress::is_dummy)
      .def("size", &DynamixelAddress::size)
      .def("address", &DynamixelAddress::address)
      .def("data_type", &DynamixelAddress::data_type)
      .def("physical_unit", &DynamixelAddress::physical_unit)
      .def("make_dummy", &DynamixelAddress::make_dummy)
      .def("val2pulse", &DynamixelAddress::val2pulse, py::arg("val"), py::arg("model_num"))
      .def("pulse2val", &DynamixelAddress::pulse2val, py::arg("pulse"), py::arg("model_num"));

  m.def("dynamixel_series", &dynamixel_series, py::arg("model_num"));
  m.def("series_from_model", &dynamixel_series, py::arg("model_num"));
  m.def("has_external_port", &has_external_port, py::arg("model_num"));
  m.def("has_current_sensor", &has_current_sensor, py::arg("model_num"));

  py::class_<DynamixelCommunicator>(m, "DynamixelCommunicator")
      .def(py::init<>())
      .def(py::init<const char*, int, int>(),
           py::arg("port_name"),
           py::arg("baudrate"),
           py::arg("latency_timer") = 16)
      .def("GetPortHandler", &DynamixelCommunicator::GetPortHandler, py::arg("port_name"))
      .def("set_baudrate", &DynamixelCommunicator::set_baudrate, py::arg("baudrate"))
      .def("set_latency_timer", &DynamixelCommunicator::set_latency_timer, py::arg("latency_timer"))
      .def("set_status_return_level", &DynamixelCommunicator::set_status_return_level, py::arg("level"))
      .def("set_verbose", &DynamixelCommunicator::set_verbose, py::arg("verbose"))
      .def("port_name", &DynamixelCommunicator::port_name)
      .def("timeout_last_read", &DynamixelCommunicator::timeout_last_read)
      .def("comm_error_last_read", &DynamixelCommunicator::comm_error_last_read)
      .def("hardware_error_last_read", &DynamixelCommunicator::hardware_error_last_read)
      .def("hardware_error_id_last_read", &DynamixelCommunicator::hardware_error_id_last_read)
      .def("set_retry_config", &DynamixelCommunicator::set_retry_config, py::arg("num_try"), py::arg("msec_interval"))
      .def("OpenPort", &DynamixelCommunicator::OpenPort)
      .def("ClosePort", &DynamixelCommunicator::ClosePort)
      .def("Reboot", &DynamixelCommunicator::Reboot, py::arg("servo_id"))
      .def("FactoryReset", &DynamixelCommunicator::FactoryReset, py::arg("servo_id"), py::arg("level"))
      .def("Ping", &DynamixelCommunicator::Ping, py::arg("servo_id"))

      // single parameter operations
      .def("Write", py::overload_cast<DynamixelAddress, uint8_t, int64_t>(&DynamixelCommunicator::Write),
           py::arg("addr"), py::arg("servo_id"), py::arg("value"))
      .def("SyncWrite", py::overload_cast<DynamixelAddress, const std::vector<uint8_t>&, const std::vector<int64_t>&>(&DynamixelCommunicator::SyncWrite),
           py::arg("addr"), py::arg("servo_id_list"), py::arg("value_list"))
      .def("SyncWrite", py::overload_cast<DynamixelAddress, const std::map<uint8_t, int64_t>&>(&DynamixelCommunicator::SyncWrite),
           py::arg("addr"), py::arg("id_value_map"))
      .def("Read", py::overload_cast<DynamixelAddress, uint8_t>(&DynamixelCommunicator::Read),
           py::arg("addr"), py::arg("servo_id"))
      .def("SyncRead", py::overload_cast<DynamixelAddress, const std::vector<uint8_t>&>(&DynamixelCommunicator::SyncRead),
           py::arg("addr"), py::arg("servo_id_list"))
      .def("SyncRead_fast", py::overload_cast<DynamixelAddress, const std::vector<uint8_t>&>(&DynamixelCommunicator::SyncRead_fast),
           py::arg("addr"), py::arg("servo_id_list"))

      // multi parameter operations
      .def("Write", py::overload_cast<const std::vector<DynamixelAddress>&, uint8_t, const std::vector<int64_t>&>(&DynamixelCommunicator::Write),
           py::arg("addr_list"), py::arg("servo_id"), py::arg("value_list"))
      .def("SyncWrite", py::overload_cast<const std::vector<DynamixelAddress>&, const std::vector<uint8_t>&, const std::vector<std::vector<int64_t>>&>(&DynamixelCommunicator::SyncWrite),
           py::arg("addr_list"), py::arg("servo_id_list"), py::arg("value_matrix"))
      .def("SyncWrite", py::overload_cast<const std::vector<DynamixelAddress>&, const std::map<uint8_t, std::vector<int64_t>>&>(&DynamixelCommunicator::SyncWrite),
           py::arg("addr_list"), py::arg("id_values_map"))
      .def("Read", py::overload_cast<const std::vector<DynamixelAddress>&, uint8_t>(&DynamixelCommunicator::Read),
           py::arg("addr_list"), py::arg("servo_id"))
      .def("SyncRead", py::overload_cast<const std::vector<DynamixelAddress>&, const std::vector<uint8_t>&>(&DynamixelCommunicator::SyncRead),
           py::arg("addr_list"), py::arg("servo_id_list"))
      .def("SyncRead_fast", py::overload_cast<const std::vector<DynamixelAddress>&, const std::vector<uint8_t>&>(&DynamixelCommunicator::SyncRead_fast),
           py::arg("addr_list"), py::arg("servo_id_list"))

      // retry helpers
      .def("tryPing", &DynamixelCommunicator::tryPing, py::arg("servo_id"))
      .def("tryWrite", py::overload_cast<DynamixelAddress, uint8_t, int64_t>(&DynamixelCommunicator::tryWrite),
           py::arg("addr"), py::arg("servo_id"), py::arg("value"))
      .def("tryRead", py::overload_cast<DynamixelAddress, uint8_t>(&DynamixelCommunicator::tryRead),
           py::arg("addr"), py::arg("servo_id"))
      .def("tryWrite", py::overload_cast<const std::vector<DynamixelAddress>&, uint8_t, const std::vector<int64_t>&>(&DynamixelCommunicator::tryWrite),
           py::arg("addr_list"), py::arg("servo_id"), py::arg("value_list"))
      .def("tryRead", py::overload_cast<const std::vector<DynamixelAddress>&, uint8_t>(&DynamixelCommunicator::tryRead),
           py::arg("addr_list"), py::arg("servo_id"))

      // snake_case aliases for python ergonomics
      .def("set_port_handler", &DynamixelCommunicator::GetPortHandler, py::arg("port_name"))
      .def("open_port", &DynamixelCommunicator::OpenPort)
      .def("close_port", &DynamixelCommunicator::ClosePort)
      .def("try_ping", &DynamixelCommunicator::tryPing, py::arg("servo_id"))
      .def("try_read_uint16",
           [](DynamixelCommunicator& self, int address, int servo_id) {
             DynamixelAddress dp(static_cast<uint16_t>(address), TYPE_UINT16);
             return static_cast<int>(self.tryRead(dp, static_cast<uint8_t>(servo_id)));
           },
           py::arg("address"), py::arg("servo_id"))
      .def("try_write_uint8",
           [](DynamixelCommunicator& self, int address, int servo_id, int value) {
             DynamixelAddress dp(static_cast<uint16_t>(address), TYPE_UINT8);
             return self.tryWrite(dp, static_cast<uint8_t>(servo_id), static_cast<int64_t>(value));
           },
           py::arg("address"), py::arg("servo_id"), py::arg("value"));

  // convenient address constants for existing scripts
  m.attr("ADDR_MODEL_NUMBER") = py::int_(AddrCommon::model_number.address());
  m.attr("ADDR_BAUDRATE") = py::int_(AddrX::baudrate.address());
  m.attr("ADDR_X_TORQUE_ENABLE") = py::int_(AddrX::torque_enable.address());
  m.attr("ADDR_P_TORQUE_ENABLE") = py::int_(AddrP::torque_enable.address());
  m.attr("TORQUE_DISABLE") = py::int_(static_cast<int>(TORQUE_DISABLE));
  m.attr("SERIES_X") = py::int_(static_cast<int>(SERIES_X));
  m.attr("SERIES_P") = py::int_(static_cast<int>(SERIES_P));

  m.attr("BAUDRATE_INDEX_9600") = py::int_(static_cast<int>(BAUDRATE_INDEX_9600));
  m.attr("BAUDRATE_INDEX_57600") = py::int_(static_cast<int>(BAUDRATE_INDEX_57600));
  m.attr("BAUDRATE_INDEX_115200") = py::int_(static_cast<int>(BAUDRATE_INDEX_115200));
  m.attr("BAUDRATE_INDEX_1M") = py::int_(static_cast<int>(BAUDRATE_INDEX_1M));
  m.attr("BAUDRATE_INDEX_2M") = py::int_(static_cast<int>(BAUDRATE_INDEX_2M));
  m.attr("BAUDRATE_INDEX_3M") = py::int_(static_cast<int>(BAUDRATE_INDEX_3M));
  m.attr("BAUDRATE_INDEX_4M") = py::int_(static_cast<int>(BAUDRATE_INDEX_4M));
  m.attr("BAUDRATE_INDEX_4M5") = py::int_(static_cast<int>(BAUDRATE_INDEX_4M5));
  m.attr("BAUDRATE_INDEX_6M") = py::int_(static_cast<int>(BAUDRATE_INDEX_6M));
  m.attr("BAUDRATE_INDEX_10M5") = py::int_(static_cast<int>(BAUDRATE_INDEX_10M5));
}
