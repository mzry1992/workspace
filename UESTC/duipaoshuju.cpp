#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("out.txt","w",stdout);
    cout << 100 << endl;
    for (int i = 1;i <= 100;i++)
    {
        cout << 1000 << ' ' << 1000 << endl;
        for (int j = 1;j <= 1000;j++)
        {

            cout << rand()%100-50 << ' ' << rand()%100-50 << ' ' << rand()%100-50 << endl;
            cout << rand()%100-50 << ' ' << rand()%100-50 << ' ' << rand()%100-50 << endl;
        }

            cout << rand()%100-50 << ' ' << rand()%100-50 << ' ' << rand()%100-50 << endl;
    }
}
