#include <iostream>
using namespace std;
int main()
{
    int N,M;
    cin >> N >> M;
    int v[M][N];
    for (int y = 0; y < M; y++)
    {
        for (int x = 0; x < N; x++)
        {
            cin >> v[y][x];
        }
    }
    int k = 0, start=0, n=0, m=0;
    while (k < N*M)
    {
        n = N - (start * 2) - 1;
        m = M - (start * 2) - 1;
        if (n <= 0 and m <= 0) 
        {
            cout << v[M/2][N/2];
            break;
        }
        for (int x = 0; x < n; x++)
        {
            cout << v[start][x+start];
            k++;
        }
        for (int y = 0; y < m; y++)
        {
            cout << v[y+start][N-1-start];
            k++;
        }
        for (int x = 0; x < n; x++)
        {
            cout << v[M-1-start][N-1-x-start];
            k++;
        }
        for (int y = 0; y < m; y++)
        {
            cout << v[M-1-y-start][start];
            k++;
        }
        start += 1;
    }   
    return 0;
}