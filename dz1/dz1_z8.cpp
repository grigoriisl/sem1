#include <iostream>
#include <string>
using namespace std;

int main()
{
    char s;
    int dl, sch=0;
    cout << "Введите длину строки: ";
    cin >> dl;
    cout << "Введите строку по символам: ";
    for (int i=0; i<dl;i++)
    {
        cin >> s;
        if ((s=='A') || (s=='E') || (s=='I') || (s=='O') || (s=='U') || (s=='Y'))
        {
            sch++;
        }
    }
    cout << "Количество гласных: " << sch; 
    return 0;
}