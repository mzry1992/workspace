#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

int n,b;
struct thing
{
    string type;
    int v;
    int w;
}a[1200];
int w[1200];

bool cmp1(thing a,thing b)
{
    return a.type < b.type;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&b);
        for (int i = 1;i <= n;i++)
        {
            cin >> a[i].type;
            scanf("%*s%d%d",&a[i].v,&a[i].w);
            w[i] = a[i].w;
        }
        sort(a+1,a+n+1,cmp1);
        sort(w+1,w+n+1);
        int maxres = 0;
        int tl,tr;
        tl = 1;
        tr = n;
        while (tl+1 < tr)
        {
            int mid = (tl+tr)/2;
            int minw = w[mid];
            int nowtype = 0;
            int head = 1;
            int tcost = 0;
            int nowcost = 1992100500;
            bool flag = true;
            int j = 1;
            while (j <= n)
            {
                if (a[head].type == a[j].type)
                {
                    if (a[j].w >= minw)
                    {
                        if (a[j].v < nowcost)
                            nowcost = a[j].v;
                    }
                    j++;
                }
                else
                {
                    if (nowcost == 1992100500)
                        flag = false;
                    tcost += nowcost;
                    nowcost = 1992100500;
                    head = j;
                    j = head;
                }
            }
            if (nowcost == 1992100500)
                flag = false;
            tcost += nowcost;
            if (flag == true && tcost <= b)
                tl = mid;
            else
                tr = mid-1;
        }
        printf("%d\n",w[tl]);
    }
}
