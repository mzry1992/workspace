#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int M = 2000000 + 5;
const int N = 200000 + 5;
struct Node{
	int p,v;
	Node(int _p,int _v):p(_p),v(_v){
	}
	bool operator < (const Node &T)const{
		return v < T.v;
	}
};
vector<Node>E[N];
int n,m;
int pre[N],preE[N];
int used[N],Len[N];
queue<int>Q;
void bfs(int s){
	 memset(used,0,sizeof(used));
	 memset(Len,0,sizeof(Len));
	 used[s] = 1;pre[n] = -1;
	 while(Q.empty() != true) Q.pop();
	 Q.push(s);
	 while(Q.empty() != true){
		  int p = Q.front();
		  Q.pop();
		  for(int i = 0;i < E[p].size();i++){
			 int Newp = E[p][i].p;
			 if(used[Newp] == 0){
				used[Newp] = 1;Len[Newp] = Len[p] + 1;
				pre[Newp] = p;preE[Newp] = E[p][i].v;
				Q.push(Newp);
			 }else{
				 if(Len[Newp] == Len[p] + 1){
					 if(E[p][i].v < preE[Newp]){
						preE[Newp] = E[p][i].v;
						pre[Newp] = p;
					 }
				 }
			 }
		  }
	 }
	 return;
}
vector<int>Ans;
int main(){
	int i,j,k;
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		for(i = 1;i <= n;i++) E[i].clear();
		for(i = 1;i <= m;i++){
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			E[a].push_back(Node(b,c));
			E[b].push_back(Node(a,c));
		}
		for(i = 1;i <= n;i++)
			sort(E[i].begin(),E[i].end());
		bfs(n);
		printf("%d\n",Len[1]);
		int tmp = 1;
		Ans.clear();
		while(tmp != n){
			Ans.push_back(preE[tmp]);
			tmp = pre[tmp];
		}
		for(i = 0;i < Ans.size();i++){
			if(i != 0)printf(" ");
			printf("%d",Ans[i]);
		}
		printf("\n");
	}
	return 0;
}
