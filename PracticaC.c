/*
 * File:   PracticaC.c
 * Author: porte
 *
 * Created on 22 de octubre de 2019, 06:08 PM
 */

#include "puertos.h"
 
void main(void) {
 
    uint8_t key;
    inicializar_puertos();
 
    while(1)
    {
        key = leer_keypad();
 
        if (key != 255)
            PORTD = ~(key<<4);
    }
}