#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("in.txt","w",stdout);
    cout << 5000 << endl;
    for (int i = 0;i < 5000;i++)
    {
        for (int i = 0;i < 3;i++)
            cout << rand()%20000 << ' ' << rand()%20000 << ' ';
        cout << rand()%20000-10000 << ' ' << rand()%20000-10000 << endl;
        for (int i = 0;i < 3;i++)
            cout << -rand()%20000 << ' ' << -rand()%20000 << ' ';
        cout << rand()%20000-10000 << ' ' << rand()%20000-10000 << endl;
    }
}
