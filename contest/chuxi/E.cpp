#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct rect
{
    int x1,x2,y1,y2,r,g,b;
};

rect r[1000];
int n,m,x,y,R,G,B;

int main()
{
    int ft = 0;
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        for (int i = 0;i < n;i++)
            scanf("%d%d%d%d%d%d%d",&r[i].x1,&r[i].y1,&r[i].x2,&r[i].y2,
                  &r[i].r,&r[i].g,&r[i].b);
        printf("Case %d:\n",++ft);
        for (int i = 0;i < m;i++)
        {
            scanf("%d%d",&x,&y);
            R = G = B = 255;
            for (int j = n-1;j >= 0;j--)
                if (r[j].x1 <= x && x <= r[j].x2 &&
                    r[j].y1 <= y && y <= r[j].y2)
                        {
                            R = r[j].r;
                            G = r[j].g;
                            B = r[j].b;
                            break;
                        }
            printf("%d %d %d\n",R,G,B);
        }
        printf("\n");
    }
    return 0;
}
