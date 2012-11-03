#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    freopen("H.in","w",stdout);
    for (int i = 0;i < 1;i++)
    {
        cout << 15000 << endl;
        for (int j = 0;j < 15000;j++)
            cout << (rand()%10000)-5000 << ' ' << (rand()%10000)-5000 << endl;
    }
    cout << 0 << endl;
}
