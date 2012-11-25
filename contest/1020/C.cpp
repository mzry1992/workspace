#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long k,m;
unsigned long long l,r,mid;
char s[20],sn[20],spre[20];
int len,lensn,lenspre;
long long t11[20];

long long Gao(long long n,long long pre)
{
    if (pre == 0)   return 1;
    //I64d!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    sprintf(sn,"%lld",n);
    sprintf(spre,"%lld",pre);
    lensn = strlen(sn);
    lenspre = strlen(spre);
    int lpos = 0;
    bool flag;
    long long tmp;
    //cout << sn << ' ' << spre << endl;
    for (lpos = 0; lpos < lensn; lpos++)
    {
        flag = true;
        for (int i = 0; i < lenspre; i++)
            if (spre[i] > sn[i+lpos])
            {
                flag = false;
                break;
            }
            else if (spre[i] < sn[i+lpos])
                break;
        if (flag == false)  continue;
        for (int i = 0; i < lenspre; i++)
            if (spre[i] != sn[i+lpos])
            {
                return t11[lensn-lenspre+1-lpos];
                //(lensn-lenspre+1)
            }
        //I64d!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        sscanf(sn+lenspre+lpos,"%lld",&tmp);
        //cout << n << ' ' << pre << ' ' << sn << ' ' << spre << endl;
        //cout << tmp << ' ' << lensn << ' ' << lenspre << endl;
        return t11[lensn-lenspre-lpos]+tmp+1;
    }
    //(lensn-lenspre)
}

long long calc(long long n,long long m)
{
    //I64d!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    sprintf(s,"%lld",m);
    len = strlen(s);
    long long res = 0;
    long long pre = 0;
    for (int i = 0; i < len; i++)
    {
        //cout << i << ' ' << res << endl;
        for (int j = 0; j < s[i]-'0'; j++)
            res += Gao(n,pre*10+j);
        res++;
        pre = pre*10+s[i]-'0';
    }
    return res-1;
}

int main()
{
    t11[1] = 1;
    for (int i = 2; i < 20; i++)
        t11[i] = t11[i-1]*10+1;
    //cout << Gao(1831,1) << endl;
    //cout << Gao(1831,20) << endl;
    //cout << calc(1831,25) << endl;
    //cout << Gao(100000000888888879LL,1) << endl;
    //cout << calc(100000000888888879LL,1000000000LL) << endl;
    //cout << calc(104589,1559) << endl;
    while (cin >> m >> k)
    {
        l = max(k,m);
        r = 1000000000000000000LL;
        while (l < r)
        {
            //cout << l << ' ' << r << endl;
            mid = l+r-1>>1;
            if (calc(mid,m) < k)
                l = mid+1;
            else
                r = mid;
        }
        if (l == 1000000000000000000LL)
            l = 0;
        cout << l << endl;
        //cout << calc(k,m) << endl;
    }
    return 0;
}
