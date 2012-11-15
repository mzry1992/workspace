#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

const char s[5] = "XYZ";

int main()
{
    freopen("in.txt","w",stdout);
    cout << 1 << endl;
    cout << 1000 << ' ' << 1000 << endl;
    for (int i = 0;i < 1000;i++)
    {
        char a,b;
        a = s[rand()%3];
        while (true)
        {
            b = s[rand()%3];
            if (b != a) break;
        }
        cout << a << "=" << rand()%1000+1 << "," <<
                b << "=" << rand()%1000+1 << endl;
    }
    return 0;
}

