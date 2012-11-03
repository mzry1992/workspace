#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
char s[10],A,B,C;
int x[1100],y[1100],z[1100],xx[1100],yy[1100],zz[1100];
void init(int a,int b,int c)
{
    int i;
    for (i=0;i<a;i++)
        x[i]=xx[i]=i;
    for (i=0;i<b;i++)
        y[i]=yy[i]=i;
    for (i=0;i<c;i++)
        z[i]=zz[i]=i;
}
void swap1(int a,int b)
{
    int tmp=x[a];
    x[a]=x[b];
    x[b]=tmp;
    xx[x[a]]=a;
    xx[x[b]]=b;
}
void swap2(int a,int b)
{
    int tmp=y[a];
    y[a]=y[b];
    y[b]=tmp;
    yy[y[a]]=a;
    yy[y[b]]=b;
}
void swap3(int a,int b)
{
    int tmp=z[a];
    z[a]=z[b];
    z[b]=tmp;
    zz[z[a]]=a;
    zz[z[b]]=b;
}
void find(int a)
{
    if (a>A*B*C || a<=0) return;
    a--;
    printf("%d %d %d\n",xx[a/(B*C)],yy[(a/C)%B],zz[a%C]);
}
int main()
{
    int a,b,c,i;
    while (scanf("%s",s)!=EOF)
    {
        if (strcmp(s,"FILL")==0)
        {
            printf("START\n");
            scanf("%d%d%d",&A,&B,&C);
            init(A,B,C);
            //cout<<'a'<<endl;
        }
        /*for (i=0;i<A;i++) printf("%d ",xx[i]);
        puts("");
        for (i=0;i<B;i++) printf("%d ",yy[i]);
        puts("");
        for (i=0;i<C;i++) printf("%d ",zz[i]);
        puts("");*/
        if (strcmp(s,"SWAP1")==0)
        {
            scanf("%d%d",&a,&b);
            swap1(a,b);
        }
        if (strcmp(s,"SWAP2")==0)
        {
            scanf("%d%d",&a,&b);
            swap2(a,b);
        }
        if (strcmp(s,"SWAP3")==0)
        {
            scanf("%d%d",&a,&b);
            swap3(a,b);
        }
        if (strcmp(s,"QUERY")==0)
        {
            scanf("%d%d%d",&a,&b,&c);
            printf("%d\n",x[a]*B*C+y[b]*C+z[c]+1);
        }
        if (strcmp(s,"FIND")==0)
        {
            scanf("%d",&a);
            find(a);
        }
    }
}

