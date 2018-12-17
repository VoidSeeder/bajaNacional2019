#include "CerradoCombustivel.h"

#include <Arduino.h>

CerradoCombustivel::CerradoCombustivel(int pino1, int pino2)
{
    CerradoCombustivel::leitura1 = HIGH;
    CerradoCombustivel::leitura2 = HIGH;
    CerradoCombustivel::sinal1 = pino1;
    CerradoCombustivel::sinal2 = pino2;

    pinMode(pino1, INPUT_PULLUP);
    pinMode(pino2, INPUT_PULLUP);
}

void CerradoCombustivel::verificarCombustivel()
{
    CerradoCombustivel::leitura1 = digitalRead(CerradoCombustivel::sinal1); //Leitura do primeiro sensor
    CerradoCombustivel::leitura2 = digitalRead(CerradoCombustivel::sinal2); //Leitura do segundo sensor

    if((CerradoCombustivel::leitura1== HIGH) || (CerradoCombustivel::leitura2==HIGH)) //Condiço para situacao do combustivel (sensores capacitivos normalmente HIGH)
    {
        combustivel = 1; //Tanque cheio
    }
    else
    {
        combustivel = 0; //Tanque quase vazio
    }
}

int CerradoCombustivel::getCombustivel()
{
    return CerradoCombustivel::combustivel;
}
