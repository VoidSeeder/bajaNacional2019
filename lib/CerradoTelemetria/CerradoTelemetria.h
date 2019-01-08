#ifndef CERRADOTELEMETRIA_H_INCLUDED
#define CERRADOTELEMETRIA_H_INCLUDED

#include <Arduino.h>

#include <SofwareSerial.h>

class CerradoTelemetria
{
private:
    SoftwareSerial *mySerial;
    String chave;
    String message;
public:
    CerradoTelemetria(SofwareSerial* mySerial, String chave);
    void registrar(int temp1, int temp2, int velocidade, int voltage, bool comb);
    void enviar();
};

#endif // CERRADOTELEMETRIA_H_INCLUDED