#include <iostream>
using namespace std;
int main()
{
    int N,M, L=1, sch=1;
    cin >> N;
    M=N;
    int v[M][N];
    int k = 0, start=0, n=0, m=0;
    while (k < N*M)
    {
        n = N - (start * 2) - 1;
        m = M - (start * 2) - 1;
        if (n <= 0 and m <= 0) 
        {
            v[M/2][N/2]=sch;
            sch++;
            break;
        }
        for (int x = 0; x < n; x++)
        {
            v[start][x+start]=sch;
            sch++;
            k++;
        }
        for (int y = 0; y < m; y++)
        {
            v[y+start][N-1-start]=sch;
            sch++;
            k++;
        }
        for (int x = 0; x < n; x++)
        {
            v[M-1-start][N-1-x-start]=sch;
            sch++;
            k++;
        }
        for (int y = 0; y < m; y++)
        {
            v[M-1-y-start][start]=sch;
            sch++;
            k++;
        }
        start += 1;
    } 
    //cout << sch;
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}