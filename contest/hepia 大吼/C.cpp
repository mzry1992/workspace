#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int n,T1,T2,ans;
struct N
{
    int t,sum;
    int time;
} peo[55];
class cmp
{
public:
    bool operator()(const int &a,const int &b) const
    {
        if(peo[a].t==peo[b].t)
            return peo[a].sum<peo[b].sum;
        return peo[a].t>peo[b].t;
    }
};
priority_queue<int,vector<int>,cmp> s1,s2;
queue<int> q1,q2;
void solve1()
{
    int first=q1.front();
    if(peo[first].time+peo[first].t>T2)
    {
        if(s2.empty())
        {
            T2=peo[first].time+peo[first].t;
            peo[first].time=T2;
            s2.push(first);
            q1.pop();
        }
        else
        {
            while(!s2.empty())
            {
                int top=s2.top();
                s2.pop();
                q2.push(top);
            }
        }
    }
    else
    {
        peo[first].time=T2;
        s2.push(first);
        q1.pop();
    }
    if(q1.empty())
    {
    	if(s1.empty() || peo[s1.top()].time+peo[s1.top()].t>T2)
    	{
			while(!s2.empty())
			{
				int top=s2.top();
				s2.pop();
				q2.push(top);
			}
    	}
    	else
    	{
    		while(!s1.empty())
    		{
    			int top=s1.top();
    			s1.pop();
    			q1.push(top);
    		}
    	}
    }
}
bool solve2()
{
    int first=q2.front();
    if(peo[first].time+peo[first].t>T1)
    {
        if(s1.empty())
        {
            T1=peo[first].time+peo[first].t;
            peo[first].time=T1;
            peo[first].sum--;
            if(peo[first].sum==0)
                ans=max(ans,peo[first].time);
            else
                s1.push(first);
            q2.pop();
        }
        else
        {
            while(!s1.empty())
            {
                int top=s1.top();
                s1.pop();
                q1.push(top);
            }
        }
    }
    else
    {
        peo[first].time=T1;
        peo[first].sum--;
        if(peo[first].sum==0)
            ans=max(ans,peo[first].time);
        else
            s1.push(first);
        q2.pop();
    }
    if(q2.empty())
    {
    	if(s2.empty() || peo[s2.top()].time+peo[s2.top()].t>T1)
    	{
			while(!s1.empty())
			{
				int top=s1.top();
				s1.pop();
				q1.push(top);
			}
    	}
    	else
    	{
    		while(!s2.empty())
			{
				int top=s2.top();
				s2.pop();
				q2.push(top);
			}
    	}
    }
}
int main()
{
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        int i;
        for(i=0; i<n; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            peo[i].t=a;
            peo[i].sum=b;
            peo[i].time=0;
            s1.push(i);
        }
        int tmp=s1.top();
        s1.pop();
        q1.push(tmp);
        while(!s1.empty())
        {
            int top=s1.top();
            s1.pop();
            if(peo[top].t==peo[tmp].t)
                continue;
            tmp=top;
            q1.push(tmp);
        }
        T1=T2=ans=0;
        while(!q1.empty()||!q2.empty())
        {
            if(q2.empty())
                solve1();
            else if(q1.empty())
                solve2();
            else
            {
                int k1,k2;
                k1=q1.front();
                k2=q2.front();
                if(peo[k1].time+peo[k1].t<peo[k2].time+peo[k2].t)
                    solve1();
                else
                    solve2();
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}


