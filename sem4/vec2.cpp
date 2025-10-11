#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int n;
    int flag=0;
    cout << "Введите размер квадратной матрицы: ";
    cin >> n;
    int v[n][n];
    int v1[n][n];
    int v2[n][n];
    int v3[n][n];
    int v4[n][n];
    cout << "Введите " << n << " строк по " << n << " чисел:" << endl;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> v[i][j];
        }
    }
    int sum1=0, sum2=0, sum3=0, sum4=0;
    for (int i = 0; i < n; i++) 
    {
        sum1=sum1+v[i][i];
    }
    for (int i = 0; i < n; i++) 
    {
        sum2=sum2+v[n-1-i][n-1-i];
    }

    int flag3=0, sum33=0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            sum3=sum3+v[i][j];
        }
        if (flag3==0)
        {
            flag3=1;
            sum33==sum3;
        }
        else if (sum33!=sum3)
        {
            flag3==2;
        }
        else
        {
            sum33=sum3;
        }
    }

    int flag4=0, sum44=0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            sum4=sum4+v[i][j];
        }
        if (flag4==0)
        {
            flag4=1;
            sum44==sum4;
        }
        else if (sum44!=sum4)
        {
            flag4==2;
        }
        else
        {
            sum44=sum4;
        }
    }
    cout << "Без проверки набора чисел" << endl;
    if ((sum1==sum2) and (sum44==sum33) and (flag3==1) and (flag4==1))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}