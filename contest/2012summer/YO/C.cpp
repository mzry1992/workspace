#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

const int rp[6] = {0,1,4,5,3,2};
int n;
char col[4][6][30];
const int per[24][6] = {{0,1,2,3,4,5},{1,2,3,0,4,5},{2,3,0,1,4,5},{3,0,1,2,4,5},
                      {0,3,2,1,5,4},{3,2,1,0,5,4},{2,1,0,3,5,4},{1,0,3,2,5,4},
                      {0,5,2,4,1,3},{5,2,4,0,1,3},{2,4,0,5,1,3},{4,0,5,2,1,3},
                      {1,4,3,5,0,2},{4,3,5,1,0,2},{3,5,1,4,0,2},{5,1,4,3,0,2},
                      {0,4,2,5,3,1},{4,2,5,0,3,1},{2,5,0,4,3,1},{5,0,4,2,3,1},
                      {1,5,3,4,2,0},{5,3,4,1,2,0},{3,4,1,5,2,0},{4,1,5,3,2,0}};

int a[4],res;
map<string,int> face;

void DFS(int now)
{
    if (now == n)
    {
        int tres = 0;
        for (int i = 0;i < 6;i++)
        {
            face.clear();
            for (int j = 0;j < n;j++)
                face[col[j][per[a[j]][i]]]++;
            int maxcol = 0;
            for (map<string,int>::iterator it = face.begin();it != face.end();it++)
                maxcol = max(maxcol,it->second);
            tres += n-maxcol;
        }
        res = min(res,tres);
    }
    else
        for (a[now] = 0;a[now] < 24;a[now]++)
            DFS(now+1);
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        if (n == 0) break;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < 6;j++)
                scanf("%s",col[i][rp[j]]);
        res = 24;
        a[0] = 0;
        DFS(1);
        printf("%d\n",res);
    }
	return 0;
}
