#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;

int n;

int main()
{
    freopen("ALCIS.txt","w",stdout);
    n = 100000;
    cout << 1 << endl;
    cout << n << ' ' << n << endl;
    for (int i = 1;i <= n;i++)
        cout << (rand()%200000-100000) << ' ';
    cout << endl;
    for (int i = 1;i <= n;i++)
    {
        int l,r;
        l = rand()%n+1;
        r = rand()%n+1;
        if (l > r)
        {
            int temp = l;
            l = r;
            r = temp;
        }
        if (rand()%2 == 0)
        {
            cout << 'a' << ' ' << l << ' ' << r << ' ' << (rand()%200000-100000) << endl;
        }
        else
            cout << 'q' << ' ' << l << ' ' << r << endl;
    }
}
