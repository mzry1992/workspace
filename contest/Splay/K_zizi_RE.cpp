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
        Treap_Node *EMPTY=NULL;
        N=M=0;
    }
    void init()
    {
        N=M=0;
    }
    struct Treap_Node
    {
        Treap_Node *son[2];//left & right
        int value,fix;
        int num,size;
        Treap_Node() {}
        Treap_Node(int _value)
        {
            son[0]=son[1]=NULL;
            value=_value;
            fix=rand()*rand();
            num=size=1;
        }
        int sonSize(bool flag)
        {
            if (son[flag]==NULL)
                return 0;
            else
                return son[flag]->size;
        }
    } node[MAXN],*root;
    Treap_Node *merge(Treap_Node *p,Treap_Node *q)
    {
        if (p==NULL)
            return q;
        else if (q==NULL)
            return p;
        if (p->fix<q->fix)
        {
            p->son[1]=merge(p->son[1],q);
            p->size=p->sonSize(0)+p->sonSize(1)+p->num;
            return p;
        }
        else
        {
            q->son[0]=merge(q->son[0],p);
            p->size=p->sonSize(0)+p->sonSize(1)+p->num;
            return q;
        }
    }
    pair<Treap_Node*, Treap_Node*> split(Treap_Node *p,int n)
    {
        if (!n)
            return make_pair((Treap_Node*)NULL,p);
        if (n==p->size)
            return make_pair(p,(Treap_Node*)NULL);
        if (p->sonSize(0)>=n)
        {
            pair<Treap_Node*, Treap_Node*> ret=split(p->son[0],n);
            p->son[0]=ret.second;
            p->size=p->sonSize(0)+p->sonSize(1)+p->num;
            return make_pair(ret.first,p);
        }
        else
        {
            pair<Treap_Node*, Treap_Node*> ret=split(p->son[1],n-p->sonSize(0)-1);
            p->son[1]=ret.first;
            p->size=p->sonSize(0)+p->sonSize(1)+p->num;
            return make_pair(p,ret.second);
        }
    }
    void insert(int value)
    {
        Treap_Node *p=&node[N++];
        *p=Treap_Node(value);
        root=merge(root,p);
    }
    Treap_Node * remove(Treap_Node *p,int value)
    {
        if (p->value==value)
        {
            if (p->num>1)
            {
                p->num--;
                return p;
            }
            pair<Treap_Node*,Treap_Node*> ret=split(p,p->sonSize(0));
            return merge(ret.first,split(ret.second,1).second);
        }
        if (value<p->value)
            p->son[0]=remove(p->son[0],value);
        else
            p->son[1]=remove(p->son[1],value);
        p->size=p->sonSize(0)+p->sonSize(1)+p->num;
        return p;
    }
    void remove(int value)
    {
        root=remove(root,value);
    }
    bool find(Treap_Node *p,int value)
    {
        if (p==NULL)
            return 0;
        if (p->value==value)
            return 1;
        if (value<p->value)
            return find(p->son[0],value);
        else
            return find(p->son[1],value);
    }
    bool find(int value)
    {
        return find(root,value);
    }
    int size()
    {
        if(root)
            return root->size;
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
        int ret=lower_bound(root,value);
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
        int ret=upper_bound(root,value);
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
    freopen("K2.out","w",stdout);
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
