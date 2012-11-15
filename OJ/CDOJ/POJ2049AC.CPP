#include <iostream>
#include <queue>
using namespace std;
#define MAX(a,b) (a>b ? a:b)

const int INF=100000000;
const int MAX_SIZE=256;
struct State
{
	int x,y;
	int c;
	bool operator < (const State &a) const
	{
		return  a.c<c;
	}
};
priority_queue<State> qu;
int vE[MAX_SIZE][MAX_SIZE];
int hE[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];

int N,M;
int Xmax,Ymax;
int xd,yd;
void Clear(void)
{
	while(!qu.empty())
	{
		qu.pop();
	}
}
void BFS(void)
{
	int x,y;
	for(x=0; x<Xmax+1; x++)
	{
		for(y=0; y<Ymax+1; y++)
		{
			dist[x][y]=INF;
		}
	}
	State pn;
	pn.x=0; pn.y=0;
	pn.c=0;
	dist[0][0]=0;
	qu.push(pn);
	while(!qu.empty())
	{
		pn=qu.top();
		qu.pop();
		x=pn.x; y=pn.y;
		if(x==xd && y==yd)
		{
			return;
		}
		// ио
		if(y+1 <= Ymax && dist[x][y+1]> dist[x][y]+vE[x][y+1])
		{
			dist[x][y+1]=dist[x][y]+vE[x][y+1];
			pn.x=x; pn.y=y+1; pn.c=dist[x][y+1];
			qu.push(pn);
		}
		// ср
		if(x+1 <=Xmax && dist[x+1][y]>dist[x][y]+hE[x+1][y])
		{
			dist[x+1][y]=dist[x][y]+hE[x+1][y];
			pn.x=x+1; pn.y=y; pn.c=dist[x+1][y];
			qu.push(pn);
		}
		// об
		if(y-1 >=0 && dist[x][y-1]> dist[x][y]+vE[x][y])
		{
			dist[x][y-1]=dist[x][y]+vE[x][y];
			pn.x=x; pn.y=y-1; pn.c=dist[x][y-1];
			qu.push(pn);
		}
		// вС
		if(x-1 >=0 && dist[x-1][y]>dist[x][y]+hE[x][y])
		{
			dist[x-1][y]=dist[x][y]+hE[x][y];
			pn.x=x-1; pn.y=y; pn.c=dist[x-1][y];
			qu.push(pn);
		}
	}
	dist[xd][yd]=-1;
}

int main(void)
{
	int i,j;
	int x,y,d,t;
	x=INF;
	double ex,ec;
	while(cin>>N>>M)
	{
		if(N==-1 && M==-1)
			break;
		memset(vE,0,sizeof(vE));
		memset(hE,0,sizeof(hE));
		Xmax=0; Ymax=0;

		for(i=0; i<N; i++)
		{
			cin>>x>>y>>d>>t;
			if(d==0)
			{
				for(j=0; j<t; j++)
				{
					vE[x+j][y]=INF;
				}
				Xmax=MAX(x+t,Xmax);
				Ymax=MAX(y,Ymax);
			}
			else
			{
				for(j=0; j<t; j++)
				{
					hE[x][y+j]=INF;
				}
				Xmax=MAX(x,Xmax);
				Ymax=MAX(y+t,Ymax);
			}
		}
		for(i=0; i<M; i++)
		{
			cin>>x>>y>>d;
			if(d==0)
			{
				vE[x][y]=1;
			}
			else
			{
				hE[x][y]=1;
			}
		}
		cin>>ex>>ec;
		if(ex>Xmax || ec>Ymax)
		{
			cout<<"0"<<endl;
		}
		else
		{
			xd=int(ex); yd=int(ec);
			BFS();
			cout<<dist[xd][yd]<<endl;
			Clear();
		}
	}
	return 0;
}
