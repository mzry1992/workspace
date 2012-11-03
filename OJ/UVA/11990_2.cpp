#include"iostream"
#include"cstring"
#include"cstdio"
#include"algorithm"
#include"cmath"
#include"stack"
#include"queue"
#include"vector"
#include"map"
#include"ctime"
#include"set"
#define int_max 0x7fffffff
#define ll_max 0x7fffffffffffffffLL
#define fr first
#define se second
typedef long long ll;
typedef unsigned long long llu;
using namespace std;
const int maxn=201000;
#define ch(x,f) ((x)->c[(f)])
struct Node
{
    int val;
    int sz;
    Node *c[2],*pre;
} node[maxn*20],*cnt,*pos[maxn][20];
class Splay
{
public:
    Node *nil,*root;
    inline void up(Node *x)
    {

    }
    inline void rotate(Node *x,int f)
    {
        register Node *y=x->pre;
        ch(y,!f)=ch(x,f);
        ch(x,f)->pre=y;
        x->pre=y->pre;
        if(x->pre!=nil)ch(y->pre,ch(y->pre,1)==y)=x;
        ch(x,f)=y;
        y->pre=x;
        y->sz=ch(y,0)->sz+ch(y,1)->sz+1;
    }
    inline void splay(Node *x)
    {
        while(x->pre!=nil)
        {
            if(x->pre->pre==nil)
                rotate(x,ch(x->pre,0)==x);
            else
            {
                int t=(ch(x->pre->pre,0)==x->pre);
                if(ch(x->pre,t)==x)
                    rotate(x,!t);
                else rotate(x->pre,t);
                rotate(x,t);
            }
        }
        x->sz=ch(x,0)->sz+ch(x,1)->sz+1;
        root=x;
    }
    inline void init()
    {
        nil=++cnt;
        ch(nil,0)=ch(nil,1)=nil->pre=nil;
        nil->sz=nil->val=0;
        newnode(root,-int_max);
        root->pre=nil;
        newnode(ch(root,1),int_max);
        cnt->pre=root;
        root->sz=2;
    }
    inline void newnode(Node *&x,int val)
    {
        x=++cnt;
        ch(x,0)=ch(x,1)=x->pre=nil;
        x->sz=1;
        x->val=val;
    }
    inline void insert(int v)
    {
        register Node *x=root;
        for(;;)
        {
            if(x->val>v)
            {
                if(ch(x,0)!=nil)x=ch(x,0);
                else
                {
                    newnode(ch(x,0),v);
                    cnt->pre=x;
                    splay(cnt);
                    return ;
                }
            }
            else
            {
                if(ch(x,1)!=nil)x=ch(x,1);
                else
                {
                    newnode(ch(x,1),v);
                    cnt->pre=x;
                    splay(cnt);
                    return ;
                }
            }
        }
    }
    inline int findsm(int v)
    {
        register Node *x=root,*r;
        int sum=0;
        for(;;)
        {
            if(x->val>v)
            {
                if(ch(x,0)!=nil)x=ch(x,0);
                else return sum;
            }
            else
            {
                r=x;
                sum+=ch(x,0)->sz+1;
                if(ch(x,1)!=nil)x=ch(x,1);
                else return sum;
            }
        }
    }
    inline int findsmaller(int v)
    {

        return findsm(v-1)-1;
    }
    inline int findbigger(int v)
    {
        return root->sz-1-findsm(v);
    }
} spt[maxn];
int n,m,tree[200002];
inline void update(int x)
{
    while(x<=n)
    {
        ++tree[x];
        x+=x&-x;
    }
}
inline int find(int x)
{
    int sum=0;
    while(x>0)
    {
        sum+=tree[x];
        x-=x&-x;
    }
    return sum;
}
void updateadd(int x,int v)
{
    int e=0;
    while(x<=n)
    {
        spt[x].insert(v);
        x+=x&-x;
    }
}
inline int find(int x,int v)
{
    register int sum=0;
    while(x>0)
    {
        sum+=spt[x].findbigger(v);
        x-=x&-x;
    }
    return sum;
}
inline int find2(int x,int v)
{
    register int sum=0;
    while(x>0)
    {
        sum+=spt[x].findsmaller(v);
        x-=x&-x;
    }
    return sum;
}
int a[maxn],po[maxn],x;
char in;
inline void read(int &num)
{
    in = getchar();
    while(in < '0' || in > '9') in = getchar();
    num = in - '0';
    while(in = getchar(), in >= '0' && in <= '9')num *= 10, num += in - '0';
}
char s[20],bas;
inline void put(ll x)
{
    bas = 0;
    for(; x; x/=10)s[bas++] = x%10+'0';
    for(; bas--;)putchar(s[bas]);
    putchar('\n');
    return;
}
bool vis[200011];
int b[200001];
ll ans[200001];
int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int st=clock(),x,y;
    while(scanf("%d %d",&n,&m)==2)
    {
        ll sum=0;
        cnt=node;
        memset(vis,0,sizeof(vis[0])*(n+1));
        memset(tree,0,sizeof(tree[0])*(n+1));
        for(int i=1; i<=n; ++i)
        {
            spt[i].init();
            scanf("%d",&x);
            po[a[i]=x]=i;
        }
        for(int i=0; i<m; ++i)
        {
            scanf("%d",&x);
            vis[b[i]=x]=1;
        }
        for(int i=n; i>=1; --i)
        {
            x=a[i];
            if(vis[x]==0)
            {
                updateadd(i,x);//puts("a");
                update(x);
                sum+=find(x-1);
            }
        }
        for(int i=m-1; i>=0; --i)
        {
            y=b[i],x=po[y];
            updateadd(x,y);
            sum+=find(x,y)+find2(n,y)-find2(x,y);
            ans[i]=sum;
        }
        for(int i=0; i<m; ++i)
            printf("%lld\n",ans[i]);
    }
//	printf("%dms\n",clock()-st);
}
