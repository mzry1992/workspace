#include<stdio.h>   
#include<string.h>   
#include<queue>   
using namespace std;   
const int Len=40005;   
const int inf=1<<30;   
#define max(a,b) a>b ? a:b   
struct Edge{   
       int num;   
       int value;   
       int next;   
}E[Len*2];   
int p[Len];   
int L[Len];   
int n,m;   
int tot;   
int spfa(int s)   
{   
    bool visit[Len];   
    memset(visit,0,sizeof(visit));   
    memset(L,-20,sizeof(L));   
    printf("kkkkkkkkkkkkkkkk%d\n",L[1]);
    L[s]=0;   
    int que[Len*10];   
    int head,tail;   
    head=tail=0;   
    que[tail++]=s;   
    visit[s]=true;   
    while(head<tail)   
    {   
         int u=que[head++];   
         visit[u]=false;   
         printf("%d\n",u);
         for(int i=p[u];i!=-1;i=E[i].next)   
             if((L[E[i].num]<E[i].value+L[u])&&E[i].num!=s)   
             {   
                  L[E[i].num]=E[i].value+L[u];   
                  if(!visit[E[i].num])   
                  {   
                      visit[E[i].num]=true;   
                      que[tail++]=E[i].num;   
                  }   
             }   
    }   
    int k,Max=inf;   
    for(int i=1;i<=n;i++)   
    {   
        if(L[i]<Max)   
        {   
            Max=L[i];   
            k=i;   
        }   
    }   
    for (int i=1;i <= n;i++)
        printf("%d ",L[i]);
    printf("\n");
    return k;   
}   
int main()   
{   
    while(scanf("%d%d",&n,&m)!=EOF)   
    {   
        tot=0;   
        memset(p,-1,sizeof(p));   
        int a,b,c;   
        char d,dd;   
        for(int i=1;i<=m;i++)   
        {   
             scanf("%d%d%d",&a,&b,&c);   
             getchar();   
             getchar();   
             E[tot].num=b;   
             E[tot].next=p[a];   
             E[tot].value=-c;   
             p[a]=tot++;   
             E[tot].num=a;   
             E[tot].next=p[b];   
             E[tot].value=-c;   
             p[b]=tot++;   
        }   
        for (a = 1;a <= n;a++)
        {
            printf("%d :",a);
            for(b=p[a];b!=-1;b=E[b].next)   
                printf("|%d %d %d| ",E[b].num,E[b].value,E[b].next);
            printf("\n");
        }
        int start=1;   
        int end=spfa(start);   
        start=end;   
        end=spfa(start);   
        printf("%d\n",-L[end]);   
    }   
    return 0;   
}  


