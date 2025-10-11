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

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            v1[j][i]=v[i][j];
        }
    }
    cout << "Отраженный относительно главной диагонали массив:" << endl;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout << v1[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            v2[n-1-i][n-1-j]=v[j][i];
        }
    }
    cout << "Отраженный относительно побочной главной диагонали массив:" << endl;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout << v2[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            v3[i][j]=v[i][n-1-j];
        }
    }
    cout << "Отраженный относительно побочной главной диагонали массив:" << endl;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout << v3[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            v4[i][j]=v[n-1-i][j];
        }
    }
    cout << "Отраженный относительно побочной главной диагонали массив:" << endl;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout << v4[i][j] << " ";
        }
        cout << endl;
    }
    
    flag=0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (v1[i][j]==v2[i][j])
            {
                flag++;
            }
        }
    }
    if (flag==n*n)
    {
        cout << "Массивы v1 и v2 совпадают" << endl;
    }

    flag=0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (v1[i][j]==v3[i][j])
            {
                flag++;
            }
        }
    }
    if (flag==n*n)
    {
        cout << "Массивы v1 и v3 совпадают" << endl;
    }

    flag=0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (v1[i][j]==v4[i][j])
            {
                flag++;
            }
        }
    }
    if (flag==n*n)
    {
        cout << "Массивы v1 и v4 совпадают" << endl;
    }

    flag=0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (v2[i][j]==v3[i][j])
            {
                flag++;
            }
        }
    }
    if (flag==n*n)
    {
        cout << "Массивы v2 и v3 совпадают" << endl;
    }

    flag=0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (v2[i][j]==v4[i][j])
            {
                flag++;
            }
        }
    }
    if (flag==n*n)
    {
        cout << "Массивы v2 и v4 совпадают" << endl;
    }

    flag=0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (v3[i][j]==v4[i][j])
            {
                flag++;
            }
        }
    }
    if (flag==n*n)
    {
        cout << "Массивы v3 и v4 совпадают" << endl;
    }
    return 0;
}