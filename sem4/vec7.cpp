#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int n;
    double def=0, x, y, z, def1, def2, def3, def11, def22, def33;
    //cout << "Введите размер матрицы: ";
    //cin >> n;
    n=3;
    double v[n][n+1];
    double v1[n][n+1];
    cout << "Введите " << n << " строк по " << n+1 << " чисел:" << endl;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n+1; j++) 
        {
            cin >> v[i][j];
        }
    }
    def1=(v[1][1]*v[2][2])-(v[2][1]*v[1][2]);
    def2=(v[1][0]*v[2][2])-(v[1][2]*v[2][0]);
    def3=(v[1][0]*v[2][1])-(v[2][0]*v[1][1]);
    def=(v[0][0]*def1)-(v[0][1]*def2)+(v[0][2]*def3);
    

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n+1; j++) 
        {
            v1[i][j] = v[i][j];
        }
    }
    v1[0][0]=v[0][3];
    v1[1][0]=v[1][3];
    v1[2][0]=v[2][3];
    def1=(v1[1][1]*v1[2][2])-(v1[2][1]*v1[1][2]);
    def2=(v1[1][0]*v1[2][2])-(v1[1][2]*v1[2][0]);
    def3=(v1[1][0]*v1[2][1])-(v1[2][0]*v1[1][1]);
    def11=(v1[0][0]*def1)-(v1[0][1]*def2)+(v1[0][2]*def3);

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n+1; j++) 
        {
            v1[i][j] = v[i][j];
        }
    }
    v1[0][1]=v[0][3];
    v1[1][1]=v[1][3];
    v1[2][1]=v[2][3];
    def1=(v1[1][1]*v1[2][2])-(v1[2][1]*v1[1][2]);
    def2=(v1[1][0]*v1[2][2])-(v1[1][2]*v1[2][0]);
    def3=(v1[1][0]*v1[2][1])-(v1[2][0]*v1[1][1]);
    def22=(v1[0][0]*def1)-(v1[0][1]*def2)+(v1[0][2]*def3);

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n+1; j++) 
        {
            v1[i][j] = v[i][j];
        }
    }
    v1[0][2]=v[0][3];
    v1[1][2]=v[1][3];
    v1[2][2]=v[2][3];
    def1=(v1[1][1]*v1[2][2])-(v1[2][1]*v1[1][2]);
    def2=(v1[1][0]*v1[2][2])-(v1[1][2]*v1[2][0]);
    def3=(v1[1][0]*v1[2][1])-(v1[2][0]*v1[1][1]);
    def33=(v1[0][0]*def1)-(v1[0][1]*def2)+(v1[0][2]*def3);
    cout << def11 << " " << def22 << " " << def33 << " " ;
    x=def11/def;
    y=def22/def;
    z=def33/def;
    cout << "X = " << x << endl;
    cout << "Y = " << y << endl;
    cout << "Z = " << z << endl;
    return 0;
}