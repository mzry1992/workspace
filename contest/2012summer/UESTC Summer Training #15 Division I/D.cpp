#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1100001;
int rank[maxn],sml[maxn],num[maxn],r[maxn];
bool isprime[maxn];

void getPrime()
{
    memset(isprime,1,sizeof(isprime));
    memset(sml,-1,sizeof(sml));
    for (int i=2;i<maxn;i++)
        if (isprime[i])
        {
            for (int j=i+i;j<maxn;j+=i)
            {
                isprime[j]=0;
                if (sml[j]==-1)
                    sml[j]=i;
            }
            sml[i]=i,num[i] = 1;
        }
    for (int i = 2;i < maxn;i++)
        if (!isprime[i])
            num[i] = 1+num[i/sml[i]];
}

bool cmp1(const int& a,const int& b)
{
    if (num[a] == num[b])
        return a < b;
    return num[a] < num[b];
}

bool cmp2(const int& a,const int& b)
{
    if (sml[a] == sml[b])
        return r[a/sml[a]] < r[b/sml[b]];
    return sml[a] < sml[b];
}

void getRank()
{
    for (int i = 0;i < maxn;i++)
        rank[i] = r[i] = i;
    sort(rank+2,rank+maxn,cmp1);
    int pre = 2;
    for (int i = 3;i <= maxn;i++)
        if (i == maxn || num[rank[i]] != num[rank[i-1]])
        {
            if (pre != 2)
                sort(rank+pre,rank+i,cmp2);
            for (int j = pre;j < i;j++)
            {
                r[rank[j]] = j;
            }
            pre = i;
        }
}

struct elem
{
    int v,index;
}a[maxn];

int d[30][maxn];
int s[30][maxn];

bool cmp(elem a,elem b)
{
    if (a.v == b.v)
        return a.index <= b.index;
    return a.v < b.v;
}

void build(int depth,int l,int r)
{
    if (l == r)
        return;
    int mid = l+r>>1;
    int tl,tr;
    tl = tr = 0;
    for (int i = l;i <= r;i++)
    {
        if (cmp(a[d[depth][i]],a[mid]))
        {
            d[depth+1][l+tl] = d[depth][i];
            tl++;
        }
        else
        {
            d[depth+1][mid+1+tr] = d[depth][i];
            tr++;
        }
        s[depth][i] = tl;
    }
    build(depth+1,l,mid);
    build(depth+1,mid+1,r);
}

int find(int depth,int dl,int dr,int fl,int fr,int k)
{
    if (fl == fr)
        return a[d[depth][fl]].v;
    int ls,rs;
    int mid = dl+dr>>1;
    ls = (fl == dl)?0:s[depth][fl-1];
    rs = s[depth][fr];
    return (rs-ls < k)?find(depth+1,mid+1,dr,mid+fl-dl-ls+1,mid+fr-dl-rs+1,k-(rs-ls)):
    find(depth+1,dl,mid,dl+ls,dl+rs-1,k);
}

int main()
{
    getPrime();
    getRank();
    for (int i = 1;i < maxn;i++)
    {
        a[i].v = r[i];
        a[i].index = i;
    }
    sort(a+1,a+maxn,cmp);
    for (int i = 1;i < maxn;i++)
        d[0][a[i].index] = i;
    build(0,1,maxn-1);
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
        int a,b,k;
        scanf("%d%d%d",&a,&b,&k);
        int res = rank[find(0,1,maxn-1,a,b,k)];
        printf("Case %d:",cas);
        while (res > 1)
        {
            printf(" %d",sml[res]);
            res /= sml[res];
        }
        printf("\n");
	}
	return 0;
}
