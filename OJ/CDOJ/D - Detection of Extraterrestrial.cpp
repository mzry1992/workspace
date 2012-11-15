#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[1000],ks[1000];
int len,res[1000],lenks;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%s",s);
        len = strlen(s);
        for (int i = 1;i <= len;i++)
        {
            res[i] = 0;
            for (int j = 1;j*i <= len;j++)
            {
                for (int k = 0;k+j-1 < len;k++)
                {
                    lenks = 0;
                    for (int q = 1;q <= i;q++)
                        for (int p = 0;p < j;p++)
                            ks[lenks++] = s[k+p];
                    ks[lenks++] = 0;
                    if (strstr(s,ks) != 0)
                        res[i] = lenks-1;
                }
            }
        }
        printf("Case #%d: ",ft);
        for (int i = 1;i <= len;i++)
            printf("%d ",res[i]);
        printf("\n");
    }
}
