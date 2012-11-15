#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
#include <algorithm>
using namespace std;

int n,pos;
char s[10];
int curO,curB;
int totO,totB;

int abs(int x)
{
    if (x < 0)  return -x;
    return x;
}

int main()
{
    int t;
    freopen("A-large.in","r",stdin);
    freopen("AAAAAA.txt","w",stdout);
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        curO = curB = 1;
        totO = totB = 0;
        for (int i = 1;i <= n;i++)
        {
            scanf("%s%d",s,&pos);
            if (s[0] == 'O')
            {
                int now = curO;
                for (int i = 1;i <= abs(pos-now);i++)
                    totO++;
                if (totO < totB)    totO = totB;
                totO++;
                curO = pos;
            }
            else
            {
                int now = curB;
                for (int i = 1;i <= abs(pos-now);i++)
                    totB++;
                if (totB < totO)    totB = totO;
                totB++;
                curB = pos;
            }
        }
        printf("Case #%d: %d\n",ft,max(totO,totB));
    }
}
