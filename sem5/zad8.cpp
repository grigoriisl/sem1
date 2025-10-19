#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
using namespace std;

int main()
{
    int n=20;
    cout << "Введите количество элементов: " << endl;
    cin >> n;
    vector <double> num;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(0.0, 180.0);  
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
    num.erase(remove_if(num.begin(), num.end(), [](double x){ return x > 120; }), num.end());

    double sum = accumulate(num.begin(), num.end(), 0); 
    cout << "Среднее значение: " << sum/(num.size()) << endl;
 
    int c = count_if(num.begin(), num.end(),
        [](double temp) 
        {
            return temp ==0;  
        });
    bool logic = (c == 0);
    if (logic==1) 
    {
        cout << "Скорость была равна нулю" << endl;
    } 
    else 
    {
        cout << "Скорость была равна нулю" << endl;
    }

    sort(num.begin(), num.end());
    cout << "Максимальные 10 значений: ";
    for (int i=num.size()-10; i!=num.size();i++)
    {
        cout << num[i] << " ";
    }

    cout << endl;
    cout <<"Готовый vector: ";
    for (double el : num) 
    {
        cout << el << " ";
    }
    return 0;
}