#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Point
{
    int x,y;
};

int n;
Point s[5000],e[5000];

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)
            scanf("%d%d%d%d",&s[i].x,&s[i].y,&e[i].x,&e[i].y);
        int res = 0;
        for (int i = 0;i < n;i++)
            for (int j = i+1;j < n;j++)
            {
                if ((e[i].x-s[i].x)*(e[j].x-s[j].x)+(e[i].y-s[i].y)*(e[j].y-s[j].y) != 0)   continue;
                if (e[i].x == e[j].x && e[i].y == e[j].y)
                {
                    res++;
                    continue;
                }
                if (e[i].x == s[j].x && e[i].y == s[j].y)
                {
                    res++;
                    continue;
                }
                if (s[i].x == e[j].x && s[i].y == e[j].y)
                {
                    res++;
                    continue;
                }
                if (s[i].x == s[j].x && s[i].y == s[j].y)
                {
                    res++;
                    continue;
                }
            }
        printf("%d\n",res);
    }
    return 0;
}
