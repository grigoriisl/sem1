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
    uniform_real_distribution<double> dist(-100.0, 100.0);  
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
    num.erase(remove_if(num.begin(), num.end(), [](double x){ return x > 50; }), num.end());
    num.erase(remove_if(num.begin(), num.end(), [](double x){ return x < -50; }), num.end());

    auto max_it = max_element(num.begin(), num.end(), [](double a, int b) {
        return a < b;
    });
    double maxi = *max_it;
    cout << "Максимальный элемент: " << maxi << endl; 
    auto min_it = max_element(num.begin(), num.end(), [](double a, int b) {
        return a > b;
    });
    double mini = *min_it;
    cout << "Минимальный элемент: " << mini << endl; 
    double sum = accumulate(num.begin(), num.end(), 0); 
    cout << "Среднее значение элементов: " << sum/(num.size()) << endl;
 
    int c = count_if(num.begin(), num.end(),
        [](double temp) 
        {
            return temp <= -10.0;  
        });
    bool logic = (c == 0);
    if (logic==1) 
    {
        cout << "Все температуры превышают -10 градусов" << endl;
    } 
    else 
    {
        cout << "Не все температуры превышают -10 градусов" << endl;
    }

    cout << endl;
    cout <<"Готовый vector: ";
    for (double el : num) 
    {
        cout << el << " ";
    }
    return 0;
}