#include <iostream>
using namespace std;

int main()
{
    int ch;
    cout << "Введите целое число ";
    cin >> ch;
    if (ch%2==0)
    {
        cout << "Число " << ch << " - четное" << endl;
    }
    else
    {
        cout << "Число " << ch << " - нечетное" << endl;
    }
    return 0;
}