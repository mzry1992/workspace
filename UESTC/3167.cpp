#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,s,a[100000],b[25000],c[25000],d[100000],next[25000],pnow,check[100000],newcheck[100000];
bool rank[26];

int main()
{
    while (scanf("%d%d%d",&n,&m,&s) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
            check[i] = 0;
        }
        for (int i = 1; i <= s; i++)
            rank[i] = false;
        for (int i = 0; i < m; i++)
        {
            scanf("%d",&b[i]);
            rank[b[i]] = true;
        }
        for (int i = 1; i <= s; i++)
            if (rank[i] == true)
            {
                for (int k = 0; k < n; k++)
                    newcheck[k] = s+1;
                for (int j = 1; j <= s; j++)
                {
                    for (int k = 0; k < m; k++)
                        c[k] = (b[k] == i)?j:0;
                    for (int k = 0; k < n; k++)
                        d[k] = (a[k] == j)?j:0;
                    next[0] = pnow = -1;
                    for (int k = 1; k < m; k++)
                    {
                        while (pnow >= 0 && c[pnow+1] != c[k])  pnow = next[pnow];
                        if (c[pnow+1] == c[k])  pnow++;
                        next[k] = pnow;
                    }
                    pnow = -1;
                    for (int k = 0; k < n; k++)
                    {
                        while (pnow >= 0 && c[pnow+1] != d[k])  pnow = next[pnow];
                        if (c[pnow+1] == d[k])   pnow++;
                        if (pnow+1 == m)
                        {
                            newcheck[k-m+1] = j;
                            pnow = next[pnow];
                        }
                    }
                }
                for (int k = 0; k < n; k++)
                    if (newcheck[k] <= check[k])  check[k] = s+1;
                    else check[k] = newcheck[k];
            }
        int count = 0;
        for (int i = 0; i < n; i++)
            if (check[i] <= s)
                count++;
        printf("%d\n",count);
        for (int i = 0; i < n; i++)
            if (check[i] <= s)
                printf("%d\n",i+1);
    }
    return 0;
}
