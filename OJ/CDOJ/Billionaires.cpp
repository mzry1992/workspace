#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int n;
map<string,int> mapN;
map<string,int> mapC;
map<string,int>::iterator it;
string name,names[12000],city,citys[70000];
int totN,totC;
char s1[100],s2[100];
long long money;
long long mn[12000],mc[70000],tree[70000*10];
int pn[12000];
int m,k;
struct statu
{
    int t,n,c;
}s[70000];

bool cmp(statu a,statu b)
{
    return a.t < b.t;
}

long long read(int k)
{
    long long res = 0;
    while (k > 0)
    {
        res = max(res,tree[k]);
        k -= k & -k;
    }
    return res;
}

void updata(int k,long long v)
{
    while (k <= totC)
    {
        tree[k] = max(tree[k],v);
        k += k & -k;
    }
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        mapN.clear();
        mapC.clear();
        totN = totC = 0;
        memset(mn,0,sizeof(mn));
        memset(mc,0,sizeof(mc));
        for (int i = 1;i <= n;i++)
        {
            scanf("%s%s%lld",s1,s2,&money);
            mn[i] = money;
            mc[i] += money;
            names[i] = s1;
            city = s2;
            mapN[names[i]] = i;
            it = mapC.find(city);
            if (it == mapC.end())
            {
                totC++;
                mapC[city] = totC;
                citys[totC] = city;
            }
            totN++;
            citys[i] = city;
        }
        scanf("%d%d",&m,&k);
        for (int i = 1;i <= k;i++)
        {
            scanf("%d%s%s",&s[i].t,s1,s2);
            name = s1;
            city = s2;
            it = mapC.find(city);
            if (it == mapC.end())
            {
                totC++;
                mapC[city] = totC;
                citys[totC] = city;
            }
            s[i].n = mapN[name];
            s[i].c = mapC[city];
        }
        sort(s+1,s+1+k,cmp);
        int premax =
    }
}
