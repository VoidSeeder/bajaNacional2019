#include <Arduino.h>
#include <GerenciadorDeProcessos.h>

//#include <Wire.h>        //Biblioteca para manipulação do protocolo I2C
//#include <DS3231.h>      //Biblioteca para manipulação do DS3231
 
//DS3231 rtc;              //Criação do objeto do tipo DS3231
//RTCDateTime dataehora;   //Criação do objeto do tipo RTCDateTime

#include "MCUFRIEND_kbv.h"
MCUFRIEND_kbv tft;

#include "CerradoTemperatura.h"
CerradoTemperatura term;

#include "CerradoDisplay.h"
CerradoDisplay tela(&tft);

#define PINO1 40
#define PINO2 41

#include "CerradoCombustivel.h"
CerradoCombustivel ppk(PINO1, PINO2);

#define PININT 21

#include "CerradoVelocidade.h"
CerradoVelocidade velocidade(PININT);

#include "CerradoBateria.h"
CerradoBateria bateria(A15);

int cont = 0;

void mudar();

void interrupcao()
{
  velocidade.setRotacao(velocidade.getRotacao() + 1);
  velocidade.setTempo(millis());
  velocidade.setDeltaT(velocidade.getTempo() - velocidade.getTempo2());

  velocidade.setTempo2(velocidade.getTempo());
  //cont++;
  //Serial.println(cont);
}

void setup() {
  tft.begin(tft.readID());
  Serial.begin(9600);

  //rtc.begin();            //Inicialização do RTC DS3231
 
  //rtc.setDateTime(__DATE__, __TIME__);

  //attachInterrupt(digitalPinToInterrupt(21), interrupcao, FALLING);

  //tela.introducao();

  tela.telaPrincipal();

  //tela.telaVelocidade();

  //tela.telaTempo();

  //tela.telaTemperatura();

  attachInterrupt(digitalPinToInterrupt(19), mudar, FALLING);
}

int n = 0;
//int cont = 0;
int hora = 0, minuto = 0, segundo = 0;
int tempMotor = 9, tempCvt = 73;

void loop() {
  switch (n)
  {
    case 0:
      noInterrupts();
      velocidade.calcularVelocidade(0);
      term.calcularTemperatura();
      //tela.atualizar(velocidade.getVelocidadeA());
      //ppk.verificarCombustivel();
      //bateria.calcularTensao();
      //dataehora = rtc.getDateTime();
      tela.atualizar(15, 11, 50, 95, 99, 1, 11.5);
      delay(200);
      interrupts();
      break;
    case 1:
      noInterrupts();
      velocidade.calcularVelocidade(0);
      tela.atualizar(velocidade.getVelocidadeA());
      interrupts();
      delay(200);
      //(cont == 99) ? cont = 0 : cont++;
      break;
    case 2:
      noInterrupts();
      //dataehora = rtc.getDateTime();
      //tela.atualizar(dataehora.hour, dataehora.minute, dataehora.second);
      interrupts();
      break;
    case 3:
      noInterrupts();
      //term.calcularTemperaura();
      //tela.atualizar(term.getTempC(), term.getTempC());
      interrupts();

      (tempMotor == 537) ? tempMotor = 0 : tempMotor++;
      (tempCvt == 537) ? tempCvt = 0 : tempCvt++;
      break;
    default:
      break;
  }
}

void mudar()
{
  (n == 3) ? n = 0 : n++;

  switch (n)
  {
    case 0:
      tela.telaPrincipal();
      break;
    case 1:
      tela.telaVelocidade();
      break;
    case 2:
      tela.telaTempo();
      break;
    case 3:
      tela.telaTemperatura();
      break;
    default:
      break;
  }
}