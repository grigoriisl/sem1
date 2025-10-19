#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

int main() 
{ 
    string str;
    vector<string> itog;
    string slovo;
    cout << "Введите строку: ";
    getline(cin, str);
    stringstream ss(str);
    while(ss >> slovo)
    {
        std::reverse(slovo.begin(), slovo.end());
        itog.push_back(slovo);
    }
    cout << "Полученная строка: ";
    for(const auto& kusok : itog)
    {
            cout << kusok << " ";
    }
    return 0; 
}