#include<cstdio>
#include<cstdlib>

int main()
{
    freopen("table.out","w",stdout);
    for (int i=0;i<64;i++)
    {
        int ii=i;
        char a[7];
        a[6]=0;
        for (int j=5;j>=0;j--)
        {
            if (ii&1) a[j]='1';else a[j]='0';
            ii/=2;
        }
        printf("\"%s\",",a);
    }
}
