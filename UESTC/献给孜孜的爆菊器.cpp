#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("我没有下限.txt","w",stdout);
    for (int i = 1;i <= 10;i++)
    {
        cout << 1000 << endl;
        for (int j = 1;j <= 1000;j++)
            cout << rand()%1000-500 << ' ';
        cout << endl;
    }
}
