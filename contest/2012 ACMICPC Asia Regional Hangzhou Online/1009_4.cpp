#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

#define lowbit(x) (x&(-x))
#define LL long long
#define ULL unsigned long long
#define maxn 201
#define msize 100000
#define CC(m,what) memset(m,what,sizeof(m))
#define inf 0x7f7f7f7f
#define infll 1LL << 62
#define eps 1e-9
#define lson l , m , fa << 1
#define rson m + 1 , r , fa << 1 | 1
#define pi acos(-1.0)
#define keytree (ch[ch[root][1]][0])
#define lc fa << 1
#define rc fa << 1 | 1

template<class Z>inline bool checkmax(Z &a,Z b)
{
    if(a==-1||a<b)
    {
        a=b;
        return true;
    }
    return false;
}
template<class Z>inline bool checkmin(Z &a,Z b)
{
    if(a==-1||a>b)
    {
        a=b;
        return true;
    }
    return false;
}


/*row行col列的矩阵，矩阵为增广矩阵答案存在第col + 1列*/
double mat[maxn][maxn];
int row,col;
int st,ed,d,x,y;
int n,m;
int cnt;
inline int dcmp(double d)
{
    return d < -eps ? -1 : d > eps;
}
void gauss()
{
    int r , c , i , j;
    for(r = c = 0 ; r < row && c < col ;  r ++ , c ++)
    {
        for(i = r ; i < row ; i ++)if(dcmp(mat[i][c]) != 0)break;
        if(i == row)
        {
            r --;
            continue;
        }
        if(i != r)for(j = c ; j <= col ; j ++)swap(mat[i][j],mat[r][j]);
        for(i = r + 1 ; i < row ; i ++)
        {
            if(dcmp(mat[i][c]) != 0)
            {
                double temp = mat[i][c] / mat[r][c];
                for(j = c ; j <= col ; j ++)mat[i][j] -= mat[r][j] * temp;
            }
        }
    }
    for(i = row - 1 ; i >= 0 ; i --)
    {
        mat[i][col] /= mat[i][i];
        mat[i][i] = 1;
        for(j = i - 1 ; j >= 0 ; j --) mat[j][col] -= mat[j][i] * mat[i][col];
    }
}
int vis[maxn];
int g[maxn];
int p[maxn];
struct node
{
    int di,idx;
    node() {}
    node(int a,int b)
    {
        di = a , idx = b;
    }
};
int f(int x,int y)
{
    return (x % y + y) % y;
}
bool bfs(int x)
{
    CC(vis , -1);
    queue<node>que;
    cnt = 0;
    que.push(node(x , st));
    vis[st] = cnt++;
    bool flag = false;
    while(!que.empty())
    {
        node temp = que.front();
        que.pop();
        for(int i = 1 ; i <= m ; i ++)
        {
            if(p[i] == 0)continue;
            int dd,tt;
            tt = f(temp.idx + i * d , 2 * (n - 1));
            dd = g[tt];
            if(vis[tt] != -1)continue;
            vis[tt] = cnt ++;
            que.push(node(dd , tt));
            if(dd == y)flag = true;
        }
    }
    return flag;
}
void gao()
{
    CC(mat,0);
    int i,j;
    for(i = 0 ; i < 2 * (n - 1) ; i ++)
    {
        if(vis[i] == -1)continue;
        mat[vis[i]][vis[i]] = 100;
        if(g[i] == y)
        {
            mat[vis[i]][cnt] = 0;
            continue;
        }
        for(j = 1 ; j <= m ; j ++)
        {
            int tt = f(i + j * d , 2 * (n - 1));
            mat[vis[i]][vis[tt]] -= p[j];
            mat[vis[i]][cnt] += p[j] * j;
        }
    }
    row = cnt;
    col = cnt;
}
int main()
{
	freopen("data.in","r",stdin);
	freopen("data_4.out","w",stdout);
    int cas;
    int i,j,k,l;
    scanf("%d",&cas);
    while(cas--)
    {
        cnt = 0;
        scanf("%d%d%d%d%d",&n,&m,&y,&x,&d);
        for(i = 1 ; i <= m ; i ++)
            scanf("%d",&p[i]);
        if(x == y)
        {
            printf("0.00\n");
            continue;
        }
        if(d == 0)
        {
            st = n + x - 1;
        }
        else if(d == 1)
        {
            st = n - x - 1;
        }
        else
        {
            if(x == n - 1)st = 0;
            else st = n - 1;
        }
        d = 1;
        int cc = 0;
        for(i = n - 1 ; i >= 0 ; i --)g[cc++] = i;
        for(i = 1 ; i < n - 1 ; i ++)g[cc++] = i;


        if(!bfs(x))
        {
            puts("Impossible !");
            continue;
        }
        gao();
        gauss();
        printf("%.2f\n",mat[0][cnt]);
    }
}
