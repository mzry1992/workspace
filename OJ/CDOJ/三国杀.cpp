#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
int m1[2200],m2[2200];
char s1[10],s2[10],s3[10];

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        memset(m1,0,sizeof(m1));
        memset(m2,0,sizeof(m2));
        printf("Case #%d:\n",ft);
        for (int i = 1;i <= m;i++)
        {
            scanf("%s%s%s",s1,s2,s3);
            int a,b;
            if (s1[0] == 'K')
            {
                sscanf(s2,"%d",&a);
                sscanf(s3,"%d",&b);
                int dist;
                dist = (b-a > 0)?(b-a):(a-b);
                dist = (dist > n-dist)?(n-dist):dist;
                dist = dist-m1[a]+m2[b];
                if (dist <= 1)
                    printf("Yes!\n");
                else
                    printf("I'm sorry.\n");
            }
            else
            {
                sscanf(s1,"%d",&a);
                sscanf(s3,"%d",&b);
                if (s2[0] == '-')
                    m1[a] = b;
                else
                    m2[a] = b;
            }
        }
        printf("\n");
    }
}
