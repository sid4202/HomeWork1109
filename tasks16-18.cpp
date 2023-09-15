#include <iostream>
#include "middle.h"

int itc_rev_oct_num(long long number)
{
    long long pOf8 = 1;
    int decimalNumber = 0;
    while (number > 0)
    {
        decimalNumber += (number % 10) * pOf8;
        number /= 10;
        pOf8 *= 8;
    }
    return decimalNumber;
}

int itc_covert_num(long long number, int ss)
{
    long long ssNumber = 1;
    while(number > 0)
    {
        ssNumber *= 10;
        ssNumber += number % ss;
        number /= ss;
    }

    long long reversedNumber = 0;

    while(ssNumber > 0)
    {
        int lastDigit = ssNumber % 10;
        reversedNumber *= 10;
        reversedNumber += lastDigit;
        ssNumber /= 10;
    }
    return reversedNumber / 10;
}

int itc_rev_covert_num(long long number, int ss)
{
    long long pOfss = 1;
    int decimalNumber = 0;
    while (number > 0)
    {
        decimalNumber += (number % 10) * pOfss;
        number /= 10;
        pOfss *= ss;
    }
    return decimalNumber;
}