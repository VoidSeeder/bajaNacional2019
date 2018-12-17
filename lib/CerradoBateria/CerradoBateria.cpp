#include "CerradoBateria.h"

#include <Arduino.h>

CerradoBateria::CerradoBateria(int pino)
{
    voltage = 0;
    voltage2 = 0;
    sensorValue = 0;
    porta = pino;
}

void CerradoBateria::calcularTensao()
{
  sensorValue = analogRead(porta);
  voltage = ((float)sensorValue) * (12.0 / 1023.0);
  voltage2 = voltage;
}

float CerradoBateria::getVoltage2()
{
    return voltage2;
}
