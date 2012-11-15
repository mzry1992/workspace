#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("in.txt","w",stdout);
    int n,m;
    n = 10;
    m = 10;
    for (int ft = 1;ft <= 10;ft++)
    {
    cout << n << ' ' << m << endl;

    for (int i = 0; i < m; i++)
        printf("%d ",rand()%1000+1);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ",rand()%1000+1);
        printf("\n");
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ",rand()%1000);
        printf("\n");
    }
    }
    cout << 0  << ' ' << 0 << endl;
    return 0;
}

