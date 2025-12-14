#include <iostream>
using namespace std;

int main()
{
    int v;
    cout << "Введите возраст: ";
    cin >> v;
    if (v<18)
    {
        cout << "Возраст меньше 18";
    }
    else if(v>=18 and v<=60)
    {
        cout << "Возраст от 18 до 60";
    }
    else
    {
        cout << "Возраст старше 60";
    }
    return 0;
}