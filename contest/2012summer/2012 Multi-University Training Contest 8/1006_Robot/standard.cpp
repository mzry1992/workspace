#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 1000
#define MAXI 1000000
 
const int dh[] = { 0, 1, 0,-1};
const int dw[] = { 1, 0,-1, 0};
 
int H, W, N, X, Y;
bool vst[MAXN][MAXN][4];
int head[MAXI + 1], link[MAXN * MAXN * 4];
 
char mp[MAXN][MAXN + 1], ins[MAXI + 1], stat[MAXI + 1];
 
inline bool can(int x, int y) {
    return 0 <= x && x < H && 0 <= y && y < W && mp[x][y] != '#';
}
 
int arc[MAXI + 1][4];
 
void pp_ins() {         // preprocess
    stat[0] = 3;
    for (int i = 0; i < N; ++i)
        if (ins[i] == 'R')
            stat[i + 1] = (stat[i] + 1) % 4;
        else
            stat[i + 1] = (stat[i] + 3) % 4;
    int nxt[4] = {N + 1, N + 1, N + 1, N + 1};
    for (int i = N; i >= 0; --i) {
        copy(nxt, nxt + 4, arc[i]);
        nxt[(int)stat[i]] = i;
    }
}
 
inline int node(int x, int y, int d) {
    return y + x * W + d * W * H;
}
 
bool add(int s, int x, int y, int d) {
    bool ret = false;
    for ( ; can(x, y) && !vst[x][y][d]; x += dh[d], y += dw[d]) {
        if (mp[x][y] == 'E') { ret = true; break; }
        link[node(x, y, d)] = head[s];
        head[s] = node(x, y, d);
        vst[x][y][d] = true;
    }
    return ret;
}
 
bool bfs() {
    pp_ins();
    fill(head, head + N + 1, -1);
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            for (int k = 0; k < 4; ++k)
                vst[i][j][k] = false;
    if (add(0, X, Y, 3)) return true;
    for (int i = 0; i <= N; ++i) {
        for (int p = head[i]; p != -1; p = link[p]) {
            int y = p % W, x = p / W % H;
            for (int k = 0; k < 4; ++k)
                if (arc[i][k] <= N && add(arc[i][k], x, y, k))
                    return true;
        }
    }
    return false;
}
 
int main() {
    while (scanf("%d%d%d ", &H, &W, &N) != EOF) {
        gets(ins);
        for (int i = 0; i < H; ++i)
            gets(mp[i]);
        for (int i = 0; i < H; ++i)
            for (int j = 0; j < W; ++j)
                if (mp[i][j] == 'S')
                    X = i, Y = j;
        puts(bfs() ? "Yes" : "No");
    }
    return 0;
}
