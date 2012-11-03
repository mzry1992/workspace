#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int n,m;
map<string,int> mp;
map<string,int> nam;
string temp;
char th[1010][300],sx[100010][300],tsx[300];
int totsx;
struct graph
{
    int to,next;
}g[500000];
int totg;
int visit[100010];
string res[100010];

void addedge(int u,int v)
{
    totg++;
    g[totg].to = v;
    g[totg].next = g[u].next;
    g[u].next = totg;
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 1;i <= n;i++)
            g[i].next = -1;
        totg = n;
        totsx = 0;
        mp.clear();
        nam.clear();
        for (int i = 1;i <= n;i++)
        {
            scanf("%s",th[i]);
            th[i][strlen(th[i])-1] = 0;
            temp = th[i];
            nam[temp] = i;
            while (true)
            {
                char tc;
                scanf("%s%c",tsx,&tc);
                temp = tsx;
                int id;
                if (mp.find(temp) == mp.end())
                {
                    totsx++;
                    mp[temp] = totsx;
                    id = totsx;
                    strcpy(sx[totsx],tsx);
                }
                else
                    id = mp[temp];
                addedge(i,id);
                if(tc == '\n') break;
            }
        }
        scanf("%d",&m);
        for (int i = 1;i <= m;i++)
        {
            memset(visit,0,sizeof(visit));
            int totman = 0;
            while (true)
            {
                char tc;
                scanf("%s%c",tsx,&tc);
                temp = tsx;
                int id = nam[temp];
                for (int vv = g[id].next;vv != -1;vv = g[vv].next)
                    visit[g[vv].to]++;
                totman++;
                if(tc == '\n') break;
            }
            int totres = 0;
            for (int j = 1;j <= totsx;j++)
            if (visit[j] == totman)
            {
                totres++;
                res[totres] = sx[j];
            }
            sort(res+1,res+1+totres);
            if (totres == 0)
                printf("No solution.\n");
            else
            {
                for (int i = 1;i < totres;i++)
                    printf("%s ",res[i].c_str());
                printf("%s\n",res[totres].c_str());
            }
        }
    }
}
