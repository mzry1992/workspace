#include <iostream>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const double EPS = 1e-8;

inline int sgn(double d) {
    if (fabs(d)<EPS) return 0;
    return d>0?1:-1;
}

int gauss(int N, int M, double a[][222]) {
    int i, j, r, c, pvt;
    double maxp;
    for (r=0, c=0; r<N && c<M; ++r, ++c) {
        for (maxp=0, i=r; i < N; ++i)
            if (fabs(a[i][c])>fabs(maxp)) maxp = a[pvt=i][c];
        if (sgn(maxp)==0) {
            r--;
            continue;
        }
        if (pvt != r)
            for (j = r; j <= M; ++j) swap(a[r][j], a[pvt][j]);
        for (j = c+1; j <= M; ++j) {
            a[r][j] /= maxp;
            for (i = r+1; i < N; ++i)
                a[i][j] -= a[i][c]*a[r][j];
        }
    }
    for (i = r; i < N; ++i)
        if (sgn(a[i][M])) return -1;
    if (r < M) return M-r;
    for (i = M-1; i >= 0; --i)
        for (j = i+1; j < M; ++j)
            a[i][M] -= a[j][M]*a[i][j];
    return 0;
}

int T, N, M, s, t, d;
double a[222][222];
double p[111];

int vis[222];

bool bfs(int s) {
    queue<int> q;
    q.push(s);
    memset(vis, 0, sizeof vis);
    vis[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < M; ++i) {
            u++; if (u==N) u = 0;
            if (sgn(p[i]) && !vis[u]) {
                vis[u] = 1;
                q.push(u);
            }
        }
    }
    if (vis[t] || vis[(N-t)%N]) return 1;
    else return 0;
}

int main() {
	freopen("data.in","r",stdin);
	freopen("data_6.out","w",stdout);
    int i, j, k, r, c;
    cin>>T;
    while (T--) {
        cin>>N>>M>>t>>s>>d;
        assert(N!=0);
        for (i = 0; i < M; ++i) {
            cin>>p[i];
            p[i] /= 100;
        }
        N = N-1<<1;
        if (d > 0) s = N-s;
        if (s==t) {
            puts("0.00");
            continue;
        }
        if (!bfs(s)) {
            puts("Impossible !");
            continue;
        }
        double sum = 0;
        for (i = 0; i < M; ++i)
            sum += p[i]*(i+1);
        memset(a, 0, sizeof a);
        for (i = 0; i < N; ++i) {
            a[i][i] = 1;
            if (!vis[i]) {
                a[i][N] = 1e9;
                continue;
            }
            if (i==t||i==(N-t)%N) {
                a[i][N] = 0;
                continue;
            }
            a[i][N] = sum;
            int now = i;
            for (j = 0; j < M; ++j) {
                now++; if (now==N) now = 0;
                a[i][now] -= p[j];
            }
        }
        if (~gauss(N, N, a)) {
            printf("%.2f\n", a[s][N]+EPS);
        }
        else puts("Impossible !");
    }
    return 0;
}
