#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

bool provgl(char c) 
{
    c = tolower(c); 
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

bool provsogl(char c) 
{
    c = tolower(c); 
    return (c >= 'a' && c <= 'z') && (!provgl(c));
}

int main() 
{
    string str;
    cout << "Введите строку: ";
    getline(cin, str); 
    int glasn = 0,sogl=0;
    for (char c : str)
    {
        if (provgl(c)==true)
        {
            glasn++;
        } 
        else if (provsogl(c)==true) 
        {
            sogl++;
        }
    }
    cout << "Количество гласных: " << glasn << endl;
    cout << "Количество согласных: " << sogl << endl;
    return 0;
}