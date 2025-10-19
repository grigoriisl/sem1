#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
using namespace std;

int main()
{
    int n=50;
    // cout << "Введите количество элементов: " << endl;
    // cin >> n;
    vector <double> num;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(0.0, 100.0);  
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
    double sred= (num[num.size()-1]-num[0]);
    if (sred<0)
    {
        cout << "Конечное больше начального";
    }
    else
    {
        cout << "Среднее потребление: " << sred << endl;
    }
    if (mini<(maxi*0.05))
    {
        cout << "Уровень падал ниже 5% от максимального " << endl;
    }
    else
    {
        cout << "Уровень не падал ниже 5% от максимального " << endl;
    }

    int c = count_if(num.begin(), num.end(),
        [](double x) 
        {
            return x >= 10 and x<=90;  
        });
    bool logic = (c == 0);
    if (logic==1) 
    {
        cout << "Двигатель работал всё время в пределах от 10 до 90 кВт " << endl;
    } 
    else 
    {
        cout << "Двигатель не работал всё время в пределах от 10 до 90 кВт" << endl;
    }
    sort(num.begin(), num.end());
    cout <<"Готовый vector: ";
    for (double el : num) 
    {
        cout << el << " ";
    }
    cout << endl;
    if (num.size()%2==1)
    {
        cout << "Медиана: " << num[num.size() / 2];
    }
    else
    {
        cout << "Медиана: " << (double(num[num.size() / 2-1]+num[num.size() / 2]))/2;
    }
    return 0;
}