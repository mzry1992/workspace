#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
struct Node
{
    int id,num;
    vector<Node *> to;
}*top,*K,*NEXT,ele[40000];
int size;
int k;
int num[128*128*128];
Node *newNode(int id)
{
    ele[size].id=id;
    ele[size].num=num[id]++;
    ele[size].to.clear();
    return &ele[size++];
}
void add(int id)
{
    if (size==0)
    {
        top=newNode(id);
        K=top;
        return ;
    }
    if (size==1)
    {
        Node *tmp=newNode(id);
        tmp->to.push_back(top);
        top->to.push_back(tmp);
        NEXT=top=tmp;
        return ;
    }
    Node *tmp=newNode(id);
    tmp->to.push_back(top);
    top->to.push_back(tmp);
    top=tmp;
    if (size<=k)
        return ;
    tmp=K;
    K=NEXT;
    for (int i=0; i<K->to.size(); i++)
        if (K->to[i]!=tmp)
            NEXT=K->to[i];
}
int getId(char *s)
{
    int l=strlen(s);
    int ret=0;
    for (int i=l-1; i>=0; i--)
        ret=ret*128+s[i];
    return ret;
}
void getS(int id)
{
    do
    {
        putchar(id%128);
        id/=128;
    }
    while (id);
    puts("");
}
void rotate()
{
    if (k<=1)
        return ;
    if (size<=1)
        return ;
    if (k==2 || size==2)
    {
        top->to.clear();
        for (int i=0; i<K->to.size(); i++)
            if (K->to[i]!=top)
                top->to.push_back(K->to[i]);
        K->to.clear();
        K->to.push_back(top);
        top->to.push_back(K);
        Node *tmp=top;
        NEXT=top=K;
        K=tmp;
        return ;
    }
    Node *tmp=top,*tmp2=top->to[0];
    for (int j=0; j<K->to.size(); j++)
        if (K->to[j]!=NEXT)
        {
            for (int i=0; i<K->to[j]->to.size(); i++)
                if (K->to[j]->to[i]==K)
                {
                    K->to[j]->to[i]=top;
                    break;
                }
            top->to.push_back(K->to[j]);
            K->to.erase(K->to.begin()+j);
            break;
        }
    NEXT=tmp2;
    top=K;
    K=tmp;
}
int a[40000];
int main()
{
    int n,m;
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0; i<n; i++)
    {
        char s[4];
        scanf("%s",s);
        a[i]=getId(s);
    }
    for (int i=n-1; i>=0; i--)
        add(a[i]);
    while (m--)
    {
        char s[10];
        scanf("%s",s);
        if (s[0]=='R')
            rotate();
        else
        {
            char t[5];
            sscanf(s,"ADD(%s)",t);
            t[strlen(t)-1]=0;
            add(getId(t));
        }
        /*puts("------------------");
        Node *pre=NULL,*now=top;
        for (int i=0; i<size; i++)
        {
            getS(now->id);
            for (int j=0; j<now->to.size(); j++)
                if (now->to[j]!=pre)
                {
                    pre=now;
                    now=now->to[j];
                    break;
                }
        }
        puts("------------------");*/
    }
    Node *pre=NULL,*now=top;
    for (int i=0; i<size; i++)
    {
        getS(now->id);
        for (int j=0; j<now->to.size(); j++)
            if (now->to[j]!=pre)
            {
                pre=now;
                now=now->to[j];
                break;
            }
    }
    return 0;
}
