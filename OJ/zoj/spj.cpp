#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int ans[] = {
	5,
	17,
	17,
	5,
	110,
	17,
	45,
	2,
	50,
	32,
	25,
	37,
	9,
	44,
	75,
	25,
	49,
	2,
	48,
	57,
	13,
	13,
	53,
	81,
	32
};
FILE *f;
int n , m;
char maze[22][11];
char out[22][11];
char temp[999];
char tmp[999];
bool vis[22][11];
int dx[] = {-1 , 1 , 0 , 0};
int dy[] = {0 , 0 , -1 , 1};
struct Node {
	int x , y , step;
	Node() {}
	Node(int a,int b,int c):x(a) , y(b) , step(c) {}
};
queue <Node> que;
int bfs(int sx,int sy) {
	while (!que.empty()) que.pop();
	que.push(Node(sx , sy , 1));
	memset(vis , false , sizeof(vis));
	vis[sx][sy] = true;
	while (!que.empty()) {
		int x = que.front().x;
		int y = que.front().y;
		int step = que.front().step + 1;
		que.pop();
		for (int d = 0 ; d < 4 ; d ++) {
			int xx = x + dx[d];
			int yy = y + dy[d];
			if (xx < 0 || xx == n || yy < 0 || yy == m) continue;
			if (vis[xx][yy]) continue;
			vis[xx][yy] = true;
			if (out[xx][yy] == '.') que.push(Node(xx , yy , step));
			if (out[xx][yy] == 'T') return step;
		}
	}
	return -1;
}
bool judge(int cas) {
	int i , j;
	if (!gets(temp)) {
		printf("Case : %d . No first line\n" , cas );
		return true;
	}
	sprintf(tmp , "Case %d: %d" , cas , ans[cas-1]);
	if (strcmp(tmp , temp)) {
	    cout << tmp << ' ' << temp << endl;
		printf("Case : %d . Wrong Answer or Wrong ID : %s\n" , cas , temp);
		return true;
	}
	int sx , sy;
	for (i = 0 ; i < n ; i ++) {
		if (!gets(out[i])) {
			printf("Case : %d . No complete map\n" , cas );
			return true;
		}
		if (strlen(out[i]) != m) {
			printf("Case : %d . Wrong map size\n" , cas );
			return true;
		}
		for (j = 0 ; j < m ; j ++) {
			if (out[i][j] != '.' && out[i][j] != 'B' && out[i][j] != 'W' &&
				out[i][j] != 'S' && out[i][j] != 'T') {
					printf("Case : %d . Illegal char\n" , cas );
					return true;
			}
			if (maze[i][j] == 'S') {
				if ( out[i][j] != 'S') {
					printf("Case : %d . Wrong 'S' \n" , cas );
					return true;
				}
				sx = i , sy = j;
			}
			if (maze[i][j] == 'T' && out[i][j] != 'T') {
				printf("Case : %d . Wrong 'T' \n" , cas );
				return true;
			}
			if (maze[i][j] == 'B' && out[i][j] != 'B') {
				printf("Case : %d . Wrong 'B' \n" , cas );
				return true;
			}
		}
	}
	if (bfs(sx , sy) != ans[cas-1]) {
		printf("Case : %d . Wrong path \n" , cas );
		return true;
	}
	if (!gets(temp)) {
		printf("Case : %d . No empty line\n" , cas );
		return true;
	}
	return false;
}
int main() {
	freopen("TDM.out","r",stdin);
	f = fopen("TD.in" , "r");
	int T;
	fscanf(f , "%d",&T);
	for (int cas = 1 ; cas <= T ; cas ++) {
		fscanf(f , "%d%d" , &n , &m);
		for (int i = 0 ; i < n ; i ++) {
			fscanf(f , "%s" , maze[i]);
		}
		if (judge(cas)) return 0;
	}
	puts("AC");
	return 0;
}
