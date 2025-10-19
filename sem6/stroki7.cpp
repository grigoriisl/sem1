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
    char elem = str[0];
    cout << "Введите не пустую строку: ";
    cin >> str;
    for (int i = 1; i < str.length(); i++) 
    {
        if (str[i] == elem) 
        {
            sch++;
        } 
        else 
        {
            itog += elem + to_string(sch);
            elem = str[i];
            sch = 1;
        }
    }
    itog = itog + elem + to_string(sch);
    cout << "Полученная строка: " << itog << endl;
    return 0;
}