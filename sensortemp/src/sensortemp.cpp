/* Author:  	Eduardo Cáceres de la Calle
 * Subject: 	Sistemas Digitales Avanzados (SDA)
 * Degree: 	    Industrial Electronics and Automatic Control Engineering
 * University:	Universidad de Valladolid (UVa) - EII
 *
 * Code written in 2016, during my first contact with Arduino.
 * Uploaded for educational purposes only, don't be too hard on me :)
 * 
 */

#include "Arduino.h"
#include "sensortemp.h"
#include <string.h>

sensortemp::sensortemp(int pin)     // Constructor
{
	_pin=pin+A0;
}

void sensortemp::temp_serial(float lectura, float volt, float temp)
{
    Serial.print("\nLectura: ");
    Serial.print(lectura);
    Serial.print("V\tVoltaje: ");
    Serial.print(volt);
    Serial.print("\tTemperatura (C): ");
    Serial.print(temp);
}


float sensortemp::muestreo_temp()
{
    float lectura=analogRead(_pin);
    float volt=lectura*(5/(float)1023);
	// Sería mejor hacer una multiplicación(hardware) que división (software)
    // Es decir, multiplicar directamente por la constante 5/1023
    float temp=100*volt-50;	    //temp=    (volt-0.5)/0.01;

    //temp_serial(lectura, volt, temp);   //Comprobacion de las conversiones
    return(temp);
}

float sensortemp::temp_C()
{
  float temperatura_media;
    for(int i=1;i<33;i++)
    {
       temperatura_media+= muestreo_temp();
       delay(31.25);  //  1000 ms /32 lecturas
    }
    temperatura_media/=(float)32;

    return(temperatura_media);
}

float sensortemp::temp_F()
{
    float temp=temp_C();	// Evitando repetir código innecesariamente

    float temperatura_media= 32+ 1.8*temp;

    return(temperatura_media);
}
