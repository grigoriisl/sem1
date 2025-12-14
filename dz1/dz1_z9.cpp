#include <iostream>
using namespace std;

int main()
{
    int n=0,sum=0;
    cout << "Введите натуральное число: ";
    cin >> n;
    for (int i=1;i<n+1;i++)
    {
        if ((i%2==0) || (i%5==0))
        {
            sum=sum+i;
        }
    }
    cout << "Сумма подходящих чисел: " << sum;
    return 0;
}