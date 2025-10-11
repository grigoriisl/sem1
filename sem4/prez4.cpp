<<<<<<< HEAD
#include <iostream>
#include <cmath>

using namespace std;

const int N = 4;

double det(double A[N][N])
{
    double c, r = 1;
    for(int i = 0; i < N; i++) {
        for(int k = i + 1; k < N; k++) {
            c = A[k][i] / A[i][i];
            for(int j = i; j < N; j++)
                A[k][j] = A[k][j] - c * A[i][j];
        }
    }
    for (int i = 0; i < N; i++)
        r *= A[i][i];
    return r;
}

int main()
{
    double def = 0, x, y, z, def1, def2, def3, def11, def22, def33;
    
    double v[N][N];
    double v1[N][N];
    double v2[N][N];
    double v3[N][N];
    double v4[N][N];
    double A[3];
    double B[3];
    double C[3];
    double D[3];
    v[0][3]=1;
    v[1][3]=1;
    v[2][3]=1;
    v[3][3]=1;
    cout << "Введите координату точки A: ";
    for (int i = 0; i < 3; i++)
    {
        cin >> A[i];
        v[0][i] = A[i];
    }
    v[0][3] = 1;
    
    cout << "Введите координату точки B: ";
    for (int i = 0; i < 3; i++)
    {
        cin >> B[i];
        v[1][i] = B[i];
    }
    v[1][3] = 1;
    
    cout << "Введите координату точки C: ";
    for (int i = 0; i < 3; i++)
    {
        cin >> C[i];
        v[2][i] = C[i];
    }
    v[2][3] = 1;
    
    cout << "Введите координату точки D: ";
    for (int i = 0; i < 3; i++)
    {
        cin >> D[i];
        v[3][i] = D[i];
    }
    v[3][3] = 1;
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            v1[i][j] = v[i][j];
            v2[i][j] = v[i][j];
            v3[i][j] = v[i][j];
            v4[i][j] = v[i][j];
        }
    }
    int n=4;
    double det0 = det(v);
        for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            v1[i][j]=v[i][j];
        }
    }
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            v2[i][j]=v[i][j];
        }
    }
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            v3[i][j]=v[i][j];
        }
    }
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            v4[i][j]=v[i][j];
        }
    }
    for (int i = 0; i < N; i++) 
    {
        v1[i][0] = A[0]*A[0] + A[1]*A[1] + A[2]*A[2];
        v2[i][1] = A[0]*A[0] + A[1]*A[1] + A[2]*A[2];
        v3[i][2] = A[0]*A[0] + A[1]*A[1] + A[2]*A[2];
        v4[i][3] = A[0]*A[0] + A[1]*A[1] + A[2]*A[2];
    }
    
    double det1 = det(v1);
    double det2 = det(v2);
    double det3 = det(v3);
    double det4 = det(v4);
    
    double ca = det1 / det0;
    double cb = det2 / det0;
    double cc = det3 / det0;
    double cd = det4 / det0;
    
    double x0 = (-ca) / 2;
    double y0 = (-cb) / 2;
    double z0 = (-cc) / 2;
    //  for (int i = 0; i < N; i++) 
    // {
    //     for (int j = 0; j < N; j++) 
    //     {
    //         cout << v1[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << ca << det1 << det0 << endl;
    cout << "Координаты центра: ( " << x0 << " " << y0 << " " << z0 << " )" << endl;
    double r = sqrt((x0 * x0) + (y0 * y0) + (z0 * z0) - cd);
    cout << "Радиус сферы: " << r << endl;
    return 0;
}
=======
#include <iostream>
#include <cmath>

using namespace std;

const int N = 4;

double det(double A[N][N])
{
    double c, r = 1;
    for(int i = 0; i < N; i++) {
        for(int k = i + 1; k < N; k++) {
            c = A[k][i] / A[i][i];
            for(int j = i; j < N; j++)
                A[k][j] = A[k][j] - c * A[i][j];
        }
    }
    for (int i = 0; i < N; i++)
        r *= A[i][i];
    return r;
}

int main()
{
    double def = 0, x, y, z, def1, def2, def3, def11, def22, def33;
    
    double v[N][N];
    double v1[N][N];
    double v2[N][N];
    double v3[N][N];
    double v4[N][N];
    double A[3];
    double B[3];
    double C[3];
    double D[3];
    v[0][3]=1;
    v[1][3]=1;
    v[2][3]=1;
    v[3][3]=1;
    cout << "Введите координату точки A: ";
    for (int i = 0; i < 3; i++)
    {
        cin >> A[i];
        v[0][i] = A[i];
    }
    v[0][3] = 1;
    
    cout << "Введите координату точки B: ";
    for (int i = 0; i < 3; i++)
    {
        cin >> B[i];
        v[1][i] = B[i];
    }
    v[1][3] = 1;
    
    cout << "Введите координату точки C: ";
    for (int i = 0; i < 3; i++)
    {
        cin >> C[i];
        v[2][i] = C[i];
    }
    v[2][3] = 1;
    
    cout << "Введите координату точки D: ";
    for (int i = 0; i < 3; i++)
    {
        cin >> D[i];
        v[3][i] = D[i];
    }
    v[3][3] = 1;
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            v1[i][j] = v[i][j];
            v2[i][j] = v[i][j];
            v3[i][j] = v[i][j];
            v4[i][j] = v[i][j];
        }
    }
    int n=4;
    double det0 = det(v);
        for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            v1[i][j]=v[i][j];
        }
    }
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            v2[i][j]=v[i][j];
        }
    }
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            v3[i][j]=v[i][j];
        }
    }
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            v4[i][j]=v[i][j];
        }
    }
    for (int i = 0; i < N; i++) 
    {
        v1[i][0] = A[0]*A[0] + A[1]*A[1] + A[2]*A[2];
        v2[i][1] = A[0]*A[0] + A[1]*A[1] + A[2]*A[2];
        v3[i][2] = A[0]*A[0] + A[1]*A[1] + A[2]*A[2];
        v4[i][3] = A[0]*A[0] + A[1]*A[1] + A[2]*A[2];
    }
    
    double det1 = det(v1);
    double det2 = det(v2);
    double det3 = det(v3);
    double det4 = det(v4);
    
    double ca = det1 / det0;
    double cb = det2 / det0;
    double cc = det3 / det0;
    double cd = det4 / det0;
    
    double x0 = (-ca) / 2;
    double y0 = (-cb) / 2;
    double z0 = (-cc) / 2;
    //  for (int i = 0; i < N; i++) 
    // {
    //     for (int j = 0; j < N; j++) 
    //     {
    //         cout << v1[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << ca << det1 << det0 << endl;
    cout << "Координаты центра: ( " << x0 << " " << y0 << " " << z0 << " )" << endl;
    double r = sqrt((x0 * x0) + (y0 * y0) + (z0 * z0) - cd);
    cout << "Радиус сферы: " << r << endl;
    return 0;
}
>>>>>>> 4619b528edc52aaa3dbea425304de27a97bbb387
