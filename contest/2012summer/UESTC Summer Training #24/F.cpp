#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a[300];
int m[1000000];
int main()
{
    int totcas;
    scanf("%d",&totcas);
    while (totcas--)
    {
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
            scanf("%d",&a[i]);
        memset(m,0,sizeof(m));
        for (int i=n; i<=1000000; i++)
        {
            bool flag=1;
            for (int j=0; j<n; j++)
                if (m[a[j]%i]==i)
                {
                    flag=0;
                    break;
                }
                else
                    m[a[j]%i]=i;
            if (flag)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
