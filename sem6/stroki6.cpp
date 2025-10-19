#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
#include <string>
#include <cctype>
using namespace std;

string salad(const string& text, int sdvig) 
{
    string result = "";
    sdvig = sdvig % 26;
    if (sdvig < 0) 
    {
        sdvig = sdvig + 26;
    }
    for (char c : text) 
    {
        if (isupper(c)) 
        {
            result += (c - 'A' + sdvig) % 26 + 'A';
        } 
        else if (islower(c)) 
        {
            result += (c - 'a' + sdvig) % 26 + 'a';
        } 
        else 
        {
            result = result + c;
        }
    }
    return result;
}

int main() 
{
    string str;
    int sdvig;
    cout << "Введите текст: ";
    getline(cin, str);
    cout << "Введите Сдвиг-число: ";
    cin >> sdvig;
    string itog = salad(str, sdvig);
    cout << "Зашифрованный текст: " << itog << endl;
    return 0;
}