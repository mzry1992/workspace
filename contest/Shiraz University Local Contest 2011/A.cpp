#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[21];
int len,n;
long long num[21][21],a[9];
long long res,fac[10],nowres,a9n;

void DFS(int nown,int nowpos,long long nowval,int nowlen)
{
    //cout << nown << ' ' << nowpos << ' ' << nowval << ' ' << nowlen << endl;
    if (nown == n)
    {
        nowres = a9n;
        int pre = 0;
        for (int i = 1; i <= n; i++)
            if (i == n || a[i] != a[i-1])
            {
                nowres /= fac[i-pre];
                pre = i;
            }
        res += nowres;
//        printf("|");
//        for (int i = 0;i < n;i++)
//            printf("%lld ",a[i]);
//        printf(" nowres = %lld|\n",nowres);
        return;
    }

    if (s[nowpos] == '0')   return;

    if (nown == n-1)
    {
        if (num[nowpos][len-1] >= nowval)
        {
            a[nown] = num[nowpos][len-1];
            DFS(nown+1,0,0,0);
        }
        return;
    }
    //for (int i = nowpos+nowlen-1;i < len;i++)
    for (int i = nowpos; i < len; i++)
    {
        //if ((n-nown)*(i-nowpos+1) < len-nowpos) break;
        if (num[nowpos][i] >= nowval)
        {
            a[nown] = num[nowpos][i];
            DFS(nown+1,i+1,a[nown],i-nowpos+1);
        }
    }
}

int main()
{
    fac[0] = 1;
    for (int i = 1; i <= 9; i++)
        fac[i] = fac[i-1]*i;
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%s",s);
        len = strlen(s);
        for (int i = 0; i < len; i++)
        {
            num[i][i] = s[i]-'0';
            for (int j = i+1; j < len; j++)
                num[i][j] = num[i][j-1]*10+s[j]-'0';
        }
        n = s[0]-'0';

        if (len == 1 || s[1] == '0')
            res = 0;
        else if (n == 1)
            res = 9;
        else
        {
            res = 0;
            a9n = fac[9]/fac[9-n];
            DFS(0,1,0,0);
        }
        printf("%lld\n",res);
    }
    return 0;
}
