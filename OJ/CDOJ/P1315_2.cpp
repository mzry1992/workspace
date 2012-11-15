#include <iostream>
using namespace std;
const int M=1605;
struct Edge
{
   int id,next;
}nd[3*M],pas[3*M];
int n,m,end;
char ch[45][45];
int val[M],w[M];
bool use[M];
int order[M],be[M],cnt,coun;
void addedge(int u,int v)
{
    nd[end].next=nd[u].next;
    nd[end].id=v;
    nd[u].next=end;
    
    pas[end].next=pas[v].next;
    pas[end].id=u;
    pas[v].next=end;
    end++;
}
bool check(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m)
    {
       if(ch[x][y]=='#')return 0;
       return 1;
    }
    return 0;
}
void read()
{
    int i,j,d;
    memset(nd,-1,sizeof(nd));
    memset(pas,-1,sizeof(pas));
    cin>>n>>m;
    end=n*m;
    for(i=0;i<n;i++)cin>>ch[i];
    for(i=0;i<n;i++)
     for(j=0;j<m;j++)
     {
        if(ch[i][j]!='#')
        {
           if(check(i,j+1))addedge(i*m+j,i*m+j+1);  
           if(check(i+1,j))addedge(i*m+j,(i+1)*m+j);
           d=ch[i][j]-'0';

           if(ch[i][j]=='*')
           {
             d=0;
             int x,y;
             cin>>x>>y;
             if(check(x,y))addedge(i*m+j,x*m+y);
           }
           val[i*m+j]=d;
        }
        else val[i*m+j]=0;
     }
}
void dfs(int u)
{
     use[u]=1;
     int i;
     for(i=nd[u].next;i!=-1;i=nd[i].next)
     {
       int v=nd[i].id;
       if(use[v])continue;
       dfs(v);
     }
     order[coun++]=u;
}
void rdfs(int u)
{
     use[u]=1;
     be[u]=cnt;
     int i;
     for(i=pas[u].next;i!=-1;i=pas[i].next)
     {
       int v=pas[i].id;
       if(use[v])continue;
       rdfs(v);
     }
}
void Make_G()
{
     int i,j;
     memset(pas,-1,sizeof(pas));
     int g_end=cnt+1;
     for(i=0;i<n*m;i++)
      for(j=nd[i].next;j!=-1;j=nd[j].next)
      {
         int v=nd[j].id;
         if(be[v]!=be[i])
         {
           pas[g_end].next=pas[be[i]].next;
           pas[g_end].id=be[v];
           pas[be[i]].next=g_end;
           g_end++;
         }
      }
}
int maxn,ans;
void DFS(int u)
{
    use[u]=1;
    ans+=w[u];
    if(ans>maxn){maxn=ans;}
    int i;
    for(i=pas[u].next;i!=-1;i=pas[i].next)
    {
       int v=pas[i].id;
       if(!use[v])
       {
         DFS(v);
       }
    }
    ans-=w[u];
    use[u]=0;
}
void work()
{
   memset(use,0,sizeof(use));
   coun=0;
   int i,j;
   for(i=0;i<n*m;i++)
   if(!use[i])dfs(i);
   cnt=0;
   memset(use,0,sizeof(use));
   for(i=coun-1;i>=0;i--)
   if(!use[order[i]])
   {
     cnt++;
     rdfs(order[i]);
   }
   Make_G();//Ëõµã¹¹Í¼
   for(i=1;i<=cnt;i++)
   {
     w[i]=0;
     for(j=0;j<n*m;j++)
      if(be[j]==i)w[i]+=val[j];
   }
   
        for (i = 0;i < n*m;i++)
            cout << i << ' ' << be[i] << endl;
        for (i = 1;i < cnt;i++)
        {
            cout << i << ' ' << w[i] << " : " ;
            for (j = pas[i].next;j != -1;j = pas[j].next)
                cout << pas[j].id << ' ' ;
            cout << endl;
        } 
   memset(use,0,sizeof(use));
   ans=0;maxn=-1;
   DFS(be[0]);
   printf("%d\n",maxn); 
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       read();
       work();      
    }
    return 0;
}
