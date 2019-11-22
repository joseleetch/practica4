#include "puertos.h"
 
void inicializar_puertos(void)
{
    PORTB = 0xFF;
    TRISB = 0X0F;
    PORTD = 0XFF;
    TRISD = 0x00;
    PORTBbits.RB0 = 0b0;
    OPTION_REG &= 0b01111111;
}
 
uint8_t leer_keypad(void)
{
    const uint8_t keypad_array[17] =
      /* 1  4  7   *  2  5  8  0  3  6  9   #   A   B   C   D      */
        {1, 4, 7, 14, 2, 5, 8, 0, 3, 6, 9, 15, 10, 11, 12, 13, 255};
 
    uint8_t key = 0, columna;
 
    for (columna = 0b00000001; columna < 0b00010000; columna <<= 1)
    {
        PORTB = ~(columna << 4);
        if (PORTBbits.RB0 == 0) break; key++;
        if (PORTBbits.RB1 == 0) break; key++;
        if (PORTBbits.RB2 == 0) break; key++;
        if (PORTBbits.RB3 == 0) break; key++;
    }
    PORTB = 0xFF;
    return keypad_array[key];
}