#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
#include <string>
using namespace std;

int main() {
    string str;
    string itog = "";
    int sch = 1;
    char kusok = str[0];
    cout << "Введите не пустую строку: ";
    cin >> str;
    for (int i = 1; i < str.length(); i++) 
    {
        if (str[i] == kusok) 
        {
            sch++;
        } 
        else 
        {
            itog =itog + kusok + to_string(sch);
            kusok = str[i];
            sch = 1;
        }
    }
    itog = itog + kusok + to_string(sch);
    cout << "Полученная строка: " << itog << endl;
    return 0;
}