#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

bool flag[61][61][61][61];
int la,lb,dp[61][61][61][61];
char a[61],b[61];

int DP(int l1,int r1,int l2,int r2)
{
    if (l1 > r1 || l2 > r2) return 0;
    if (flag[l1][r1][l2][r2])   return dp[l1][r1][l2][r2];
    flag[l1][r1][l2][r2] = true;
    int& res = dp[l1][r1][l2][r2];
    res = 0;
    int nl1,nl2,nr1,nr2;
    for (int i = 0;i < 26;i++)
    {
        nl1 = l1;
        while (nl1 <= r1 && a[nl1]-'a' != i)    nl1++;
        if (nl1 > r1)   continue;
        nr1 = r1;
        while (nr1 >= l1 && a[nr1]-'a' != i)    nr1--;
        if (nr1 < l1)   continue;
        nl2 = l2;
        while (nl2 <= r2 && b[nl2]-'a' != i)    nl2++;
        if (nl2 > r2)   continue;
        nr2 = r2;
        while (nr2 >= l2 && b[nr2]-'a' != i)    nr2--;
        if (nr2 < l2)   continue;
        //printf("%d %d %d %d %d %d %d\n",l1,r1,l2,r2,nl1,nr1,nl2,nr2);
        if (nl1 == nr1 || nl2 == nr2)   res = max(res,1);
        else
            res = max(res,DP(nl1+1,nr1-1,nl2+1,nr2-1)+2);
    }
    return res;
}

int main()
{
    int totcas = 100;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%s%s",a,b);
        la = strlen(a);
        lb = strlen(b);
        memset(flag,false,sizeof(flag));
        printf("Case %d: %d\n",cas,DP(0,la-1,0,lb-1));
    }
    return 0;
}
