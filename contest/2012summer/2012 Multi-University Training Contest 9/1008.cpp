#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n,k;
int main()
{
    int cas=1;
    while(scanf("%d%d",&n,&k)==2)
    {
        if(k>1)
        {
            if (n%2 == 1 && k*2 == n-1)
                printf("Case %d: Alice %d\n",cas++,k);
            else
                printf("Case %d: Alice 1\n",cas++);
        }
        else
        {
            if(n%2==1)
                printf("Case %d: Bob\n",cas++);
            else
                printf("Case %d: Alice 1\n",cas++);
        }
    }
    return 0;
}
