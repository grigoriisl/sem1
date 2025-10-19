#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <random>
#include <cmath>
#include <cctype>
using namespace std;

int main() 
{ 
    cout << "Введите строку: ";
    string str;
    getline(cin, str);
    for(size_t i=0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }
    str[0] = toupper(str[0]);
    for(size_t i=0; i < str.length(); i++)
    {
        if((str[i] == '!') or (str[i] == '.') or (str[i] == '?'))
        {
            if (i+2 < str.length())
            {
                str[i+2] = toupper(str[i+2]);
            }
        }
    }
    cout << "Получившаяся строка: ";
    cout << str;
    return 0; 
}
