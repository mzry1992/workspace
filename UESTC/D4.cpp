#include <stdio.h>
#include <string.h>
#define MaxN 55
#define MaxS 1700010

int st, fin, N, px, m, n;
int g[MaxN][4], len[MaxN], q[2][MaxS], d[2][MaxS], pt[5];
bool adj[MaxN][MaxN];
char s[MaxN][MaxN];

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int co;

int BFS()
{
    for (int i = 0; i < 2; ++i) memset(d[i], -1, sizeof(int)*pt[m]);
    int ql[2] = {0, 0}, qr[2] = {0, 0}, p[5];
    q[0][qr[0]++] = st;
    q[1][qr[1]++] = fin;
    d[0][st] = 0;
    d[1][fin] = 0;
    co = 0;
    while (ql[0] < qr[0] && ql[1] < qr[1])
    {
        if (qr[0] < qr[1])
        {
            int step = d[0][q[0][ql[0]]];
//        printf("%d %d\n", qr[0], qr[1]);
//        printf("%d\n", step);
            while (ql[0] < qr[0] && d[0][q[0][ql[0]]] == step)
            {
        co++;
                int u = q[0][ql[0]++], x = u;
                for (int i = 0; i < m; ++i)
                {
                    p[i] = x%N;
                    x /= N;
                }
//            puts("->");
//            for (int i = 0; i < m; ++i) printf("%d %d\n", p[i]/n, p[i]%n);
//            printf("%d\n\n", d[0][u]);
                int first = 0;
                for (int i = 0; i < m; ++i) if (p[i] != px)
                    {
                        first = i;
                        break;
                    }
                for (int i = first; i < m; ++i)
                {
                    for (int k = 0; k < len[p[i]]; ++k)
                    {
                        int np = g[p[i]][k];
                        bool fail = 0;
                        for (int j = first; j < m; ++j) if (i != j && adj[p[j]][np])
                            {
                                fail = 1;
                                break;
                            }
                        if (!fail)
                        {
                            int v = u+pt[i]*(np-p[i]);
                            if (d[0][v] == -1)
                            {
                                d[0][v] = d[0][u] + 1;
                                q[0][qr[0]++] = v;
                                if (d[1][v] != -1) return d[0][v] + d[1][v];
                            }
                        }
                    }
                }
            }
        }
        else
        {
            int step = d[1][q[1][ql[1]]];
            while (ql[1] < qr[1] && d[1][q[1][ql[1]]] == step)
            {
        co++;
                int u = q[1][ql[1]++], x = u;
                for (int i = 0; i < m; ++i)
                {
                    p[i] = x%N;
                    x /= N;
                }
//            if (ql[1] < 20) {
//            puts("<-");
//            for (int i = 0; i < m; ++i) printf("%d %d\n", p[i]/n, p[i]%n);
//            printf("%d\n\n", d[1][u]);
//            }
                int last = m-1;
                for (int i = 0; i < m; ++i) if (p[i] != px)
                    {
                        last = i - 1;
                        break;
                    }
                for (int i = m-1; i > last; --i)
                {
                    for (int k = 0; k < len[p[i]]; ++k)
                    {
                        int np = g[p[i]][k];
                        bool fail = 0;
                        for (int j = m-1; j > last; --j) if (i != j && adj[p[j]][np])
                            {
                                fail = 1;
                                break;
                            }
                        if (!fail)
                        {
                            int v = u+pt[i]*(np-p[i]);
                            if (d[1][v] == -1)
                            {
                                d[1][v] = d[1][u] + 1;
                                q[1][qr[1]++] = v;
                                if (d[0][v] != -1) return d[0][v] + d[1][v];
                            }
                        }
                    }
                }
                if (last != -1)
                {
                    bool fail = 0;
                    for (int j = last + 1; j < m; ++j) if (adj[px][p[j]]) fail = 1;
                    if (!fail)
                    {
                        for (int k = 0; k < len[px]; ++k)
                        {
                            int np = g[px][k];
                            fail = 0;
                            for (int j = last + 1; j < m; ++j) if (adj[p[j]][np])
                                {
                                    fail = 1;
                                    break;
                                }
                            if (!fail)
                            {
                                int v = u+pt[last]*(np-p[last]);
                                if (d[1][v] == -1)
                                {
                                    d[1][v] = d[1][u] + 1;
                                    q[1][qr[1]++] = v;
                                    if (d[0][v] != -1) return d[0][v] + d[1][v];
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    //freopen("test.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        N = n*n;
        st = fin = 0;
        for (int i = 0; i < N; ++i) len[i] = 0;
        for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) adj[i][j] = 0;
        pt[0] = 1;
        for (int i = 1; i <= m; ++i) pt[i] = pt[i-1] * N;
        for (int i = 0; i < n; ++i) scanf("%s", s[i]);
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)
            {
                if (s[i][j] == 'x')
                {
                    px = i*n + j;
                }
                else if (s[i][j] != 'o')
                {
                    int id = s[i][j] - '1';
                    st += pt[id] * (i*n+j);
                }
                for (int d = 0; d < 4; ++d)
                {
                    int x = i + dx[d], y = j + dy[d];
                    if (x >= 0 && x < n && y >= 0 && y < n)
                    {
                        g[i*n+j][len[i*n+j]++] = x*n+y;
                        adj[i*n+j][x*n+y] = 1;
                    }
                }
            }
        for (int i = 0; i < m; ++i) fin = fin * N + px;
        co = 0;
        printf("%d\n", BFS());
        printf("%d\n",co);
    }
    return 0;
}
