#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct interval
{
    int l,r,typ,id;
};

bool cmp(const interval& a,const interval& b)
{
    if (a.r == b.r)
        return a.l > b.l;
    return a.r < b.r;
}

bool cmp1(const interval& a,const interval& b)
{
    if (a.r == b.r)
        return a.typ < b.typ;
    return a.r < b.r;
}

interval a[200000];
int n,m,pre[200000],ans[100000],pos[200000];
bool del[200000];

vector<vector<int> > f;
vector<int> tmp;

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d",&a[i].l,&a[i].r);
            a[i].typ = -1;
            a[i].id = i;
        }
        sort(a,a+n,cmp);
        memset(del,false,sizeof(del));
        int maxl = a[0].l;
        for (int i = 1; i < n; i++)
        {
            if (a[i].l <= maxl)
                del[i] = true;
            maxl = max(a[i].l,maxl);
        }

        int tn = n;
        n = 1;
        for (int i = 1; i < tn; i++)
            if (!del[i])
                a[n++] = a[i];

        pre[a[0].id] = -1;
        for (int i = 1;i < n;i++)
        {
            if (a[0].r > a[i].l)
                pre[a[i].id] = -1;
            else
            {
                int l = 0,r = i-1,mid;
                while (l < r)
                {
                    mid = l+r+1>>1;
                    if (a[mid].r <= a[i].l)
                        l = mid;
                    else
                        r = mid-1;
                }
                pre[a[i].id] = a[l].id;
            }
        }

        for (int i = 0; i < m; i++)
        {
            scanf("%d%d",&a[n+i].l,&a[n+i].r);
            a[n+i].typ = i;
        }
        n += m;
        sort(a,a+n,cmp1);

        f.clear();
        for (int i = 0;i < n;i++)
            if (a[i].typ == 0)
            {
                if (pre[a[i].id] == -1)
                {
                    tmp.clear();
                    tmp.push_back(a[i].id);
                    f.push_back(tmp);
                    pos[a[i].id] = f.size()-1;
                }
                else
                {
                    if (f[pos[pre[a[i].id]]].back() == pre[a[i].id])
                    {
                        pos[a[i].id] = pos[pre[a[i].id]];
                        f[pos[a[i].id]].push_back(a[i].id);
                    }
                    else
                    {

                    }
                }
            }
    }
    return 0;
}
