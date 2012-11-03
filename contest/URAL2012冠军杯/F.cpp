#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n,m;
struct Node
{
	int time,to,atime,eid;
	Node(){}
	Node(int _time,int _to,int _atime,int _eid)
	{
		time = _time;
		to = _to;
		atime = _atime;
		eid = _eid;
	}
	bool operator < (const Node& b)const
	{
		if (time == b.time)
		{
			if (to == b.to)
			{
				if (atime == b.atime)
					return eid < b.eid;
				return atime < b.atime;
			}
			return to < b.to;
		}
		return time < b.time;
	}
};

vector<Node > node[100000];

struct Sta
{
	int pos,time,preid;
	Sta(){}
	Sta(int _pos,int _time,int _preid)
	{
		pos = _pos;
		time = _time;
		preid = _preid;
	}
};

int FindPos(int pos,Node now)
{
	return lower_bound(node[pos].begin(),node[pos].end(),now)-node[pos].begin();
}

vector<int> dist[100000];
vector<pair<int,int> > pre[100000];

bool BFS()
{
	int spos,epos,stime,etime;
	scanf("%d%d%d%d",&spos,&epos,&stime,&etime);
	spos--;
	epos--;
	node[spos].push_back(Node(stime,-1,-1,-1));
	node[epos].push_back(Node(etime,-1,-1,-1));

	for (int i = 0;i < n;i++)
	{
		dist[i].resize(node[i].size());
		pre[i].resize(node[i].size());
		for (int j = 0;j < dist[i].size();j++)
			dist[i][j] = 0x3f3f3f3f;
		sort(node[i].begin(),node[i].end());
	}

	queue<Sta > Q;
	Sta now,nxt;
	now = Sta(spos,stime,FindPos(spos,Node(stime,-1,-1,-1)));
	Q.push(now);
	dist[now.pos][now.preid] = 0;
	pre[now.pos][now.preid] = make_pair(-1,-1);

	while (!Q.empty())
	{
		now = Q.front();
		Q.pop();

		//printf("now.pos = %d, now.time = %d, dis = %d\n",now.pos,now.time,dist[now.pos][now.preid]);
		if (now.pos == epos && now.time == etime)
		{
			pair<int,int> haha = make_pair(now.pos,now.preid);
			vector<int> ret;
			while (true)
			{
				pair<int,int> nxt = make_pair(pre[haha.first][haha.second].first,pre[haha.first][haha.second].second);

				if (nxt.first == -1)	break;
				if (node[nxt.first][nxt.second].to != -1 && (nxt.first != haha.first || nxt.second < haha.second))
					ret.push_back(node[nxt.first][nxt.second].eid);
				haha = nxt;
			}
			reverse(ret.begin(),ret.end());
			printf("%d\n",ret.size());
			for (int i = 0;i < ret.size();i++)
				printf("%d ",ret[i]+1);
			printf("\n");
			return true;
		}

		if (now.preid+1 < node[now.pos].size())
		{
			nxt = Sta(now.pos,node[now.pos][now.preid+1].time,now.preid+1);
			//printf("%d %d %d\n",nxt.pos,nxt.time,nxt.preid);
			if (dist[nxt.pos][nxt.preid] > dist[now.pos][now.preid]+1)
			{
				dist[nxt.pos][nxt.preid] = dist[now.pos][now.preid]+1;
				pre[nxt.pos][nxt.preid] = make_pair(now.pos,now.preid);
				Q.push(nxt);
			}
		}
		if (node[now.pos][now.preid].to != -1)
		{
			nxt.pos = node[now.pos][now.preid].to;
			nxt.time = node[now.pos][now.preid].atime;
			nxt.preid = FindPos(nxt.pos,Node(nxt.time,-1,-1,node[now.pos][now.preid].eid));

			if (dist[nxt.pos][nxt.preid] > dist[now.pos][now.preid]+1)
			{
				dist[nxt.pos][nxt.preid] = dist[now.pos][now.preid]+1;
				pre[nxt.pos][nxt.preid] = make_pair(now.pos,now.preid);
				Q.push(nxt);
			}
		}
	}
	return false;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 0;i < m;i++)
	{
		int u,v,st,at;
		scanf("%d%d%d%d",&u,&v,&st,&at);
		u--;
		v--;
		node[u].push_back(Node(st,v,at,i));
		node[v].push_back(Node(at,-1,-1,i));
	}

	if (BFS() == false)
		puts("Impossible");

    return 0;
}

