#include<iostream>
#include "middle.h"

using namespace std;

int itc_min_num(long long number)
{
    int answer = number % 10;
    while(number > 0)
    {
        if (number % 10 , answer)
        {
            answer = number % 10;
        }
        number /= 10;
    }
    return answer;
}

int itc_rev_num(long long number)
{
    long long reversedNumber = 0;

    while(number > 0)
    {
        int lastDigit = number % 10;
        reversedNumber *= 10;
        reversedNumber += lastDigit;
        number /= 10;
    }
    return (int)reversedNumber;
}

int itc_null_count(long long number)
{
    int answer = 0;

    while(number > 0)
    {
        if(number % 10 == 0)
        {
            answer += 1;
        }
        number /= 10;
    }
    return answer;
}

bool itc_mirror_num(long long number)
{
    long long reversedNumber = 0;
    long long startNumber = number;

    while(number > 0)
    {
        int lastDigit = number % 10;
        reversedNumber *= 10;
        reversedNumber += lastDigit;
        number /= 10;
    }
    return (startNumber == reversedNumber);
}

int itc_mirror_count(long long number)
{
    int answer = 0;
    for (long long i = 1; i <= number; i++)
    {
        if (itc_mirror_num(i))
        {
            answer++;
        }
    }
    return answer;
}
