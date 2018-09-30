/* Author: 	    Eduardo Cáceres de la Calle
 * Subject: 	Sistemas Digitales Avanzados (SDA)
 * Degree: 	    Industrial Electronics and Automatic Control Engineering
 * University:	Universidad de Valladolid (UVa) - EII
 *
 * Code written in 2016, during my first contact with Arduino.
 * Uploaded for educational purposes only, don't be too hard on me :)
 * 
 */

#ifndef Prueba
#define Prueba

#include "Arduino.h";

class sensortemp
{
public:		// Funciones públicas
    sensortemp(int pin);    // Constructor
    /*  Define el pin donde está conectado el sensor
    *   Quedará almacenado en la variable _pin
    */

    void temp_serial(float lectura, float volt, float temp);
    /*  Muestra por el puerto serie las tres variables que se le pasa
    *   Función diseñada para comprobaciones del correcto funcionamiento del sensor
    */

    float muestreo_temp();
    /*  Realiza una sola lectura del puerto _pin (comprendida entre 0 y 1023)
    *   Transforma esa lectura en el valor de voltaje que recibe (entre 0 y 5V)
    *   Transforma ese voltaje en la temperatura en ºC a la que se somete al sensor
    *   Devuelve ese valor
    */

    float temp_C();
    /*  Llama 32 veces a la función muestreo_temp(), de manera que obtenga 32 lecturas/segundo
    *   Calcula la media de esas 32 lecturas
    *   Devuelve la temperatura media en ºC
    */

    float temp_F();
    /*  Llama a la función temp_C(), evistando así repetir código y obteniendo ya la temp media
    *   Transforma la temperatura media de ºC a ºF
    *   Devuelva la temperatura media en ºF
    */

private:	// Variables privadas
    int _pin;
};

#endif


