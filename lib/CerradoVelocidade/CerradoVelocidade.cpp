#include "CerradoVelocidade.h"

#include <Arduino.h>
#include <EEPROM.h>

CerradoVelocidade::CerradoVelocidade(int p)
{
    CerradoVelocidade::rotacao = 0;
    CerradoVelocidade::Tcoleta = 250;
    CerradoVelocidade::previousMillis = 0;
    CerradoVelocidade::tempo = 0;
    CerradoVelocidade::tempo2 = 0;
    CerradoVelocidade::velocidade = 1;
    CerradoVelocidade::velocidadeA = 0;
    CerradoVelocidade::distancia = 0;
    CerradoVelocidade::distancia2 = 0;
    CerradoVelocidade::distancia3 = 0;
    CerradoVelocidade::pino = p;
}

void CerradoVelocidade::calcularVelocidade(int addr)
{
    CerradoVelocidade::currentMillis = millis(); //Armazena o tempo do calculo atual
    if ((CerradoVelocidade::currentMillis - CerradoVelocidade::previousMillis) >= CerradoVelocidade::Tcoleta) //Condicao para garantir que a velocidade sera atualizada a cada 250 millis (tempo de coleta)
    {
        CerradoVelocidade::velocidade = ((0.5633/CerradoVelocidade::deltaT)*1000)*3.6; //Calculo da velocidade Km/h (usando 1/3 do perimetro da roda)
        CerradoVelocidade::previousMillis = CerradoVelocidade::currentMillis; //Salva o tempo do ultimo calculo

        CerradoVelocidade::deltaT = 100000000; //Valor alto para garantir que nao haja divisao por 0
        CerradoVelocidade::distancia = 0.5633 * CerradoVelocidade::rotacao; //Calculo da distancia percorrida
        CerradoVelocidade::distancia2 = CerradoVelocidade::distancia + CerradoVelocidade::distancia2; //Incremento na distancia total

        if (CerradoVelocidade::distancia2 == 1000) //Garantir que o display informe apenas a distancia em Km
        {
            CerradoVelocidade::distancia3 = CerradoVelocidade::distancia3 + 1;
            if (CerradoVelocidade::distancia3 == 250)
            {
                CerradoVelocidade::distancia3 = 0;
            }
            EEPROM.write(addr, CerradoVelocidade::distancia3);
            CerradoVelocidade::distancia2 = 0;
        }

        CerradoVelocidade::rotacao = 0; //Zera  arotacao para garantir que quando o veiculo estiver parado nao haja incremento na distancia
        CerradoVelocidade::velocidadeA = CerradoVelocidade::velocidade; //Salva a velocidade para ser exibida no display antes de ser zerada
        CerradoVelocidade::velocidade = 0; //Zera a velocidade para novo calculo

    }
}

int CerradoVelocidade::getPino()
{
    return CerradoVelocidade::pino;
}

void CerradoVelocidade::setRotacao(int r)
{
    CerradoVelocidade::rotacao = r;
}

int CerradoVelocidade::getRotacao()
{
    return CerradoVelocidade::rotacao;
}

void CerradoVelocidade::setTempo(unsigned long t)
{
    CerradoVelocidade::tempo = t;
}

unsigned long CerradoVelocidade::getTempo()
{
    return CerradoVelocidade::tempo;
}

void CerradoVelocidade::setTempo2(unsigned long t)
{
    CerradoVelocidade::tempo2 = t;
}

unsigned long CerradoVelocidade::getTempo2()
{
    return CerradoVelocidade::tempo2;
}

void CerradoVelocidade::setDeltaT(unsigned long d)
{
    CerradoVelocidade::deltaT = d;
}

unsigned long CerradoVelocidade::getDeltaT()
{
    return CerradoVelocidade::deltaT;
}

int CerradoVelocidade::getVelocidadeA()
{
    return CerradoVelocidade::velocidadeA;
}
