#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[100],ts[100],ns[100];
int a,b,res,len,l;

bool check2(char *s,int num)
{
    sprintf(ts,"%d",num);
    len = strlen(ts);
    for (int i = 1;i < len;i++)
        if (ts[i] > ts[i-1])
            ns[i-1] = '/';
        else if (ts[i] == ts[i-1])
            ns[i-1] = '-';
        else
            ns[i-1] = '\\';
    int cur = 0,tot,ttot;
    for (int i = 0;i < l;)
    {
        if (s[i] != ns[cur])    return false;
        tot = 0;
        for (int j = i;j < l;j++)
            if (s[j] == s[i])
                tot++;
            else
                break;
        ttot = 0;
        for (int j = cur;j < len-1;j++)
            if (ns[j] == ns[cur])
                ttot++;
            else
                break;
        if (ttot < tot) return false;
        cur += ttot;
        i += tot;
    }
    if (cur < len-1)    return false;
    return true;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out1.txt","w",stdout);
    while (scanf("%s",s) != EOF)
    {
        scanf("%d%d",&a,&b);
        res = 0;
        l = strlen(s);
        for (int i = a;i <= b;i++)
            if (check2(s,i) == true)
            {
                res++;
            }
        printf("%08d\n",res);
    }
}
