#include<iostream>
#include "middle.h"

using namespace std;

int itc_second_max_num(long long number)
{
    if(number / 10 == 0)
        return -1;

    int max_max = -1, max_second = -1;
    while(number > 0)
    {
        if (number % 10 > max_max)
        {
            max_second = max_max;
            max_max = number % 10;
        }
        else if (number % 10 > max_second)
        {
            max_second = number % 10;
        }

        number /= 10;
    }
    return max_second;
}

int itc_second_simple_max_num(long long number)
{
    if(number / 10 == 0)
        return -1;

    int max_max = -1, max_second = -1;
    while(number > 0)
    {
        if (number % 10 > max_max)
        {
            max_second = max_max;
            max_max = number % 10;
        }
        else if (number % 10 > max_second)
        {
            max_second = number % 10;
        }

        number /= 10;
    }
    if(max_second == max_max)
        return -1;
    else
        return max_second;
}

long long itc_bin_num(long long number)
{
    long long binNumber = 1;
    while(number > 0)
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
    return reversedNumber / 10;
}

long long itc_oct_num(long long number)
{
    long long octNumber = 1;
    while(number > 0)
    {
        octNumber *= 10;
        octNumber += number % 8;
        number /= 8;
    }

    long long reversedNumber = 0;

    while(octNumber > 0)
    {
        int lastDigit = octNumber % 10;
        reversedNumber *= 10;
        reversedNumber += lastDigit;
        octNumber /= 10;
    }
    return reversedNumber / 10;
}

int itc_rev_bin_num(long long number)
{
    long long pOf2 = 1;
    int decimalNumber = 0;
    while (number > 0)
    {
        decimalNumber += (number % 10) * pOf2;
        number /= 10;
        pOf2 *= 2;
    }
    return decimalNumber;
}