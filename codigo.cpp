#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "sua autenticação blynk";
char ssid[] = "nome da rede";
char pass[] = "senha da rede";

//definindo quais pinos serão utilizados
const int nivel = 16;
const int sensor4 = 4;
const int sensor3 = 13;
const int sensor2 = 12;
const int sensor1 = 14;
const int sensor0 = 5;

BlynkTimer timer;
void checkPhysicalButton();

//definindo status dos pinos
int nivel_State = LOW;
int sensor4_State = HIGH;
int sensor3_State = HIGH;
int sensor2_State = HIGH;
int sensor1_State = HIGH;
int sensor0_State = HIGH;


BLYNK_CONNECTED() {
Blynk.syncVirtual(V4);
}
BLYNK_WRITE(V4) {
  nivel_State = param.asInt();
  digitalWrite(nivel, sensor4_State);
  digitalWrite(nivel, sensor3_State);
  digitalWrite(nivel, sensor2_State);
  digitalWrite(nivel, sensor1_State);
  digitalWrite(nivel, sensor0_State);
}
void checkPhysicalButton()
{
  if (digitalRead(sensor4) == LOW) {
      nivel_State = !nivel_State;
      Blynk.virtualWrite(V4, HIGH);
       
       }
    else{
       Blynk.virtualWrite(V4, LOW);
       Blynk.notify("SENSOR DO LADÃO ACIONADO!!!");
    } 

  if (digitalRead(sensor3) == LOW) {
      nivel_State = !nivel_State;
      Blynk.virtualWrite(V3, HIGH);
       }
    else{
       Blynk.virtualWrite(V3, LOW);
    }   

    if (digitalRead(sensor2) == LOW) {
      nivel_State = !nivel_State;
      Blynk.virtualWrite(V2, HIGH);
       }
    else{
       Blynk.virtualWrite(V2, LOW);
    }   

    if (digitalRead(sensor1) == LOW) {
      nivel_State = !nivel_State;
      Blynk.virtualWrite(V1, HIGH);
       }
    else{
       Blynk.virtualWrite(V1, LOW);
    }   

     if (digitalRead(sensor0) == LOW) {
      nivel_State = !nivel_State;
      Blynk.virtualWrite(V0, HIGH);
       }
    else{
       Blynk.virtualWrite(V0, LOW);
    }  
}

void setup()
{
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  pinMode(nivel, OUTPUT);
  pinMode(sensor4, INPUT_PULLUP);
   pinMode(sensor3, INPUT_PULLUP);
   pinMode(sensor2, INPUT_PULLUP);
   pinMode(sensor1, INPUT_PULLUP);
   pinMode(sensor0, INPUT_PULLUP);
  digitalWrite(nivel, nivel_State);

  timer.setInterval(100L, checkPhysicalButton);
}

void loop()
{
  Blynk.run();
  timer.run();
}