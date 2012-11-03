#include<cstdio>
#include<algorithm>
using namespace std;
struct Person
{
    int a,b;
    Person() {}
    Person(int _a,int _b)
    {
        a=_a;
        b=_b;
    }
} per[10000];
pair<pair<int,int> ,int> tmp[10000];
struct Fac
{
    int a,b;
    Fac() {}
    Fac(int _a,int _b)
    {
        a=_a;
        b=_b;
        int g=__gcd(a,b);
        a/=g;
        b/=g;
        if (a<0)
        {
            a=-a;
            b=-b;
        }
    }
    bool operator<(const Fac &t)const
    {
        if (b>=0 && t.b<0)
            return 0;
        if (b<0 && t.b>=0)
            return 1;
        long long x=(long long)a*t.b,y=(long long)b*t.a;
        return x<y;
    }
    bool operator==(const Fac &t)const
    {
        return a==t.a && b==t.b;
    }
};
struct Event
{
    Fac num;
    bool typ;
    Event() {}
    Event(int s,int t,bool _typ)
    {
        num=Fac(per[s].b-per[t].b,per[t].a-per[s].a);
        typ=_typ;
    }
    bool operator<(const Event &t)const
    {
        if (num==t.num)
            return typ<t.typ;
        else
            return num<t.num;
    }
} event[9980*20];
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (m>n)
            m=n;
        for (int i=0; i<n; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            per[i]=Person(a,b);
            tmp[i]=make_pair(make_pair(b,a),i);
        }

        if (n==1)
        {
            puts("0.0000");
            continue;
        }
        sort(tmp,tmp+n);
        int ans=0;
        for (int i=0; i<n; i++)
            if (tmp[i].second<m)
                ans+=i;
        int now=ans;
        int L=0;
        for (int i=0; i<m; i++)
            for (int j=m; j<n; j++)
            if (per[i].a!=per[j].a)
            {
                event[L++]=Event(i,j,per[i].b<per[j].b || (per[i].b==per[j].b && per[i].a<per[j].a));
                //printf("%d %d %d/%d %d\n",i,j,event[L-1].num.a,event[L-1].num.b,event[L-1].typ);
            }
        sort(event,event+L);
        for (int i=0; i<L; i++)
            if (Fac(0,1)<event[i].num)
            {
                if (!event[i].typ)
                    now--;
                else
                {
                    now++;
                    if (i==L-1 || !(event[i+1].num==event[i].num))
                        ans=max(ans,now);
                }
                //printf("%d %d %d\n",event[i].num.a,event[i].num.b,now);
            }
        printf("%.4f\n",(double)ans/(n-1));
    }
    return 0;
}
