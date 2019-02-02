#include <virtuabotixRTC.h>

// Determina os pinos ligados ao modulo myRTC(clock, data, rst)
virtuabotixRTC myRTC(6, 7, 8);

void setup() 
{ 
    Serial.begin(9600);

    pinMode(3,OUTPUT);
    // Informacoes iniciais de data e hora - USE 1X PARA AJUSTAR O RTC
    // (segundos, minutos, hora, dia da semana, dia do mes, mes, ano)
    //myRTC.setDS1302Time(00,27, 11, 6, 02, 02, 2019);
    // Apos setar as informacoes, remova ou comente a linha acima e carregue novamente o sketch
}

void loop() 
{
   myRTC.updateTime(); 
   if (myRTC.hours == 15 && myRTC.minutes == 0)  //HORA ON
   {
      digitalWrite(3,HIGH); //Escolha a porta que você ligou o LED
   }
   if (myRTC.hours == 15 && myRTC.minutes == 5) //HORA OFF
   {
      digitalWrite(3,LOW);
   }


// Imprime as informacoes no serial monitor SE QUISER MOSTRAR
   imprime_dia_da_semana(myRTC.dayofweek);
   Serial.print(" ");
   Serial.print(myRTC.dayofmonth);
   Serial.print("/");
   Serial.print(myRTC.month);
   Serial.print("/");
   Serial.print(myRTC.year);
   Serial.print(" ");
   if (myRTC.hours < 10)
   {
      Serial.print("0");
   }
   Serial.print(myRTC.hours);
   Serial.print(":");
   if (myRTC.minutes < 10)
   {
      Serial.print("0");
   }
   Serial.print(myRTC.minutes);
   Serial.print(":");
   if (myRTC.seconds < 10)
   {
      Serial.print("0");
   }
   Serial.println(myRTC.seconds);
   delay(1000);
}

void imprime_dia_da_semana(int dia)
{
   switch (dia)
   {
      case 1:
         Serial.print("Domingo");
      break;
      case 2:
         Serial.print("Segunda");
      break;
      case 3:
         Serial.print("Terca");
      break;
      case 4:
         Serial.print("Quarta");
      break;
      case 5:
         Serial.print("Quinta");
      break; 
      case 6: 
         Serial.print("Sexta");
      break;
      case 7:
         Serial.print("Sabado");
      break;
   }
}
