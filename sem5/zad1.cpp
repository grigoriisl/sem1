#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> num(10);
    int x;
    for (int i=0; i<10; i++)
    {
        num[i]=i+1;
    }
    for_each(num.begin(),num.end(), [](int num){
        cout << num << " ";
    });
    return 0;
}