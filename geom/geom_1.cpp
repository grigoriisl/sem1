#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float v[6];
    float sum=0, r1,r2,r3;
    cout << "Введите x1: ";//0
    cin >> v[0];
    cout << "Введите y1: ";//1
    cin >> v[1];
    cout << "Введите x2: ";//2
    cin >> v[2];
    cout << "Введите y2: ";//3
    cin >> v[3];
    cout << "Введите x3: ";//4
    cin >> v[4];
    cout << "Введите y3: ";//5
    cin >> v[5];
    r1=(v[3]-v[5])*v[0];
    r2=(v[5]-v[1])*v[2];
    r3=(v[1]-v[3])*v[4];
    sum=0.5*abs(r1+r2+r3);
    cout << "Площадь: " << sum;
    return 0;
}