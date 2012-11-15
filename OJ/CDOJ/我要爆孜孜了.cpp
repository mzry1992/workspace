#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("zizinihao.txt","w",stdout);
    cout << 100 << endl;
    for (int i = 1;i <= 100;i++)
    {
        cout << 20 << ' ' << 1 << endl;
        for (int j = 1;j <= 20;j++)
        {
            cout << (char)(rand()%26+'A');
        }
        cout << endl;
    }
}
