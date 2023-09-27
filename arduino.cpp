#define ports {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}


long long num_to_bin(int decimal)
{
 
    long long binNumber = 1;
    while(decimal > 0)
    {
        binNumber *= 10;
        binNumber += number % 2;
        number /= 2;
    }

    long long reversedNumber = 0;

    while(binNumber > 0)
    {
        int lastDigit = binNumber % 10;
        reversedNumber *= 10;
        reversedNumber += lastDigit;
        binNumber /= 10;
    }
    return reversedNumber / 10 * multiplier;
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
}

void loop() {
  for (int i = 0;i < 13
}
