#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int m,n,t,a[100][2],b[100][2];
char word[100][30];
int c[100],d[100][100];

queue<int> words;
vector<int> taken[100];
int now,tim,totuse;

void Gao()
{
    for (int i = 0; i < n; i++)
        taken[i].clear();
    for (int i = 0; i < m; i++)
        words.push(i);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            d[i][j] = 0;
    while (true)
    {
        for (int j = 0; j < 2; j++)
            for (int i = 0; i < n; i++)
            {
                totuse = 0;
                while (!words.empty())
                {
                    if (totuse == t)    break;
                    now = words.front();
                    words.pop();
                    tim = max(1,c[now]-(a[i][j]+b[i][!j])-d[i][now]);
                    if (totuse+tim <= t)
                    {
                        taken[i].push_back(now);
                        totuse += tim;
                    }
                    else
                    {
                        words.push(now);
                        d[i][now] += t-(totuse);
                        totuse = t;
                    }
                    if (words.empty())  return;
                }
            }
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while (scanf("%d%d",&n,&t) != EOF)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 2; j++)
                scanf("%d%d",&a[i][j],&b[i][j]);
        scanf("%d",&m);
        for (int i = 0; i < m; i++)
            scanf("%s%d",word[i],&c[i]);
        Gao();
        for (int i = 0; i < n; i++)
        {
            printf("%d ",taken[i].size());
            for (int j = 0; j < taken[i].size(); j++)
                printf("%s ",word[taken[i][j]]);
            printf("\n");
        }
    }
    return 0;
}
