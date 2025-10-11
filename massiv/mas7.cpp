#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n=15, sch=0, posnaim=0, posnaib=0;
    int naib=0, naim=0, buf1=0, buf2=0;
    int v[n];
    for (int i=0;i<n;i++)
    {
        cout << "Введите элемент массива номер " << i+1 << ": ";
        cin >>  v[i];
    }
    naib=v[0];
    naim=v[0];
    posnaib=0;
    posnaim=0;
    for (int k=0;k<n;k++)
    {
       if (v[k]>naib)
       {
        posnaib=k;
        naib=v[k];
       }
       if (v[k]< naim)
       {
        posnaim=k;
        naim=v[k];
       }
    }
    if (naib==0 or naim==0)
    {
        for (int i=0;i<posnaim;i++)
        {
            v[i]=0;
        }
        cout << "Полученный массив: ";
        for (int i=0;i<n;i++)
        {
            cout << v[i] << " ";
        }
    }
    else
    {
        cout << "Условие не выполнено";
    }
    return 0;
}
