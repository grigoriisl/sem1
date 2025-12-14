#include <iostream>
using namespace std;

int main()
{
    for (int i=32;i!=127;i++)
    {
        cout << "Символ номер " << i << " : " << "\"\"" << char(i) << "\"\"" << endl; //как одну кавычку?????!!!
    }
    return 0;
}