#include <iostream>
#include <vector>
#include <cstring> 
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;


string naibdlina(const string& str1, const string& str2) 
{
    int max_len = 0;
    string result = "";
    for (int i = 0; i < str1.length(); i++) 
    {
        for (int j = 0; j < str2.length(); j++) 
        {
            int len = 0;
            while (i + len < str1.length() && j + len < str2.length() && str1[i + len] == str2[j + len]) 
            {
                len++;
            }
            if (len > max_len) 
            {
                max_len = len;
                result = str1.substr(i, len);
            }
        }
    }
    return result;
}

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
        const char* word = v[i].c_str();
        const char* last_char = word + v[i].size() - 1;
        if (*last_char == 'b' || *last_char == 'B') 
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
    string s10=v[v.size()-1];
    const char* last_word = s10.c_str();
    while (*last_word) {
        if (*last_word == 'd' || *last_word == 'D') 
        {
            schd=schd+1;
        }
        last_word++;
    }

    string upper_str = s;
    char* ptr = &upper_str[0];
    while (*ptr) {
        *ptr = toupper(*ptr);
        ptr++;
    }

    //5
    int sovpad = 0;
    for (int i=0; i < v.size(); i++) 
    {
        const char* word_ptr = v[i].c_str();
        int word_len = v[i].size();
        if (word_len >= 2) 
        {
            if (*(word_ptr + 1) == *(word_ptr + word_len - 2)) 
            {
                sovpad++;
            }
        }
    }
    
    //6
    string samayadlinna = "";
    for (int i=0; i < v.size(); i++) 
    {
        for (int j=i+1; j < v.size(); j++) 
        {
            string common = naibdlina(v[i], v[j]);
            if (common.length() > samayadlinna.length()) 
            {
                samayadlinna = common;
            }
        }
    }

    cout << "Количество слов, оканчивающих на букву b: " << sch << endl;
    cout << "Длина самого длинного слова: " << maxi << endl;
    cout << "Количество букв d в последнем слове строки: " << schd << endl;
    cout << "Строка со всеми заглавными буквами: " << upper_str << endl;
    cout << "Количество слов у которых совпадает второй и предпоследний символ:" << sovpad << endl;
    cout << "Самая длинная общая подстрока: " << samayadlinna << endl;
    return 0;
}