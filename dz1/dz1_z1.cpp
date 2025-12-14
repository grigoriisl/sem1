#include <iostream>
using namespace std;

int main()
{
    int dl;
    cout << "Введите длину в сантиметрах: ";
    cin >> dl;
    cout << "количество полных метров: "<< dl/100 << endl;
    cout << "количество сантиметров: "<< dl%100 << endl;
    return 0;
}