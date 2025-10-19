#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

int main() { 
    int sch = 0;
    string str2 = "";
    string str1 = "";
    cout << "Введите строку 1: ";
    cin >> str1;
    cout << "Введите строку 2: ";
    cin >> str2;
    bool flag = 0;
    for(int i = 0; i < str1.length() ; i++)
    {
        for(int j = 0; j < str2.length(); j++)
        {
            if(str1[i] == str2[j]) 
            {
                sch++;
            } 
            else 
            { 
                continue;
            }
        }
        if(sch >= 1)
        {
            sch = 0;
            continue;
        } 
        else 
        {
            cout << "Нет";
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        cout << "Да";
    }
    return 0; 
}
