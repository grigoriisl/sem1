#include <iostream>
#include <cmath>
using namespace std;

float diag(float x1,float x2, float y1, float y2)
{
    double c1,c2, res;
    c1=pow((x2-x1),2);
    c2=pow((y2-y1),2);    
    res=pow(c1+c2, 0.5);
    return res;
}

int main()
{
    int n=0;
    float sum =0, r=0, itog=0, d1=0,d2,d3,d4,d5,d6 ,maxi=0;
    n=4;
    float x[n];
    float y[n];
    float mas[6];
    cout << "Введите координаты каждой из вершин" << endl;
    for (int i=0; i<n ; i++)
    {
        cout << "Введите x " << i+1 << "-й вершины: ";
        cin >> x[i]; 
        cout << "Введите y " << i+1 << "-й вершины: ";
        cin >> y[i]; 
    }
    d1=diag(x[0], x[1], y[0], y[1]);
    maxi=d1;
    d2=diag(x[2], x[1], y[2], y[1]);
    if (d2>maxi)
    {
        maxi=d2;
    }
    d3=diag(x[3], x[1], y[3], y[1]);
    if (d4>maxi)
    {
        maxi=d3;
    }
    d4=diag(x[2], x[0], y[2], y[0]);
    if (d4>maxi)
    {
        maxi=d4;
    }
    d5=diag(x[3], x[0], y[3], y[0]);
    if (d5>maxi)
    {
        maxi=d5;
    }
    d6=diag(x[3], x[2], y[3], y[2]);
    if (d6>maxi)
    {
        maxi=d6;
    }
    sum=d1+d2+d3+d4+d5+d6-(2*maxi);
    cout << "Периметр: " << sum;
    return 0;
}