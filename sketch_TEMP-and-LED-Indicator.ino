#include <dht.h>

dht DHT;
int red_light_pin = 11;
int green_light_pin = 10;
int blue_light_pin = 9;

int control_pin = 13;

//File csvFile = SD.open("temp.csv");

//int temp = DHT.temperature;
//int humidity = DHT.humidity;

#define DHT11_PIN 7

void setup() {
  Serial.begin(9600);
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  pinMode(control_pin, OUTPUT);
}

void loop() {
  int chk = DHT.read11(DHT11_PIN);
  if (!chk == DHTLIB_OK) { // if  not OK -> turns on RED LED
    digitalWrite(control_pin, HIGH);
    RGB_color(255, 255, 0);
  } else {
    digitalWrite(control_pin, LOW);
    printTempAndHumid();
  }
  delay(5000);
}

void printTempAndHumid() {
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  //ledControllerHumid();
  ledControllerTemp();
}

void ledControllerHumid() {
  if (DHT.humidity > 40.00) {
    RGB_color(255, 0, 0);
  } else if (DHT.humidity > 35.00) {
    RGB_color(0, 255, 0);
  } else {
    RGB_color(0, 0, 255);
  }
}

void ledControllerTemp() {
  if (DHT.temperature > 23.00) {
    RGB_color(255, 0, 0);
  } else if (DHT.temperature > 20.00) {
    RGB_color(0, 255, 0);
  } else {
    RGB_color(0, 0, 255);
  }
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
{
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
