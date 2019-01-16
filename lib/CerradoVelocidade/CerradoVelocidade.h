#ifndef CERRADOVELOCIDADE_H_INCLUDED
#define CERRADOVELOCIDADE_H_INCLUDED

#include <Arduino.h>
#include <EEPROM.h>

class CerradoVelocidade
{
private:
    int rotacao; //Rotacao da roda
    float Tcoleta; //Tempo de atualizacao da velocidade
    unsigned long currentMillis; //Tempo do calculo atual
    long previousMillis; //Tempo do calculo anterior
    unsigned long tempo; //Tempo da interrupcao atual
    unsigned long tempo2; //Tempo da interrupcao anterior
    unsigned long deltaT; //Diferenca entre os tempos da interrupcao anterior e atual
    int velocidade; //Variavel que armazena a valocidade (Km/h)
    int velocidadeA; //velocidade obtida no ultimo calculo (para ser exibida no display)
    int distancia; //Calculo da distancia atual
    int distancia2; //Caluclo da distancia total
    long int distancia3; //Contador de quantos quilometros unitarios foram percorridos
    int pino;
public:
    CerradoVelocidade(int p);
    void calcularVelocidade();
    void setRotacao(int r);
    int getRotacao();
    void setTempo(unsigned long t);
    unsigned long getTempo();
    void setTempo2(unsigned long t);
    unsigned long getTempo2();
    void setDeltaT(unsigned long d);
    unsigned long getDeltaT();
    int getPino();
    int getVelocidadeA();
};

#endif // CERRADOVELOCIDADE_H_INCLUDED
