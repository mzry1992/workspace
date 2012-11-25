#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

set<pair<int,int> > ss,nxt;
set<pair<int,int> >::iterator ita,itb;
int dp[600][600];

int main()
{
    memset(dp,63,sizeof(dp));
    dp[1][1] = 1;
    ss.insert(make_pair(1,1));
    for (ita = ss.begin();ita != ss.end();ita++)
        for (itb = ss.begin();;itb++)
        {

            if (itb == ita) break;
        }
    int a,b;
    while (scanf("%d%d",&a,&b) != EOF)
        printf("%d\n",dp[a][b]);
    return 0;
}

