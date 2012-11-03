#include <stdio.h>
#include <string.h>
#define MaxN 250
#define MaxB 18

struct P {
	int x, y;
}p[MaxN], rec[10];

int board[MaxB][MaxB], cnt[2], n, col;
int dx[] = {1, 1, 0, -1};
int dy[] = {0, 1, 1, 1};

bool check(int x, int y, int k)
{
	return x >= 0 && x < 15 && y >= 0 && y < 15 && board[x][y] == k;
}

int canWin(int user)
{
	int nr = 0;
	for (int i = 0; i < 15; ++i)
		for (int j = 0; j < 15; ++j)
			if (board[i][j] == -1) {
				for (int d = 0; d < 4; ++d) {
					int tt = 1;
					for (int k = 1; ; ++k, ++tt)
						if (!check(i+k*dx[d], j+k*dy[d], user)) break;
					for (int k = 1; ; ++k, ++tt)
						if (!check(i-k*dx[d], j-k*dy[d], user)) break;
					if (tt >= 5) {
						rec[nr].x = i;
						rec[nr].y = j;
						nr++;
						if (nr > 1) return nr;
						break;
					}
				}
			}
			return nr;
}

void solve(int user)
{
	if (canWin(user) > 0) {
		printf("Place %s at (%d,%d) to win in 1 move.\n", user ? "black" : "white", rec[0].x, rec[0].y);
		return;
	}
	int tmp = canWin(1-user);
	if (tmp > 1) {
		puts("Lose in 2 moves.");
		return;
	}
	else if (tmp == 1) {
		board[rec[0].x][rec[0].y] = user;
		p[n] = rec[0];
		if (canWin(user) > 1)
			printf("Place %s at (%d,%d) to win in 3 moves.\n", user ? "black" : "white", p[n].x, p[n].y);
		else
			puts("Cannot win in 3 moves.");
		return;
	}
	for (int r = 0; r < 15; ++r) for (int c = 0; c < 15; ++c) if (board[r][c] == -1) {
		board[r][c] = user;
		if (canWin(user) > 1) {
			printf("Place %s at (%d,%d) to win in 3 moves.\n", user ? "black" : "white", r, c);
			return;
		}
		board[r][c] = -1;
	}
	puts("Cannot win in 3 moves.");
	return;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out2.txt","w",stdout);
	while (scanf("%d", &n), n) {
		memset(board, -1, sizeof(board));
		cnt[0] = cnt[1] =0;
		for (int i = 0; i < n; ++i) {
			scanf("%d%d%d", &p[i].x, &p[i].y, &col);
			board[p[i].x][p[i].y] = col;
			++cnt[col];
		}
		if (cnt[0] == cnt[1]) solve(1);
		else if (cnt[0] + 1 == cnt[1]) solve(0);
		else puts("Invalid.");
	}
	return 0;
}
