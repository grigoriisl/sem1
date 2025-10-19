#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

bool unik(const char* str, int start, int k) 
{
    for (int i = start; i < start + k - 1; i++) 
    {
        for (int j = i + 1; j < start + k; j++) 
        {
            if (str[i] == str[j]) 
            {
                return 0; 
            }
        }
    }
    return true;
}

vector<string> poisk(const string& s, int k) 
{
    vector<string> result;
    int n = s.length();
    const char* charArray = s.c_str();
    for (int i = 0; i <= n - k; i++) 
    {
        if (unik(charArray, i, k)) 
        {
            result.push_back(s.substr(i, k));
        }
    }
    
    return result;
}

int main() 
{
    string str;
    int k;
    cout << "Введите строку: ";
    cin >> str;
    cout << "Введите k: ";
    cin >> k;
    vector<string> unik = poisk(str, k);
    cout << "Подстроки длины " << k << " с уникальными символами:" << endl;
    for (const string& substr : unik) 
    {
        cout << substr << endl;
    }
    return 0;
}