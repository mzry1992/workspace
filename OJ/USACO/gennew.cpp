#include <cstdio>
using namespace std;

int main()
{
    freopen("57.txt","r",stdin);
    freopen("57out.txt","w",stdout);
    for (int i = 0;i < 10;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            char s[10];
            scanf("%s",s);
            printf("webcard[%d, %d] = \"%s\"; ",i,j,s);
        }
        printf("\n");
    }
}
