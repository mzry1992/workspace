#include<cstdio>
#include<algorithm>
using namespace std;
struct person
{
    int a,b;
    person() {}
    person(int _a,int _b)
    {
        a=_a;
        b=_b;
    }
    bool operator<(const person &t)const
    {
        if (a+b!=t.a+t.b)
            return a+b<t.a+t.b;
        else
            return a<t.a;
    }
} per[2000];
int main()
{
    freopen("1005.in","r",stdin);
    freopen("1005.out2","w",stdout);
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int tot=0;
        for (int i=0; i<n; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            per[i]=person(a,b);
            tot+=a;
        }
        sort(per,per+n);
        int l;
        scanf("%d",&l);
        int ans=0;
        do
        {
            int sum=tot;
            int res=0;
            for (int i=0; i<n; i++)
                if (per[i].a+sum>=l)
                {
                    sum-=per[i].b;
                    res++;
                }
            ans=max(res,ans);
        }
        while(next_permutation(per,per+n));
        printf("%d\n",ans);
    }
    return 0;
}
