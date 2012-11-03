#include <cstdio>
#include <algorithm>
#define N 15
#include <cstring>
using namespace std;

int a[N][N], d[][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};
int n, m, black, white;

inline bool in(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < N;
}

bool check(int x, int y) {
	int cnt[8] = {0};
	for (int i = 0; i < 8; ++i) {
		int nx = x + d[i][0], ny = y + d[i][1];
		while (in(nx, ny) && a[nx][ny] == a[x][y]) {
			++cnt[i];
			nx += d[i][0], ny += d[i][1];
		}
	}
	for (int i = 0; i < 4; ++i) {
		if (cnt[i] + cnt[i + 4] >= 4) {
			return true;
		}
	}
	return false;
}

bool have(int x, int y) {
	for (int i = 0; i < 8; ++i) {
		int nx = x + d[i][0], ny = y + d[i][1];
		if (in(nx, ny) && a[nx][ny] != -1) {
			return true;
		}
	}
	return false;
}

bool have(int c, int x, int y) {
	for (int i = 0; i < 8; ++i) {
		int nx = x + d[i][0], ny = y + d[i][1];
		if (in(nx, ny) && a[nx][ny] == c) {
			return true;
		}
	}
	return false;
}

bool solve1(int c, int& x, int& y) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (a[i][j] == -1 && have(c, i, j)) {
				a[i][j] = c;
				if (check(i, j)) {
					a[i][j] = -1;
					x = i, y = j;
					return true;
				}
				a[i][j] = -1;
			}
		}
	}
	return false;
}

int solve2(int c, int& x, int& y) {
	int ans1 = -1;
	for (int x1 = 0; x1 < N && ans1 != 1; ++x1) {
		for (int y1 = 0; y1 < N && ans1 != 1; ++y1) {
			if (a[x1][y1] == -1) {
				a[x1][y1] = c;
				int ans2 = -1;
				for (int x2 = 0; x2 < N && ans2 != 1; ++x2) {
					for (int y2 = 0; y2 < N && ans2 != 1; ++y2) {
						if (a[x2][y2] == -1 && have(x2, y2)) {
							a[x2][y2] = 1 - c;
							if (check(x2, y2)) {
								a[x2][y2] = -1;
								ans2 = 1;
								continue;
							}
							int x, y;
							if (!solve1(c, x, y)) {
								ans2 = 0;
							}
							a[x2][y2] = -1;
						}
					}
				}
				x = x1, y = y1;
				ans1 = max(-ans2, ans1);
				a[x1][y1] = -1;
			}
		}
	}
	return ans1;
}

int main() {
    freopen("in.txt","r",stdin);
	int n;
	while (scanf("%d", &n), n) {
		memset(a, -1, sizeof (a));
		int x, y, c;
		black = 0, white = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d%d%d", &x, &y, &c);
			a[x][y] = c;
			if (c) {
				++black;
			}
			else {
				++white;
			}
		}
		if (black != white && black != white + 1) {
			puts("Invalid.");
			continue;
		}
		if (black == white) {
			c = 1;
		}
		else {
			c = 0;
		}
		if (solve1(c, x, y)) {
			printf("Place %s at (%d,%d) to win in 1 move.\n", (c ? "black" : "white"), x, y);
			continue;
		}
		int ans = solve2(c, x, y);
		if (ans == 0) {
			puts("Cannot win in 3 moves.");
		}
		else if (ans == -1) {
			puts("Lose in 2 moves.");
		}
		else {
			printf("Place %s at (%d,%d) to win in 3 moves.\n", (c ? "black" : "white"), x, y);
		}
	}
}
