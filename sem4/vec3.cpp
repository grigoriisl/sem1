#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N,M;
    cout << "Введите N и M";
    cin >> N >> M;
    int vn[N][2];
    int vm[2][M];
    int v[N][M];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0;j < M; j++ )
        {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        int maxi = -9999999;
        int mini = 999999;
        for (int j = 0;j < M; j++ )
        {
            if (v[i][j] > maxi)
            {
                maxi = v[i][j];
            }
            if (v[i][j] < mini)
            {
                mini = v[i][j];
            }
        vn[i][0] = maxi;
        vn[i][1] = mini;

        }
    }

    for (int i = 0; i < M; i++)
    {
        int maxi = -9999999;
        int mini = 9999999;
        for (int j = 0;j < N; j++ )
        {
            if (v[j][i] > maxi)
            {
                maxi = v[j][i];
            }
            if (v[j][i] < mini)
            {
                mini = v[j][i];
            }
        vm[0][i] = maxi;
        vm[1][i] = mini;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0;j < M; j++ )
        {
            if ((v[i][j] == vn[i][1]) and (v[i][j] == vm[0][i]))
            {
                cout << "Тип данных А, индексы" << i << "-" << j << ":" << v[i][j] << endl;
            }
            else
            {
                cout << "None" << endl;
            }
        }
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0;j < N; j++ )
        {
            if ((v[i][j] == vn[i][0]) and (v[i][j] == vm[1][i]))
            {
                cout << "Тип данных В, индексы - " << i << "-" << j << ":" << v[i][j] << endl;
            }
            else
            {
                cout << "None" << endl;
            }
        }
    }
}