#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN=100000;
const int MAXM=100000;
const int inf=0x7fffffff;
struct Treap
{
    int N,M;
    Treap()
    {
        N=M=0;
        root[M]=NULL;
    }
    void init()
    {
        N=M=0;
        root[M]=NULL;
    }
    struct Treap_Node
    {
        Treap_Node *son[2];//left & right
        int value,fix;
        int size;
        Treap_Node() {}
        Treap_Node(int _value)
        {
            son[0]=son[1]=NULL;
            value=_value;
            fix=rand()*rand();
            size=1;
        }
        int sonSize(bool flag)
        {
            if (son[flag]==NULL)
                return 0;
            else
                return son[flag]->size;
        }
    } node[MAXN*20],*root[MAXM];
    Treap_Node *newNode(int value)
    {
        node[N]=Treap_Node(value);
        return &node[N++];
    }
    Treap_Node *newNode(Treap_Node *p)
    {
        node[N]=Treap_Node(p->value);
        node[N].fix=p->fix;
        node[N].son[0]=p->son[0];
        node[N].son[1]=p->son[1];
        node[N].size=p->size;
        return &node[N++];
    }
    Treap_Node *merge(Treap_Node *p,Treap_Node *q)
    {
        if (p==NULL)
            return q;
        else if (q==NULL)
            return p;
        if (p->fix<q->fix)
        {
            Treap_Node *np=newNode(p);
            np->son[1]=merge(p->son[1],q);
            np->size=np->sonSize(0)+np->sonSize(1)+1;
            return np;
        }
        else
        {
            Treap_Node *nq=newNode(q);
            nq->son[0]=merge(p,q->son[0]);
            nq->size=nq->sonSize(0)+nq->sonSize(1)+1;
            return nq;
        }
    }
    pair<Treap_Node*, Treap_Node*> split(Treap_Node *p,int n)//Î´Íê³É°æ
    {
        if (p==NULL)
            return make_pair((Treap_Node*)NULL,(Treap_Node*)NULL);
        if (!n)
            return make_pair((Treap_Node*)NULL,p);
        if (n==p->size)
            return make_pair(p,(Treap_Node*)NULL);
        if (p->sonSize(0)>=n)
        {
            Treap_Node* np=newNode(p);
            pair<Treap_Node*, Treap_Node*> ret=split(p->son[0],n);
            np->son[0]=ret.second;
            np->size=np->sonSize(0)+np->sonSize(1)+1;
            return make_pair(ret.first,np);
        }
        else
        {
            Treap_Node* np=newNode(p);
            pair<Treap_Node*, Treap_Node*> ret=split(p->son[1],n-p->sonSize(0)-1);
            np->son[1]=ret.first;
            np->size=np->sonSize(0)+np->sonSize(1)+1;
            return make_pair(np,ret.second);
        }
    }
    int smalls(Treap_Node *p,int value)
    {
        if (p==NULL)
            return 0;
        if (p->value<=value)
            return 1+p->sonSize(0)+smalls(p->son[1],value);
        else
            return smalls(p->son[0],value);
    }
    Treap_Node *find(Treap_Node *p,int value)
    {
        if (p==NULL)
            return NULL;
        if (p->value==value)
            return p;
        if (value<p->value)
            return find(p->son[0],value);
        else
            return find(p->son[1],value);
    }
    void insert(int value)
    {
        Treap_Node *p=newNode(value);
        pair<Treap_Node*,Treap_Node*> ret=split(root[M-1],smalls(root[M-1],value));
        root[M++]=merge(merge(ret.first,p),ret.second);
    }
    void remove(int value)
    {
        pair<Treap_Node*,Treap_Node*> ret=split(root[M-1],smalls(root[M-1],value)-1);
        root[M++]=merge(ret.first,split(ret.second,1).second);
    }
    bool find(int value)
    {
        return find(root[M-1],value);
    }
    int size()
    {
        if(root[M-1])
            return root[M-1]->size;
        else
            return 0;
    }
    int lower_bound(Treap_Node *p, int value)
    {
        if (p==NULL)
            return value+1;
        if (p->value==value)
            return value;
        if (value<p->value)
            return lower_bound(p->son[0],value);
        else
        {
            int ret=lower_bound(p->son[1],value);
            if (ret!=value+1)
                return ret;
            else
                return p->value;
        }
    }
    int lower_bound(int value)
    {
        int ret=lower_bound(root[M-1],value);
        if (ret!=value+1)
            return ret;
        else
            return value-inf;
    }
    int upper_bound(Treap_Node *p,int value)
    {
        if (p==NULL)
            return value-1;
        if (p->value==value)
            return value;
        if (value<p->value)
        {
            int ret=upper_bound(p->son[0],value);
            if (ret!=value-1)
                return ret;
            else
                return p->value;
        }
        else
            return upper_bound(p->son[1],value);
    }
    int upper_bound(int value)
    {
        int ret=upper_bound(root[M-1],value);
        if (ret!=value-1)
            return ret;
        else
            return value+inf;
    }
};
Treap treap;
int main()
{
    freopen("K.in","r",stdin);
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int flag=-1,ans=0;
        treap.init();
        for (int i=0; i<n; i++)
        {
            int typ,x;
            scanf("%d%d",&typ,&x);
            if (flag==-1)
            {
                treap.insert(x);
                flag=typ;
            }
            else if (typ==flag)
                treap.insert(x);
            else
            {
                if (treap.find(x))
                    treap.remove(x);
                else
                {
                    int pre=treap.lower_bound(x),suc=treap.upper_bound(x);
                    if (x-pre<=suc-x)
                    {
                        ans+=x-pre;
                        treap.remove(pre);
                    }
                    else
                    {
                        ans+=suc-x;
                        treap.remove(suc);
                    }
                }
                if (!treap.size())
                    flag=-1;
            }
            ans%=1000000;
        }
        printf("%d\n",ans);
    }
    return 0;
}
