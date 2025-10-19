#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
using namespace std;

int main()
{
    int n=20;
    // cout << "Введите количество элементов: " << endl;
    // cin >> n;
    vector <int> num;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(-50, 50);
    for (int i = 0; i < n; ++i) {
        num.push_back(dist(gen));
    }
    for (int el : num) 
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
    int sum = accumulate(num.begin(), num.end(), 0); 
    cout << "Сумма элементов: " << sum << endl;
    sort(num.begin(), num.end(), [](int a, int b) { return a < b; });

    // for (int el : num) 
    // {
    //     cout << el << " ";
    // }

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