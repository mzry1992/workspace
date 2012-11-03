#include<cstdio>
#include<cstring>
#include<cstdlib>
bool flag[500][500];
int main()
{
    int t=1;
    printf("%d\n",t);
    while (t--)
    {
        int n=10,p=10;
        printf("%d %d\n",p,n);
        for (int i=0;i<n;i++)
            printf("%d ",rand()%p);
        puts("");
        for (int i=0;i<n;i++)
            printf("%d ",rand()%p);
        puts("");
        int m=100;
        printf("%d\n",m);
        for (int i=0;i<m;i++)
            if (rand()&1)
                printf("Q %d\n",rand()%n);
            else
                if (rand()&1)
                    printf("C A %d %d\n",rand()%n,rand()%p);
                else
                    printf("C B %d %d\n",rand()%n,rand()%p);
    }
    return 0;
}
