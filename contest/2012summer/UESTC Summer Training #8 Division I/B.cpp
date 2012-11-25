#include<cstdio>
#include<map>
#include<algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
const static int mod = 100000037;
int head[mod];
struct hash_tables
{
    pair<int,int> key;
    int val,next;
}ele[50000000];
int L;
int getHash(pair<int,int> x)
{
    return ((long long)x.first*1000000000+x.second)%mod;
}
void clear()
{
    memset(head,255,sizeof(head));
    L = 0;
}
inline int find(int hash,pair<int,int> x)
{
    for (int i = head[hash];i != -1;i = ele[i].next)
        if (ele[i].key == x)    return i;
    return -1;
}
inline int insert(int hash,pair<int,int> x)
{
    ele[L].key = x;
    ele[L].val = 0;
    ele[L].next = head[hash];
    head[hash] = L++;
    return L-1;
}
int N,M;
struct ops
{
    int x,y;
    bool typ;
}op[500000];
int tmp[500000],n;

void init()
{
    for (int i = 0;i < n;i++)
        tmp[i] = op[i].y;
    sort(tmp,tmp+n);
    M = unique(tmp,tmp+n)-tmp;
    for (int i = 0;i < n;i++)
        op[i].y = M-(lower_bound(tmp,tmp+M,op[i].y)-tmp)-1;

    for (int i = 0;i < n;i++)
        tmp[i] = op[i].x;
    sort(tmp,tmp+n);
    N = unique(tmp,tmp+n)-tmp;
    for (int i = 0;i < n;i++)
        op[i].x = lower_bound(tmp,tmp+N,op[i].x)-tmp;
}

void update(int x,int y)
{
    x++;
    y++;
    pair<int,int> tmp;
    for(;x<=N;x+=x&-x)
        for (int j=y;j<=M;j+=j&-j)
        {
            tmp=make_pair(x,j);
            int hash=getHash(tmp);
            int f=find(hash,tmp);
            if (f==-1)
            {
                f=insert(hash,tmp);
                ele[f].val=0;
            }
            ele[f].val++;
        }
}
int query(int x,int y)
{
    x++;y++;
    int sum=0;
    pair<int,int> tmp;
    for (;x;x^=x&-x)
        for (int j=y;j;j^=j&-j)
        {
            tmp=make_pair(x,j);
            int hash=getHash(tmp);
            int f=find(hash,tmp);
            if (f==-1)
                continue;
            sum+=ele[f].val;
        }
    return sum;
}
int wg;
char ch;
bool ng;

inline int readint()
{
    ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9'))    ch = getchar();
    if (ch == '-')
    {
        ng = true;
        ch = getchar();
    }
    else ng = false;
    wg = ch-'0';
    ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        wg = wg*10+ch-'0';
        ch = getchar();
    }
    if (ng == true) wg = -wg;
    return wg;
}
int main()
{
    clear();
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        char s;
        scanf(" %c",&s);
        op[i].x=readint();
        op[i].y=readint();
        if (s=='+')
            op[i].typ=1;
        else
            op[i].typ=0;
    }
    init();
    for (int i=0;i<n;i++)
    {
        if (op[i].typ)
            update(op[i].x,op[i].y);
        else
            printf("%d\n",query(op[i].x,op[i].y));
    }
    return 0;
}
