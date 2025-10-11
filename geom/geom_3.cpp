#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float v[6];
    float c1,c2;
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
    c1=(v[0]+v[2]+v[4])/3.0;
    c2=(v[1]+v[3]+v[5])/3.0;
    cout << "Cx: : " << c1  << endl;
    cout << "Cy: : " << c2;
    return 0;
}