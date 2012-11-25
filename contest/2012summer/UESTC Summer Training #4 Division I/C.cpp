#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

bool isPrime[1000001],b[1000001];
int a[1000001],fac[64],factot;
int n,res;

void gen(int now)
{
    if (isPrime[now] == true)
    {
        fac[factot++] = now;
        return;
    }
    fac[factot++] = a[now];
    gen(now/a[now]);
}

void gen2(int pos,int val)
{
    if (val <= res) return;
    //printf("%d %d\n",pos,val);
    if (pos == factot)
    {
        //printf("111 %d\n",val);
        if (b[val] == true)
            res = max(res,val);
        else
            b[val] = true;
        return;
    }
    int i;
    for (i = pos;i < factot && fac[i] == fac[pos];i++);
    gen2(i,val);
    int nxt = val;
    for (int j = pos;j < i;nxt/=fac[j++])
    {
        //printf("%d %d\n",nxt,fac[j]);
        gen2(i,nxt/fac[j]);
    }
}

int main()
{
    scanf("%d",&n);
    //n = 100000;
    memset(b,false,sizeof(b));
    res = 1;
    for (int i = 0;i < n;i++)
    {
        int v;
        scanf("%d",&v);
        //v = i+1;
        if (v == 1) continue;
        factot = 0;
        gen(v);
        //cout << v << endl;
        sort(fac,fac+factot);
        /*for (int j = 0;j < factot;j++)
            printf("%d ",fac[j]);
        printf("\n");*/
        gen2(0,v);
    }
    printf("%d\n",res);
	return 0;
}
