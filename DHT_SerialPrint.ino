#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 7
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);


void setup(){
Serial.begin(9600);
dht.begin();
}

void loop(){
delay(1000);
float humi = dht.readHumidity();
float tempC = dht.readTemperature();
float tempF = dht.readTemperature(true);

if (isnan(humi) || isnan(tempF)){
  Serial.print("Failed to read from DHT sensor!");
}else{
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.print(",");
  Serial.print("Humidity: ");
  Serial.print(humi);
}

}