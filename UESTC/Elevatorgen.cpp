#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("ele.in","w",stdout);
    cout << 5 << endl;
    for (int i = 1;i <= 5;i++)
    {
        cout << 1 << ' ' << 10 << endl;
        for (int j = 1;j <= 10;j++)
        {
            while (true)
            {
                int ta = (rand()%50)+1;
                int tb = (rand()%50)+1;
                if (ta == tb)   continue;
                cout << (rand()%20) << ' ' << ta << ' ' << tb << endl;
                break;
            }
        }
    }
}
