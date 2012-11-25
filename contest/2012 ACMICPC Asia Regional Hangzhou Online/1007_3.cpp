#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
int cao;
struct node
{
    node *f,*next[26];
    int len;
    int id;
    int flag;
    int ma;
    node(){}
    node(int x)
    {
        f=0;
        id=1;
        len=x;
        flag=0;
        ma=0;
        memset(next,0,sizeof(next));
    }
}v[500005];
node *now;
node *root;
node* newnode(int x)
{
    v[cao]=node(x);
    return &v[cao++];
}
void init()
{
    cao=0;
    root=now=newnode(0);
}
void gao(int x)
{
    node *p=now;
    node *np=newnode(p->len+1);
    while(p&&p->next[x]==0)
    {
        p->next[x]=np;
        p=p->f;
    }

    if(p==0)
        np->f=root;
    else
    {
        node *q=p->next[x];
        if(q->len==p->len+1)
        np->f=q;
        else
        {
            node *nq=newnode(p->len+1);
            nq->f=q->f;
            q->f=nq;
            np->f=nq;
            nq->id=0;
            memcpy(nq->next,q->next,sizeof(q->next));
            while(p&&p->next[x]==q)
            {
                p->next[x]=nq;
                p=p->f;
            }

        }
    }
    now=np;
}
void run(char s[],node *p)
{
    int i=0;
    p->flag=1;
    int rt=0;
    while(s[i])
    {
        int x=s[i]-'a';
        while(p&&p->next[x]==0)
        {
            p=p->f;
        }
        if(p!=0)
        {
            rt=min(rt,p->len);
            p=p->next[x];
        }
        else
            p=root;
        p->flag=1;
        rt=min(rt+1,p->len);
        p->ma=max(p->ma,rt);
        i++;
    }
}

vector<int>q[500005];
char ch[100005];
long long sum;
void dfs(int x)
{
    int i;
    for(i=0;i<q[x].size();i++)
    {
        int y=q[x][i];
        dfs(y);
        if(v[x].flag==2)
        continue;
        if(v[y].flag==2|v[y].flag==1)
        {
            v[x].flag=2;
        }
    }
}

int main()
{
    freopen("data.in","r",stdin);
    freopen("data2.out","w",stdout);
    int T;
    scanf("%d",&T);
    int as=0;
    while(T--)
    {
        as++;
        int n;
        scanf("%d",&n);
        init();
        scanf("%s",ch);
        int l=strlen(ch);
        int i;
        for(i=0;i<l;i++)
        {
            gao(ch[i]-'a');
        }
        for(i=1;i<=n;i++)
        {
            scanf("%s",ch);
            run(ch,root);
        }
        for(i=0;i<cao;i++)
        {
            q[i].clear();
        }
        for(i=1;i<cao;i++)
        {
            q[v[i].f-v].push_back(i);
        }
        dfs(0);
     //   for(i=0;i<cao;i++)
     //   printf("%d\n",v[i].flag);
        sum=0;
        for(i=1;i<cao;i++)
        {
            int f=v[i].f-v;
            if(v[i].flag==0)
            {
                sum+=v[i].len-v[f].len;
            }
            if(v[i].flag==1)
            {
                sum+=v[i].len-v[i].ma;
            }
        }
        printf("Case %d: %I64d\n",as,sum);
    }
    return 0;
}
