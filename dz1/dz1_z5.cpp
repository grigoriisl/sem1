#include <iostream>
using namespace std;

int main()
{
    int ch;
    cout << "Введите целое число: ";
    cin >> ch;
    if (ch%3==0 and ch%5==0)
    {
        cout << "Число " << ch << " делится и на 3, и на 5" << endl;
    }
    else if(ch%3==0)
    {
        cout << "Число " << ch << " делится на 3" << endl;
    }
    else if(ch%5==0)
    {
        cout << "Число " << ch << " делится на 5" << endl;
    }
    else 
    {
        cout << "Число " << ch << " не делится ни на 3, ни на 5" << endl;

    }
    return 0;
}