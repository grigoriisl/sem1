#include <iostream>
#include <string>
#include <vector>

using namespace std;

void myStrCat(const char* str, char* dest) 
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
    cout << "Введите строку номер 1: ";
    cin.getline(stroka, maxdlina);
    cout << "Введите строку номер 2: ";
    cin.getline(stroka, maxdlina);
    myStrCat(stroka, dest);
    cout << "Скопированная строка: " << dest << endl;
    return 0;
}