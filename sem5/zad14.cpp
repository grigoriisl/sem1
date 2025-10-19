#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;

int main()
{
    int n=24;
    vector <int> num(24);
    vector<double> otkl(24);
    vector <int> num1(24);
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(100.0, 500.0);  
    cout << "Изначальный массив: " << endl;
    for (int i = 0; i < n; ++i) 
    {
        num[i]=(dist(gen));
    }

    for (double el : num) 
    {
        cout << el << " ";
    }
    num1=num;
    cout << endl;
    double sum = accumulate(num.begin(), num.end(), 0); 
    cout << "Суммарное потребление: " << sum << endl;
    cout << "Среднее потребление: " << sum/(num.size()) << endl;
    auto max_it = max_element(num.begin(), num.end(), [](double a, int b) {
        return a < b;
    });
    double maxi = *max_it;
    cout << "Часы максимального потребления: ";
    for (int i=0; i < num.size(); i++)
    {
        if (num[i]==maxi)
        {
            cout << i << "-й час; ";
        }
    }
    cout << endl;
    cout << "топ-5 минимальных часов потребления: " << endl;
	transform(num1.begin(), num1.end(), otkl.begin(), [&sum](int x){return x - (double)sum/24;});
	sort(otkl.begin(), otkl.end());
	for(int i = 0; i < 5; i++)
	{
		auto temp = find(num1.begin(), num1.end(), otkl[i]+(double)sum/24);
		cout << i + 1 << ". " << temp - num1.begin() + 1 << "-й час; ";
	}
    return 0;
}