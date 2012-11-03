#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n,q,id1,id2;
char s1[20],s2[20];
map<string,int> nameid;
char namelist[2000][20];
int totname;

struct Edge
{
    int to,next;
}edge[2000];
int head[2000],L;
bool g[2000][2000];

int getid(char s[])
{
    if (nameid.find(s) != nameid.end())
        return nameid[s];
    int len = strlen(s);
    for (int i = 0;i <= len;i++)
        namelist[totname][i] = s[i];
    nameid[namelist[totname]] = totname;
    head[totname] = -1;
    totname++;
    return totname-1;
}

void addedge(int u,int v)
{
    g[u][v] = g[v][u] = true;

    edge[L].to = v;
    edge[L].next = head[u];
    head[u] = L++;

    edge[L].to = u;
    edge[L].next = head[v];
    head[v] = L++;
}

map<int,int> res;
map<int,int>::iterator it;
vector<string> ss;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&q);
        totname = 0;
        nameid.clear();
        L = 0;
        memset(g,false,sizeof(g));
        for (int i = 0;i < n;i++)
        {
            scanf("%s%s",s1,s2);
            id1 = getid(s1);
            id2 = getid(s2);
            addedge(id1,id2);
        }
        /*for (int i = 0;i < totname;i++)
        {
            cout << "id = " << i << ' ' << namelist[i] << endl;
            for (int j = head[i];j != -1;j = edge[j].next)
                cout << '(' << edge[j].to << " " << namelist[edge[j].to] << " )" << endl;
        }*/
        printf("Case %d:\n",ft);
        for (int i = 0;i < q;i++)
        {
            scanf("%s",s1);
            id1 = getid(s1);
            res.clear();
            ss.clear();
            for (int j = head[id1];j != -1;j = edge[j].next)
                for (int k = head[edge[j].to];k != -1;k = edge[k].next)
                {
                    if (g[id1][edge[k].to] == true) continue;
                    if (id1 == edge[k].to)  continue;
                    res[edge[k].to]++;
                }
            id2 = -1;
            for (it = res.begin();it != res.end();it++)
                id2 = max(id2,it->second);
            if (id2 == -1)
                puts("-");
            else
            {
                for (it = res.begin();it != res.end();it++)
                    if (it->second == id2)
                        ss.push_back(namelist[it->first]);
                sort(ss.begin(),ss.end());
                printf("%s",ss[0].c_str());
                for (int i = 1;i < ss.size();i++)
                    printf(" %s",ss[i].c_str());
                printf("\n");
            }
        }
    }
    return 0;
}
