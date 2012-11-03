#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

int n,m;
set<long long> res;
char com[100],a,b;
int c,d;
long long tmp;

int main()
{
    freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        res.clear();
        for (int i = 0;i < m;i++)
        {
            scanf("%s",com);
            a = com[0];
            c = 0;
            for (int j = 2;;j++)
            {
                if (com[j] == ',')
                {
                    b = com[j+1];
                    d = 0;
                    for (int k = j+3;com[k] != 0;k++)
                        d = d*10+com[k]-'0';
                    break;
                }
                c = c*10+com[j]-'0';
            }
            if (a > b)
            {
                swap(a,b);
                swap(c,d);
            }
            if (c > n || d > n) continue;
            c--;
            d--;
            for (int j = 0;j < n;j++)
            {
                if (a == 'X' && b == 'Y')
                    tmp = c*1000*1000+d*1000+j;
                else if (a == 'X' && b == 'Z')
                    tmp = c*1000*1000+j*1000+d;
                else
                    tmp = j*1000*1000+c*1000+d;
                res.insert(tmp);
            }
        }
        printf("%d\n",res.size());
    }
    return 0;
}
