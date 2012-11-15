#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct node
{
    long long a,b,c;
    int id;
    char key;
};

node a[10000];
int n;

bool cmp(const node&a,const node&b)
{
    if (a.c == b.c)
    {
        int ta,tb;
        if (a.key == '>')   ta = 3;
        else if (a.key == '=')  ta = 2;
        else ta = 1;
        if (b.key == '>')   tb = 3;
        else if (b.key == '=')  tb = 2;
        else tb = 1;
        if (ta == tb)
            return a.id < b.id;
        return ta > tb;
    }
    return a.c > b.c;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
        {
            scanf("%I64d%I64d",&a[i].a,&a[i].b);
            a[i].c = a[i].a+a[i].b;
            a[i].id = i;
            if (a[i].a > a[i].b)    a[i].key = '>';
            else if (a[i].a == a[i].b) a[i].key = '=';
            else a[i].key = '<';
        }
        sort(a,a+n,cmp);
        for (int i = 0;i < n;i++)
            printf("%I64d+%I64d=[%c%I64d]\n",a[i].a,a[i].b,a[i].key,a[i].c);
        printf("\n");
    }
    return 0;
}
