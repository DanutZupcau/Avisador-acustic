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
const int ldr1 = A1;
const int ldr2 = A2;

int valLdr0;                 // guardar valor del ldr  
int valLdr1;
int valLdr2;
int rapidesa;                    // freqüència del xiulet


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
  
  valLdr1 = analogRead(ldr1);

  valLdr2 = analogRead(ldr2);
  Serial.println(valLdr2);
  
  if (valLdr0 < 400){
  rapidesa=valLdr0;
  rapidesa=map(rapidesa, 200, 1023, 200, 1500);
  
  tone(xiulet, 500, rapidesa);   // xiulet de durada 100ms
  delay(rapidesa+100);            // esperar xiulet + silenci 
  }


  if (valLdr1 < 400){
  rapidesa=valLdr1;
  rapidesa=map(rapidesa, 100, 1023, 20, 700);
  
  tone(xiulet, 750, rapidesa);   // xiulet de durada 100ms
  delay(rapidesa+100);            // esperar xiulet + silenci 
  }



    if (valLdr2 < 400){
  rapidesa=valLdr2;
  rapidesa=map(rapidesa, 100, 1023, 20, 600);
  
  tone(xiulet, 1000, rapidesa);   // xiulet de durada 100ms
  delay(rapidesa+100);            // esperar xiulet + silenci 
  }


  



}

//********** Funcions *************************************************************
