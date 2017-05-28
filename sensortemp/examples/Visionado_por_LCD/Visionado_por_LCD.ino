/* Author: 	Eduardo Cáceres de la Calle
 * Subject: 	Sistemas Digitales Avanzados (SDA)
 * Degree: 	Industrial Electronics and Automatic Control Engineering
 * University:	Universidad de Valladolid (UVa) - EII
 *
 * Code written in 2016, during my first contact with Arduino.
 * Uploaded for educational purposes only, don't be too hard on me :)
 * 
 */

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#include <sensortemp.h>
sensortemp sensor1(1);

void temp_serie(float temp_c, float temp_f);
void temp_lcd(float temp_c, float temp_f);

byte upper_a[8]=
{
  0b01110,
  0b00010,
  0b01110,
  0b01010,
  0b01110,
  0b11111,
  0b00000,
  0b00000
};

byte upper_o[8]=
{
  0b01110,
  0b01010,
  0b01110,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

void setup()
{
  Serial.begin(9600);
  
  lcd.createChar(1, upper_a);
  lcd.createChar(2, upper_o);
  
  lcd.begin(16, 2);
  
  lcd.setCursor(3,0);
  lcd.print("La T");
  lcd.write(byte(1));
  lcd.print(" es:");
}

void loop()
{
   float temperatura_celsius=sensor1.temp_C();
   float temperatura_fah=sensor1.temp_F();

   temp_serie(temperatura_celsius, temperatura_fah);
   temp_lcd(temperatura_celsius, temperatura_fah);
}

void temp_serie(float temp_c, float temp_f)
{
   Serial.print("\nTemperatura en grados Celsius: ");
   Serial.print(temp_c);
   Serial.print(";\t\tTemperatura en grados Fahrenheit: ");
   Serial.print(temp_f);
}

void temp_lcd(float temp_c, float temp_f)
{
    lcd.setCursor(0,1);
    lcd.print(temp_c);
    lcd.write(byte(2));
    lcd.print("C");
    
    lcd.print("-");
    lcd.print(temp_f);
    lcd.write(byte(2));
    lcd.print("F");    
}
