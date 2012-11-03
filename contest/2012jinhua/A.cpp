#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n1,n2,a1[30],a2[30],res[30];

bool cmp(int a,int b)
{
    return a > b;
}

bool cmp2(int a,int b)
{
    if (a%10 == b%10)
        return a < b;
    return a%10 < b%10;
}

void Gao()
{
    sort(a1,a1+n1,cmp);
    sort(a2,a2+n2,cmp);
    n1 = unique(a1,a1+n1)-a1;
    n2 = unique(a2,a2+n2)-a2;
    for (int len = min(n1,n2); len >= 1; len--)
    {
        for (int i = 0;i+len <= n1;i++)
            for (int j = 0;j+len <= n2;j++)
            {
                bool check = true;
                for (int k = 0;k < len;k++)
                    if (a1[i+k] != a2[j+k])
                    {
                        check = false;
                        break;
                    }
                if (check == true)
                {
                    for (int k = 0;k < len;k++)
                        res[k] = a1[i+k];
                    printf("%d",res[0]);
                    for (int k = 1;k < len;k++)
                        printf(" %d",res[k]);
                    printf("\n");
                    sort(res,res+len,cmp2);
                    printf("%d",res[0]);
                    for (int k = 1;k < len;k++)
                        printf(" %d",res[k]);
                    printf("\n");
                    return;
                }
            }
    }
    puts("NONE");
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%d%d",&n1,&n2);
        for (int i = 0; i < n1; i++)
            scanf("%d",&a1[i]);
        for (int i = 0; i < n2; i++)
            scanf("%d",&a2[i]);
        Gao();
    }
    return 0;
}
