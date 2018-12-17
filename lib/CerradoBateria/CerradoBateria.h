#ifndef CERRADOBATERIA_H_INCLUDED
#define CERRADOBATERIA_H_INCLUDED

#include <Arduino.h>

class CerradoBateria
{
private:
    float voltage;
    float voltage2;
    int sensorValue;
    int porta;
public:
    CerradoBateria(int pino);
    void calcularTensao();
    float getVoltage2();
};

#endif // CERRADOBATERIA_H_INCLUDED
