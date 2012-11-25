#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN=100000;
const int inf=0x7fffffff;

struct Treap
{
    int N;
    Treap()
    {
        N=0;
        root=NULL;
    }
    void init()
    {
        N=0;
        root=NULL;
    }
    struct Treap_Node
    {
        Treap_Node *son[2];//left & right
        int value,fix;
        int num,size;
        Treap_Node(){}
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
    }node[MAXN],*root;
    void rotate(Treap_Node *&p,bool flag)
    {
        int _size=p->size;
        Treap_Node *tmp=p->son[!flag];
        p->size=p->sonSize(flag)+tmp->sonSize(flag)+p->num;
        p->son[!flag]=tmp->son[flag];
        tmp->son[flag]=p;
        tmp->size=_size;
        p=tmp;
    }
    void insert(Treap_Node *&p,int value)
    {
        if (p==NULL)
        {
            p=&node[N++];
            *p=Treap_Node(value);
            return ;
        }
        if (p->value==value)
        {
            p->num++;
            p->size++;
            return ;
        }
        bool flag;
        if (value<p->value)
            flag=0;
        else
            flag=1;
        insert(p->son[flag],value);
        if (p->son[flag]->fix<p->fix)
            rotate(p,!flag);
        p->size=p->sonSize(0)+p->sonSize(1)+p->num;
    }
    bool remove(Treap_Node *&p,int value)
    {
        if (p==NULL)
            return 0;
        if (p->value==value)
        {
            if (p->num>1)
            {
                p->num--;
                p->size--;
                return 1;
            }
            else if (p->son[0]==NULL || p->son[1]==NULL)
            {
                if (p->son[0]==NULL)
                    p=p->son[1];
                else
                    p=p->son[0];
                return 1;
            }
            else
            {
                bool flag;
                if (p->son[0]->fix<p->son[1]->fix)
                    flag=0;
                else
                    flag=1;
                rotate(p,!flag);
                bool ret=remove(p->son[!flag],value);
                p->size=p->num+p->sonSize(0)+p->sonSize(1);
                return ret;
            }
        }
        else
        {
            bool flag,ret;
            if (value<p->value)
                flag=0;
            else
                flag=1;
            ret=remove(p->son[flag],value);
            p->size=p->num+p->sonSize(0)+p->sonSize(1);
            return ret;
        }
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
    void insert(int value)
    {
        insert(root,value);
    }
    bool remove(int value)
    {
        return remove(root,value);
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
    freopen("K.out","w",stdout);
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int flag=-1,ans=0;
        treap.init();
        for (int i=0;i<n;i++)
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
