#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,tot,res[200],totres,r[200],reslcm;
const int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
struct canuse
{
    int val,id;
}num[200];

bool cmp(canuse a,canuse b)
{
    return a.val < b.val;
}

void DFS(int dep,int last,int sum,int use,int lcm)
{
    if (sum == n)
    {
        if (lcm > reslcm)
        {
            reslcm = lcm;
            totres = dep;
            for (int i = 0;i < dep;i++)
                r[i] = res[i];
        }
        else if (lcm == reslcm)
        {
            for (int i = 0;i < min(dep,totres);i++)
                if (r[i] > res[i])
                {
                    totres = dep;
                    for (int j = 0;j < dep;j++)
                        r[j] = res[j];
                    break;
                }
        }
        return;
    }
    for (int i = 1;i < tot;i++)
        if (num[i].val > last && sum+num[i].val <= n)
            if (((use>>num[i].id)&1) == 0)
            {
                res[dep] = num[i].val;
                DFS(dep+1,num[i].val,sum+num[i].val,use|(1<<num[i].id),lcm*num[i].val);
            }
}

int main()
{
    tot = 1;
    num[0].val = 1;
    num[0].id = 25;
    for (int i = 0;i < 25;i++)
        for (int j = prime[i];j <= 100;j = j*prime[i])
        {
            num[tot].val = j;
            num[tot].id = i;
            tot++;
        }
    sort(num,num+tot,cmp);
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        reslcm = 0;
        DFS(0,0,0,0,1);
        res[0] = 1;
        DFS(1,1,1,0,1);
        int now = 0;
        printf("%d ",reslcm);
        for (int i = 0;i < totres;i++)
        {
            for (int j = now+2;j <= now+r[i];j++)
                printf("%d ",j);
            printf("%d ",now+1);
            now = now+r[i];
        }
        printf("\n");
    }
}
