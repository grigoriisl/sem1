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
    getline(cin, str);
    string result = "";
    for (char c : str) 
    {
        if (!isdigit(c)) 
        {
            result = result + c;
        }
    }
    
    cout << "Получившаяся строка: " << result << endl;
    
    return 0;
}

