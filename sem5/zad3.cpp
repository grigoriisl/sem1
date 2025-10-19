#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<double> num(20);
    double x;
    cout << "Введите элементы вектора в строку: ";
    for (int i=0; i<20; i++)
    {
        cin >> x;
        num[i]=x;
    }
    auto max_it = max_element(num.begin(), num.end(), [](double a, int b) {
        return a < b;
    });
    double maxi = *max_it;
    cout << "Максимальный элемент: " << maxi; 
    return 0;
}