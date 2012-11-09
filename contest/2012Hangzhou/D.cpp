#include <cstdio>
#include <cstring>
using namespace std;
int N;
struct hash_map
{
    int mod;
    int head[1<<21];
    struct hash_tables
    {
        short key1,key2;
        int val;
        int next;
    } ele[80000*22];
    int N;
    int getHash(short key1,short key2)
    {
        return ((key1<<15)+key2)%mod;
    }
    void clear(int _mod)
    {
        mod=_mod;
        memset(head,-1,4*_mod);
        N = 0;
    }
    int fint(short key1,short key2)
    {
        for (int i = head[getHash(key1,key2)]; i != -1; i = ele[i].next)
            if (ele[i].key1 == key1 && ele[i].key2 == key2)
                return i;
        return -1;
    }
    void insert(short key1,short key2)
    {
        int tmp = getHash(key1,key2);
        ele[N].key1 = key1;
        ele[N].key2 = key2;
        ele[N].val = 0;
        ele[N].next = head[tmp];
        head[tmp] = N++;
    }
    int& get(short key1,short key2)
    {
        int tmp = fint(key1,key2);
        if (tmp == -1)
        {
            insert(key1,key2);
            return ele[N-1].val;
        }
        else
            return ele[tmp].val;
    }
};
hash_map tree;
void update(int x,int y,int z)
{
    for (x++; x<=N; x+=x&-x)
    {
        for (int j=y+1; j<=N; j+=j&-j)
            tree.get(x-1,j-1)+=z;
    }
}
int read(int x,int y)
{
    x++;
    y++;
    if (x<=0 || y<=0)
        return 0;
    if (x>N)
        x=N;
    if (y>N)
        y=N;
    int ret=0;
    for (; x; x^=x&-x)
        for (int j=y; j; j^=j&-j)
            ret+=tree.get(x-1,j-1);
    return ret;
}
int wg;
char ch;
bool ng;
inline int readint()
{
    ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-')
    {
        ng = true;
        ch = getchar();
    }
    else
        ng = false;
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
    while (1)
    {
        int n,m;
        scanf("%d",&n);
        if (!n)
            break;
        scanf("%d",&m);
        N=n*2+1;
        if (m<10000)
            tree.clear(100007);
        else
            tree.clear(1000007);
        while (m--)
        {
            int typ,x,y,z;
            typ=readint();
            x=readint();
            y=readint();
            z=readint();
            if (typ==1)
                update(x-y+n,x+y,z);
            else
                printf("%d\n",read(x-y+n+z,x+y+z)+read(x-y+n-z-1,x+y-z-1)-read(x-y+n-z-1,x+y+z)-read(x-y+n+z,x+y-z-1));
        }
    }
    return 0;
}
