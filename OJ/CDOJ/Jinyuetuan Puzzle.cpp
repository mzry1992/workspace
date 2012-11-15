#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a[7][1001],m,b[1<<7];
char buf[50];
int len,op,ed,tc;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for (int i = 0;i < 7;i++)
        {
            scanf("%d",&tc);
            for (int j = 0;j < tc;j++)
            {
                scanf("%s",buf);
                len = strlen(buf);
                for (int k = 0;k <= len;k++)
                    if (k == len)
                    {
                        sscanf(buf,"%d",&op);
                        a[i][op] = 1;
                    }
                    else if (buf[k] == '-')
                    {
                        sscanf(buf,"%d-%d",&op,&ed);
                        a[i][op] = 2;
                        a[i][ed] = -2;
                        break;
                    }
            }
        }
        scanf("%d",&m);
        for (int i = 0;i < m;i++)
        {
            scanf("%s",buf);
            b[i] = 0;
            for (int j = 6;j >= 0;j--)
            {
                b[i] <<= 1;
                if (buf[j] == '1')
                    b[i] |= 1;
            }
        }
    }
    return 0;
}
