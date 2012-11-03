/*
ID: muziriy3
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

int a,b,c;
bool use[30];
bool visit[30][30][30];

void DFS(int la,int lb,int lc)
{
    if (visit[la][lb][lc] == true)  return;
    visit[la][lb][lc] = true;
    if (la == 0)
        use[lc] = true;
    int t[3];
    int k[3];
    t[0] = la;  k[0] = a;
    t[1] = lb;  k[1] = b;
    t[2] = lc;  k[2] = c;
    for (int i = 0;i < 3;i++)
    for (int j = 0;j < 3;j++)
    if (i != j)
    {
        int n[3];
        for (int q = 0;q < 3;q++)
            n[q] = t[q];
        if (t[i]+t[j] > k[j])
        {
            n[j] = k[j];
            n[i] = t[i]-(k[j]-t[j]);
        }
        else
        {
            n[j] = t[i]+t[j];
            n[i] = 0;
        }
        DFS(n[0],n[1],n[2]);
    }
}

int main()
{
    freopen("milk3.in","r",stdin);
    freopen("milk3.out","w",stdout);
    scanf("%d%d%d",&a,&b,&c);
    memset(use,false,sizeof(use));
    memset(visit,false,sizeof(visit));
    DFS(0,0,c);
    bool first = true;
    for (int i = 0;i <= c;i++)
    if (use[i] == true)
    {
        if (first == false)
            printf(" ");
        first = false;
        printf("%d",i);
    }
    printf("\n");
}
