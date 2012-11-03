/*
ID: muziriy3
PROG: runround
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
bool use[10];
int num[10];

bool check(int now)
{
    int tot = 10;
    while (now > 0)
    {
        tot--;
        num[tot] = now%10;
        if (num[tot] == 0)  return false;
        now /= 10;
    }
    memset(use,false,sizeof(use));
    int cur,next;
    int visit;
    visit = 0;
    cur = tot;
    while (true)
    {
        if (visit == 10-tot)
        if (cur == tot)    return true;
        else
            return false;
        if (use[num[cur]] == true)   return false;
        use[num[cur]] = true;
        visit++;
        cur = (cur-tot+num[cur])%(10-tot)+tot;
    }
}

int main()
{
    freopen("runround.in","r",stdin);
    freopen("runround.out","w",stdout);
    scanf("%d",&n);
    for (int i = n+1;;i++)
    if (check(i) == true)
    {
        printf("%d\n",i);
        break;
    }
}
