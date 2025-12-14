#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Введите целое число: ";
    cin >> n;
    cout << "Квадраты всех чисел до введенного числа: ";
    for (int i=1;i<=n;i++)
    {
        cout << i*i << " ";
    }
    return 0;
}