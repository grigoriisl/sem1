#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int n;
    double def=0, theta, x, y, def1, def2, def3, x1,y1;
    n=2;
    double v[n][n+1];
    cout << "Введите угол O: ";
    cin >> theta;
    cout << "Введите координату x точки: ";
    cin >> x;
    cout << "Введите координату y точки: ";
    cin >> y;
    v[0][2]=x;
    v[1][2]=y;
    v[0][0]=cos(theta * M_PI / 180.0 );
    v[0][1]=sin(theta * M_PI / 180.0 );
    v[1][0]=sin(theta * M_PI / 180.0 )*(-1);
    v[1][1]=cos(theta * M_PI / 180.0 );
    x1=(x*v[0][0])+(y*v[0][1]);
    y1=(x*v[1][0])+(y*v[1][1]);
    cout << "x1: " << x1 << "   ";
    cout << "y1: " << y1;
}