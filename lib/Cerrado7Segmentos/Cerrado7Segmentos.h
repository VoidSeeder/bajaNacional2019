#ifndef CERRADO7SEGMENTOS_H_INCLUDED
#define CERRADO7SEGMENTOS_H_INCLUDED

#include <Arduino.h>
#include "MCUFRIEND_kbv.h"

class Cerrado7Segmentos
{
  private:
    boolean segmentos[7];
    int x, y, escala;
    MCUFRIEND_kbv *display;
    uint16_t color, background;
    void segmento(int seg, boolean liga);

  public:
    Cerrado7Segmentos(int _x, int _y, int _escala, MCUFRIEND_kbv *_display, uint16_t _color, uint16_t _background);
    void printarNumero(int num);
};

#endif // CERRADODISPLAY_H_INCLUDED