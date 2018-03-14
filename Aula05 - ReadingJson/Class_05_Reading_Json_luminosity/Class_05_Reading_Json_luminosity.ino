#include <ArduinoJson.h>
const int LED = 3;
const int LUZ = A1;
const int TAMANHO = 200;
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(10);
  pinMode(LED,OUTPUT);
}

void loop() {
  if(Serial.available() > 0) {
     char texto[TAMANHO];
     Serial.readBytesUntil('\n', texto, TAMANHO);
     StaticJsonBuffer<TAMANHO> jsonBuffer;
     JsonObject& json = jsonBuffer.parseObject(texto);
     if(json.success() && json.containsKey("led")){
        analogWrite(LED, json["led"]);
     }
  }
  StaticJsonBuffer<TAMANHO> jsonBuffer;
  JsonObject& json = jsonBuffer.createObject();
  json["luz"] = analogRead(LUZ);
  json.printTo(Serial);
  Serial.println();
  delay(1000);
}
