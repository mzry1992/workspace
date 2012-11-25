#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char a[1000010],b[10010];
int p[10010],la,lb;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%s%s",b,a);
        la = strlen(a);
        lb = strlen(b);
int j;
p[0] = j = -1;
for (int i = 1; i < lb; i++)
{
    while (j >= 0 && b[j+1] != b[i])    j = p[j];
    if (b[j+1] == b[i]) j++;
    p[i] = j;
}
j = -1;
int res = 0;
for (int i = 0;i < la;i++)
{
    while (j >= 0 && b[j+1] != a[i])    j = p[j];
    if (b[j+1] == a[i]) j++;
    if (j+1 == lb)
        res++;
}
printf("%d\n",res);
    }
    return 0;
}
