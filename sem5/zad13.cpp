#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
using namespace std;

int main(){
    int n=50;
    // cout << "Введите количество элементов: " << endl;
    // cin >> n;
    vector <double> num;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(-50.0, 50.0);  
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
    for_each(num.begin(),num.end(),[](int a){cout << a << " ";}); cout << endl;
    num.erase(remove_if(num.begin(),num.end(),[](int a){return a <= 0 or a >= 12;}), num.end()); 
    double sum = accumulate(num.begin(),num.end(),0); 
    cout << "Среднее значение: " << sum/(num.size()) << endl;
    auto MinMaxit = minmax_element(num.begin(),num.end());
    cout << "Минимальный элемент: " << *MinMaxit.first << endl;
    cout << "Максимальынй элемент: " << *MinMaxit.second << endl;
    cout << "Все значения больше 8 бар: ";
    for_each(num.begin(),num.end(),[](int a){if (a > 8) cout << a << " ";});
    return 0;
}