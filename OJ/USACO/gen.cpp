#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("test.in","w",stdout);
    for (int i = 1;i <= 1000;i++)
    {
        int n,m;
        n = rand()%100+100;
        m = rand()%1000+1000;
        printf("%d %d\n",n,m);
        for (int j = 1;j <= m;j++)
        {
            int u,v,c;
            u = rand()%n+1;
            v = rand()%n+1;
            c = rand()%100+1;
            printf("%d %d %d\n",u,v,c);
        }
    }
}
