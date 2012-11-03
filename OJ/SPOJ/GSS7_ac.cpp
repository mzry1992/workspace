// I'm the Topcoder
//C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
//C++
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <stack>
#include <string>
#include <list>
#include <queue>
#include <map>
#include <vector>
#include <deque>
#include <set>
using namespace std;

//*************************OUTPUT*************************
#ifdef WIN32
#define INT64 "%I64d"
#define UINT64 "%I64u"
#else
#define INT64 "%lld"
#define UINT64 "%llu"
#endif

//**************************CONSTANT***********************
#define INF 0x3f3f3f3f
#define eps 1e-8
#define PI acos(-1.)
#define PI2 asin (1.);
typedef long long LL;
//typedef __int64 LL;   //codeforces
typedef unsigned int ui;
typedef unsigned long long ui64;
#define MP make_pair
typedef vector<int> VI;
typedef vector<int> VS;
typedef pair<int, int> PII;
#define pb push_back
#define mp make_pair

//***************************SENTENCE************************
#define CL(a,b) memset (a, b, sizeof (a))
#define sqr(a,b) sqrt ((double)(a)*(a) + (double)(b)*(b))

//****************************FUNCTION************************
template <typename T> double DIS(T va, T vb) { return sqr(va.x - vb.x, va.y - vb.y); }
template <class T> inline T INTEGER_LEN(T v) { int len = 1; while (v /= 10) ++len; return len; }
template <typename T> inline T square(T va, T vb) { return va * va + vb * vb; }

// aply for the memory of the stack
#pragma comment (linker, "/STACK:1024000000,1024000000")
//end

#define CY 100005
#define NODE 4*CY
#define E 2*CY
typedef int typec;

struct node{
	typec mx_sum, mx_l, mx_r, sum;
};
struct re{
	int v, nxt;
}e[E];

struct tree{
	int L, R, color;
	typec v, mx, L_mx, R_mx, sum;
}seg[NODE];

int g[CY], fa[CY], dep[CY], size[CY], son[CY], top[CY], ind[CY];
int ar[CY], tb[CY];
int idx, idy, N, Q;

void init() {
	idx = idy = 0;
	memset(g, -1, sizeof(g));
}

void addedge(int u, int v) {
	e[idx].v = v;
	e[idx].nxt = g[u]; g[u] = idx++;
}

void dfs1(int u, int f, int d) {
	dep[u] = d + 1;
	fa[u] = f;
	size[u] = 1;
	son[u] = -1;
	for (int i = g[u]; ~i; i = e[i].nxt) {
		int v = e[i].v;
		if (f != v) {
			dfs1(v, u, d + 1);
			size[u] += size[v];
			if (-1 == son[u] || size[son[u]] < size[v]) {
				son[u] = v;
			}
		}
	}
}

void dfs2(int u, int pt) {
	ind[u] = ++idy;
	tb[idy] = u;
	top[u] = pt;
	if (~son[u]) dfs2(son[u], pt);
	for (int i = g[u]; ~i; i = e[i].nxt) {
		int v = e[i].v;
		if (v != fa[u] && son[u] != v) {
			dfs2(v, v);
		}
	}
}

inline void up(int id, int lc, int rc) {
	seg[id].L_mx = max(seg[lc].L_mx, seg[lc].sum + seg[rc].L_mx);
	seg[id].R_mx = max(seg[rc].R_mx, seg[rc].sum + seg[lc].R_mx);
	seg[id].mx = max(max(seg[lc].mx, seg[rc].mx), seg[lc].R_mx + seg[rc].L_mx);
	seg[id].sum = seg[lc].sum + seg[rc].sum;
}

inline void down(int id, int lc, int rc) {
	seg[id].color = -1;
	seg[lc].color = seg[rc].color = 1;
	seg[lc].v = seg[rc].v = seg[id].v;
	typec va = seg[lc].v * (seg[lc].R - seg[lc].L + 1);
	typec vb = seg[rc].v * (seg[rc].R - seg[rc].L + 1);
	seg[lc].sum = va;
	seg[rc].sum = vb;
	if (seg[id].v > 0) {
		seg[lc].mx = seg[lc].L_mx = seg[lc].R_mx = va;
		seg[rc].mx = seg[rc].L_mx = seg[rc].R_mx = vb;
	} else {
		seg[lc].mx = seg[lc].L_mx = seg[lc].R_mx = 0;
		seg[rc].mx = seg[rc].L_mx = seg[rc].R_mx = 0;
	}
}

