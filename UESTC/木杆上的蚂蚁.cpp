#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct ant
{
    char name[50];
    char fx[50];
    int pos;
}a[150],res[150],res2[150];
int n,L;

bool cmp(ant a,ant b)
{
    return a.pos < b.pos;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&L);
        for (int i = 1;i <= n;i++)
        {
            scanf("%s%d%s",a[i].name,&a[i].pos,a[i].fx);
            res2[i].pos = (a[i].fx[0] == 'L')?(a[i].pos):(L-a[i].pos);
        }
        sort(a+1,a+n+1,cmp);
        int l,r;
        l = 1;
        r = n;
        int tot = 0;
        while (true)
        {
            if (tot == n)   break;
            for (int i = l;i <= r;i++)
            if (a[i].fx[0] == 'R'){  l = i;break;}
            else
            {
                tot++;
                strcpy(res[tot].name,a[i].name);
                l++;
            }
            for (int i = r;i >= l;i--)
            if (a[i].fx[0] == 'L'){ r = i;break;}
            else
            {
                tot++;
                strcpy(res[tot].name,a[i].name);
            }
            int tl,tr;
            tl = l;
            tr = r;
            for (int i = l;i < r;i++)
            if (a[i].fx[0] == 'R' && a[i+1].fx[0] == 'L')
            {
                tl = i;
                break;
            }
            for (int i = r-1;i >= l;i++)
            if (a[i].fx[0] == 'R' && a[i+1].fx[0] == 'L')
            {
                tr = i;
                break;
            }
            for (int i = l;i <= tl;i++)
                a[i].fx[0] = 'L';
            for (int i = tr+1;i <= r;i++)
                a[i].fx[0] = 'R';
            if (tl != tr)
            {
                a[tl+1].fx[0] = 'R';
                a[tr].fx[0] = 'L';
            }
        }
        sort(res+1,res+n+1,cmp);
        sort(res2+1,res2+n+1,cmp);
        printf("Case #%d:\n",ft);
        for (int i = 1;i <= n;i++)
            printf("%d %s\n",res2[i].pos,res[i].name);
    }
}
