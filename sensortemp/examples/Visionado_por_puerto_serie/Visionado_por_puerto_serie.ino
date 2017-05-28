/* Author: 	Eduardo Cáceres de la Calle
 * Subject: 	Sistemas Digitales Avanzados (SDA)
 * Degree: 	Industrial Electronics and Automatic Control Engineering
 * University:	Universidad de Valladolid (UVa) - EII
 *
 * Code written in 2016, during my first contact with Arduino.
 * Uploaded for educational purposes only, don't be too hard on me :)
 * 
 */

#include <sensortemp.h>

sensortemp sensor1(1);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.print("\nTemperatura en Celsius: ");
  Serial.print(sensor1.temp_C());
  Serial.print(";\tTemperatura en Fahrenheit: ");
  Serial.print(sensor1.temp_F());
}
