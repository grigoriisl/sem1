#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int n;
    int flag=0, def=0, x, y, z;
    int v[2][3];
    v[0][0]=2;
    v[0][1]=3;
    v[1][0]=5;
    v[1][1]=-1;
    v[0][2]=13;
    v[1][2]=9;
    def=(v[0][1]*v[1][1])-(v[0][0]*v[1][0]);
    x=def/v[0][2];
    y=def/v[1][2];
    cout << "Матрица: " << endl;
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << "X = " << x << endl;
    cout << "Y = " << y << endl;
    return 0;
}