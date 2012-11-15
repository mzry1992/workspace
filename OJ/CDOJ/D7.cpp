#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct HeapNode
{
    friend bool operator < (HeapNode a,HeapNode b)
    {
        if (a.f == b.f)
            return a.step < b.step;
        return a.f < b.f;
    }
    int sta,step,curmin,f;
    HeapNode() {}
    HeapNode(int _sta,int _step,int _curmin,int _f)
    {
        sta = _sta;
        step = _step;
        curmin = _curmin;
        f = _f;
    }
};

struct Heap
{
    HeapNode heap[2000010];
    int hs;
    void Clear()
    {
        hs = 0;
    }
    bool Empty()
    {
        return hs == 0;
    }
    void sink(int p)
    {
        HeapNode a = heap[p];
        for (int q = p<<1; q <= hs; p = q, q <<= 1)
        {
            if (q < hs && heap[q+1] < heap[q]) ++q;
            if (!(heap[q] < a)) break;
            heap[p] = heap[q];
        }
        heap[p] = a;
    }
    HeapNode PopTop()
    {
        HeapNode r = heap[1];
        heap[1] = heap[hs--];
        sink(1);
        return r;
    }
    void swim(int p)
    {
        HeapNode a = heap[p];
        for (int q = p>>1; q && a < heap[q]; p = q, q >>= 1)
            heap[p] = heap[q];
        heap[p] = a;
    }
    void Push(HeapNode a)
    {
        heap[++hs] = a;
        swim(hs);
    }
};

int n,m,epos,pos[4],p[4],op,ed,dist[6*6];
char mp[10][10];
Heap Q;

int f(int sta)
{
    int res = 0,now;
    for (int i = m-1; i >= 0; i--)
    {
        now = sta%(n*n);
        sta /= n*n;
        res += dist[now];
    }
    return res;
}

inline bool checkin(int x,int y)
{
    if (x < 0 || x >= n || y < 0 || y >= n) return false;
    return true;
}

inline bool check(int curmin,int p[4])
{
    for (int i = curmin; i < m; i++)
        for (int j = i+1; j < m; j++)
            if (abs(p[j]%n-p[i]%n)+abs(p[j]/n-p[i]/n) == 1)
                return false;
    return true;
}

const int step[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
bool visit[6*6*6*6*6*6*6*6];
HeapNode now,updata;

int Gao()
{
    Q.Clear();
    Q.Push(HeapNode(op,0,0,0+f(op)));
    memset(visit,false,sizeof(visit));
    visit[op] = true;
    while (!Q.Empty())
    {
        now = Q.PopTop();
        if (now.sta == ed)  return now.step;
        for (int i = m-1; i >= 0; i--)
        {
            pos[i] = now.sta%(n*n);
            now.sta /= n*n;
        }
        for (int i = now.curmin; i < m; i++)
            for (int k = 0; k < 4; k++)
                if (checkin(pos[i]/n+step[k][0],pos[i]%n+step[k][1]) == true)
                {
                    for (int j = 0; j < m; j++)
                        p[j] = pos[j];
                    p[i] = (p[i]/n+step[k][0])*n+(p[i]%n+step[k][1]);
                    if (check(now.curmin,p) == true)
                    {
                        updata.step = now.step+1;
                        updata.curmin = now.curmin;
                        updata.sta = 0;
                        for (int j = 0; j < m; j++)
                            updata.sta = updata.sta*n*n+p[j];
                        if (p[updata.curmin] == epos)
                            updata.curmin++;
                        if (visit[updata.sta] == false)
                        {
                            visit[updata.sta] = true;
                            updata.f = updata.step+f(updata.sta);
                            Q.Push(updata);
                        }
                    }
                }
    }
    return -1;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 0; i < n; i++)
            scanf("%s",mp[i]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (mp[i][j] == 'x')
                    epos = i*n+j;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (mp[i][j] >= '1' && mp[i][j] <= '4')
                    pos[mp[i][j]-'1'] = i*n+j;
        op = ed = 0;
        for (int i = 0; i < m; i++)
        {
            op = op*n*n+pos[i];
            ed = ed*n*n+epos;
        }
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                dist[i*n+j] = abs(i-epos/n)+abs(j-epos%n);
        printf("%d\n",Gao());
    }
    return 0;
}
