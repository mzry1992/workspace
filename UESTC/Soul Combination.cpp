#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char sa[2000],sb[2000];
int k;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&k);
        scanf("%s",sa);
        scanf("%s",sb);
        int cur = 0;
        int l = strlen(sa);
        printf("Case #%d: ",ft);
        while (true)
        {
            if (cur+k-1 < l)
            {
                for (int i = 0;i < k;i++)
                    putchar(sa[cur+i]);
                for (int i = 0;i < k;i++)
                    putchar(sb[cur+i]);
                cur += k;
            }
            else
            {
                for (int i = cur;i < l;i++)
                    putchar(sa[i]);
                for (int i = cur;i < l;i++)
                    putchar(sb[i]);
                break;
            }
        }
        puts("");
    }
}
