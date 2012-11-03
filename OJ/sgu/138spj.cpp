#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int tot[6];
int n;

void Gao()
{
    memset(tot,0,sizeof(tot));
    int c;
    c = 0;
    bool err = false;
    for (int i = 0; i < n; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        tot[a]++;
        tot[b]++;
        if (a == b)
            err = true;
        if (c != 0 && a != c && b != c)
            err = true;
        c = a;
    }
    if (err == true)
        printf("err\n");
    else
    {
        printf("%d\n",5);
        for (int i = 1;i <= 5;i++)
            printf("%d ",tot[i]);
        printf("\n");
    }
}

int main()
{
    while (scanf("%d",&n) != EOF)
        Gao();
    return 0;
}
