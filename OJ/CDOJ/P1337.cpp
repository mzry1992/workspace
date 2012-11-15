#include <iostream>
using namespace std;

int tcase,fcase;
int n,m;
int ans;

int solve(int n,int m)
{
    int i,j;
    if (n > m)
    {
          i = n;    n = m;  m = i;
    }
    
    return 0;
}

int main()
{
    scanf("%d",&tcase);
    for (fcase = 1;fcase <= tcase;fcase++)
    {
        scanf("%d %d",&n,&m);
        ans = solve(n,m);
        printf("%d\n",ans);
    }
}
