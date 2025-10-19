#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<double> num(10);
    double x;
    cout << "Введите элементы вектора в строку: ";
    for (int i=0; i<10; i++)
    {
        cin >> x;
        num[i]=x;
    }
    cout << endl << "Умноженные на 2 значения: " << endl;
    for_each(num.begin(),num.end(), [](double num){
        cout << num*2 << " ";
    });
    return 0;
}