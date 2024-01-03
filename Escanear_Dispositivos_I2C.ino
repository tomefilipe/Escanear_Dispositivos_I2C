
#include <Wire.h>

byte Erro, Endereco;
int NDispositivos;

void setup() 
{
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Escaneando I2C");
}
 
void loop() 
{
  Serial.println("Escaneando I2C...");
  NDispositivos = 0;
  for(Endereco = 1; Endereco < 127; Endereco++ ) 
  {
    Wire.beginTransmission(Endereco);
    Erro = Wire.endTransmission();
    if (Erro == 0) 
    {
      Serial.print("I2C device found at Endereco 0x");
      if (Endereco<16) 
      {
        Serial.print("0");
      }
      Serial.println(Endereco,HEX);
      NDispositivos++;
    }
    else if (Erro==4) 
    {
      Serial.print("Unknow Erro at Endereco 0x");
      if (Endereco<16) 
      {
        Serial.print("0");
      }
      Serial.println(Endereco,HEX);
    }    
  }

  if (NDispositivos == 0) 
  {
    Serial.println("No I2C devices found\n");
  }
  else 
  {
    Serial.println("done\n");
  }
  delay(5000);          
}
