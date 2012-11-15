#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int a[8]={0,10,1,200,20,2,6};
int b[8]={0,8,2,17,11,5,6};
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int nn=n;
        if (n==3) printf("7");
        else if (n==4) printf("4");
        else if (n==5) printf("2");
        else if (n==6) printf("6");
        else if (n==7) printf("8");
        else if (n==10) printf("22");
        else
        {
            int p=n%7;
            n-=b[p];
            if (p!=0) printf("%d",a[p]);
            while (n>0)
            {
                printf("8");n-=7;
            }
        }
        printf(" ");
        if (nn%2==1)
        {
            printf("7");
            nn-=3;
        }
        for (int i=1;i<=nn/2;i++) printf("1");
        puts("");
    }
}
