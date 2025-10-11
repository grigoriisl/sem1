#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int n;
    double def=0, x, y, z, def1, def2, def3, def11, def22, def33;
    n=3;
    double v[n][n+1];
    cout << "Введите " << n << " строк по " << n-1 << " чисел: x и y каждой из точек в формате (x1, y1)" << endl;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n-1; j++) 
        {
            cin >> v[i][j];
        }
    }
    v[0][2]=1;
    v[1][2]=1;
    v[2][2]=1;
    def1=(v[1][1]*v[2][2])-(v[2][1]*v[1][2]);
    def2=(v[1][0]*v[2][2])-(v[1][2]*v[2][0]);
    def3=(v[1][0]*v[2][1])-(v[2][0]*v[1][1]);
    def=(v[0][0]*def1)-(v[0][1]*def2)+(v[0][2]*def3);
    double res = 0.5 * abs(def);
    if (res==0)
    {
        cout << "Треугольника не существует";
    }
    else
    {
        cout << "Площадь треугольника равна: " << res;
    }
}