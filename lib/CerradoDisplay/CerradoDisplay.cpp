#include "CerradoDisplay.h"

CerradoDisplay::CerradoDisplay(MCUFRIEND_kbv *_display)
{
    display = _display;
}

void CerradoDisplay::introducao()
{
    display->setRotation(1);

    int r1 = 220, g1 = 190, b1 = 100;

    int r2 = 240, g2 = 160, b2 = 40;

    int r = r1, g = g1, b = b1;

    for (int n = 0; n < 480; n++)
    {
        display->drawFastVLine(n, 0, 320, display->color565(r, g, b));

        r = r1 + ((r2 - r1) * ((double)n / 479));
        g = g1 + ((g2 - g1) * ((double)n / 479));
        b = b1 + ((b2 - b1) * ((double)n / 479));
    }

    display->drawBitmap(33, 9, logovet414x302, 414, 302, display->color565(179, 89, 0));
    delay(1000);

    for (int i = 0; i < 480; i++)
    {
        display->vertScroll(0, 480, i);
        display->drawFastVLine(i, 0, 320, WHITE);
        delay(2);
    }

    for (int i = 0; i < 110; i++)
    {
        display->vertScroll(0, 480, i);
    }

    display->drawBitmap(226, 32, logoufu254x256, 254, 256, BLUE);
    delay(1000);

    for (int i = 110; i < 220; i++)
    {
        display->vertScroll(0, 480, i);
        delay(5);
    }

    display->setFont(&FreeSansBold12pt7b);
    display->setTextColor(BLUE);

    display->setCursor(10, 116);
    display->print("UNIVERSIDADE");
    display->setCursor(25, 166);
    display->print("FEDERAL DE");
    display->setCursor(25, 216);
    display->print("UBERLANDIA");

    delay(2000);
    display->fillScreen(WHITE);
    display->vertScroll(0, 480, 0);
}

