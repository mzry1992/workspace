#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool flag[25][25];
bool dp[25][25];
bool f[25][25][2];
bool g[25][25][2];
int n;
char s[26];
bool solve(int l,int r);
bool calc(int l,int r,bool typ)
{
    if (f[l][r][typ])
        return g[l][r][typ];
    bool &ret=g[l][r][typ];
    f[l][r][typ]=true;
    int cnt = 0;
    for (int i = l;i <= r;i++)
        if (s[i] == 'a'+typ)
            cnt++;
    if (!cnt)
        return ret=0;
    if (cnt==r-l+1)
        return ret=1;
    for (int mid = l;mid < r;mid++)
    if (s[mid] != s[mid+1])
        if ((calc(l,mid,typ) && calc(mid+1,r,typ))||(calc(l,mid,typ)&&solve(mid+1,r))||(solve(l,mid)&&calc(mid+1,r,typ)))
            return ret=1;
    return ret=0;
}
bool solve(int l,int r)
{
    if (flag[l][r] == true) return dp[l][r];
    bool& res = dp[l][r];

    flag[l][r] = true;

    int cntb = 0;
    for (int i = l;i <= r;i++)
        if (s[i] == 'b')
            cntb++;
    if (cntb == 0)
        cntb = r-l+1;
    if (cntb == r-l+1)
    {
        if (cntb == 1)
            return res = false;
        return res = true;
    }

    for (int mid = l;mid < r;mid++)
        if (s[mid] != s[mid+1] && ((solve(l,mid) && solve(mid+1,r))||
                                   (calc(l,mid,0)&&calc(mid+1,r,0))||(calc(l,mid,1)&&calc(mid+1,r,1))))
            return res = true;
    return res=false;
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1;cas <= totcas;cas++)
    {
        scanf("%s",s);
        n = strlen(s);
        memset(flag,false,sizeof(flag));
        memset(f,false,sizeof(f));
        printf("%d\n",solve(0,n-1));
    }
    return 0;
}

