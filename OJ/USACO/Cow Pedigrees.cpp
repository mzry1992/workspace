/*
ID: muziriy3
PROG: nocows
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <deque>
#define MOD 9901
using namespace std;

int n,k;
int dp[400][400];

int main()
{
    //freopen("nocows.in","r",stdin);
    //freopen("nocows.out","w",stdout);
    scanf("%d%d",&n,&k);
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;

}
