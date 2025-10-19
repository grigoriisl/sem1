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
    std::uniform_int_distribution<int> dist(-100, 100);
    cout << "Изначальный массив: " << endl;
    for (int i = 0; i < n; ++i) 
    {
        num.push_back(dist(gen));
    }

    for (int el : num) 
    {
        cout << el << " ";
    }
    cout << endl;
    auto it = find(num.begin(), num.end(), 7); 
    if (it != num.end()) 
    {
        std::cout << "Элемент найден: " << *it << " на позиции " << (it - num.begin()) <<  endl;
    }
    else 
    {
        cout << "Элемент не найден" << endl;
    }
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end()); 
    cout <<"Готовый vector: ";
    for (int el : num) 
    {
        cout << el << " ";
    }
    return 0;
}