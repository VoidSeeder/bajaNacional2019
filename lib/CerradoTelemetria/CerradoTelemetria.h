#ifndef CERRADOTELEMETRIA_H_INCLUDED
#define CERRADOTELEMETRIA_H_INCLUDED

#include <Arduino.h>

#include <LoRa.h>

class CerradoTelemetria
{
private:
    String chave;
    String message;
public:
    CerradoTelemetria(String chave);
    void registrar(int temp1, int temp2, int velocidade, int voltage, bool comb);
    void enviar();
};

#endif // CERRADOTELEMETRIA_H_INCLUDED