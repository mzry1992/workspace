#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int h,n,l,r;
struct ss
{
    int l,r;
    int id;
}s[50100];
int res[100100];
bool use[50100];

int main()
{
    while (scanf("%d%d",&h,&n) != EOF)
    {
        memset(s,0,sizeof(s));
        memset(res,0,sizeof(res));
        memset(use,false,sizeof(use));
        for (int i = 1;i <= n;i++)
        {
            scanf("%d%d",&l,&r);
            s[i].id = i;
            s[i].l = l;
            s[i].r = r;
        }
        bool flag;
        flag = true;
        for (int i = 1;i <= n;i++)
            if (s[i].l-s[i].r != s[1].l-s[1].r)
            {
                flag = false;
                break;
            }
        if (s[1].l == s[1].r)
        {
            for (int i = 2;i <= n;i++)
                if (s[i].l != s[i-1].l)
                {
                    flag = false;
                    break;
                }
            if (flag == false)
            {
                printf("0\n");
                continue;
            }
            for (int i = 1;i <= n;i++)
                printf("%d ",i);
            printf("\n");
            continue;
        }
        int now = s[1].l;
        res[now] = 1;
        for (int i = 2;i <= n;i++)
        {
            if (s[i].l >= minl && s[i].l <= maxl)
            {
                if (res[s[i].l] == 0)
                {
                    res[s[i].l] = s[i].id;
                    continue;
                }
            }
            if (h-s[i].r >= minl && h-s[i].r <= maxl)
            {
                if (res[h-s[i].r] == 0)
                {
                    res[h-s[i].r] = -s[i].id;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        for (int i = minl;i <= maxl;i += abs(s[1].l-s[1].r))
            if (res[i] == 0)
            {
                flag = false;
                break;
            }
        if (flag == false)
        {
            printf("0\n");
            continue;
        }
        if (s[1].l < s[1].r)
        {
            for (int i = minl;i <= maxl;i += abs(s[1].l-s[1].r))
                printf("%d ",res[i]);
            printf("\n");
        }
        else
        {
            for (int i = maxl;i >= minl;i -= abs(s[1].l-s[1].r))
                printf("%d ",res[i]);
            printf("\n");
        }
    }
}
