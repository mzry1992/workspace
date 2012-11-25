#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int n;
struct N
{
    int st,ed;
    int num;
}lec[100005];
bool arr(N a,N b)
{return a.st<b.st;}
struct M
{
    int last;
    int kind;
};
class cmp
{
    public:
        bool operator()(const M a,const M b) const
            {
                return a.last>b.last;
            }
};
priority_queue<M,vector<M>,cmp> q;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
	    int i;
	    for(i=0;i<n;i++)
	    {
            scanf("%d%d",&lec[i].st,&lec[i].ed);
            lec[i].num=i;
	    }
	    sort(lec,lec+n,arr);
	    while(!q.empty())
            q.pop();
        int ans=0;
	    for(i=0;i<n;i++)
	    {
	        M room,sec;
	        if(q.empty())
            {
                ans++;
                room.last=lec[i].ed;
                room.kind=lec[i].num;
                q.push(room);
            }
            else
            {
                room=q.top();
                q.pop();
                if(room.last<=lec[i].st)
                {
                    if((room.kind==0&&lec[i].num==1)||(room.kind==1&&lec[i].num==0))
                    {
                        if(q.empty())
                        {
                            ans++;
                            sec.last=lec[i].ed;
                            sec.kind=lec[i].num;
                            q.push(sec);
                        }
                        else
                        {
                            sec=q.top();
                            q.pop();
                            if(sec.last<=lec[i].st)
                            {
                                sec.last=lec[i].ed;
                                sec.kind=min(sec.kind,lec[i].num);
                            }
                            else
                            {
                                M ne;
                                ans++;
                                ne.last=lec[i].ed;
                                ne.kind=lec[i].num;
                                q.push(ne);
                            }
                            q.push(sec);
                        }
                    }
                    else
                    {
                        room.last=lec[i].ed;
                        room.kind=min(room.kind,lec[i].num);
                    }
                }
                else
                {
                    ans++;
                    sec.last=lec[i].ed;
                    sec.kind=lec[i].num;
                    q.push(sec);
                }
                q.push(room);
            }
	    }
	    printf("%d\n",ans);
	}
	return 0;
}
