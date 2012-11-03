#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

bool mp[20][20],used[20],findres;
int n,m,s,t[4],tott,maxdep,dist[20][20];

void calcdis()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            dist[i][j] = mp[i][j];
        dist[i][i] = 0;
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            if (i != k )
                for (int j = 0; j < n; j++)
                    if (i != j && j != k)
                        if (dist[i][j] == 0 || dist[i][j] > dist[i][k]+dist[k][j])
                            dist[i][j] = dist[i][k]+dist[k][j];
}

void DFS(int deep,int now)
{
    if (findres == true) return;
    if (used[now] == true)  return;

    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if (mp[i][j] == true)
            {
                mp[i][j] = mp[j][i] = false;

                calcdis();
                if (deep == maxdep)
                {
                    bool check = true;
                    for (int k = 0; k < tott; k++)
                        if (dist[now][t[k]] != 0)
                        {
                            check = false;
                            break;
                        }
                    if (check == true)  findres = true;
                    mp[i][j] = mp[j][i] = true;
                    return;
                }
                int nowtotdist,mintotdist = 0,nxt = 0;
                for (int k = 0; k < n; k++)
                    if (mp[now][k] == true)
                    {
                        nowtotdist = 0;
                        for (int q = 0; q < tott; q++)
                            nowtotdist += dist[k][t[q]];
                        //cout << "id = " << k << " totdist = " << nowtotdist << endl;
                        if (mintotdist == 0 || mintotdist > nowtotdist)
                        {
                            mintotdist = nowtotdist;
                            nxt = k;
                        }
                    }
                //cout << deep << ' ' << now << " cut : (" << i << "->" << j << ") nxt = " << nxt << endl;
                /*for (int x= 0; x < n; x++)
                {
                    for (int y = 0; y < n; y++)
                        printf("(%d,%d) ",mp[x][y],dist[x][y]);
                    printf("\n");
                }*/
                DFS(deep+1,nxt);

                mp[i][j] = mp[j][i] = true;
            }
}

int main()
{
    n = 10;
    m = 30;
    tott = 1;
    for (int i = 0; i < m; i++)
    {
        while (true)
        {
            int u = rand()%n;
            int v = rand()%n;
            if (u != v && mp[u][v] == false)
            {
                mp[u][v] = mp[v][u] = true;
                break;
            }
        }
    }
    s = rand()%n;
    for (int i = 0; i < tott; i++)
    {
        while (true)
        {
            t[i] = rand()%n;
            if (s != t[i] && used[t[i]] == false)
            {
                used[t[i]] = true;
                break;
            }
        }
    }
    cout << s << ' ' << t[0] << endl;
    for (maxdep = 1; maxdep <= m; maxdep++)
    {
        cout << maxdep << endl;
        findres = false;
        /*for (int x= 0; x < n; x++)
        {
            for (int y = 0; y < n; y++)
                printf("%d ",mp[x][y]);
            printf("\n");
        }*/
        DFS(0,s);
        if (findres == true)    break;
    }
    printf("%d\n",maxdep);
    return 0;
}
