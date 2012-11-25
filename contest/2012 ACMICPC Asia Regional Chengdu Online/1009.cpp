#include <cstdio>
#include <algorithm>
using namespace std;
struct Person
{
    int s,w;
    Person(){}
    Person(int _s,int _t)
    {
        s=_s;
        w=_t;
    }
    bool operator<(const Person &a)const
    {
        return s+w<a.s+a.w;
    }
}person[100000];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0; i<n; i++)
        {
            int s,w;
            scanf("%d%d",&w,&s);
            person[i]=Person(s,w);
        }
        sort(person,person+n);
        long long sum=person[0].w,ans=0;
        for (int i=1; i<n; i++)
        {
            ans=max(ans,sum-person[i].s);
            sum+=person[i].w;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
