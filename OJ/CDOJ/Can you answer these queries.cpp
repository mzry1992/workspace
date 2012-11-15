#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;
const int NSIZE = 100010;
unsigned long long num[NSIZE][64];
struct node
{
    unsigned long long sum;
    int step;
    bool fin;
};
node tree[NSIZE*4];
void build(int p ,int l ,int r)
{
    if(l == r)
    {
        tree[p].step = 0;
        tree[p].sum = num[l][0];
        if(tree[p].sum <=1) tree[p].fin = true;
        else tree[p].fin = false;
        return;
    }

    int mid = (l+r)>>1;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    tree[p].fin = tree[p*2].fin && tree[p*2+1].fin;
    tree[p].sum = tree[p*2].sum + tree[p*2+1].sum;
    //tree[p].step = 0;
}
void doit(int p ,int l ,int r,int al ,int ar)
{
    if(ar < l || al > r) return;
    if(tree[p].fin) return ;
    if(l == r)
    {
        tree[p].sum = num[l][++tree[p].step];
        if(tree[p].sum <=1) tree[p].fin = true;
        return;
    }
    int mid = (l+r) >>1;
    doit(p*2,l,mid,al,ar);
    doit(p*2+1,mid+1,r,al,ar);
    tree[p].sum = tree[p*2].sum + tree[p*2+1].sum;
    if(tree[p*2].fin && tree[p*2+1].fin)
        tree[p].fin = true;
}
unsigned long long ask(int p ,int l, int r,int al ,int ar)
{
    if(al <= l && ar>=r) return tree[p].sum;
    if(ar < l || al > r) return 0;

    int mid = (l+r)>>1;
    unsigned long long r1 = ask(p*2,l,mid,al,ar);
    unsigned long long r2 = ask(p*2+1,mid+1,r,al,ar);
    return r1 + r2;
}
unsigned long long isqrt(unsigned long long a)
{
    if(a == 0) return 0;
    if(a == 1) return 1;
    unsigned long long tmp = (long long)sqrt(1.0*a);
    if (tmp*tmp<a)
    {
        while (true)
        {
            if ((tmp+1)*(tmp+1) <= a)   tmp++;
            else
                break;
        }
        return tmp;
    }
    else
    {
        while (true)
        {
            if ((tmp-1)*(tmp-1) > a)    tmp--;
            else
                break;
        }
        return tmp;
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    int cas = 0;
    while(scanf("%d",&n) == 1)
    {

        for(int i = 0 ; i < n ; i++)
        {
            scanf("%I64u",&num[i][0]);
            for(int j = 1 ; j < 64; j++)
            {
                num[i][j] = (unsigned long long)floor(sqrt(1.0*num[i][j-1]));
                //num[i][j] = isqrt(num[i][j-1]);
                if(num[i][j] <=1 )break;
            }
        }
        //puts("HI");
        for(int i = 0 ; i < NSIZE*4 ; i++)
        {
            tree[i].fin = false;
            tree[i].step = 0;
            tree[i].sum = 0;
        }
        build(1,0,n-1);
        int Q;
        scanf("%d",&Q);
        printf("Case #%d:\n",++cas);
        for(int Qi = 0; Qi < Q ; Qi++)
        {
            int cmd , l,r;
            scanf("%d%d%d",&cmd,&l,&r);
            --l;
            --r;
            if (l > r)  swap(l,r);
            if(cmd == 0)
            {
                doit(1,0,n-1,l,r);
            }
            else
            {
                unsigned long long ans = ask(1,0,n-1,l,r);
                printf("%I64u\n",ans);
            }
        }
        puts("");
    }
    return 0;
}
