#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <random>
#include <cmath>
#include <cctype>
#include <cstring>
using namespace std;

string proverka(const string& str1, const string& str2) 
{
    int m = str1.length();
    int n = str2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n+1, 0));
    int maxi = 0;
    int end = 0;
    for (int i = 1; i <= m; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            if (str1[i - 1] == str2[j - 1]) 
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxi) 
                {
                    maxi = dp[i][j];
                    end = i - 1;
                }
            } 
            else 
            {
                dp[i][j] = 0;
            }
        }
    }
    if (maxi == 0) 
    {
        return "";
    }
    return str1.substr(end-maxi+1, maxi);
}

int main() 
{
    string str1, str2;
    cout << "Введите первую строку: ";
    getline(cin, str1);
    cout << "Введите вторую строку: ";
    getline(cin, str2);
    string itog = proverka(str1, str2);
    if (itog.empty()) 
    {
        cout << "Общих подстрок не найдено" << endl;
    } else 
    {
        cout << "Наибольшая общая подстрока: " << itog << endl;
    }
    return 0;
}