#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int x,y;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&x,&y);
        double res = 1/(double)(x*y+y+1);
        printf("Case #%d: %.8f\n",ft,res);
    }
    return 0;
}
