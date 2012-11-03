#include <iostream>
#include <cstdio>
using namespace std;

int n,m,a[100010];
struct treetype
{
       int key,max;
}t[3000000];

void make(int now,int L,int R)
{
     if (L == R)      
        t[now].key = t[now].max = a[L];
     else
     {
           make(now*2,L,(L+R)/2);
           make(now*2+1,(L+R)/2+1,R);
           t[now].max = max(t[now*2].max,t[now*2+1].max);
     }
}

void add(int now,int L,int R,int pos,int tkey)
{
     if (L == R)
           t[now].key = t[now].max = tkey;
     else
     {
         if (pos <= (L+R)/2)
            add(now*2,L,(L+R)/2,pos,tkey);
         else
             add(now*2+1,(L+R)/2+1,R,pos,tkey);
         t[now].max = max(t[now*2].max,t[now*2+1].max);
     }
}

int que(int now,int L,int R,int l,int r)
{
    if ((L > r) || (R < l))     return -1992100500;
    if ((L >= l) && (R <= r))   return t[now].max;
    return max(que(now*2,L,(L+R)/2,l,r),que(now*2+1,(L+R)/2+1,R,l,r));
}

int main()
{
    int i;
    scanf("%d%d",&n,&m);
    for (i = 1;i <= n;i++)
        scanf("%d",&a[i]);
    make(1,1,n);
    int com,a,b;
    for (i = 1;i <= m;i++)
    {
        scanf("%d%d%d",&com,&a,&b);
        if (com == 1)
           add(1,1,n,a,b);
        else
            printf("%d\n",que(1,1,n,a,b));
    }
    system("pause");
    return 0;
}
