#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
#include <numeric>
#include <iomanip>
#include <math.h>
using namespace std;

int main() // хотел выводить построчно, но не влезает
{
	srand(time(0));
	vector<vector<double>> temp(5, vector<double>(30));
	vector<vector<double>> pressure(5, vector<double>(100));
	vector<double> middle(5);
	vector<vector<double>> minipre(5, vector<double>(2));
	vector<vector<double>> dtemp(5, vector<double>(29));
	vector<vector<double>> dpr(5, vector<double>(99));
	vector<vector<double>> norma(5, vector<double>(100));
	double mxd = 0;
	int maxkanal = 0;

	for(int i = 0; i < 5; i++) 
    {
        generate(temp[i].begin(), temp[i].end(), []()
        {
            return (rand()%63 - 10 + (double)(rand()%28)/10.0);
        });
    }
    
	for(int i = 0; i < 5; i++) 
    {
        generate(pressure[i].begin(), pressure[i].end(), []()
        {
            return (rand()%30 + 1 + (double)(rand() % 11)/10.0);
        });
    }
	for(int i = 0; i < 5; i++)
	{
		cout << i+1 << endl << "Давление ";
		for_each(pressure[i].begin(), pressure[i].end(), [](double x)
        {
            cout << x << ";  ";
        });
		cout << endl <<"Температеруа ";
		for_each(temp[i].begin(), temp[i].end(), [](double x)
        {
            cout << x << ";  ";
        });
		cout << endl;
	}
	transform(temp.begin(), temp.end(), middle.begin(), [](const vector<double>& channel)
    {
        return accumulate(channel.begin(), channel.end(), 0.0)/30.0;
    });
	for(int i = 0; i < 5; i++)
	{
		auto mini = min_element(pressure[i].begin(), pressure[i].end());
		auto maxi = max_element(pressure[i].begin(), pressure[i].end());
		minipre[i][0] = *mini;
		minipre[i][1] = *maxi;
	}

	for(int i = 0; i < 5; i++)
	{
		transform(temp[i].begin()+1, temp[i].end(), temp[i].begin(), dtemp[i].begin(), [](double a, double b)
        {
            return b - a;
        });
		transform(pressure[i].begin()+1, pressure[i].end(), pressure[i].begin(), dpr[i].begin(), [](double a, double b)
        {
            return b - a;
        });
	}
	for(int i = 0; i < 5; i++)
	{
		if(mxd<dtemp[i][1]-dtemp[i][0]) mxd=dtemp[i][1]-dtemp[i][0];
		maxkanal = i+1;
	}

	cout << endl <<"Канал с наибольшей вариацией температуры: " << maxkanal << endl;
	for(int i = 0; i < 5; i++) 
    {
        transform(pressure[i].begin(), pressure[i].end(), norma[i].begin(), [&minipre, i](double x){return (x-minipre[i][0]) / (minipre[i][1]-minipre[i][0]);});
    }

	cout << "значения давления после нормализации, которые превышают 0.9: " << endl;
	for(int i = 0; i < 5; i++)
    {
        for_each(norma[i].begin(), norma[i].end(), [](double x){if(x > 0.9) 
            {
                cout << x << endl;
            }
        });
    }

	auto mxtp = max_element(middle.begin(), middle.end());
	sort(middle.begin(), middle.end());
	cout << endl << "Средние температуры каналов после сортировки: ";
	for_each(middle.begin(), middle.end(), [](double x){cout << x << " ";});
	cout << endl << "канал с максимальной средней температурой: " << mxtp - middle.begin() + 1;
	return 0;
}