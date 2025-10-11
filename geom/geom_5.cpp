#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float v[6];
    float c1,c2, sum=0;
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
    c1=(v[2]-v[0])*(v[5]-v[1]);
    c2=(v[3]-v[0])*(v[4]-v[1]);
    sum=c1-c2;
    if (sum==0)
    {
        cout << "Точки лежат на одной прямой";
    }
    else
    {
        cout << "Точки не лежат на одной прямой";
    }
    return 0;
}