#include <iostream>
#include <string>
#include <vector>

using namespace std;

int myStrLen(const char* str) 
{
    if (str == nullptr) 
    {
        return 0;
    }
    const char* ptr = str;
    while (*ptr != '\0') 
    {
        ptr++;
    }
    return ptr - str;
}

int main() 
{
    const int maxdlina = 100;
    char stroka[maxdlina];
    cout << "Введите строку: ";
    cin.getline(stroka, maxdlina);
    cout << "Длина строки: " << myStrLen(stroka) << endl;
    return 0;
}