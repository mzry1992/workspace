#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct Flight
{
	int tim,to,riv,id,dis;
	pair<int,int> pre;
	Flight(){}
	Flight(int _tim,int _to,int _riv,int _id)
	{
		tim=_tim;
		to=_to;
		riv=_riv;
		id=_id;
		dis=-1;
		pre=make_pair(-1,-1);
	}
	bool operator<(const Flight &a)const
	{
		return tim<a.tim;
	}
};
vector<Flight> sec[100001];
int getId(const vector<Flight> &a,int x)
{
	if (a.empty() || a.back().tim<x)
		return -1;
	int l=0,r=a.size()-1;
	while (l<r)
	{
		int mid=l+r>>1;
		if (a[mid].tim>=x)
			r=mid;
		else
			l=mid+1;
	}
	return l;
}
void print(int pos,int id)
{
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++)
	{
		int u,v,s,t;
		scanf("%d%d%d%d",&u,&v,&s,&t);
		sec[u].push_back(Flight(s,v,t,i));
	}
	for (int i=1;i<=n;i++)
		sort(sec[i].begin(),sec[i].end());
	int sp,tp,st,tt;
	scanf("%d%d%d%d",&sp,&tp,&st,&tt);
	if(sp==tp&&st<=tt)
	{
		puts("0");
		return 0;
	}
	int idx=getId(sec[sp],st);
	if (idx==-1)
	{
		puts("Impossible");
		return 0;
	}
	sec[sp][idx].dis=0;
	queue<pair<int,int> > que;
	que.push(make_pair(sp,idx));
	while (!que.empty())
	{
		int u=que.front().first,id=que.front().second;
		que.pop();
		if (id+1<sec[u].size() && sec[u][id+1].dis==-1)
		{
			sec[u][id+1].dis=sec[u][id].dis;
			sec[u][id+1].pre=sec[u][id].pre;
			que.push(make_pair(u,id+1));
		}
		int v=sec[u][id].to,vid=getId(sec[v],sec[u][id].riv);
		if (v==tp && sec[u][id].riv<=tt)
		{
			vector<int> ret;
			int nowpos = u,nowid = id;
			while (true)
			{
				ret.push_back(sec[nowpos][nowid].id+1);
				if (sec[nowpos][nowid].pre.first == -1)	break;
				int nxtpos = sec[nowpos][nowid].pre.first,nxtid = sec[nowpos][nowid].pre.second;
				nowpos = nxtpos;
				nowid = nxtid;
			}
			printf("%d\n",sec[u][id].dis+1);
			for (int i = ret.size()-1;i >= 0;i--)
				printf("%d ",ret[i]);
			puts("");
			return 0;
		}
		if (vid==-1)
			continue;
		if (sec[v][vid].dis==-1)
		{
			sec[v][vid].dis=sec[u][id].dis+1;
			sec[v][vid].pre=make_pair(u,id);
			que.push(make_pair(v,vid));
		}
	}
	puts("Impossible");
	return 0;
}
