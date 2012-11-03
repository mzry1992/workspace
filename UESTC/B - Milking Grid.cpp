#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int totf = 3;
const int mut[totf] = {29,31,37};
const int mod[totf] = {10000019,10000079,10000103};
int n,m,resn,resm,ts[10010][totf],next[10010],pnow;
char s[10010][100];

bool same(int i,int j)
{
    for (int k = 0;k < totf;k++)
        if (ts[i][k] != ts[j][k])   return false;
    return true;
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 0;i < n;i++)
            scanf("%s",s[i]);
        int res;
        for (int i = 0;i < m;i++)
        {
            bool check = true,tcheck;
            for (int j = i+1;j < m;j++)
            {
                tcheck = true;
                for (int k = 0;k < n;k++)
                    if (s[k][j] != s[k][j%(i+1)])
                    {
                        tcheck = false;
                        break;
                    }
                if (tcheck == false)
                {
                    check = false;
                    break;
                }
            }
            if (check == false)    continue;
            for (int j = 0;j < n;j++)
            {
                for (int f = 0;f < totf;f++)
                    ts[j][f] = 0;
                for (int k = 0;k <= i;k++)
                    for (int f = 0;f < totf;f++)
                        ts[j][f] = (ts[j][f]*mut[f]+s[j][k]-'A')%mod[f];
            }
            pnow = next[0] = -1;
            for (int j = 1;j < n;j++)
            {
                while (pnow >= 0 && !same(pnow+1,j))    pnow = next[pnow];
                if (same(pnow+1,j)) pnow++;
                next[j] = pnow;
            }
            res = (i+1)*(n-next[n-1]-1);
            break;
        }
        printf("%d\n",res);
    }
    return 0;
}
