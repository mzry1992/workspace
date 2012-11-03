#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

int r,c;
int t,ft;
char map[100][100];
bool visit[100][100];
bool win;

int main()
{
    int i,j;    
    scanf("%d",&t);
    for (ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&r,&c);
        for (i = 1;i <= r;i++)
            scanf("%s",&map[i]);
        
        printf("Case #%d: daizhenyang ",&ft);
        if (win == true)
           printf("win\n");
        else
            printf("lose\n");
    }
    return 0;
}
