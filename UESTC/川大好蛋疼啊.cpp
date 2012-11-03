#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
    freopen("out.txt","w",stdout);
    cout << 1 << endl;
    cout << 20000 << ' ';
    for (int i = 1;i <= 20000;i++)
        cout << i << ' ';
    cout << endl;
}
