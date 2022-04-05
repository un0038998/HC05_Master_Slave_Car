#include <SoftwareSerial.h>
SoftwareSerial btSerial(2, 3); // RX | TX
 
void setup() 
{
    Serial.begin(9600);

    btSerial.begin(38400);      
    Serial.println("btSerial started at 38400");
}
 
void loop()
{
  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
  {
    btSerial.write(Serial.read()); 
  }
  
  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (btSerial.available())
  {  
    Serial.write(btSerial.read());
  }
}

/*
Slave Command:
AT
AT+RMAAD
AT+ROLE=0
AT+UART=38400,0,0
AT+ADDR


Master Commands:
AT
AT+RMAAD
AT+ROLE=1
AT+UART=38400,0,0
AT+CMODE=0
AT+BIND=98D3:61:F613EA  (This should be your HC05 Slave address)
*/
