# esp_simple_logging
Simple logging library for ESP8266

Simple logging library, wrapped over vsnprintf to make debugging easier.  Wrote it for ESP8266, with platformio.
Has 5 logging levels:

- ```LOG_LEVEL_DEBUG```
- ```LOG_LEVEL_INFO```
- ```LOG_LEVEL_WARN```
- ```LOG_LEVEL_ERROR```

##Usage##

```
#include <Logging.h>

#define LOGLEVEL LOG_LEVEL_DEBUG

SerialClient my_client(MQTT_SERVER, MQTT_PORT, 30);

void setup() {
    Serial.begin(115200);
    delay(1000);
    Log.Init(LOG_LEVEL_INFO, &Serial);

    Log.Info("Connecting to WIFI %s", SSID);
    WiFi.begin('ssid', 'pass');

    while (WiFi.status() != WL_CONNECTED) {
    delay(500);
        Log.Info("Waiting for wifi...');
    }

    Log.Info("WIFI connected");
    Log.Info("IP Address: %s", WiFi.localIP().toString().c_str());
    delay(1000);
}

int counter = 0;
void loop() {
    delay(100);
}
```
