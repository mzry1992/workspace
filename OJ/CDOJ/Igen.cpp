#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
    freopen("I.in","w",stdout);
    int t = 20;
    int n = 5000;
    cout << t << endl;
    for (int ft = 1;ft <= t;ft++)
    {
        cout << n << endl;
        for (int i = 0;i < n;i++)
        {
            cout << (rand()%20000-10000) << ' ' << (rand()%20000-10000) << ' ' << (rand()%20000-10000) << endl;
        }
    }
}
