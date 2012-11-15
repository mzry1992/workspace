#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("B.in","w",stdout);
    for (int i = 0;i < 20;i++)
    {
        printf("100000 1000000000 1000000000\n");
        for (int j = 0;j < 100000;j++)
            printf("%d %d\n",rand()%1000000000,rand()%1000000000);
    }
    cout << 0 << ' ' << 0 << ' ' << 0 << endl;
    return 0;
}

