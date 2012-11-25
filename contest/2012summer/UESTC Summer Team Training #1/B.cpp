#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int a,b,c,ab,bc,ca;
int ta,tb,tc;

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1;cas <= totcas;cas++)
    {
        scanf("%d%d%d",&a,&b,&c);
        scanf("%d%d%d",&ab,&bc,&ca);
        int res = 0;
        for (int i = 0;i <= min(a,b);i++)
            for (int j = 0;j <= min(b,c);j++)
            {
                ta = a,tb = b,tc = c;
                ta -= i;
                tb -= i;
                tb -= j;
                tc -= j;
                if (ta < 0 || tb < 0 || tc < 0) continue;
                int k = min(ta,tc);
                res = max(res,i*ab+j*bc+k*ca);
                //printf("%d %d %d %d\n",i,j,k,i*ab+j*bc+k*ca);
            }
        printf("%d\n",res);
    }
    return 0;
}
