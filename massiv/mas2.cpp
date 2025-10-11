#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n=0, sch=0, naib=0, flag=0;
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
        if (v[k]%2==0)
        {
            sch++;
        }
        else if (flag==0)
        {
            flag=1;
            naib=v[k];
        }
        else
        {
            if (v[k]>naib)
            {
                naib=v[k];
            }
        }
    }
    cout << "Количество четных элементов: " << sch << endl;
    if (flag==0)
    {
        cout << "Нечетные числа отсутствуют";
    }
    cout << "Наибольшее нечетное число: " << naib;
    return 0;
}