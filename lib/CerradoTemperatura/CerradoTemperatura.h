#ifndef CERRADOTEMPERATURA_H_INCLUDED
#define CERRADOTEMPERATURA_H_INCLUDED

#include <Arduino.h>

#include <DallasTemperature.h>
#include <OneWire.h>

class CerradoTemperatura
{
private:
    float tempC;
    DallasTemperature* sensors;
    DeviceAddress* insideThermometer;
    void printTemperature(DeviceAddress deviceAddress);
public:
    CerradoTemperatura();
    void calcularTemperatura();
    float getTempC();
};

#endif // CERRADOTEMPERATURA_H_INCLUDED
