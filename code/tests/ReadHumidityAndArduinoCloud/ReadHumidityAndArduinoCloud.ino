#include "thingProperties.h"   //AUTOMATICALLY GENERATED to read your added Variables
  #include <Arduino_MKRIoTCarrier.h>
  MKRIoTCarrier carrier;
  
  void setup() {
  
  Serial.begin(9600);   //AUTOMATICALLY GENERATED to handle the serial monitor
  
  initProperties();  // AUTOMATICALLY GENERATED Defined in thingProperties.
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);  // AUTOMATICALLY GENERATED Connect to Arduino IoT Cloud
  setDebugMessageLevel(2); // AUTOMATICALLY GENERATED set the amount of details in debug message 0-4
  ArduinoCloud.printDebugInfo(); // AUTOMATICALLY GENERATED print out the debug message
  while(ArduinoCloud.connected() !=1 ){
  ArduinoCloud.update();
  delay(500);
}
  carrier.noCase();
  carrier.begin();
  }
  void loop() {
    
  ArduinoCloud.update();
  // read the sensor values
  humidity = carrier.Env.readHumidity();  //Upload the humidity value to the cloud variable
  // print the sensor values
  Serial.print("	 Humidity: ");
  Serial.println(humidity);
  delay(500);
  }

void onHumidityChange() {
  Serial.print("Nouvelle humidité depuis le cloud: ");
  Serial.println(humidity);
}