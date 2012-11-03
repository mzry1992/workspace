#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int tot[6];

int main()
{
    for (int i = 0;i < 20;i++)
    {
        int tim = 8;
        memset(tot,0,sizeof(tot));
        int l = rand()%5+1,w;
        for (int j = 0;j < tim;j++)
        {
            while (true)
            {
                w = rand()%5+1;
                if (l != w) break;
            }
            if (rand()%2 == 0)
                swap(w,l);
            //printf("%d %d\n",w,l);
            tot[w]++;
            tot[l]++;
            l = w;
        }
        printf("5\n");
        for (int i = 1;i <= 5;i++)
            printf("%d ",tot[i]);
        printf("\n");
    }
	return 0;
}
