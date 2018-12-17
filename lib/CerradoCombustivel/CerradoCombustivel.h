#ifndef CERRADOCOMBUSTIVEL_H_INCLUDED
#define CERRADOCOMBUSTIVEL_H_INCLUDED

#include <Arduino.h>

class CerradoCombustivel
{
private:
    int sinal1;
    int sinal2;
    int leitura1;
    int leitura2;
    int combustivel;
public:
    CerradoCombustivel(int pino1, int pino2);
    void verificarCombustivel();
    int getCombustivel();
};

#endif // CERRADOCOMBUSTIVEL_H_INCLUDED