//tela 0 (PRINCIPAL)
void CerradoDisplay::telaPrincipal()
{
    display->setRotation(1);

    int x = 30, y = 35, n = 4;

    velUnidade = new Cerrado7Segmentos(x + 30 * n, y, n, display, BLUE, WHITE);
    velDezena = new Cerrado7Segmentos(x, y, n, display, BLUE, WHITE);

    horaDezena = new Cerrado7Segmentos(325, 18, 1, display, GREEN, WHITE);
    horaUnidade = new Cerrado7Segmentos(325 + 30, 18, 1, display, GREEN, WHITE);
    minDezena = new Cerrado7Segmentos(325 + 60 + 20, 18, 1, display, GREEN, WHITE);
    minUnidade = new Cerrado7Segmentos(325 + 90 + 20, 18, 1, display, GREEN, WHITE);

    display->fillScreen(GREY);

    /*
    //Textura
    int acr = -30;

    for (int j = -30; j <= 350; j += 42)
    {
        for (int i = acr; i <= 550; i += 57)
        {
            display->drawBitmap(i, j, logo69x50, 69, 50, WHITE);
        }
        acr += -10;
    }
    */

    display->fillRoundRect(10, 10, 270, 300, 15, BLUE);
    display->fillRoundRect(20, 20, 250, 220, 12, WHITE);

    display->setFont(&FreeMonoBold24pt7b);
    display->setTextSize(1);
    display->setTextColor(WHITE);
    display->setCursor(155, 290);
    display->print("Km/h");

    display->setFont(&FreeMonoBold12pt7b);
    display->setTextSize(1);
    display->setTextColor(WHITE);
    display->setCursor(30, 270);
    display->print("100.000");
    display->setCursor(100, 290);
    display->print("Km");

    display->fillRoundRect(290, 10, 180, 65, 8, GREEN);
    display->fillRoundRect(320, 15, 145, 55, 5, WHITE);

    display->fillCircle(325 + 60 + 10, 15 + 17, 3, GREEN);
    display->fillCircle(325 + 60 + 10, 15 + 17 + 20, 3, GREEN);

    display->setRotation(0);
    display->setFont(&FreeMonoBold12pt7b);
    display->setTextSize(1);
    display->setTextColor(WHITE);
    display->setCursor(250, 310);
    display->print("Hora");
    display->setRotation(1);

    /*
    //BACKUP quadro temperatura
    display->fillRoundRect(290, 190, 180, 120, 8, RED);
    display->fillRoundRect(295, 220, 170, 55, 5, WHITE);

    display->setFont(&FreeMonoBold12pt7b);
    display->setTextSize(1);
    display->setTextColor(WHITE);
    display->setCursor(300, 210);
    display->print("Temperatura");

    display->setCursor(300, 300);
    display->print("Motor");

    display->setCursor(405, 300);
    display->print("CVT");

    tempMotorDezena = new Cerrado7Segmentos(300, 225, 1, display, RED, WHITE);
    tempMotorUnidade = new Cerrado7Segmentos(300 + 30, 225, 1, display, RED, WHITE);

    tempCvtDezena = new Cerrado7Segmentos(385, 225, 1, display, RED, WHITE);
    tempCvtUnidade = new Cerrado7Segmentos(385 + 30, 225, 1, display, RED, WHITE);
    */

    /*
    horaDezena.printarNumero(2);
    horaUnidade.printarNumero(3);
    // :
    segundoDezena.printarNumero(3);
    segundoUnidade.printarNumero(0);
    */

    display->fillRoundRect(290, 245, 180, 65, 8, RED);
    display->fillRoundRect(320, 250, 95, 55, 5, WHITE);

    display->setRotation(0);
    display->setFont(&FreeMonoBold12pt7b);
    display->setTextSize(1);
    display->setTextColor(WHITE);
    display->setCursor(20, 310);
    display->print("CVT");
    display->setRotation(1);

    display->setFont(&FreeSansBold24pt7b);
    display->setTextSize(1);
    display->setTextColor(WHITE);
    display->setCursor(432, 297);
    display->print("C");

    display->fillCircle(427, 262, 8, WHITE);
    display->fillCircle(427, 262, 4, RED);
    
    display->fillRoundRect(290, 85, 165, 65, 4, YELLOW);
    display->fillRect(455, 95, 15, 45, YELLOW);

    display->fillRoundRect(295, 90, 155, 55, 4, GREY);

    voltageDezena = new Cerrado7Segmentos(297, 93, 1, display, YELLOW, GREY);
    voltageUnidade = new Cerrado7Segmentos(297 + 30, 93, 1, display, YELLOW, GREY);
    display->fillCircle(297 + 60 + 5, 135, 3, YELLOW);
    voltageDecimal = new Cerrado7Segmentos(297 + 60 + 10, 93, 1, display, YELLOW, GREY);
    
    /*
    //BACKUP
    display->fillRoundRect(295, 90, 35, 55, 4, WHITE);
    display->fillRoundRect(295 + 35 + 5, 90, 35, 55, 4, WHITE);
    display->fillRoundRect(295 + 2 * 35 + 2 * 5, 90, 35, 55, 4, WHITE);
    display->fillRoundRect(295 + 3 * 35 + 3 * 5, 90, 35, 55, 4, WHITE);

    display->fillRoundRect(300, 95, 25, 45, 4, YELLOW);
    display->fillRoundRect(300 + 35 + 5, 95, 25, 45, 4, YELLOW);
    display->fillRoundRect(300 + 2 * 35 + 2 * 5, 95, 25, 45, 4, YELLOW);
    display->fillRoundRect(300 + 3 * 35 + 3 * 5, 95, 25, 45, 4, YELLOW);
    */

    display->fillRoundRect(290, 165, 180, 70, 8, BLACK);
    display->fillRoundRect(350, 170, 95, 60, 5, WHITE);
    //display->fillTriangle(300, 225, 460, 225, 460, 175, WHITE);

    display->drawBitmap(290, 170, gota60x60, 60, 60, WHITE);

    tempCvtCentena = new Cerrado7Segmentos(325, 253, 1, display, RED, WHITE);
    tempCvtDezena = new Cerrado7Segmentos(325 + 30, 253, 1, display, RED, WHITE);
    tempCvtUnidade = new Cerrado7Segmentos(325 + 60, 253, 1, display, RED, WHITE);

    atualizar(15, 23, 30, 95, 999, false, 5);
}

