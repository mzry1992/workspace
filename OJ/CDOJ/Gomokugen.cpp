#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("in.txt","w",stdout);
    for (int ft = 1;ft <= 20;ft++)
    {
    cout << 44 << endl;
    int mp[15][15];
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            mp[i][j] = 2;
    for (int i = 0; i < 22; i++)
    {
        int a,b;
        while (true)
        {
            a = rand()%15;
            b = rand()%15;
            if (mp[a][b] != 2)  continue;
            mp[a][b] = 0;
            cout << a << ' ' << b << ' ' << 0 << endl;
            break;
        }
    }
    for (int i = 0; i < 22; i++)
    {
        int a,b;
        while (true)
        {
            a = rand()%15;
            b = rand()%15;
            if (mp[a][b] != 2)  continue;
            mp[a][b] = 1;
            cout << a << ' ' << b << ' ' << 1 << endl;
            break;
        }
    }
    }
    cout << 0 << endl;
    return 0;
}

