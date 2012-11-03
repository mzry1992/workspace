#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
char mp[510][510],s[25];

int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 0;i < n;i++)
        scanf("%s",mp[i]);
    while (true)
    {
        scanf("%s",s);
        if (strcmp(s,"-1") == 0)    break;
    }
    return 0;
}
