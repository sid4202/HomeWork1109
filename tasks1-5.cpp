#include<iostream>
#include "middle.h"

using namespace std;

void itc_num_print(int number)
{
    cout << number << endl;
}

int itc_len_num(long long number)
{
    if (number == 0)
        return 1;

    if (number < 0)
        number *= -1;
            
    int answer = 0;
    while(number > 0)
    {
        answer++;
        number /= 10;
    }
    return answer;
}

int itc_sum_num(long long number)
{
    if (number < 0)
        number *= -1;
    
    int answer = 0;
    while(number > 0)
    {
        answer += number % 10;
        number /= 10;
    }
    return answer;
}

long long itc_multi_num(long long number)
{
    if (number < 0)
        number *= -1;
    
    int answer = 1;
    while(number > 0)
    {
        answer *= number % 10;
        number /= 10;
    }
    return answer;
}

int itc_max_num(long long number)
{
    if (number < 0)
        number *= -1;
    
    int answer = number % 10;
    while(number > 0)
    {
        if (number % 10 > answer)
        {
            answer = number % 10;
        }
        number /= 10;
    }
    return answer;
}

