#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float v[4];
    float c1,c2, sum=0,res=0;
    cout << "Введите x1: ";//0
    cin >> v[0];
    cout << "Введите y1: ";//1
    cin >> v[1];
    cout << "Введите x2: ";//2
    cin >> v[2];
    cout << "Введите y2: ";//3
    cin >> v[3];
    c1=pow((v[3]-v[1]),2);
    c2=pow((v[2]-v[0]),2);    
    res=pow(c1+c2, 0.5);
    cout << "Длина отрезка: " << res;
    return 0;
}