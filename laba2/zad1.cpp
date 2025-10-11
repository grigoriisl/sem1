#include <iostream>
#include <vector>
#include <cstring> 
#include <string>
using namespace std;

int main()
{
    string s, str;
    vector <string> v;
    vector <string> v1;
    int sch=0, maxi=-100, schd=0;
    cout << "Введите строку: ";
    getline(cin, s);
    int flag=0;
    s=s+" ";
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]!=' ')
        {
            str=str+s[i];
        }
        else if ((s[i]==' ') and (s[i+1] != ' '))
        {
            v.push_back(str);
            str="";
        }
    }

    //1
    v.push_back(str);
    for (int i=0; i < v.size(); i++)
    {
        if (v[i][0]=='b')
        {
            sch=sch+1;
        }
    }

    //2
    for (int i=0; i < v.size(); i++)
    {
        int len=v[i].size();
        if (len>maxi)
        {
            maxi=len;
        }
    }

    //3
    string s10=v[9];
    for (int i=0; i<s10.size(); i++)
    {
        if (s10[i]=='d')
        {
            schd=schd+1;
        }
    }

    //4
    for (int i=0; i < v.size(); i++)
    {
        string si=v[i];
        string snew="";
        //cout << si;
        const char* pos = si.c_str();
        for (int i = 0; i < si.size(); i++) 
        {
            char c = toupper(*(pos+i));
            // string kusok = c;
            snew=snew + c;
            v1.push_back(snew);
            // cout << kusok << " ";
        }
    }

    cout << "Количество слов начинающихся с буквы b: " << sch << endl;
    cout << "Наибольшая длина слова : " << maxi << endl;
    cout << "Количество букв d в последнем слове строки: " << schd << endl;

    return 0;
}