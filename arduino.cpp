#define ports {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}
#include <SoftwareSerial.h>


String num_to_bin(int decimal)
{
 
    long long binNumber = 1;
    while(decimal > 0)
    {
        binNumber *= 10;
        binNumber += decimal % 2;
        decimal /= 2;
    }
    
    long long reversedNumber = 0;
    String result = "";

    while(binNumber > 0)
    {
        int lastDigit = binNumber % 10;
        reversedNumber *= 10;
        reversedNumber += lastDigit;
        binNumber /= 10;
    }
    
  while (reversedNumber > 0)
  {
    result += (char)((int)'0' + reversedNumber % 10);
    reversedNumber /= 10;
  }
  return result.substring(0, result.length());
  
}


void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int decimal = Serial.parseInt();
  String binNum = num_to_bin(decimal);

  Serial.print(binNum + '\n');

  for (int i = 2; i < 2 + binNum.length(); i++)
  {
      if (binNum[i - 2] == '1')
        digitalWrite(i, HIGH);
  }
  
  
}
