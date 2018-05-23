/**********************************************************************************
**                                                                               **
**                              Avisador Acústic                                 **
**                                                                               **
**                                                                               **
**********************************************************************************/

//********** Includes *************************************************************

//********** Variables ************************************************************
const int xiulet = 9;        // donar nom al pin 9 de l’Arduino
const int ldr0 = A0;         // donar nom al pin A0 de l’Arduino

int valLdr0;                 // guardar valor del ldr  
int freq;                    // freqüència del xiulet

//********** Setup ****************************************************************
void setup()
{
  pinMode(xiulet, OUTPUT);     // definir el pin 9 com una sortida
  Serial.begin(9600);
}

//********** Loop *****************************************************************
void loop()
{
  valLdr0 = analogRead(ldr0);   // llegir valor ldr
  
  
  freq=valLdr0;
  Serial.println(valLdr0);
  freq=map(freq, 0, 1023, 0, 2000);
  
  tone(xiulet, freq, 100);   // xiulet de durada 100ms
  delay(100+100);            // esperar xiulet + silenci
}

//********** Funcions *************************************************************

