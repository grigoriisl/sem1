#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n=15, sch=0, posnaim=0, posnaib=0;
    double naib=0, naim=0, buf1=0, buf2=0;
    double v[n];
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
    if (posnaim-posnaib==1)
    {
        cout << "Произведение минимального и максимального элементов: " << naib*naim << endl; 
    }
    else
    {
        cout << "Максимальный элемент массива не предшествует минимальному элементу";
    }
    //cout << posnaib << posnaim;
    return 0;
}
