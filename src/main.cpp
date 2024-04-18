#include <Arduino.h>
#include "BioFlexIII.h"

int BioflexRX = 17;   // AMARILLO(Tx)
int BioflexTX = 19;   // VERDE(Rx)
int StartButton = 26; // BLANCO (boton Start)
int Power = 25;       // ROJO (+5v power) se usa como reset

void setup()
{
  Serial.begin(115200);
  BioFlexInit(BioflexRX, BioflexTX, StartButton, Power);
}

void loop()
{
  if (digitalRead(StartButton) == 0)
  {
    BioFlexPowerOn(true);
    digitalWrite(Power, 1); // Enciendo el BioFlex
    Serial.println("Enciendo Bioflex.");
    delay(100);

    // 1- muestro la version:
    Serial.print("Version: ");
    Serial.println(BioflexGetVersion());
    // 2- capturo huella:
    CaptureFingerprint();

    delay(1000);
    digitalWrite(Power, 0); // apago Bioflex.

    while (digitalRead(StartButton) == 0)
    {
      // espera solar el boton
    }
  }
}
