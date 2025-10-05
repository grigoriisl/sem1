#include <iostream>
using namespace std;
int vectornoe(int x1, int y1, int x2, int y2)
{
    int res = x1*y2 - x2*y1;
    if (res >= 0) 
    {
        return 1;
    }
    return 0;
}

int main() 
{
    int n = 0;
    cout << "Введите количество вершин выпуклого многоугольника: ";
    cin >> n;
    int v[2][n+1];
    char k = 65;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 0)
            {
                cout << "Введите координату X точки " << k << ": ";
            }
            else {
                cout << "Введите координату Y точки " << k << ": ";
                k++;
            }
            cin >> v[j][i];
        }
    }
    v[0][n] = v[0][0];
    v[1][n] = v[1][0];
    int xnach;
    int ynach;
    cout << "Введите координату X точки:";
    cin >> xnach;
    cout << "Введите координаты Y точки:";
    cin >> ynach;
    int dxRay = 10000 - xnach;
    int dyRay = 10000 - ynach;
    int dx1;
    int dx2; 
    int dy1;
    int dy2;
    int sch = 0;
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 0){
                dx1 = v[j][i] - xnach;
                dx2 = v[j][i+1] - ynach;
            }
            else{   
                dy1 = v[j][i] - xnach;
                dy2 = v[j][i+1] - ynach;         
            }
        }
        if ((vectornoe(dxRay,dyRay,dx1,dy1) + vectornoe(dxRay,dyRay,dx2,dy2)) == 1)
        {
            sch=sch+1;
        }
    }
    if (sch % 2 == 1)
    {
        cout << "Точка лежит внутри";
    }
    else{
        cout << "Точка лежит снаружи";
    }
    return 0;
}
