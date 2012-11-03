#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int a[4],b[4];
        for (int i=0;i<3;i++) scanf("%d",&a[i]);
        for (int i=0;i<3;i++) scanf("%d",&b[i]);
        bool flag=true;
        for (int i=0;i<3;i++)
        {
            if (a[i]>b[i]) puts("First");
            else if (a[i]==b[i]) continue;
            else puts("Second");
            if (a[i]!=b[i])
            {
                flag=false;break;
            }
        }
        if (flag) puts("Same");

    }
}
