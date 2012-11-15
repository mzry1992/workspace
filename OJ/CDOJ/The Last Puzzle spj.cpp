#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a[200],b[200];
char com[200];

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%d",&a[i]);
        for (int i = 0; i < n; i++)
            scanf("%d",&b[i]);
    }
    return 0;
}

