#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
#include <string>
using namespace std;

int main() 
{
    string str;
    cout << "Введите строку: ";
    cin >> str;
    int sch = 0;
    for (int i = 0; i < str.length(); i++) 
    {
        bool unik = 1;
        for (int j = 0; j < i; j++) 
        {
            if (str[i] == str[j]) 
            {
                unik = 0;
                break;
            }
        }
        if (unik==1) 
        {
            sch++;
        }
    }
    cout << "Количество уникальных символов в строке: " << sch;
    return 0;
}