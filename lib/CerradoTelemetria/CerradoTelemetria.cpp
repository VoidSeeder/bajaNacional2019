#include "CerradoTelemetria.h"

String completar (String str, int x) {
  while (str.length() < x) {
    str = "0" + str;
  }
  return str;
}

String binToHex (String str) {
  String retorno = "";
  int i = 0;
  int tamStr = str.length();

  while (i + 4 <= tamStr) {
    if (str.substring(i, i + 4) == "0000") {
      retorno.concat("0");
    }
    if (str.substring(i, i + 4) == "0001") {
      retorno.concat("1");
    }
    if (str.substring(i, i + 4) == "0010") {
      retorno.concat("2");
    }
    if (str.substring(i, i + 4) == "0011") {
      retorno.concat("3");
    }
    if (str.substring(i, i + 4) == "0100") {
      retorno.concat("4");
    }
    if (str.substring(i, i + 4) == "0101") {
      retorno.concat("5");
    }
    if (str.substring(i, i + 4) == "0110") {
      retorno.concat("6");
    }
    if (str.substring(i, i + 4) == "0111") {
      retorno.concat("7");
    }
    if (str.substring(i, i + 4) == "1000") {
      retorno.concat("8");
    }
    if (str.substring(i, i + 4) == "1001") {
      retorno.concat("9");
    }
    if (str.substring(i, i + 4) == "1010") {
      retorno.concat("A");
    }
    if (str.substring(i, i + 4) == "1011") {
      retorno.concat("B");
    }
    if (str.substring(i, i + 4) == "1100") {
      retorno.concat("C");
    }
    if (str.substring(i, i + 4) == "1101") {
      retorno.concat("D");
    }
    if (str.substring(i, i + 4) == "1110") {
      retorno.concat("E");
    }
    if (str.substring(i, i + 4) == "1111") {
      retorno.concat("F");
    }
    i += 4;
  }
  return retorno;
}

String hexToBin (String str) {
  String binBase = "";
  int i = 0;

  while (i < str.length()) {
    switch (str.charAt(i)) {
      case '0': binBase.concat("0000"); break;
      case '1': binBase.concat("0001"); break;
      case '2': binBase.concat("0010"); break;
      case '3': binBase.concat("0011"); break;
      case '4': binBase.concat("0100"); break;
      case '5': binBase.concat("0101"); break;
      case '6': binBase.concat("0110"); break;
      case '7': binBase.concat("0111"); break;
      case '8': binBase.concat("1000"); break;
      case '9': binBase.concat("1001"); break;
      case 'A': binBase.concat("1010"); break;
      case 'B': binBase.concat("1011"); break;
      case 'C': binBase.concat("1100"); break;
      case 'D': binBase.concat("1101"); break;
      case 'E': binBase.concat("1110"); break;
      case 'F': binBase.concat("1111"); break;
      default: break;
    }
    i++;
  }
  return binBase;
}

int binToDec (String str) {
  int x = 0;

  for (int i = 0; i < str.length(); i++) {
    if (str.charAt(i) == '1') {
      x += 1;
    }

    x = x * 2;
  }

  return  x / 2;
}

String calcularResto (String str, String chave) {
  String aux;
  
  for (int j=0; j<(chave.length()-1); j++)
 {
  str = str + "0";
 }

  while (str.length() >= chave.length()) {
    if (str.charAt(0) == '1') {
      for (int i = 0; i < chave.length(); i++) {
        if (str.charAt(i) == chave.charAt(i)) {
          aux = str.substring(i+1);
          str =str.substring(0, i) + "0" + aux;
        } else {
          aux = str.substring(i+1);
          str = str.substring(0, i)+ "1" + aux;
        }
      }
    } else {
      str.remove(0, 1);
    }
  }

  return str;
}

void CerradoTelemetria::registrar(int temp1, int temp2, int velocidade, int voltage, bool comb){
    String TEMP1 =  String(temp1, BIN);
    String TEMP2 =  String(temp2, BIN);
    String VELOCIDADE =  String(velocidade, BIN);
    String VOLTAGE = String(voltage, BIN);
    String COMB = String(comb, BIN);

    TEMP1 = completar(TEMP1, 8);
    TEMP2 = completar(TEMP2, 8);
    VELOCIDADE = completar(VELOCIDADE, 8);
    VOLTAGE = completar(VOLTAGE, 8);
    COMB = completar(COMB, 8);

    this->message = TEMP1 + TEMP2 + VELOCIDADE + VOLTAGE + COMB;

    this->message.concat(calcularResto(this->message, this->chave));

    this->message = binToHex(this->message);
}

void CerradoTelemetria::enviar(){
    this->mySerial->print(this->message);
}

CerradoTelemetria::CerradoTelemetria (SoftwareSerial* mySerial, String chave){
  this->mySerial = mySerial;
  this->chave = chave;
}