void CerradoDisplay::atualizar(int velocidade, int hora, int min, int tempMotor,
                               int tempCvt, boolean combustivel, float voltagem)
{
    int dezena = velocidade / 10, unidade = velocidade % 10;

    velDezena->printarNumero(dezena);
    velUnidade->printarNumero(unidade);

    dezena = hora / 10;
    unidade = hora % 10;

    horaDezena->printarNumero(dezena);
    horaUnidade->printarNumero(unidade);

    dezena = min / 10;
    unidade = min % 10;

    minDezena->printarNumero(dezena);
    minUnidade->printarNumero(unidade);

    /*
    dezena = tempMotor / 10;
    unidade = tempMotor % 10;

    tempMotorDezena->printarNumero(dezena);
    tempMotorUnidade->printarNumero(unidade);
    */

    int centena = tempCvt / 100;
    dezena = (tempCvt % 100) / 10;
    unidade = tempCvt % 10;

    tempCvtCentena->printarNumero(centena);
    tempCvtDezena->printarNumero(dezena);
    tempCvtUnidade->printarNumero(unidade);
    
    if (combustivelAnterior != combustivel)
    {
        display->setFont(&FreeSansBold24pt7b);
        display->setTextSize(1);
        display->setTextColor(BLACK);
        display->setCursor(355, 225);
        display->fillRoundRect(350, 170, 95, 60, 5, WHITE);

        if(combustivel)
        {
            display->print("ON");
        }
        else
        {
            display->print("OFF");
        }
        
        combustivelAnterior = combustivel;
    }

    dezena = ((int)voltagem) / 10;
    unidade = ((int)voltagem) % 10;
    int decimal = (int)((voltagem - (float)dezena * 10.0 - (float)unidade) * 10.0);

    voltageDezena->printarNumero(dezena);
    voltageUnidade->printarNumero(unidade);
    voltageDecimal->printarNumero(decimal);
}

