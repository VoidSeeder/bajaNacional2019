#include <Arduino.h>

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
CerradoCombustivel comb(PINO1, PINO2);

#define PININT 18
#include "CerradoVelocidade.h"
CerradoVelocidade velocidade(PININT);

#include "CerradoBateria.h"
CerradoBateria bateria(A8);

#include "CerradoTelemetria.h"
CerradoTelemetria HC12("110000111");

#include <GerenciadorDeProcessos.h>
Processo P_atualizar;
Processo P_verificarCombustivel;
Processo P_calcularVelocidade;
Processo P_verificarBateria;
Processo P_enviarInformacoes;
Processo P_verificarTemperatura;
void atualizar();
void verificarCombustivel();
void calcularVelocidade();
void verificarBateria();
void enviarInformacoes();
void verificarTemperatura();

int telaAtual;

void mudar();
void interrupcao();

void setup() {
    tft.begin(tft.readID());
    setSyncProvider(RTC.get);

    tela.introducao();

    attachInterrupt(digitalPinToInterrupt(19), mudar, FALLING);
    attachInterrupt(digitalPinToInterrupt(18), interrupcao, FALLING);

    tela.telaPrincipal();
    telaAtual = 0;

    b_adicionarTarefa(atualizar, "Atualiza a tela", 250, SIM, &P_atualizar);
    b_adicionarTarefa(verificarCombustivel, "Verifica o nivel de combustivel", 5000, SIM, &P_verificarCombustivel);
    b_adicionarTarefa(calcularVelocidade, "Calcula a velocidade", 200, SIM, &P_calcularVelocidade);
    b_adicionarTarefa(verificarBateria, "Verifica a tensão da bateria", 4000, SIM, &P_verificarBateria);
    b_adicionarTarefa(enviarInformacoes, "Envia as informacoes via LoRa", 500, SIM, &P_enviarInformacoes);
    b_adicionarTarefa(verificarTemperatura, "Verifica as temperaturas", 1000, SIM, &P_verificarTemperatura);
    b_habilitarEscalonador();
}

void loop() {
    iniciarProcessos();
}

void atualizar() {
    switch (telaAtual) {
    case 0:
      tela.atualizar(velocidade.getVelocidadeA(), hour(), minute(), term.getTempC(), term.getTempC(), comb.getCombustivel(), bateria.getVoltage2());
      break;
    case 1:
      tela.atualizar(velocidade.getVelocidadeA());
      break;
    case 2:
      tela.atualizar(hour(), minute(), second());
      break;
    case 3:
      tela.atualizar(term.getTempC(), term.getTempC());
      break;
    default:
      break;
  }
}

void verificarCombustivel() {
    comb.verificarCombustivel();
}

void calcularVelocidade() {
    velocidade.calcularVelocidade();
}

void verificarBateria() {
    bateria.calcularTensao();
}

void enviarInformacoes() {
    HC12.registrar(term.getTempC(), term.getTempC(), velocidade.getVelocidadeA(), bateria.getVoltage2(), comb.getCombustivel());
    HC12.enviar();
}

void verificarTemperatura() {
    term.calcularTemperatura();
}

void mudar() {
  (telaAtual == 3) ? (telaAtual = 0) : (telaAtual++);

  switch (telaAtual) {
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

void interrupcao() {
  velocidade.setRotacao(velocidade.getRotacao() + 1);
  velocidade.setTempo(millis());
  velocidade.setDeltaT(velocidade.getTempo() - velocidade.getTempo2());

  velocidade.setTempo2(velocidade.getTempo());
}