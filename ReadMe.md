# lib_dynamixel

Robotis社の[Dynamixel](https://e-shop.robotis.co.jp/list.php?c_id=89)をROSから制御するためのライブラリ.  
基本的にROSで使うことを想定しているので，単体でのビルドは試してない．
ROS1に組み込んだものが[こちら](https://github.com/SHINOBI-organization/DynamixelHandler-ros1/tree/main)

## API List

短く書くために，型名は略記しています．

**クラスの設定**
- `DynamixelCommunicator` `DynamixelCommunicator()`
- `DynamixelCommunicator` `DynamixelCommunicator(dev_name, baudrate, latency_timer = 16)`
- `bool` `OpenPort()`
- `bool` `ClosePort()`
- `void` `set_baudrate(baudreate)`
- `void` `set_latency_timer(latency_timer)`
- `void` `set_baudrate(baudrate)` 
- `void` `set_latency_timer(latency_timer)` 
- `void` `set_status_return_level(level)` 
- `void` `set_verbose(verbose)` 
- `void` `set_retry_config(num_try, msec_interval)`
- `string` `port_name()`

**Dynamixelとの通信**
- `void` `Reboot(id_t)`
- `void` `FactoryReset(id_t, level)`
- `bool` `Ping(id_t)`
- `bool` `tryPing(id_t)`
- `bool` `Write(address, id_t, data_t)`
- `bool` `tryWrite(address, id_t, data_t)`
- `bool` `Write(vector<address>, id_t, vector<data_t>)`
- `bool` `tryWrite(vector<address>, id_t, vector<data_t>)`
- `bool` `SyncWrite(address, map<id_t, data_t>)`
- `bool` `SyncWrite(vector<address>, map<id_t, vector<data_t>>)`
- `bool` `SyncWrite(address, vector<id_t>, vector<data_t>)` (非推奨)
- `bool` `SyncWrite(vector<address>, vector<id_t>, vector<vector<data_t>>)` (非推奨)
- `bool` `BulkWrite(map<id_t, address>, map<id_t, data_t>)` (未実装)
- `bool` `BulkWrite(map<id_t, vector<address>>, map<id_t, vector<data_t>>)` (未実装)
- `data_t` `Read(address, id_t)`
- `data_t` `tryRead(address, id_t)`
- `vector<data_t>` `Read(vector<address>, id_t)`
- `vector<data_t>` `tryRead(vector<address>, id_t)`
- `map<id_t, data_t>` `SyncRead(address, vector<id_t>)`
- `map<id_t, vector<data_t>>` `SyncRead(vector<address>, vector<id_t>)`
- `map<id_t, data_t>` `BulkRead(map<id_t, address>)` (未実装)
- `map<id_t, vector<data_t>>` `BulkRead(map<id_t, vector<address>>)` (未実装)

**エラー処理**
- `bool` `timeout_last_read()`
- `bool` `comm_error_last_read()`
- `bool` `hardware_error_last_read()`
- `vector<id_t>` `hardware_error_id_last_read()`


## 詳細説明

### `DynamixelCommunicator()`

### `DynamixelCommunicator(const char *port_name, int baudrate, int latency_timer = 16)`
`dev_name` に接続先デバイス名を，`baudrate` に通信速度を，`latency_timer` にレイテンシタイマーを指定して初期化します．
```cpp
DynamixelCommunicator dxl("/dev/ttyUSB0", 1000000, 16);
```

### `OpenPort()`
ポートを開き，レイテンシタイマーおよびボーレートを設定します．
```cpp
DynamixelCommunicator dxl("/dev/ttyUSB0", 1000000, 16); // 通信の設定
if (dxl.OpenPort()) {
    // ポートが正常に開かれた場合の処理
}
```

### `ClosePort()`
ポートを閉じます．
```cpp
dxl.ClosePort();
```

### `set_baudrate(int baudrate)`
通信速度を設定します．
```cpp
dxl.set_baudrate(57600);
```

### `set_latency_timer(uint8_t latency_timer)`
USBシリアル通信のレイテンシタイマーを設定します．
```cpp
dxl.set_latency_timer(8);
```

### `set_status_return_level(int level)`
ステータスパケットの返りを指定します．
```cpp
dxl.set_status_return_level(2);
```

### `set_verbose(bool verbose)`
動作ログを標準出力に表示するかを指定します．
```cpp
dxl.set_verbose(true);
```

### `set_retry_config(int num_try, int msec_interval)`
通信失敗時のリトライ回数とリトライ間隔を設定します．
```cpp
dxl.set_retry_config(3, 50); // 3回まで失敗しても50ms間隔で再試行
```

### `port_name()`
使用しているポート名を取得します．
```cpp
std::string name = dxl.port_name();
```

### `Reboot(uint8_t servo_id)`
指定したDynamixelをリブートします．
```cpp
dxl.Reboot(1); // ID 1のサーボをリブート
```

### `FactoryReset(uint8_t servo_id, FactoryResetLevel level)`
指定したDynamixelを工場出荷状態に戻します．
```cpp
dxl.FactoryReset(1, FACTORY_RESET_EXCLUDE_ID_BAUDRATE); // ID 1のサーボをファクトリーリセット（IDとボーレートを除く）
```
FactoryResetLevel は以下のように定義されています．
  - `FACTORY_RESET_EXCLUDE_ID`         : ID以外のコントロールテーブルの値をリセット 
  - `FACTORY_RESET_EXCLUDE_ID_BAUDRATE`: IDとボーレート以外のコントロールテーブルの値をリセット
  - `FACTORY_RESET_ALL`                : 全てのコントロールテーブルの値をリセット

### `Ping(uint8_t servo_id)`
指定したDynamixelに ping を送り，応答があるかを確認します．
```cpp
bool is_alive = dxl.Ping(1); // ID 1のサーボにping
```

### `tryPing(uint8_t servo_id)`
指定したDynamixelにたいして，応答があるか，繰り返し上限に達するまで ping を送ります．
```cpp
bool is_alive = dxl.tryPing(1); // ID 1のサーボにpingを複数回試行
```

### `Write(DynamixelAddress address, uint8_t servo_id, int64_t data)`
Dynamixelに情報を書き込みます．
```cpp
DynamixelAddress addr(30, TYPE_UINT8);
dxl.Write(addr, 1, 255); // ID 1のサーボのアドレス30に255を書き込む
```

### `tryWrite(DynamixelAddress address, uint8_t servo_id, int64_t data)`
Dynamixelに情報を書き込み，正常応答があるか，繰り返し上限に達するまで試行します．
```cpp
DynamixelAddress addr(30, TYPE_UINT8);
dxl.tryWrite(addr, 1, 255); // ID 1のサーボのアドレス30に255を書き込む（複数回試行）
```

### `Write(const vector<DynamixelAddress>& address_vec, uint8_t servo_id, const vector<int64_t>& data_vec)`
複数のアドレスに情報を書き込みます．
```cpp
vector<DynamixelAddress> addrs = {DynamixelAddress(30, TYPE_UINT8), DynamixelAddress(31, TYPE_UINT8)};
vector<int64_t> data = {255, 128};
dxl.Write(addrs, 1, data); // ID 1のサーボのアドレス30と31にそれぞれ255と128を書き込む
```

### `tryWrite(const vector<DynamixelAddress>& address_vec, uint8_t servo_id, const vector<int64_t>& data_vec)`
複数のアドレスに情報を書き込み，正常応答があるか，繰り返し上限に達するまで試行します．
```cpp
vector<DynamixelAddress> addrs = {DynamixelAddress(30, TYPE_UINT8), DynamixelAddress(31, TYPE_UINT8)};
vector<int64_t> data = {255, 128};
dxl.tryWrite(addrs, 1, data); // ID 1のサーボのアドレス30と31にそれぞれ255と128を書き込む（複数回試行）
```

### `SyncWrite(DynamixelAddress dp, const map<uint8_t, int64_t>& id_data_int_map)`
複数のDynamixelの同一のアドレスに情報を書き込みます．
```cpp
map<uint8_t, int64_t> id_data = {{1, 255}, {2, 128}, {3, 64}};
DynamixelAddress addr(30, TYPE_UINT8);
dxl.SyncWrite(addr, id_data); // ID 1, 2, 3のサーボのアドレス30にそれぞれ255, 128, 64を書き込む
```

### `SyncWrite(const vector<DynamixelAddress>& dp_list, const map<uint8_t, vector<int64_t>>& id_data_int_map)`
複数のDynamixelの複数のアドレスに情報を書き込みます．
```cpp
vector<DynamixelAddress> addrs = {DynamixelAddress(30, TYPE_UINT8), DynamixelAddress(31, TYPE_UINT8)};
map<uint8_t, vector<int64_t>> id_data = {{1, {255, 128}}, {2, {128, 64}}, {3, {64, 32}}};
dxl.SyncWrite(addrs, id_data); // ID 1, 2, 3のサーボのアドレス30と31にそれぞれ255, 128, 128, 64, 64, 32を書き込む
```

### `SyncWrite(DynamixelAddress dp, const vector<uint8_t>& servo_id_list, const vector<int64_t>& data_int_list)` (非推奨)
複数のDynamixelの同一のアドレスに情報を書き込みます．
```cpp
vector<uint8_t> ids = {1, 2, 3};
vector<int64_t> data = {255, 128, 64};
DynamixelAddress addr(30, TYPE_UINT8);
dxl.SyncWrite(addr, ids, data); // ID 1, 2, 3のサーボのアドレス30にそれぞれ255, 128, 64を書き込む
```

### `SyncWrite(const vector<DynamixelAddress>& dp_list, const vector<uint8_t>& servo_id_list, const vector<vector<int64_t>>& data_vec_list)` (非推奨)
複数のDynamixelの複数のアドレスに情報を書き込みます．
```cpp
vector<DynamixelAddress> addrs = {DynamixelAddress(30, TYPE_UINT8), DynamixelAddress(31, TYPE_UINT8)};
vector<uint8_t> ids = {1, 2, 3};
vector<vector<int64_t>> data = {{255, 128}, {128, 64}, {64, 32}};
dxl.SyncWrite(addrs, ids, data); // ID 1, 2, 3のサーボのアドレス30と31にそれぞれ255, 128, 128, 64, 64, 32を書き込む
```

### `BulkWrite(map<id_t, address>, map<id_t, data_t>)` (未実装)
// Placeholder: (Not yet implemented)

### `BulkWrite(map<id_t, vector<address>>, map<id_t, vector<data_t>>)` (未実装)
// Placeholder: (Not yet implemented)

### `Read(DynamixelAddress dp, uint8_t servo_id)`
Dynamixelから情報を読み込みます．
```cpp
DynamixelAddress addr(30, TYPE_UINT8);
int64_t data = dxl.Read(addr, 1); // ID 1のサーボのアドレス30からデータを読み込む
```

### `tryRead(DynamixelAddress dp, uint8_t servo_id)`
Dynamixelから情報を読み込み，正常応答があるか，繰り返し上限に達するまで試行します．
```cpp
DynamixelAddress addr(30, TYPE_UINT8);
int64_t data = dxl.tryRead(addr, 1); // ID 1のサーボのアドレス30からデータを読み込む（複数回試行）
```

### `Read(const vector<DynamixelAddress>& dp_list, uint8_t servo_id)`
複数のアドレスから情報を読み込みます．
```cpp
vector<DynamixelAddress> addrs = {DynamixelAddress(30, TYPE_UINT8), DynamixelAddress(31, TYPE_UINT8)};
vector<int64_t> data = dxl.Read(addrs, 1); // ID 1のサーボのアドレス30と31からデータを読み込む
```

### `tryRead(const vector<DynamixelAddress>& dp_list, uint8_t servo_id)`
Dynamixelから情報を読み込み，正常応答があるか，繰り返し上限に達するまで試行します．
```cpp
vector<DynamixelAddress> addrs = {DynamixelAddress(30, TYPE_UINT8), DynamixelAddress(31, TYPE_UINT8)};
vector<int64_t> data = dxl.tryRead(addrs, 1); // ID 1のサーボのアドレス30と31からデータを読み込む（複数回試行）
```

### `SyncRead(DynamixelAddress dp, const vector<uint8_t>& servo_id_list)`
複数のDynamixelの同一のアドレスから情報を読み込みます．
```cpp
vector<uint8_t> ids = {1, 2, 3};
DynamixelAddress addr(30, TYPE_UINT8);
map<uint8_t, int64_t> data = dxl.SyncRead(addr, ids); // ID 1, 2, 3のサーボのアドレス30からデータを読み込む
```

### `SyncRead(const vector<DynamixelAddress>& dp_list, const vector<uint8_t>& servo_id_list)`
複数のDynamixelの複数のアドレスから情報を読み込みます．
```cpp
vector<DynamixelAddress> addrs = {DynamixelAddress(30, TYPE_UINT8), DynamixelAddress(31, TYPE_UINT8)};
vector<uint8_t> ids = {1, 2, 3};
map<uint8_t, vector<int64_t>> data = dxl.SyncRead(addrs, ids); // ID 1, 2, 3のサーボのアドレス30と31からデータを読み込む
```

### `BulkRead(map<id_t, address>)` (未実装)
// Placeholder: (Not yet implemented)

### `BulkRead(map<id_t, vector<address>>)` (未実装)
// Placeholder: (Not yet implemented)

### `timeout_last_read()`
直近の通信がタイムアウトで失敗したかを返します．
```cpp
bool timeout = dxl.timeout_last_read();
```

### `comm_error_last_read()`
直近の通信で通信エラーが発生したかを返します．
```cpp
bool comm_err = dxl.comm_error_last_read();
```

### `hardware_error_last_read()`
直近の通信でハードウェアエラーが発生したかを返します．
```cpp
bool hw_err = dxl.hardware_error_last_read();
```

### `vector<id_t> hardware_error_id_last_read()`
直近の通信でハードウェアエラーが発生したサーボIDの一覧を返します．
```cpp
vector<uint8_t> err_ids = dxl.hardware_error_id_last_read();
```