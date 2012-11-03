#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int k,m,t,n;

int main()
{
    freopen("Game of Life2.in","w",stdout);
    cout << 20 << endl;
    for (int i = 0;i < 5;i++)
    {
        k = rand()%5+1;
        m = rand()%10;
        t = rand()%10;
        n = rand()%10;
        cout << k << ' ' << m << ' ' << t << ' ' << n << endl;
        for (int j = 0;j < k;j++)
        {
            for (int x = 0;x < 4;x++)
            {
                for (int y = 0;y < 4;y++)
                    cout << rand()%2 << ' ';
                cout << endl;
            }
        }
    }
    for (int i = 5;i < 20;i++)
    {
        cout << 10 << ' ' << 20 << ' ' << 10000 << ' ' << 20 << endl;
        for (int j = 0;j < 10;j++)
        {
            for (int x = 0;x < 4;x++)
            {
                for (int y = 0;y < 4;y++)
                    cout << rand()%2 << ' ';
                cout << endl;
            }
        }
    }
}
