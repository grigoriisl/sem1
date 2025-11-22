#include <iostream>
#include <string>
#include <vector>

using namespace std;

void myStrCopy(const char* str, char* dest) 
{
    while (*str != '\0') 
    {
        *dest = *str;
        dest++;
        str++;
    }
    *dest = '\0';
}

int main() 
{
    const int maxdlina = 100;
    char stroka[maxdlina];
    char dest[maxdlina];
    cout << "Введите строку: ";
    cin.getline(stroka, maxdlina);
    myStrCopy(stroka, dest);
    cout << "Скопированная строка: " << dest << endl;
    return 0;
}