//TELA 1 (velocidade)
void CerradoDisplay::telaVelocidade()
{
    display->setRotation(1);

    display->fillScreen(GREY);

    int x = 30, y = 35, n = 4;

    velUnidadeKph = new Cerrado7Segmentos(x + 30 * n, y, n, display, BLUE, WHITE);
    velDezenaKph = new Cerrado7Segmentos(x, y, n, display, BLUE, WHITE);

    velUnidadeMps = new Cerrado7Segmentos(300 + 30 * 2, 20, 2, display, BLUE, WHITE);
    velDezenaMps = new Cerrado7Segmentos(300, 20, 2, display, BLUE, WHITE);

    velUnidadeMph = new Cerrado7Segmentos(300 + 30 * 2, 20 + 155, 2, display, BLUE, WHITE);
    velDezenaMph = new Cerrado7Segmentos(300, 20 + 155, 2, display, BLUE, WHITE);

    display->fillRoundRect(10, 10, 270, 300, 15, BLUE);
    display->fillRoundRect(20, 20, 250, 220, 12, WHITE);

    display->setFont(&FreeMonoBold24pt7b);
    display->setTextSize(1);
    display->setTextColor(WHITE);
    display->setCursor(155, 290);
    display->print("Km/h");

    display->setFont(&FreeMonoBold12pt7b);
    display->setTextSize(1);
    display->setTextColor(WHITE);
    display->setCursor(30, 270);
    display->print("100.000");
    display->setCursor(100, 290);
    display->print("Km");

    //7 de borda
    display->fillRoundRect(290, 10, 133, 145, 12, BLUE);
    display->fillRoundRect(297, 17, 119, 105, 10, WHITE);

    display->setFont(&FreeMonoBold12pt7b);
    display->setTextSize(1);
    display->setTextColor(WHITE);
    display->setCursor(365, 145);
    display->print("m/s");

    //display->drawFastHLine(0,160,480,BLACK);

    display->fillRoundRect(290, 10 + 155, 133, 145, 12, BLUE);
    display->fillRoundRect(297, 17 + 155, 119, 105, 10, WHITE);

    display->setFont(&FreeMonoBold12pt7b);
    display->setTextSize(1);
    display->setTextColor(WHITE);
    display->setCursor(365, 145 + 155);
    display->print("mph");

    display->fillRect(430, 0, 50, 320, BLUE);

    display->setRotation(0);
    display->setFont(&FreeMonoBold24pt7b);
    display->setTextSize(1);
    display->setTextColor(WHITE);
    display->setCursor(20, 465);
    display->print("VELOCIDADE");
    display->setRotation(1);

    //BLOCO

    /*
    int x = 30, y = 35, n = 4;

    velUnidadeKph = new Cerrado7Segmentos(x + 30 * n, y, n, display, BLUE, WHITE);
    velDezenaKph = new Cerrado7Segmentos(x, y, n, display, BLUE, WHITE);

    velDezenaKph->printarNumero(9);
    velUnidadeKph->printarNumero(9);

    velUnidadeMps = new Cerrado7Segmentos(300 + 30 * 2, 20, 2, display, BLUE, WHITE);
    velDezenaMps = new Cerrado7Segmentos(300, 20, 2, display, BLUE, WHITE);

    velDezenaMps->printarNumero(9);
    velUnidadeMps->printarNumero(9);

    velUnidadeMph = new Cerrado7Segmentos(300 + 30 * 2, 20 + 155, 2, display, BLUE, WHITE);
    velDezenaMph = new Cerrado7Segmentos(300, 20 + 155, 2, display, BLUE, WHITE);

    velDezenaMph->printarNumero(9);
    velUnidadeMph->printarNumero(9);
    */
}

void CerradoDisplay::atualizar(int velocidade)
{
    //kph
    int dezena = velocidade / 10, unidade = velocidade % 10;

    velDezenaKph->printarNumero(dezena);
    velUnidadeKph->printarNumero(unidade);

    //mps
    int aux = velocidade;
    velocidade = velocidade / 3.6;

    dezena = velocidade / 10;
    unidade = velocidade % 10;

    velDezenaMps->printarNumero(dezena);
    velUnidadeMps->printarNumero(unidade);

    //Mph
    velocidade = aux / 1.609;

    dezena = velocidade / 10;
    unidade = velocidade % 10;

    velDezenaMph->printarNumero(dezena);
    velUnidadeMph->printarNumero(unidade);
}

//TELA 2 (tempo)
void CerradoDisplay::telaTempo()
{
    display->setRotation(1);

    display->fillScreen(GREY);

    int x = 40, y = 35, n = 3;

    velUnidadeKph = new Cerrado7Segmentos(x + 30 * n, y, n, display, BLUE, WHITE);

    horaDezena = new Cerrado7Segmentos(x, y, n, display, GREEN, WHITE);
    horaUnidade = new Cerrado7Segmentos(x + 30 * n, y, n, display, GREEN, WHITE);
    minDezena = new Cerrado7Segmentos(x + 60 * n + 20 * n, y, n, display, GREEN, WHITE);
    minUnidade = new Cerrado7Segmentos(x + 90 * n + 20 * n, y, n, display, GREEN, WHITE);
    segDezena = new Cerrado7Segmentos(340, 195, 2, display, GREEN, WHITE);
    segUnidade = new Cerrado7Segmentos(340 + 30 * 2, 195, 2, display, GREEN, WHITE);

    display->fillRoundRect(10, 10, 460, 300, 15, GREEN);
    display->fillRoundRect(20, 20, 440, 180, 12, WHITE);

    display->fillRoundRect(320, 20, 140, 280, 12, WHITE);
    display->fillRect(308, 200, 12, 12, WHITE);
    display->fillCircle(307, 212, 12, GREEN);

    display->fillCircle(245, 80, 12, GREEN);
    display->fillCircle(245, 140, 12, GREEN);

    /*
    horaDezena->printarNumero(9);
    horaUnidade->printarNumero(9);
    minDezena->printarNumero(9);
    minUnidade->printarNumero(9);
    segDezena->printarNumero(9);
    segUnidade->printarNumero(9);
    */

    display->setFont(&FreeMonoBold24pt7b);
    display->setTextSize(1);
    display->setTextColor(WHITE);
    display->setCursor(30, 270);
    display->print("13/11/2018");
}

