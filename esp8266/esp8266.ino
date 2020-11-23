
#include "config.h"

AdafruitIO_Feed *btn1 = io.feed("btn1");

void setup() {

  // start the serial connection
  Serial.begin(115200);

  // wait for serial monitor to open
  while(! Serial);

  Serial.print("Connecting to Adafruit IO");

  // start MQTT connection to io.adafruit.com
  io.connect();

  btn1->onMessage(handleMessage);

  while(io.mqttStatus() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  btn1->get();

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

}

void loop() {
  
  io.run();
  
}

void handleMessage(AdafruitIO_Data *data) {

  Serial.write(data->value());

}