void build(int id, int lt, int rt) {
	seg[id].L = lt; seg[id].R = rt;
	seg[id].mx = seg[id].L_mx = seg[id].R_mx = -1;
	seg[id].color = -1;
	if (lt == rt) {
		seg[id].sum = seg[id].v = ar[tb[lt]];
		if (seg[id].v > 0) {
			seg[id].mx = seg[id].L_mx = seg[id].R_mx = seg[id].v;
		}
		return ;
	}
	int mid = (lt + rt) >> 1;
	int lc = id << 1, rc = lc + 1;
	build(lc, lt, mid);
	build(rc, mid + 1, rt);
	up(id, lc, rc);
}

void update(int id, int lt, int rt, int w) {
	if (seg[id].L == lt && seg[id].R == rt) {
		seg[id].v = w;
		seg[id].sum = seg[id].v * (rt - lt + 1);
		if (w > 0) {
			seg[id].mx = seg[id].L_mx = seg[id].R_mx = seg[id].v * (rt - lt + 1);
		} else {
			seg[id].mx = seg[id].L_mx = seg[id].R_mx = 0;
		}
		seg[id].color = 1;
		return ;
	}
	int lc = id << 1, rc = lc + 1;
	if (1 == seg[id].color) {
		down(id, lc, rc);
	}
	int mid = (seg[id].L + seg[id].R) >> 1;
	if (rt <= mid) update(lc, lt, rt, w);
	else if (lt > mid) update(rc, lt, rt, w);
	else {
		update(lc, lt, mid, w);
		update(rc, mid + 1, rt, w);
	}
	up(id, lc, rc);
}

node query(int id, int lt, int rt) {
	bool flag = false;
	if (seg[id].L == lt && seg[id].R == rt) {
		node q;
		q.mx_l = seg[id].L_mx;
		q.mx_r = seg[id].R_mx;
		q.mx_sum = seg[id].mx;
		q.sum = seg[id].sum;
		return q;
	}
	int lc = id << 1, rc = lc + 1;
	if (1 == seg[id].color) {
		flag = true;
		down(id, lc, rc);
	}
	int mid = (seg[id].L + seg[id].R) >> 1;
	node q;
	if (rt <= mid) q = query(lc, lt, rt);
	else if (lt > mid) q = query(rc, lt, rt);
	else {
		node q1 = query(lc, lt, mid);
		node q2 = query(rc, mid + 1, rt);
		q.mx_sum = max(q1.mx_r + q2.mx_l, max(q1.mx_sum, q2.mx_sum));
		q.mx_l = max(q1.mx_l, q1.sum + q2.mx_l);
		q.mx_r = max(q2.mx_r, q2.sum + q1.mx_r);
		q.sum = q1.sum + q2.sum;
	}
	if (flag) up(id, lc, rc);
	return q;
}

void modify(int a, int b, int w) {
	int f1 = top[a], f2 = top[b];
	while (f1 != f2) {
		if (f1 < f2) swap(f1, f2), swap(a,b);
		update(1, ind[f1], ind[a], w);
		a = fa[f1]; f1 = top[a];
	}
	if (a < b) swap(a, b);
	update(1, ind[b], ind[a], w);
}

void calc(typec &res, typec &mx, int &f, int &v) {
	node q = query(1, ind[f], ind[v]);
	mx = max(mx, q.mx_sum);
	mx = max(mx, res + q.mx_r);
	res = max(res + q.sum, q.mx_l);
	res = max(0, res);
	v = fa[f]; f = top[v];
}

typec Find(int a, int b) {
	int f1 = top[a], f2 = top[b];
	typec r[2], value[2], mx;
	r[0] = r[1] = 0;
	value[0] = value[1] = 0;
	while (f1 != f2) {
		if (dep[f1] > dep[f2]) calc(r[0], value[0], f1, a);
		else calc(r[1], value[1], f2, b);
	}
	if (a > b) {
		calc(r[0], value[0], b, a);
	} else {
		calc(r[1], value[1], a, b);
	}
	mx = max(value[0], value[1]);
	mx = max(mx, r[0] + r[1]);
	return mx;
}

void input(int n) {
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &ar[i]);
	}
	int u, v;
	for (int i = 1; i < n; ++i) {
		scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	scanf("%d", &Q);
}

void solve(int n) {
	int root = 1;
	dfs1(root, root, 0);
	dfs2(root, root);
	build(1, 1, idy);
	int typ, u, v, w;
	while (Q--) {
		scanf("%d%d%d", &typ, &u, &v);
		if (typ == 1) {
			typec ans = Find(u, v);
			printf("%d\n", ans);
		} else {
			scanf("%d", &w);
			modify(u, v, w);
		}
	}
}

int main(void) {

    freopen("data.in", "r", stdin);
    freopen("data2.out", "w", stdout);

	while (~scanf("%d", &N)) {
		init();
		input(N);
		solve(N);
	}
	return 0;
}