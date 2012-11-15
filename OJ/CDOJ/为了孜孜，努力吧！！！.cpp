#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("out.txt","w",stdout);
    cout << 50 << ' ' << 13 << endl;
    for (int i = 1;i <= 50;i++)
    {
        cout << rand()%20+1 << ' ' << rand()%20+1 << endl;
    }
    cout << 0 << ' ' << 0;
}
