/*
ID: muziriy3
PROG: checker
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define get(num,pos) ((num>>(pos-1))&1)
#define set(num,pos) (num^(1<<(pos-1)))
using namespace std;

int n;
int pos[20];
int tot;

void DFS(int now,int use1,int use2,int use3,int low,int up)
{
    if (now == n+1)
    {
        tot++;
        if (tot > 3)    return;
        printf("%d",pos[1]);
        for (int i = 2;i <= n;i++)
            printf(" %d",pos[i]);
        printf("\n");
        return;
    }
    for (pos[now] = low;pos[now] <= up;pos[now]++)
    if (get(use1,pos[now]) == false)
    if (get(use2,now-(pos[now]-1)+5) == false)
    if (get(use3,now+(pos[now]-1)) == false)
        DFS(now+1,set(use1,pos[now]),set(use2,now-(pos[now]-1)+5),set(use3,now+(pos[now]-1)),1,n);
}

int main()
{
    freopen("checker.in","r",stdin);
    freopen("checker.out","w",stdout);
    scanf("%d",&n);
    tot = 0;
    DFS(1,0,0,0,1,n/2);
    if (tot >= 3)
    {
        tot *= 2;
        if (n%2 == 1)
            DFS(1,0,0,0,n/2+1,n/2+1);
    }
    else
        DFS(1,0,0,0,n/2+1,n);
    printf("%d\n",tot);
}
