# Arduino_Uno_Temp-Humidity-and-LED-Indicator

This setup reads data from the DHT11 temperature and humidity sensor. <br>
Depending on the input value, the LED turns blue, green or red. <br>
If connection with the sensor is lost, a separate red diode turns on and the LED turns yellow.

This is initial testing. Future improvements might include:
- Switching board to the Arduino MKR Wifi 1010.
- Implement database connectivity.
  - Hopefully using a Raspberry Pi 4 as server, using MariaDB.
- Build a nice plastic case for it to be used outside.
