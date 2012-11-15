#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
int las[210][210];
bool app[210][210];
bool visit[210];
int res[210][210];
int totres;

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        memset(app,false,sizeof(app));
        for (int i = 1;i <= 200;i++)
            visit[i] = true;
        for (int i = 1;i <= n*(n-1)/2;i++)
        {
            scanf("%d",&las[i][0]);
            for (int j = 1;j <= las[i][0];j++)
            {
                scanf("%d",&las[i][j]);
                app[las[i][j]][i] = true;
                visit[las[i][j]] = false;
            }
        }
        if (n == 2)
        {
            res[1][0] = res[2][0] = 0;
            for (int i = 1;i <= 200;i++)
            if (visit[i] == false)
            {
                if (res[1][0] == 0)
                {
                    res[1][0] = 1;
                    res[1][1] = i;
                }
                else
                {
                    res[2][0]++;
                    res[2][res[2][0]] = i;
                }
            }
        }
        else
        {
            totres = 0;
            for (int i = 1;i <= 200;i++)
            if (visit[i] == false)
            {
                totres++;
                res[totres][0] = 1;
                res[totres][1] = i;
                visit[i] = true;
                for (int j = i+1;j <= 200;j++)
                if (visit[j] == false)
                {
                    bool sam = true;
                    for (int k = 1;k <= n*(n-1)/2;k++)
                    if (app[i][k] != app[j][k])
                    {
                        sam = false;
                        break;
                    }
                    if (sam == true)
                    {
                        visit[j] = true;
                        res[totres][0]++;
                        res[totres][res[totres][0]] = j;
                    }
                }
            }
        }
        for (int i = 1;i <= n;i++)
        {
            for (int j = 0;j < res[i][0];j++)
                printf("%d ",res[i][j]);
            printf("%d\n",res[i][res[i][0]]);
        }
    }
}
