#include<cstdio>
#include <algorithm>
#include <iostream>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
#define maxn 50100
#define pw(x) ((x)*(x))
typedef long long LL;
double pi=acos(-1.0);
struct P
{
    LL x,y;
    P () {}
    P (LL x,LL y) : x(x) ,y(y) {}
    P operator - (const P & b)
    {
        return P (x-b.x,y-b.y);
    }
    LL operator * (const P & b)
    {
        return x*b.y-y*b.x;
    }
    LL operator & (const P & b)
    {
        return x*b.x+y*b.y;
    }
    P operator * (const int & a)
    {
        return P (x*a,y*a);
    }
    P operator + (const P & a)
    {
        return P (x+a.x,y+a.y);
    }
    bool operator < (const P & b)const
    {
        if(y==b.y) return x<b.x;
        return y<b.y;
    }
    double dorm()
    {
        return sqrt(pw(x)+pw(y));
    }
} pt[maxn],st[maxn],tmp[maxn];
LL r;
int sgn(LL a)
{
    return a<0?-1:a>0;
}
void convex(P pt[],int n,P st[],int & m)
{
    m=0;
    sort(pt,pt+n);
    for(int i=0; i<n; i++)
    {
        while(m>1&&(pt[i]-st[m-2])*(st[m-1]-st[m-2])>=0) m--;
        st[m++]=pt[i];
    }
    int x=m;
    for(int i=n-1; i>=0; i--)
    {
        while(m>1&&m>x&&(pt[i]-st[m-2])*(st[m-1]-st[m-2])>=0) m--;
        st[m++]=pt[i];
    }
    m--;
}
int LCHI(P pt[],int n,P a)
{
    if(n<=2) return 0;
    int t1=sgn((a-pt[0])*(a-pt[1]));
    int t2=sgn((a-pt[0])*(a-pt[n-1]));
    if(t1==0) return 1;
    if(t2==0) return n-1;
    if(t1*t2>0) return 0;
    int l=1,h=n-2;
    while(l<=h)
    {
        int mid=(l+h)/2;
        int t3=sgn((a-pt[0])*(a-pt[mid]));
        if(t3==0) return mid;
        int t4=sgn((a-pt[0])*(a-pt[mid+1]));
        if(t4==0) return mid+1;
        if(t3*t4<0) return mid;
        if(t3==t1) l=mid+1;
        else h=mid-1;
    }
    return l;
}
P run(P pt[],int l,int h,P a)
{
    int t=-2;
    for(int i=l; i<=h; i++)
    {
        t=sgn((a-pt[0])*(a-pt[i]));
        if(t) break;
    }
    if(t==0) return pt[l];
    while(l<=h)
    {
        if(l==h) return pt[l];
        int mid=(l+h)/2;
        int t1=sgn((a-pt[mid])*(a-pt[mid+1]));
        if(t1==t) l=mid+1;
        else h=mid;
    }
    return pt[l];
}

void sol(P pt[],int n,P a,P & x,P & y)
{
    int g=LCHI(pt,n,a);
    pt[n]=pt[0];
    x=run(pt,0,g,a);
    y=run(pt,g+1,n,a);
}
P f[2][2],s;
int flag;
double cal(double x)
{
    double ang=acos(x/r);
    return (pi-ang)*r*r+x*sqrt(pw(r)-pw(x));
}
double cal(P a,P b,P pt[],int n,P st[],int m)
{
    int id1=-1,id2=-1,t1,t2;
    for(int i=0; i<n; i++)
    {
        t1=sgn((pt[i]-a)*(b-a));
        if(t1)
        {
            id1=i;
            break;
        }
    }
    for(int i=0; i<m; i++)
    {
        t2=sgn((st[i]-a)*(b-a));
        if(t2)
        {
            id2=i;
            break;
        }
    }
    P O=P(0,0);
    double x=abs((O-a)*(b-a))/(a-b).dorm();
    double s=cal(x);
    int t3=sgn((O-a)*(b-a));
    if(id1!=-1&&id2!=-1&&t1==t2) return 0;
    if(id1==-1&&id2==-1) return s;
    if((id1!=-1&&(t1*t3>=0))||(id2!=-1&&(t2*t3<=0))) return s;
    return pi*r*r-s;
}
int ck(P a,P b,int id)
{
    int t1=sgn((b-a)*(f[id][0]-s));
    int t2=sgn((b-a)*(f[id][1]-s));
    if(t1*t2<=0) return 1;
    return 0;
}
int ck(P a,P b)
{
    if(!ck(a,b,0)) return 0;
    if(!flag) return 1;
    return ck(a,b,1);
}
double solve(P pt[],int n,P st[],int m)
{
    double ans=0;
    st[m]=st[0];
    for(int i=0; i<m; i++)
    {
        s=st[i];
        flag=0;
        sol(pt,n,s,f[0][0],f[0][1]);
        f[0][1]=s*2-f[0][1];
        if(m>1)
        {
            flag=1;
            f[1][0]=st[i+1];
            f[1][1]=st[(i+m-1)%m];
            f[1][1]=s*2-f[1][1];
        }
        if(flag&&ck(s,f[1][0])) ans=max(ans,cal(s,f[1][0],pt,n,st,m));
        if(flag&&ck(s,f[1][1])) ans=max(ans,cal(s,f[1][1],pt,n,st,m));
        if(ck(s,f[0][0])) ans=max(ans,cal(s,f[0][0],pt,n,st,m));
        if(ck(s,f[0][1])) ans=max(ans,cal(s,f[0][1],pt,n,st,m));
        P O=P(0,0);
        if(s.x!=O.x||s.y!=O.y)
        {
            P g=P(-s.y,s.x);
            if(ck(s,s+g)) ans=max(ans,cal(s,s+g,pt,n,st,m));
        }
    }
    return ans;
}

int main()
{
    int n,m;
    scanf("%lld",&r);
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%lld%lld",&tmp[i].x,&tmp[i].y);
    convex(tmp,n,pt,n);
    scanf("%d",&m);
    for(int i=0; i<m; i++) scanf("%lld%lld",&tmp[i].x,&tmp[i].y);
    convex(tmp,m,st,m);
    printf("%.10f ",pi*r*r-solve(st,m,pt,n));
    printf("%.10f\n",solve(pt,n,st,m));
}
