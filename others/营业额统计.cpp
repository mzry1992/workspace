#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 200001;

struct SBT
{
    int key[maxn],s[maxn],l[maxn],r[maxn],L,root;
    void init()
    {
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        memset(s,0,sizeof(s));
        memset(key,0,sizeof(key));
        root = 0;
    }
    inline void up(int x)
    {
        s[x] = s[l[x]]+s[r[x]]+1;
    }
    void rr(int& t)
    {
        int k = l[t];
        l[t] = r[k];
        r[k] = t;
        s[k] = s[t];
        up(t);
        t = k;
    }
    void lr(int& t)
    {
        int k = r[t];
        r[t] = l[k];
        l[k] = t;
        s[k] = s[t];
        up(t);
        t = k;
    }
    void maintain(int& t,bool flag)
    {
        if (flag == false)
        {
            if (s[l[l[t]]] > s[r[t]])   rr(t);
            else if (s[r[l[t]]] > s[r[t]])
            {
                lr(l[t]);
                rr(t);
            }
            else    return;
        }
        else
        {
            if (s[r[r[t]]] > s[l[t]])   lr(t);
            else if (s[l[r[t]]] > s[l[t]])
            {
                rr(r[t]);
                lr(t);
            }
            else    return;
        }
        maintain(l[t],false);
        maintain(r[t],true);
        maintain(t,true);
        maintain(t,false);
    }
    void insert(int& t,int v)
    {
        if (t == 0)
        {
            t = ++L;
            key[t] = v;
            s[t] = 1;
            l[t] = r[t] = 0;
        }
        else
        {
            s[t]++;
            if (v < key[t])
                insert(l[t],v);
            else
                insert(r[t],v);
            maintain(t,v >= key[t]);
        }
    }
    int pred(int& t,int v)
    {
        if (t == 0) return t;
        if (v < key[t])
            return pred(l[t],v);
        else
        {
            int pre = pred(r[t],v);
            return (pre?pre:t);
        }
    }
    int succ(int& t,int v)
    {
        if (t == 0) return t;
        if (v > key[t])
            return succ(r[t],v);
        else
        {
            int suc = succ(l[t],v);
            return (suc?suc:t);
        }
    }
    void debug()
    {
        printf("DEBUG:\n");
        printf("root = %4d\n",root);
        for (int i = 0; i <= L; i++)
            printf("%4d: key = %4d ,s = %4d ,l = %4d ,r = %4d\n",i,key[i],s[i],l[i],r[i]);
    }
};

int n,a;
SBT tree;

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        tree.init();
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (scanf("%d",&a) == EOF)  a = 0;
            int pred = tree.pred(tree.root,a);
            int succ = tree.succ(tree.root,a);
            int minres;
            if (i == 0) minres = a;
            else    minres = abs(tree.key[1]-a);
            if (pred != 0)
                minres = min(minres,abs(tree.key[pred]-a));
            if (succ != 0)
                minres = min(minres,abs(tree.key[succ]-a));
            //tree.debug();
            //printf("pred = %d ,succ = %d ,%d\n",pred,succ,minres);
            res += minres;
            tree.insert(tree.root,a);
        }
        printf("%d\n",res);
    }
    return 0;
}
