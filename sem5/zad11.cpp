#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
using namespace std;

int main()
{
    int n=50;
    int c=0;
    // cout << "Введите количество элементов: " << endl;
    // cin >> n;
    vector <double> num;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(0.0, 50.0);  
    cout << "Изначальный массив: " << endl;
    for (int i = 0; i < n; ++i) 
    {
        num.push_back(dist(gen));
    }

    for (double el : num) 
    {
        cout << el << " ";
    }
    cout << endl;
    num.erase(remove_if(num.begin(), num.end(), [](double i) {return i < 0.1;}), num.end());
    auto maxi = max_element(num.begin(), num.end());
    double sum = accumulate(num.begin(), num.end(), 0);
    cout << "Среднее значение: " << sum/(num.size()); 
    cout << endl << "Максимальное значение: " << *maxi << endl;

    for(int i = 0; i < num.size(); i++)
    {
        if (num[i] > 0.5) 
        {
            c++;
        }
        
    } 

    if (c == num.size())
    {
        cout << "Все значения больше 0.5";
    }
    else
    {
        cout << endl << "Не все значения больше 0.5";
    }
    sort(num.begin(), num.end(), greater<int>());
    cout << endl << "Наибольшие амплитуды для анализа: " << endl;
    if(num.size() >= 10)
    {
        for(int i = 0; i < 10; i++)
        {
        cout << num[i] << " ";
        }
    }
    else
    {
        for (double el : num) 
        {
            cout << el << " ";
        }
        cout << endl;
    }
    return 0;
}
