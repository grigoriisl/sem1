#include <iostream>
using namespace std;

int main()
{
    float c=0;
    cout << "Введите число: ";
    cin >> c;
    if (c>0)
    {
        cout << "Число " << c << " является положительным";
    }
    else if (c<0)
    {
        cout << "Число " << c << " является отприцательным";
    }
    else
    {
        cout << "Число " << c << " является нулём";
    }
    return 0;
}