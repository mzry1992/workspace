#include <iostream>
using namespace std;

int n,k;
int p[2000];

int main()
{
    int t,i;
    scanf("%d",&t);
    for (t;t > 0;t--)
    {
        scanf("%d%d",&n,&k);
        for (i = 1;i <= n;i++)
            scanf("%d",&p[i]);
    }
    return 0;
}
