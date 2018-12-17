#include "Cerrado7Segmentos.h"

const boolean numero[10][7] = {
    {1, 0, 1, 1, 1, 1, 1}, //0
    {0, 0, 0, 0, 1, 0, 1}, //1
    {1, 1, 1, 0, 1, 1, 0}, //2
    {1, 1, 1, 0, 1, 0, 1}, //3
    {0, 1, 0, 1, 1, 0, 1}, //4
    {1, 1, 1, 1, 0, 0, 1}, //5
    {1, 1, 1, 1, 0, 1, 1}, //6
    {1, 0, 0, 0, 1, 0, 1}, //7
    {1, 1, 1, 1, 1, 1, 1}, //8
    {1, 1, 1, 1, 1, 0, 1}  //9
};

Cerrado7Segmentos::Cerrado7Segmentos(int _x, int _y, int _escala, MCUFRIEND_kbv *_display, uint16_t _color, uint16_t _background)
{
    x = _x;
    y = _y;
    escala = _escala;
    display = _display;
    color = _color;
    background = _background;

    for (int i = 0; i < 7; i++)
    {
        segmentos[i] = false;
    }
}

void Cerrado7Segmentos::segmento(int seg, boolean liga)
{
    uint16_t _color;

    if (liga)
    {
        _color = color;
    }
    else
    {
        _color = background;
    }

    switch (seg + 1)
    {
    case 1:
        display->fillRoundRect(x + 3 * escala, y, 20 * escala, 4 * escala, 2 * escala, _color);
        break;
    case 2:
        display->fillRoundRect(x + 3 * escala, y + 22 * escala, 20 * escala, 4 * escala, 2 * escala, _color);
        break;
    case 3:
        display->fillRoundRect(x + 3 * escala, y + 44 * escala, 20 * escala, 4 * escala, 2 * escala, _color);
        break;
    case 4:
        display->fillRoundRect(x, y + 3 * escala, 4 * escala, 20 * escala, 2 * escala, _color);
        break;
    case 5:
        display->fillRoundRect(x + 22 * escala, y + 3 * escala, 4 * escala, 20 * escala, 2 * escala, _color);
        break;
    case 6:
        display->fillRoundRect(x, y + 25 * escala, 4 * escala, 20 * escala, 2 * escala, _color);
        break;
    case 7:
        display->fillRoundRect(x + 22 * escala, y + 25 * escala, 4 * escala, 20 * escala, 2 * escala, _color);
        break;
    default:
        break;
    }

    segmentos[seg] = !segmentos[seg];
}

void Cerrado7Segmentos::printarNumero(int num)
{
    for (int i = 0; i < 7; i++)
    {
        if (numero[num][i] != segmentos[i])
        {
            segmento(i, numero[num][i]);
        }
    }
}