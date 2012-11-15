#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,p,a[500];
bool b[500];

int main()
{
    while (scanf("%d%d",&n,&p) != EOF)
    {
        for (int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        memset(b,false,sizeof(b));
        sort(a,a+n);
        for (int i = 0;i < n;i++)
            if (a[i] > p)
            {
                p += 2;
                b[i] = true;
            }
        for (int i = 0;i < n;i++)
            if (b[i] == false)
                p++;
        printf("%d\n",p);
    }
}
