#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int totg,n,f[30],ind[30],outd[30],res[1010],totres;
struct graph
{
    int to,next;
    string word;
}g[30+1010];
char tmp[30];

int findf(int x)
{
    if (f[x] != x)  f[x] = findf(f[x]);
    return f[x];
}

void EulerRoad(int now,int roadIndex)
{
    int i;
    while (g[now].next != -1)
    {
        i = g[now].next;
        g[now].next = g[i].next;//????????????
        EulerRoad(g[i].to,i);
    }
    totres++;
    res[totres] = roadIndex;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        totg = 26;
        for (int i = 1;i <= 26;i++)
        {
            g[i].next = -1;
            f[i] = i;
            ind[i] = outd[i] = 0;
        }
        scanf("%d",&n);
        for (int i = 1;i <= n;i++)
        {
            scanf("%s",tmp);
            int u = tmp[0]-'a'+1;
            int v = tmp[strlen(tmp)-1]-'a'+1;
            int temp = g[u].next,now = u;
            while (temp != -1 && strcmp(g[temp].word.c_str(),tmp) < 0)
            {
                now = temp;
                temp = g[temp].next;
            }
            totg++;
            g[totg].to = v;
            g[totg].word = tmp;
            g[totg].next = temp;
            g[now].next = totg;
            if (findf(u) != findf(v))
                f[findf(u)] = findf(v);
            ind[v]++;
            outd[u]++;
        }
        int check1,check2,check3,check4,first;
        check1 = check2 = check3 = check4 = first = 0;
        for (int i = 1;i <= 26;i++)
        {
            if (ind[i] != outd[i])  check1++;
            if (ind[i]+1 == outd[i])   check2++;
            if (ind[i] == outd[i]+1)   check3++;
            if (ind[i]+outd[i] > 0)
            {
                if (first == 0) first = i;
                if (findf(i) != findf(first))   check4++;
            }
        }
        if ((check1 == 0 || (check1 == 2 && check2 == 1 && check3 == 1)) && check4 == 0)
        {
            totres = 0;
            if (check1 == 0)
            {
                for (int i = 1;i <= 26;i++)
                    if (ind[i] != 0)
                    {
                        EulerRoad(i,-1);
                        break;
                    }
            }
            else
            {
                for (int i = 1;i <= 26;i++)
                    if (outd[i] > ind[i])
                    {
                        EulerRoad(i,-1);
                        break;
                    }
            }
            for (int i = totres-1;i >= 2;i--)
                printf("%s.",g[res[i]].word.c_str());
            printf("%s\n",g[res[1]].word.c_str());
        }
        else printf("***\n");
    }
}
