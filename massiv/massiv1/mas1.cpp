#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n=0, sch=0;
    cout << "Введите количество элементов массива: ";
    cin >> n;
    int v[n];
    for (int i=0;i<n;i++)
    {
        cout << "Введите элемент массива номер " << i << ": ";
        cin >>  v[i];
    }
    for (int k=0;k<n;k++)
    {
        if (v[k]>(pow(2, k+1)))
        {
            sch++;
        }
    }
    cout << "Количество подходящих элементов: " << sch;
    return 0;
}