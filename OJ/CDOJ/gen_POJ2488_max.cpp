#include <iostream>
#include <cstdio>
using namespace std;

int tot;

int main()
{
    freopen("POJ2488.in","w",stdout);
    tot = 0;
    for (int i = 1;i <= 26;i++)
    for (int j = 1;j <= 26;j++)
    if (i*j <= 26)
        tot++;
    printf("%d\n",tot);
    for (int i = 1;i <= 26;i++)
    for (int j = 1;j <= 26;j++)
    if (i*j <= 26)
        printf("%d %d\n",i,j);
}
