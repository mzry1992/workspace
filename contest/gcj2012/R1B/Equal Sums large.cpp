#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <map>
using namespace std;

int n;
long long a[500];
int b[500];
map<long long,int> res;
FILE* fout;

bool Gao()
{
    for (int tims = 0; tims <= 50; tims++)
    {
        if (tims% 5 == 0)
            printf("-");
        random_shuffle(b,b+n);
        res.clear();
        for (int i = 1; i < (1<<20); i++)
        {
            long long sum = 0;
            for (int j = 0; j < 20; j++)
                if (((i>>j)&1) == 1)
                    sum += a[b[j]];
            res[sum] = i;
        }
        for (int i = 1; i < (1<<20); i++)
        {
            long long sum = 0;
            for (int j = 0; j < 20; j++)
                if (((i>>j)&1) == 1)
                    sum += a[b[20+j]];
            if (res.find(sum) != res.end())
            {
                int msk = res[sum];
                for (int j = 0;j < 20;j++)
                    if (((msk>>j)&1) == 1)
                        fprintf(fout,"%lld ",a[b[j]]);
                fprintf(fout,"\n");
                msk = i;
                for (int j = 0;j < 20;j++)
                    if (((msk>>j)&1) == 1)
                        fprintf(fout,"%lld ",a[b[20+j]]);
                fprintf(fout,"\n");
                printf("\n");
                return true;
            }
        }
    }
    printf("\n");
    return false;
}

int main()
{
    freopen("C-large.in","r",stdin);
    fout = fopen("C-large.out","w");
    srand(time(0));
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld",&a[i]);
            b[i] = i;
        }
        printf("case %d\n",cas);
        fprintf(fout,"Case #%d:\n",cas);
        if (Gao() == false)
            fprintf(fout,"Impossible\n");
    }
    return 0;
}

