#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char a[110000],b[110000];
int cntq[110000],cnt1[110000];
int l;

bool check(char a,char b)
{
    if (a == '?')   return true;
    return a == b;
}

void pre()
{
    cntq[0] = 0;
    cnt1[0] = 0;
    for (int i = 0; i < l; i++)
    {
        if (a[i] == '?' && b[i] == '?')
            cntq[i]++;
        else if (check(a[i],'1') && check(b[i],'1'))
            cnt1[i]++;
        cntq[i+1] = cntq[i];
        cnt1[i+1] = cnt1[i];
    }
}

int solve2(int pos,bool flag)
{
    int tot = 0;
    if (pos > 0)
        tot = cntq[pos-1];
    if (tot > 1)
        return -2;
    else if (tot == 1)
        return pos;
    else if (tot == 0)
    {
        tot = 0;
        if (pos > 0)
            tot = cnt1[pos-1];
        if (flag)
            tot++;
        if (tot%2 == 0)   return pos;
        else
            return -1;
    }
}

void updata(int &res,int tmp)
{
    if (tmp == -2)
        res = -2;
    else if (tmp >= 0)
    {
        if (res >= 0)
            res = -2;
        else res = tmp;
    }
}

int solve()
{
    pre();
    int cnt = 0;
    for (int i = 0; i < l; i++)
        if (a[i] != '?' && b[i] != '?')
            if (a[i] != b[i])
                cnt++;
    if (cnt > 1)
        return -1;
    else if (cnt == 1)
    {
        for (int i = 0; i < l; i++)
            if (a[i] != '?' && b[i] != '?')
                if (a[i] != b[i])
                {
                    if (i+1 < l)
                    {
                        if (!check(a[i+1],'1') || !check(b[i+1],'1'))
                            return -1;
                        for (int j = i+2; j < l; j++)
                            if (!check(a[j],'0') || !check(b[j],'0'))
                                return -1;
                    }
                    return solve2(i,a[i] == '1');
                }
    }
    else
    {
        int res = -1;
        if (a[l-1] == '?' && b[l-1] == '?')
        {
            int tmp;
            tmp = solve2(l-1,false);
            updata(res,tmp);
            if (res == -2)
                return -2;
            tmp = solve2(l-1,true);
            updata(res,tmp);
            if (res == -2)
                return -2;
        }
        else if (a[l-1] == '?')
        {
            res = solve2(l-1,b[l-1] == '0');
            if (res == -2)
                return -2;
        }
        else if (b[l-1] == '?')
        {
            res = solve2(l-1,a[l-1] == '1');
            if (res == -2)
                return -2;
        }
        for (int i = l-1; i >= 0; i--)
            if (a[i] == '?' && b[i] == '?')
            {
                if (i == 0)
                    return res;
                else
                {
                    if (a[i-1] != '?' && a[i-1] == b[i-1])
                        return res;
                    if (a[i-1] == '?' && b[i-1] == '?')
                    {
                        int tmp;
                        tmp = solve2(i-1,false);
                        updata(res,tmp);
                        if (res == -2)
                            return -2;
                        tmp = solve2(i-1,true);
                        updata(res,tmp);
                        if (res == -2)
                            return -2;
                    }
                    else if (a[i-1] == '?')
                    {
                        int tmp;
                        tmp = solve2(i-1,b[i-1] == '0');
                        updata(res,tmp);
                        if (res == -2)
                            return -2;
                    }
                    else if (b[i-1] == '?')
                    {
                        int tmp = solve2(i-1,a[i-1] == '1');
                        updata(res,tmp);
                        if (res == -2)
                            return -2;
                    }
                }
            }
            else if (check(a[i],'0') && check(b[i],'0'))
            {
                continue;
            }
            else if (check(a[i],'1') && check(b[i],'1'))
            {
                if (i == 0)
                    return res;
                else
                {
                    if (a[i-1] != '?' && a[i-1] == b[i-1])
                        return res;
                    if (a[i-1] == '?' && b[i-1] == '?')
                    {
                        int tmp;
                        tmp = solve2(i-1,false);
                        updata(res,tmp);
                        if (res == -2)
                            return -2;
                        tmp = solve2(i-1,true);
                        updata(res,tmp);
                        if (res == -2)
                            return -2;
                    }
                    else if (a[i-1] == '?')
                    {
                        int tmp;
                        tmp = solve2(i-1,b[i-1] == '0');
                        updata(res,tmp);
                        if (res == -2)
                            return -2;
                    }
                    else if (b[i-1] == '?')
                    {
                        int tmp = solve2(i-1,a[i-1] == '1');
                        updata(res,tmp);
                        if (res == -2)
                            return -2;
                    }
                }
            }
        return res;
    }
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1;cas <= totcas;cas++)
    {
        scanf("%s%s",a,b);
        l = strlen(a);
        int res = solve();

        printf("Case #%d:\n",cas);
        if (res == -1)
            puts("Impossible");
        else if (res == -2)
            puts("Ambiguity");
        else
        {
            printf("%d\n",res);
        }
    }
    return 0;
}
