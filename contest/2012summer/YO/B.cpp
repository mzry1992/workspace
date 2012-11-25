#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int m,c,n;
struct N
{
    int num,pos;
    int book[55];
    void init()
    {
        num=pos=0;
        memset(book,0,sizeof(book));
    }
}desk[15],peo[105];
queue<int> q;
void delet(int p,int k)
{
    int i;
    for(i=k;i<desk[p].num-1;i++)
        desk[p].book[i]=desk[p].book[i+1];
    desk[p].num--;
}
int main()
{
    while(1)
    {
        scanf("%d%d%d",&m,&c,&n);
        if(!m&&!c&&!n)
            break;
        int i,j;
        for(i=1;i<=m;i++)
            desk[i].init();
        for(i=0;i<n;i++)
        {
            peo[i].init();
            scanf("%d",&peo[i].num);
            for(j=0;j<peo[i].num;j++)
                scanf("%d",&peo[i].book[j]);
            q.push(i);
        }
        int ans=0;
        while(!q.empty())
        {
            int now=q.front();
            q.pop();
            int id=peo[now].book[peo[now].pos++];
            if(peo[now].pos<peo[now].num)
                q.push(now);
            bool flag=false;
            for(i=1;!flag&&i<=m;i++)
                for(j=0;!flag&&j<desk[i].num;j++)
                    if(desk[i].book[j]==id)
                    {
                        ans+=i;
                        delet(i,j);
                        flag=true;
                    }
            if(!flag)
                ans+=m+1;
            flag=false;
            if(desk[1].num<c)
            {
                ans+=1;
                desk[1].book[desk[1].num++]=id;
                flag=true;
            }
            if(!flag)
            {
                int tmp=-1,pp;
                for(i=2;!flag&&i<=m;i++)
                    if(desk[i].num<c)
                    {
                        ans+=i;
                        tmp=i;
                        pp=desk[i].num;
                        desk[i].book[desk[i].num++]=id;
                        flag=true;
                    }
                if(!flag)
                {
                    ans+=m+1;
                    tmp=m+1;
                }
                flag=false;
                ans++;
                int last=desk[1].book[0];
                delet(1,0);
                for(i=tmp;!flag&&i<=m;i++)
                    if(desk[i].num<c)
                    {
                        ans+=i;
                        desk[i].book[desk[i].num++]=last;
                        flag=true;
                    }
                if(!flag)
                    ans+=m+1;
                ans+=tmp;
                if(tmp<=m)
                    delet(tmp,pp);
                ans++;
                desk[1].book[desk[1].num++]=id;
            }
        }
        printf("%d\n",ans);
    }
	return 0;
}