void CerradoDisplay::atualizar(int hora, int minuto, int segundo)
{
    int dezena = hora / 10, unidade = hora % 10;

    horaDezena->printarNumero(dezena);
    horaUnidade->printarNumero(unidade);

    dezena = minuto / 10;
    unidade = minuto % 10;

    minDezena->printarNumero(dezena);
    minUnidade->printarNumero(unidade);

    dezena = segundo / 10;
    unidade = segundo % 10;

    segDezena->printarNumero(dezena);
    segUnidade->printarNumero(unidade);
}

//TELA 3 (temperatura)
void CerradoDisplay::telaTemperatura()
{
    display->setRotation(1);

    display->fillScreen(GREY);

    //7 de borda
    display->fillRoundRect(10, 10, 460, 145, 12, RED);
    display->fillRoundRect(17, 17, 182, 100, 10, WHITE);
    display->fillRoundRect(17, 65, 446, 55, 10, WHITE);

    display->fillRect(199, 55, 10, 10, WHITE);
    display->fillCircle(199 + 10, 54, 10, RED);

    display->setFont(&FreeMonoBold12pt7b);
    display->setTextSize(1);
    display->setTextColor(WHITE);
    display->setCursor(205, 30);
    display->print("Temperatura");
    display->setCursor(345, 55);
    display->print("do MOTOR");

    display->setCursor(50, 140);
    display->print("Celsius");

    display->setCursor(235, 140);
    display->print("Kelvin");

    display->setCursor(362, 140);
    display->print("Fahren.");

    tempMotorCentenaC = new Cerrado7Segmentos(20, 20, 2, display, RED, WHITE);
    tempMotorDezenaC = new Cerrado7Segmentos(20 + 30 * 2, 20, 2, display, RED, WHITE);
    tempMotorUnidadeC = new Cerrado7Segmentos(20 + 60 * 2, 20, 2, display, RED, WHITE);

    tempMotorCentenaK = new Cerrado7Segmentos(245, 68, 1, display, RED, WHITE);
    tempMotorDezenaK = new Cerrado7Segmentos(245 + 30, 68, 1, display, RED, WHITE);
    tempMotorUnidadeK = new Cerrado7Segmentos(245 + 60, 68, 1, display, RED, WHITE);

    tempMotorCentenaF = new Cerrado7Segmentos(372, 68, 1, display, RED, WHITE);
    tempMotorDezenaF = new Cerrado7Segmentos(372 + 30, 68, 1, display, RED, WHITE);
    tempMotorUnidadeF = new Cerrado7Segmentos(372 + 60, 68, 1, display, RED, WHITE);

    display->fillRoundRect(10, 10 + 155, 460, 145, 12, RED);
    display->fillRoundRect(17, 17 + 155, 182, 100, 10, WHITE);
    display->fillRoundRect(17, 65 + 155, 446, 55, 10, WHITE);

    display->fillRect(199, 55 + 155, 10, 10, WHITE);
    display->fillCircle(199 + 10, 54 + 155, 10, RED);

    display->setFont(&FreeMonoBold12pt7b);
    display->setTextSize(1);
    display->setTextColor(WHITE);
    display->setCursor(205, 30 + 155);
    display->print("Temperatura");
    display->setCursor(365, 55 + 155);
    display->print("da CVT");

    display->setCursor(50, 140 + 155);
    display->print("Celsius");

    display->setCursor(235, 140 + 155);
    display->print("Kelvin");

    display->setCursor(362, 140 + 155);
    display->print("Fahren.");

    tempCvtCentenaC = new Cerrado7Segmentos(20, 20 + 155, 2, display, RED, WHITE);
    tempCvtDezenaC = new Cerrado7Segmentos(20 + 30 * 2, 20 + 155, 2, display, RED, WHITE);
    tempCvtUnidadeC = new Cerrado7Segmentos(20 + 60 * 2, 20 + 155, 2, display, RED, WHITE);

    tempCvtCentenaK = new Cerrado7Segmentos(245, 68 + 155, 1, display, RED, WHITE);
    tempCvtDezenaK = new Cerrado7Segmentos(245 + 30, 68 + 155, 1, display, RED, WHITE);
    tempCvtUnidadeK = new Cerrado7Segmentos(245 + 60, 68 + 155, 1, display, RED, WHITE);

    tempCvtCentenaF = new Cerrado7Segmentos(372, 68 + 155, 1, display, RED, WHITE);
    tempCvtDezenaF = new Cerrado7Segmentos(372 + 30, 68 + 155, 1, display, RED, WHITE);
    tempCvtUnidadeF = new Cerrado7Segmentos(372 + 60, 68 + 155, 1, display, RED, WHITE);
}

