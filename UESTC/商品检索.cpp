#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

char tn[50],s[100001];
int n,m,l,len;
double a[100000][8],amin,amax,dif,bmin,bmax,wmin,wmax;

int cmp(double a,double b)
{
    if (fabs(a-b) < 1e-5)   return 0;
    if (a < b)  return -1;
    return 1;
}

const char be[] = "begin";
const char ed[] = "end";

struct tree
{
    int next[26*2+10],end;
};
tree buf[11000*30];
int totbuf;

int getid(char ch)
{
    if (ch >= 'a' && ch <= 'z') return ch-'a';
    if (ch >= 'A' && ch <= 'Z') return ch-'A'+26;
    return ch-'0'+26*2;
}

int main()
{
    freopen("in.in","r",stdin);
    freopen("out2.out","w",stdout);
    while (scanf("%d%d",&n,&m) != EOF)
    {
        totbuf = 0;
        for (int i = 0;i < 26*2+10;i++)
            buf[totbuf].next[i] = -1;
        buf[totbuf++].end = 0;
        for (int i = 0;i < n;i++)
        {
            scanf("%s",tn);
            len = strlen(tn);
            int cur = 0;
            for (int j = 0;j < len;j++)
            {
                if (buf[cur].next[getid(tn[j])] == -1)
                {
                    for (int k = 0;k < 52+10;k++)
                    {
                        buf[totbuf].next[k] = -1;
                        buf[totbuf].end = 0;
                    }
                    buf[cur].next[getid(tn[j])] = totbuf++;
                }
                cur = buf[cur].next[getid(tn[j])];
                buf[cur].end++;
            }
        }
        for (int i = 0;i < m;i++)
        {
            scanf("%d",&l);
            for (int j = 0;j < l;j++)
                for (int k = 0;k < 8;k++)
                    scanf("%lf",&a[j][k]);
            amin = amax = a[0][0];
            for (int j = 0;j < l;j++)
                for (int k = 0;k < 8;k++)
                {
                    amin = min(amin,a[j][k]);
                    amax = max(amax,a[j][k]);
                }
            if (cmp(amin,0.95*(amin+amax)/2.0) >= 0 &&
                cmp(amax,1.05*(amin+amax)/2.0) <= 0)
            {
                puts("wrong barcode!");
                continue;
            }
            dif = (amin+amax)/2.0;
            bmax = wmin = dif;
            bmin = amax;
            wmax = amin;
            for (int j = 0;j < l;j++)
                for (int k = 0;k < 8;k++)
                    if (cmp(a[j][k],dif) < 0)
                    {
                        wmin = min(wmin,a[j][k]);
                        wmax = max(wmax,a[j][k]);
                    }
                    else
                    {
                        bmin = min(bmin,a[j][k]);
                        bmax = max(bmax,a[j][k]);
                    }
            if (cmp(bmin,0.95*(bmin+bmax)/2.0) < 0 ||
                cmp(bmax,1.05*(bmin+bmax)/2.0) > 0)
            {
                puts("wrong barcode!");
                continue;
            }
            if (cmp(wmin,0.95*(wmin+wmax)/2.0) < 0 ||
                cmp(wmax,1.05*(wmin+wmax)/2.0) > 0)
            {
                puts("wrong barcode!");
                continue;
            }
            if (cmp(wmin*2,bmax) > 0 ||
                cmp(wmax*2,bmin) < 0)
            {
                puts("wrong barcode!");
                continue;
            }
            for (int j = 0;j < l;j++)
            {
                s[j] = 0;
                for (int k = 0;k < 8;k++)
                {
                    s[j] <<= 1;
                    if (cmp(a[j][k],dif) >= 0)
                        s[j] |= 1;
                }
            }
            bool flag = false;
            for (int j = 0;j < 5;j++)
                if (s[j] != be[j])
                {
                    puts("wrong barcode!");
                    flag = true;
                    break;
                }
            if (flag)   continue;
            for (int j = l-3;j < l;j++)
                if (s[j] != ed[j-(l-3)])
                {
                    puts("wrong barcode!");
                    flag = true;
                    break;
                }
            if (flag)   continue;
            for (int j = 0;j < l;j++)
                if ((s[j] < 'A' || s[j] > 'Z') &&
                    (s[j] < 'a' || s[j] > 'z') &&
                    (s[j] < '0' || s[j] > '9'))
                    {
                        puts("wrong barcode!");
                        flag = true;
                        break;
                    }
            if (flag)   continue;
            int res = 0;
            int cur = 0;
            bool hasend = true;
            for (int j = 5;j < l-3;j++)
            {
                if (buf[cur].next[getid(s[j])] == -1)
                {
                    hasend = false;
                    break;
                }
                cur = buf[cur].next[getid(s[j])];
            }
            if (hasend == true)
                res = buf[cur].end;
            printf("%d\n",res);
        }
    }
    return 0;
}
