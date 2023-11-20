#include <iostream>
#include <string>

using namespace std;
string itc_slice_str(string str, int start, int end)
{
    long long len = str.size();
    string answer;

    if (start > end)
    {
        return str;
    }

    if (end > len - 1)
    {
        end = len - 1;
    }

    for (int i = start; i <= end; i++)
    {
        answer += str[i];
    }

    return answer;
}



string reversed_str(string str)
{
    string rev_str = "";

    for (int i = str.size() - 1; i >= 0; i--)
    {
        rev_str += str[i];
    }
    return rev_str;
}

string add_to_numbers(string str1, string str2)
{
    string result = "";

    str1 = reversed_str(str1);
    str2 = reversed_str(str2);
    int sum;

    int carry = 0;
    for (int i = 0; i < str1.size(); i++)
    {

        if (i <= str2.size() - 1)
            sum = (str1[i] - '0') + (str2[i] - '0');
        else
            sum = (str1[i] - '0');

        sum += carry;

        result += sum % 10 + '0';
        carry = sum / 10;
    }

    if (carry > 0)
    {
        result += carry + '0';
    }

    return reversed_str(result);
}

bool more_equal(string a, string b){
    if (a.size() > b.size())
        return true;

    if (a.size() < b.size())
        return false;

    for (int i = 0; i < a.size(); i++){
        if (a[i] < b[i])
            return false;
    }

    return true;
}

string substract_two_numbers(string str1, string str2) {
    string result = "";

    str1 = reversed_str(str1);
    str2 = reversed_str(str2);
    int substraction;

    int last_borrow;
    for (int i = 0; i < str1.size(); i++) {
        int first_number_digit = str1[i] - '0';
        if (i <= str2.size() - 1)
            if (first_number_digit < str2[i] - '0') {
                int index_of_borrow;
                for (int j = i + 1; j < str1.size(); j++) {
                    if (str1[j] > '0') {
                        str1[j] = (str1[j] - '0' - 1) + '0';
                        break;
                    } else {
                        str1[j] = 9 + '0';
                    }
                }
                substraction = (first_number_digit + 10) - (str2[i] - '0');
            } else {
                substraction = first_number_digit - (str2[i] - '0');
            }
        else
            substraction = (str1[i] - '0');

        result += substraction + '0';

    }

    int start_of_number = 0;
    result = reversed_str(result);
    while (result[start_of_number] == '0') {
        start_of_number++;
    }

    return itc_slice_str(result, start_of_number, str1.size() - 1);
}


string itc_minus(string a, string b)
{
    if (a[0] == '-' and b[0] != '-')
    {
        string first_num = itc_slice_str(a, 1, a.size() - 1);
        if (a.size() - 1 >= b.size())
        {
            return '-' + add_to_numbers(first_num, b);
        } else {
            return '-' + add_to_numbers(b, first_num);
        }
    } else if(a[0] == '-' and b[0] == '-') {
        string first_num = itc_slice_str(a, 1, a.size() - 1);
        string second_num = itc_slice_str(b, 1, b.size() - 1);

        if (more_equal(second_num, first_num))
            return substract_two_numbers(second_num, first_num);
        else
            return '-' + substract_two_numbers(first_num, second_num);
    } else if(a[0] != '-' and b[0] == '-') {
        string second_num = itc_slice_str(b, 1, b.size() - 1);
        if (a.size() >= b.size() - 1)
        {
            return add_to_numbers(a, second_num);
        } else {
            return add_to_numbers(second_num, a);
        }
    } else {
        if(more_equal(a, b))
            return substract_two_numbers(a, b);
        else
            return '-' + substract_two_numbers(b, a);
    }
}

string itc_plus(string a, string b)
{
    if (a[0] != '-' and b[0] != '-')
    {
        if (a.size() >= b.size())
        {
            return add_to_numbers(a, b);
        } else {
            return add_to_numbers(b, a);
        }
    } else if(a[0] == '-' and b[0] == '-')
    {
        if (a.size() >= b.size())
        {
            return '-' + add_to_numbers(a, b);
        } else {
            return '-' + add_to_numbers(b, a);
        }
    } else if(a[0] == '-' and b[0] != '-')
    {
        return itc_minus(b, itc_slice_str(a, 1, a.size() - 1));
    } else
        return itc_minus(a, itc_slice_str(b, 1, b.size() - 1));
}

int main() {
    string a, b;
    char operation;
    cin >> a >> operation >>  b;
    switch(operation)
    {
        case '+':
            cout << itc_plus(a, b) << endl;
            break;
        case '-':
            cout << itc_minus(a, b) << endl;
            break;
    }
}

