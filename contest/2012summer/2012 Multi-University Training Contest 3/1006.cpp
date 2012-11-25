#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct event
{
    int pos,typ,id;
    event(){}
    event(int _pos,int _typ,int _id)
    {
        pos = _pos;
        typ = _typ;
        id = _id;
    }
    bool operator < (const event& b)const
    {
        if (pos == b.pos)
            return typ < b.typ;
        return pos < b.pos;
    }
}e[2000000];
int tote,ans[100000];
int n,m;

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1;cas <= totcas;cas++)
    {
        scanf("%d%d",&n,&m);
        tote = 0;
        for (int i = 0;i < n;i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            e[tote++] = event(l,-1,0);
            e[tote++] = event(r,1,0);
        }
        for (int i = 0;i < m;i++)
        {
            int l;
            scanf("%d",&l);
            e[tote++] = event(l,0,i);
        }
        sort(e,e+tote);
        int tot = 0;
        for (int i = 0;i < tote;i++)
            if (e[i].typ == -1)
                tot++;
            else if (e[i].typ == 0)
                ans[e[i].id] = tot;
            else
                tot--;
        printf("Case #%d:\n",cas);
        for (int i = 0;i < m;i++)
            printf("%d\n",ans[i]);
    }
	return 0;
}
