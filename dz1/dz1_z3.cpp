#include <iostream>
using namespace std;

int main()
{
    float temp;
    cout << "Введите температуру в градусах Цельсия: ";
    cin >> temp;
    cout << "Температура в Фаренгейтах:"<< (temp*9/5)+32 << endl;
    return 0;
}