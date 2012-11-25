#include<cstdio>
#include<algorithm>
using namespace std;
struct planet
{
    int num,id;
    bool operator<(const planet &a)const
    {
        if (num!=a.num)
            return num<a.num;
        else
            return id<a.id;
    }
} a[100000];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i].num);
        a[i].id=i;
    }
    sort(a,a+n);
    int ans=0,time=1,cnt=0;
    for (int i=n-2;i>=0;i--)
    {
        while ((long long)a[i].num*time<a[n-1].num)
        {
            time*=2;
            cnt++;
        }
        ans+=cnt;
    }
    printf("%d\n",ans+a[n-1].num);
    if (ans+a[n-1].num<=1000)
    while (a[n-1].num)
    {
        for (int i=0;i<n;i++)
            while ((long long)a[i].num*2<=a[n-1].num)
            {
                a[i].num*=2;
                printf("science mission to the planet %d\n",a[i].id+1);
            }
        puts("flying mission");
        for (int i=0;i<n;i++)
            a[i].num--;
    }
    return 0;
}
