#include <iostream>
#include <cstdio>
#include <cstring>
#define MIN(X,Y) (((X)>(Y))?(Y):(X))
using namespace std;

int n;
char s[100];
int use[100][100];

int solve(int l,int r)
{
    if (use[l][r] != 0) return use[l][r];
    if (l == r)
    {
        use[l][r] = 1;
        return use[l][r];
    }
    if (l > r)  return 0;
    int res = 19921005;
    if (s[l] == s[r])
        res = MIN(solve(l,r-1),solve(l+1,r));
    else
        res = 1+MIN(solve(l,r-1),solve(l+1,r));
    for (int i = l+1;i <= r-2;i++)
        res = MIN(res,solve(l,i)+solve(i+1,r));
    use[l][r] = res;
    return use[l][r];
}

int main()
{
    while (true)
    {
        int tn;
        scanf("%d",&tn);
        if (tn == 0) break;
        char ts[100];
        scanf("%s",ts);
        n = 1;
        s[0] = ts[0];
        for (int i = 1;i < tn;i++)
        if (ts[i] != ts[i-1])
        {
            s[n] = ts[i];
            n++;
        }
        s[n] = 0;
        memset(use,0,sizeof(use));
        int res = solve(0,n-1);
        printf("%d\n",res);
    }
}
