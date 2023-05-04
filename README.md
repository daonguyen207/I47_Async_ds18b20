# I47_Async_ds18b20
Thư viện đọc ds18b20 bất đồng bộ cho arduino

Mới hỗ trợ arduino thôi nhé, esp8266 và esp32 sẽ update trong các version mới hơn

Phải định nghĩa chân #define IOT47_DS18B20_PIN 8  trước khi include thư viện, nếu dùng hàng chân A0 thì tương đương 14-19

Sử dụng callback hay hàm ds18b20_read_and_wait_finish() đều ok
