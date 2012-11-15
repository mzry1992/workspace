#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("out.txt","w",stdout);
    cout << 200 << ' ' << 200 << endl;
    for (int i = 1;i <= 200;i++)
    {
        for (int j = 1;j <= 200;j++)
            cout << rand()%5000-2500 << ' ';
        cout << endl;
    }
    cout << 100000 << endl;
    for (int i = 1;i <= 100000;i++)
    {
        int x1,y1,d1,d2,x2,y2,t;
        while (true)
        {
            t = rand()%4+1;
            x1 = rand()%200+1;
            y1 = rand()%200+1;
            d1 = d2 = 0;
            if (x1 != 200)
                d1 = rand()%(200-x1)+1;
            if (y1 != 200)
                d2 = rand()%(200-y1)+1;
            x2 = x1+d1;
            y2 = y1+d2;
            cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << t << endl;
            break;
        }
    }
    cout << rand()%200+1 << ' ' << rand()%200+1 << endl;
}
