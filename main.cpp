/*
Referência Gpio
https://randomnerdtutorials.com/esp8266-pinout-reference-gpios/

  _a_
 |   |
f|_g_|b
 |   |
e|_d_|c

Módulo display 7 Segmentos 4 digitos TM1637

https://platformio.org/lib/show/258/TM1637/installation
 
*/
#include <Arduino.h>
#include <TM1637Display.h>
 
const int CLK = D6; //Set the CLK pin connection to the display
const int DIO = D5; //Set the DIO pin connection to the display
 
int numCounter = 0;
 
TM1637Display teste_display(CLK, DIO); //set up the 4-Digit Display.
 
int dig_a = 16;  // a - d0
int dig_b = 5;  // b - d1
int dig_c = 4;  // c - d2
int dig_d = 0;  // d - d3
int dig_e = 2;  // e - d4
int dig_f = 14;  // f - d5
int dig_g = 12;  // g - d6
int dio = 13;  // dio - d7 para TM1637
int clk = 15;  // clk - d8  para TM1637
int tempo = 1000;  // delay

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(dig_a, OUTPUT);
  pinMode(dig_b, OUTPUT);
  pinMode(dig_c, OUTPUT);
  pinMode(dig_d, OUTPUT);
  pinMode(dig_e, OUTPUT);
  pinMode(dig_f, OUTPUT);
  pinMode(dig_g, OUTPUT);
  pinMode(dio, OUTPUT);
  pinMode(clk, OUTPUT);

  teste_display.setBrightness(0x0a); //set the diplay to maximum brightness

}
// *****************************************************
void display(int digito){
  switch (digito) {
    case 0:
      // statements
      digitalWrite(dig_a, LOW);
      digitalWrite(dig_b, LOW);
      digitalWrite(dig_c, LOW);
      digitalWrite(dig_d, LOW);
      digitalWrite(dig_e, LOW);
      digitalWrite(dig_f, LOW);
      digitalWrite(dig_g, HIGH);
      break;
    case 1:
      // statements
      digitalWrite(dig_a, HIGH);
      digitalWrite(dig_b, LOW);
      digitalWrite(dig_c, LOW);
      digitalWrite(dig_d, HIGH);
      digitalWrite(dig_e, HIGH);
      digitalWrite(dig_f, HIGH);
      digitalWrite(dig_g, HIGH);
      break;
    case 2:
      // statements
      digitalWrite(dig_a, LOW);
      digitalWrite(dig_b, LOW);
      digitalWrite(dig_c, HIGH);
      digitalWrite(dig_d, LOW);
      digitalWrite(dig_e, LOW);
      digitalWrite(dig_f, HIGH);
      digitalWrite(dig_g, LOW);
      break;
    case 3:
      // statements
      digitalWrite(dig_a, LOW);
      digitalWrite(dig_b, LOW);
      digitalWrite(dig_c, LOW);
      digitalWrite(dig_d, LOW);
      digitalWrite(dig_e, HIGH);
      digitalWrite(dig_f, HIGH);
      digitalWrite(dig_g, LOW);
      break;
    case 4:
      // statements
      digitalWrite(dig_a, HIGH);
      digitalWrite(dig_b, LOW);
      digitalWrite(dig_c, LOW);
      digitalWrite(dig_d, HIGH);
      digitalWrite(dig_e, HIGH);
      digitalWrite(dig_f, LOW);
      digitalWrite(dig_g, LOW);
      break;
    case 5:
      // statements
      digitalWrite(dig_a, LOW);
      digitalWrite(dig_b, HIGH);
      digitalWrite(dig_c, LOW);
      digitalWrite(dig_d, LOW);
      digitalWrite(dig_e, HIGH);
      digitalWrite(dig_f, LOW);
      digitalWrite(dig_g, LOW);
      break;
    case 6:
      // statements
      digitalWrite(dig_a, LOW);
      digitalWrite(dig_b, HIGH);
      digitalWrite(dig_c, LOW);
      digitalWrite(dig_d, LOW);
      digitalWrite(dig_e, LOW);
      digitalWrite(dig_f, LOW);
      digitalWrite(dig_g, LOW);
      break;
    case 7:
      // statements
      digitalWrite(dig_a, LOW);
      digitalWrite(dig_b, LOW);
      digitalWrite(dig_c, LOW);
      digitalWrite(dig_d, HIGH);
      digitalWrite(dig_e, HIGH);
      digitalWrite(dig_f, HIGH);
      digitalWrite(dig_g, HIGH);
      break;
    case 8:
      // statements
      digitalWrite(dig_a, LOW);
      digitalWrite(dig_b, LOW);
      digitalWrite(dig_c, LOW);
      digitalWrite(dig_d, LOW);
      digitalWrite(dig_e, LOW);
      digitalWrite(dig_f, LOW);
      digitalWrite(dig_g, LOW);
      break;
    case 9:
      // statements
      digitalWrite(dig_a, LOW);
      digitalWrite(dig_b, LOW);
      digitalWrite(dig_c, LOW);
      digitalWrite(dig_d, LOW);
      digitalWrite(dig_e, HIGH);
      digitalWrite(dig_f, LOW);
      digitalWrite(dig_g, LOW);
      break;
    default:
      // statements
      digitalWrite(dig_a, HIGH);
      digitalWrite(dig_b, HIGH);
      digitalWrite(dig_c, HIGH);
      digitalWrite(dig_d, HIGH);
      digitalWrite(dig_e, HIGH);
      digitalWrite(dig_f, HIGH);
      digitalWrite(dig_g, HIGH);
      break;
  }
}
/*
void ligar(int pinos) {
  if (pinos(0)){
    digitalWrite(pinos, LOW);
  }else{
    digitalWrite(pinos, HIGH);
  }
}

void desligar(int pino) {
    digitalWrite(pino, LOW);
    delay(tempo);
}*/

void piscar(int pino, int tempo){
  digitalWrite(pino, HIGH);
  delay(tempo / 2);
  digitalWrite(pino, LOW);
  delay(tempo / 2);
}

void contador(int tempo){
  for (int i = 0; i < 10; i++){
    display(i);
    delay(tempo);
    Serial.print("digito: %d");
    Serial.print(i);
    Serial.println("");
  }
}
void oscilador(int pino, int tempo){
  piscar(pino, tempo);
}
void modulo(){

  for(numCounter = 0; numCounter < 1000; numCounter++) //Iterate numCounter
  {
    teste_display.showNumberDec(numCounter); //Display the numCounter value;
    delay(1000);
  }
}

// *****************************************************
void loop() {
  // put your main code here, to run repeatedly:
  contador(1000);
  // oscilador(clk, 1000);
  modulo;

}