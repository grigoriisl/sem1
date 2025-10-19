#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

int main()
{
    int n=20;
    cout << "Введите количество элементов: " << endl;
    cin >> n;
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
    // auto new_end = remove_if(num.begin(), num.end(),[](int num) {
    //         return num < 0; 
    // });
    num.erase(remove_if(num.begin(), num.end(), [](int x){ return x < 0; }), num.end());
    cout << "После удаления отрицательных чисел: ";
    for (int el : num) 
    {
        cout << el << " ";
    }
    return 0;
}