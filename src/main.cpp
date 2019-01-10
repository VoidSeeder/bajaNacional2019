#include <Arduino.h>
#include <GerenciadorDeProcessos.h>

//#include <Wire.h>        //Biblioteca para manipulação do protocolo I2C
//#include <DS3231.h>      //Biblioteca para manipulação do DS3231
 
//DS3231 rtc;              //Criação do objeto do tipo DS3231
//RTCDateTime dataehora;   //Criação do objeto do tipo RTCDateTime

#include <DS3232RTC.h>      // https://github.com/JChristensen/DS3232RTC

#include "MCUFRIEND_kbv.h"
MCUFRIEND_kbv tft;

#include "CerradoTemperatura.h"
CerradoTemperatura term;

#include "CerradoDisplay.h"
CerradoDisplay tela(&tft);

#define PINO1 20
#define PINO2 21

#include "CerradoCombustivel.h"
CerradoCombustivel ppk(PINO1, PINO2);

#define PININT 18

#include "CerradoVelocidade.h"
CerradoVelocidade velocidade(PININT);

#include "CerradoBateria.h"
CerradoBateria bateria(A8);

#include "SoftwareSerial.h"
SoftwareSerial mySerial(15, 14);

#include "CerradoTelemetria.h"
CerradoTelemetria HC12(&mySerial, "110000111");

int cont = 0;

void mudar();

void interrupcao() {
  velocidade.setRotacao(velocidade.getRotacao() + 1);
  velocidade.setTempo(millis());
  velocidade.setDeltaT(velocidade.getTempo() - velocidade.getTempo2());

  velocidade.setTempo2(velocidade.getTempo());
  //cont++;
  //Serial.println(cont);
}

void setup() {
  tft.begin(tft.readID());
  //Serial.begin(9600);

  setSyncProvider(RTC.get);   // the function to get the time from the RTC

  //rtc.begin();            //Inicialização do RTC DS3231
 
  //rtc.setDateTime(__DATE__, __TIME__);

  //attachInterrupt(digitalPinToInterrupt(21), interrupcao, FALLING);

  //tela.introducao();

  //tela.telaPrincipal();

  //tela.telaVelocidade();

  tela.telaTempo(day(), month(), year());

  //tela.telaTemperatura();

  attachInterrupt(digitalPinToInterrupt(19), mudar, FALLING);
  attachInterrupt(digitalPinToInterrupt(18), interrupcao, FALLING);
}

int n = 2;
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
      ppk.verificarCombustivel();
      bateria.calcularTensao();
      //dataehora = rtc.getDateTime();
      tela.atualizar(velocidade.getVelocidadeA(), hour(), minute(), term.getTempC(), term.getTempC(), ppk.getCombustivel(), bateria.getVoltage2());
      HC12.registrar(term.getTempC(), term.getTempC(), velocidade.getVelocidadeA(), bateria.getVoltage2(), ppk.getCombustivel());
      HC12.enviar();
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
      tela.atualizar(hour(), minute(), second());
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
      tela.telaTempo(day(), month(), year());
      break;
    case 3:
      tela.telaTemperatura();
      break;
    default:
      break;
  }
}