/*
ID: muziriy3
PROG: holstein
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <deque>
#include <string>
using namespace std;

int n;
int a[30];
int t;
int v[30][30];
deque<string> Q;

bool check(string now)
{
    int b[30];
    memset(b,0,sizeof(b));
    for (int i = 1;i < now.size();i++)
    for (int j = 1;j <= n;j++)
        b[j] += v[now[i]-'0'][j];
    for (int i = 1;i <= n;i++)
    if (b[i] < a[i])    return false;
    return true;
}

void BFS()
{
    Q.clear();
    Q.push_back("0");
    while (!Q.empty())
    {
        string now;
        now = Q.front();
        Q.pop_front();
        if (check(now))
        {
            printf("%d",now.size()-1);
            for (int i = 1;i < now.size();i++)
                printf(" %d",now[i]-'0');
            printf("\n");
            return;
        }
        for (int i = now[now.size()-1]-'0'+1;i <= t;i++)
            Q.push_back(now+(char)(i+'0'));
    }
}

int main()
{
    freopen("holstein.in","r",stdin);
    freopen("holstein.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1;i <= n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&t);
    for (int i = 1;i <= t;i++)
    for (int j = 1;j <= n;j++)
        scanf("%d",&v[i][j]);
    BFS();
}
