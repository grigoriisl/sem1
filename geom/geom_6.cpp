#include <iostream>
using namespace std;
int vectornoe(int x1, int y1, int x2, int y2)
{
    int Product = x1*y2 - x2*y1;
    if (Product > 0) {
        return 1;
    }
    return 0;
}
int main() 
{
    double v[2][4];
    int pos = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) 
        {
            if (j == 0)
            {
                cout << "Введите координату X точки " << pos << ":"; 
            }
            else {
                cout << "Введите координату Y точки " << pos << ":";
                pos++;
            }
            cin >> v[j][i];
        }
    }
    int Ax = v[0][0];
    int Ay = v[1][0];
    int ABx = v[0][1] - Ax;
    int ACx = v[0][2] - Ax;
    int ADx = v[0][3] - Ax;
    int ABy = v[1][1] - Ay;
    int ACy = v[1][2] - Ay;
    int ADy = v[1][3] - Ay;
    if (vectornoe(ABx,ABy,ACx,ACy) + vectornoe(ABx,ABy,ADx,ADy) == 1) 
    {
        cout << "Отрезки пересекаются";
    }
    else 
    {
        cout << "Отрезки не пересекаются";
    }
	return 0;
}