#ifndef CERRADODISPLAY_H_INCLUDED
#define CERRADODISPLAY_H_INCLUDED

#include <Arduino.h>
#include "MCUFRIEND_kbv.h"
#include "Cerrado7Segmentos.h"
#include "const.h"

class CerradoDisplay
{
private:
  //Tela principal
  boolean combustivelAnterior;
  Cerrado7Segmentos *velDezena, *velUnidade, *horaDezena, *horaUnidade, *minDezena, *minUnidade,
      *tempMotorDezena, *tempMotorUnidade, *tempCvtCentena, *tempCvtDezena, *tempCvtUnidade,
      *voltageDezena, *voltageUnidade, *voltageDecimal;
  //Tela velocidade
  Cerrado7Segmentos *velDezenaKph, *velUnidadeKph, *velDezenaMps, *velUnidadeMps, *velDezenaMph, *velUnidadeMph;
  //Tela tempo
  Cerrado7Segmentos /* *horaDezena, *horaUnidade, *minDezena, *minUnidade, */ *segDezena, *segUnidade;
  //Tela temperatura
  Cerrado7Segmentos *tempMotorCentenaC, *tempMotorDezenaC, *tempMotorUnidadeC, *tempMotorCentenaF, *tempMotorDezenaF, *tempMotorUnidadeF,
      *tempMotorCentenaK, *tempMotorDezenaK, *tempMotorUnidadeK, *tempCvtCentenaC, *tempCvtDezenaC, *tempCvtUnidadeC,
      *tempCvtCentenaF, *tempCvtDezenaF, *tempCvtUnidadeF, *tempCvtCentenaK, *tempCvtDezenaK, *tempCvtUnidadeK;
  int dia, mes, ano;
  MCUFRIEND_kbv *display;

public:
  CerradoDisplay(MCUFRIEND_kbv *_display);
  void introducao();
  void telaPrincipal();
  void telaVelocidade();
  void telaTempo();
  void telaTemperatura();
  void atualizar(int velocidade, int hora, int min, int tempMotor,
                 int tempCvt, boolean combustivel, float voltagem);
  void atualizar(int velocidade);
  void atualizar(int hora, int minuto, int segundo);
  void atualizar(int tempMotor, int tempCvt);
};

#endif // CERRADODISPLAY_H_INCLUDE