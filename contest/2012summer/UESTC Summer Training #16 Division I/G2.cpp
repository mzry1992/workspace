#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char sa[100],sb[100];
int a[100],b[100],c[100];

int main()
{
    scanf("%s%s",sa,sb);
    int l = strlen(sa);
    for (int i = 1;i < l-1;i++)
    {
        a[i-1] = sa[l-1-i]-'0';
        b[i-1] = sb[l-1-i]-'0';
    }
    l -= 2;
    for (int i = 0;i < 3*l;i++)
        a[l+i] = a[i],b[l+i] = b[i];
    memset(c,0,sizeof(c));
    for (int i = 0;i < 4*l;i++)
    {
        c[i] += a[i]+b[i];
        c[i+1] += c[i]/10;
        c[i] %= 10;
    }
//    for (int i = 2*l;i >= 0;i--)
//        printf("%d",c[i]);
//    printf("\n");
    bool find = false;
    for (int len = 1;len <= l && !find;len++)
    {
        for (int ii = 0;ii < 2*l && !find;ii++)
        {
            bool flag = true;
            for (int i = ii+len;i < 4*l && flag;i++)
                if (c[i] != c[i-len])
                    flag = false;
            if (flag)
            {
                printf("(");
                for (int i = len-1;i >= 0;i--)
                    printf("%d",c[ii+i]);
                printf(")");
                for (int i = ii-1;i >= 0;i--)
                    printf("%d",c[i]);
                printf("\n");
                find = true;
            }
        }
    }
    return 0;
}