void CerradoDisplay::atualizar(int tempMotor, int tempCvt)
{
    //MOTOR
    int centena = tempMotor / 100;
    int dezena = (tempMotor % 100) / 10;
    int unidade = tempMotor % 10;

    tempMotorCentenaC->printarNumero(centena);
    tempMotorDezenaC->printarNumero(dezena);
    tempMotorUnidadeC->printarNumero(unidade);

    tempMotor -= 273;

    if (tempMotor < 0)
    {
        display->fillRoundRect(245 + 3 - 30, 68 + 22, 20, 4, 2, RED);
    }
    else
    {
        display->fillRoundRect(245 + 3 - 30, 68 + 22, 20, 4, 2, WHITE);
    }

    centena = abs(tempMotor) / 100;
    dezena = (abs(tempMotor) % 100) / 10;
    unidade = abs(tempMotor) % 10;

    tempMotorCentenaK->printarNumero(centena);
    tempMotorDezenaK->printarNumero(dezena);
    tempMotorUnidadeK->printarNumero(unidade);

    tempMotor += 273;

    tempMotor = (int)((double)tempMotor * 1.8) + 32;

    centena = tempMotor / 100;
    dezena = (tempMotor % 100) / 10;
    unidade = tempMotor % 10;

    tempMotorCentenaF->printarNumero(centena);
    tempMotorDezenaF->printarNumero(dezena);
    tempMotorUnidadeF->printarNumero(unidade);

    //CVT
    centena = tempCvt / 100;
    dezena = (tempCvt % 100) / 10;
    unidade = tempCvt % 10;

    tempCvtCentenaC->printarNumero(centena);
    tempCvtDezenaC->printarNumero(dezena);
    tempCvtUnidadeC->printarNumero(unidade);

    tempCvt -= 273;

    if (tempCvt < 0)
    {
        display->fillRoundRect(245 + 3 - 30, 68 + 22 + 155, 20, 4, 2, RED);
    }
    else
    {
        display->fillRoundRect(245 + 3 - 30, 68 + 22 + 155, 20, 4, 2, WHITE);
    }

    centena = abs(tempCvt) / 100;
    dezena = (abs(tempCvt) % 100) / 10;
    unidade = abs(tempCvt) % 10;

    tempCvtCentenaK->printarNumero(centena);
    tempCvtDezenaK->printarNumero(dezena);
    tempCvtUnidadeK->printarNumero(unidade);

    tempCvt += 273;

    tempCvt = (int)((double)tempCvt * 1.8) + 32;

    centena = tempCvt / 100;
    dezena = (tempCvt % 100) / 10;
    unidade = tempCvt % 10;

    tempCvtCentenaF->printarNumero(centena);
    tempCvtDezenaF->printarNumero(dezena);
    tempCvtUnidadeF->printarNumero(unidade);
}