#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;
    int LsN[N][2];
    int LsM[2][M];
    int Ls[N][M];
    for (int i = 0; i < N; i++){
        for (int j = 0;j < M; j++ ){
            cin >> Ls[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        int Max = -9999999;
        int Min = 9999999999;
        for (int j = 0;j < M; j++ ){
            if (Ls[i][j] > Max){
                Max = Ls[i][j];
            }
            if (Ls[i][j] < Min){
                Min = Ls[i][j];
            }
        LsN[i][0] = Max;
        LsN[i][1] = Min;

        }
    }

    for (int i = 0; i < M; i++)
    {
        int Max = -9999999;
        int Min = 9999999999;
        for (int j = 0;j < N; j++ ){
            if (Ls[j][i] > Max){
                Max = Ls[j][i];
            }
            if (Ls[j][i] < Min){
                Min = Ls[j][i];
            }
        LsM[0][i] = Max;
        LsM[1][i] = Min;

        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0;j < M; j++ ){
            if ((Ls[i][j] == LsN[i][1]) && (Ls[i][j] == LsM[0][i]))
            {
                cout << "Тип данных А, индексы" << i << " " << j << ". Значение:" << Ls[i][j] << endl;
            }
            else{
                cout << "None" << endl;
            }
        }
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0;j < N; j++ )
        {
            if ((Ls[i][j] == LsN[i][0]) && (Ls[i][j] == LsM[1][i]))
            {
                cout << "Тип данных В, индексы - " << i << " и " << j << ". Значение:" << Ls[i][j] << endl;
            }
            else
            {
                cout << "None" << endl;
            }
        }
    }
}