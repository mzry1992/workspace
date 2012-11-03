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
        cout << 20 << ' ' << 20 << endl;
        for (int j = 1;j <= 20;j++)
        {

            cout << rand()%3+1 << ' ' << rand()%3+1 << ' ' << rand()%3+1 << endl;
            cout << rand()%3+1 << ' ' << rand()%3+1 << ' ' << rand()%3+1 << endl;
        }

            cout << 1 << ' ' << 1 << ' ' << 1 << endl;
    }
}
