#include "CerradoTemperatura.h"

#include <Arduino.h>

#define ONE_WIRE_BUS 45
OneWire oneWire(ONE_WIRE_BUS);

DeviceAddress vet =
{
    0x28, 0xFF, 0xB7, 0x14, 0xA0, 0x16, 0x04, 0xB1

};

CerradoTemperatura::CerradoTemperatura()
{
    CerradoTemperatura::sensors = new DallasTemperature(&oneWire);
    CerradoTemperatura::insideThermometer = &vet;

    CerradoTemperatura::sensors -> begin();
    CerradoTemperatura::sensors -> setResolution(*CerradoTemperatura::insideThermometer, 10);
}

void CerradoTemperatura::printTemperature(DeviceAddress deviceAddress)
{
    CerradoTemperatura::tempC = CerradoTemperatura::sensors -> getTempC(deviceAddress);
}

void CerradoTemperatura::calcularTemperatura()
{
    CerradoTemperatura::sensors -> requestTemperatures();
    CerradoTemperatura::printTemperature(*CerradoTemperatura::insideThermometer);
}

float CerradoTemperatura::getTempC()
{
    return CerradoTemperatura::tempC;
}
