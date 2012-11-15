#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
char b[11][6];
int mp[30][30];
const int step[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int res;

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        for (int i = 0;i < n;i++)
            scanf("%s",b[i]);
        res = 0;
        printf("%d\n",res);
    }
}
