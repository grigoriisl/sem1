#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
#include <string>
#include <cctype>
using namespace std;

bool proverka(const string& str) 
{
    int left = 0;
    int right = str.length() - 1;
    while (left < right) 
    {
        while (left < right && !isalpha(str[left])) 
        {
            left++;
        }
        while (left < right && !isalpha(str[right])) 
        {
            right--;
        }
        if (tolower(str[left]) != tolower(str[right])) 
        {
            return false;
        }
        
        left++;
        right--;
    }
    
    return true;
}

int main() \
{
    string str;
    cout << "Введите строку: ";
    getline(cin, str);
    if (proverka(str)) 
    {
        cout << "Строка является палиндромом" << endl;
    } else {
        cout << "Строка не является палиндромом" << endl;
    }
    
    return 0;
}