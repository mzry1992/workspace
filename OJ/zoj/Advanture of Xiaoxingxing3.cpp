#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;
typedef double db;
const db PI = acos(-1.0);
const db PI2 = PI*2.0;
const db eps = 1e-9;
const db oo = 1e100;
struct pt
{
    db x,y;
    pt() {} pt(db x,db y):x(x),y(y) {}
    pt operator +(pt a)
    {
        return pt(x+a.x,y+a.y);
    }
    pt operator -(pt a)
    {
        return pt(x-a.x,y-a.y);
    }
    pt operator *(db c)
    {
        return pt(x*c,y*c);
    }
    pt operator /(db c)
    {
        return pt(x/c,y/c);
    }
    db operator *(pt a)
    {
        return x*a.x+y*a.y;
    }
    db operator &(pt a)
    {
        return x*a.y-y*a.x;
    }
    db len2()
    {
        return x*x+y*y;
    }
    db len()
    {
        return sqrt(len2());
    }
    db ang()
    {
        return atan2(y,x);
    }
    void getP()
    {
        scanf("%lf%lf",&x,&y);
    }
    pt turn(db a) //counter-clockwise
    {
        db cx = x*cos(a)-y*sin(a);
        db cy = x*sin(a)+y*cos(a);
        return pt(cx,cy);
    }
    bool operator <(const pt &a)const
    {
        if (fabs(x-a.x) < eps) return y < a.y;
        return x < a.x;
    }
    bool operator ==(const pt &a)const
    {
        return (fabs(x-a.x) < eps &&
                fabs(y-a.y) < eps);
    }
};
int sign(db x)
{
    return (x > eps)-(x < -eps);
}
bool right(pt a,pt b,pt c)
{
    return sign((b-a) & (c-a)) < 0;
}
bool between(db a,db b,db c)
{
    return sign(b-a) >= 0 && sign(c-b) >= 0;
}
void clockwise(pt cP[],int N)
{
    db area = 0.0;
    cP[N] = cP[0];
    for (int i = 0; i < N; i++)
        area += cP[i] & cP[i+1];
    if (sign(area) < 0)
    {
        for (int i = 1,j = N-1; i < j; i++,j--)
            swap(cP[i],cP[j]);
    }
}
int find(pt cP[],int N,pt p)
{
    for (int i = 0; i < N; i++)
        if (p == cP[i])
            return i;
    return -1;
}
void cross(pt o,db r,pt a,pt b,db &ra,db &rb)
{
    db r2 = r*r;
    pt d = b-a,ao = a-o;
    db A2 = 2.0*d.len2();
    db B = 2.0*(ao * d);
    db C = ao.len2()-r2;
    db tk = B*B-2*A2*C;
    db k1 = oo,k2 = oo;
    bool fa = sign((a-o).len2()-r2) < 0;
    bool fb = sign((b-o).len2()-r2) < 0;
    ra = rb = oo;
    if (fa)
    {
        if (fb) return ;
        k1 = (sqrt(tk)-B) / A2;
    }
    else if (fb)
    {
        k1 = (-sqrt(tk)-B) / A2;
    }
    else
    {
        if (sign(tk) >= 0)
        {
            k1 = (sqrt(tk)-B) / A2;
            k2 = (-sqrt(tk)-B) / A2;
        }
    }
    if (k1 < oo / 2 && sign(k1) >= 0 && sign(k1-1.0) <= 0)
    {
        pt c = a+d*k1;
        //printf("k1 = %f : get (%.2f,%.2f)\n",k1,c.x,c.y);
        ra = (c-o).ang();
    }
    if (k2 < oo / 2 && sign(k2) >= 0 && sign(k2-1.0) <= 0)
    {
        pt c = a+d*k2;
        //printf("k2 = %f : get (%.2f,%.2f)\n",k2,c.x,c.y);
        rb = (c-o).ang();
    }
}
void update(db &r,db d,db s,db t)
{
    while (sign(d-s) < 0) d += PI2;
    if (between(s,d,t))
        r = min(r,d);
}
void error()
{
    puts("Impossible");
    while (1);
}
const int MaxP = 200;
pt P[MaxP],fP[MaxP],sk[MaxP],rP;
db L[MaxP],A[MaxP];
int id[MaxP];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out2.txt","w",stdout);
    for (int ct = 1,N; scanf("%d",&N) != EOF && N; ct++)
    {
        for (int i = 0; i < N; i++)
            P[i].getP();
        rP.getP();
        printf("Case %d: ",ct);
        if (N == 1)
        {
            error();
            continue;
        }
        //clockwise(P,N);
        memcpy(fP,P,sizeof(fP[0])*N);
        sort(fP,fP+N);
        int sn = 0;
        sk[0] = fP[0];
        for (int i = 1; i < N; i++)
        {
            while (sn > 0 && !right(sk[sn-1],sk[sn],fP[i]))
                --sn;
            sk[++sn] = fP[i];
        }
        int c = sn;
        for (int i = N-2; i >= 0; i--)
        {
            while (sn > c && !right(sk[sn-1],sk[sn],fP[i]))
                --sn;
            sk[++sn] = fP[i];
        }
        clockwise(sk,sn);
        int s = -1;
        for (int i = 0; i < sn; i++)
            if (sign(sk[i].y) == 0)
            {
                s = i;
                break;
            }
        if (s == -1)
        {
            error();
            continue;
        }
        for (int i = 0; i < sn; i++)
            sk[i+sn] = sk[i];
        memcpy(sk,sk+s,sizeof(sk[0])*sn);
        for (int i = 0; i < sn; i++)
            id[i] = find(P,N,sk[i]);
        //printf("pP : ");for (int i = 0;i < N;i++)printf("(%.2f,%.2f) ",P[i].x,P[i].y);puts("");
        //printf("sk : ");for (int i = 0;i < sn;i++)printf("(%.2f,%.2f) ",sk[i].x,sk[i].y);puts("");
        db Dx = 0.0,Ang = 0.0;
        if (sign(sk[1].y) > 0)
        {
            //printf("inside~~\n");
            pt b = sk[1]-sk[0];
            db ca = b.ang();
            pt o = pt(sk[0].x,0.0);
            pt ro = rP-o;
            db r = ro.len();
            db sa = ro.ang();
            db ta = sa+ca;
            db cr = oo;
            for (int j = 0; j < N; j++)
            {
                db a,b;
                cross(o,r,P[j],P[j+1],a,b);
                if (a < oo / 2) update(cr,a,sa,ta);
                if (b < oo / 2) update(cr,b,sa,ta);
            }
            if (cr < oo / 2)
            {
                printf("%.2f\n",(cr-sa)*180.0 / PI);
                continue;
            }
            Ang += ca;
            //printf("SK : ");for (int i = 0;i < sn;i++)printf("(%.2f,%.2f) ",sk[i].x,sk[i].y);puts("");
        }
        for (int i = 0; i < sn; i++)
            sk[i+sn] = sk[i];
        db tL = 0.0;
        for (int i = 0; i < sn; i++)
        {
            pt b = sk[i+1]-sk[i];
            L[i+sn] = L[i] = b.len();
            pt a = sk[i]-sk[i+sn-1];
            A[i+sn] = A[i] = atan2(a & b,a * b);
            tL += L[i];
        }
        //printf("L : ");for (int i = 0;i < sn;i++)printf("%.2f ",L[i]);puts("");
        //printf("A : ");for (int i = 0;i < sn;i++)printf("%.2f ",A[i]);puts("");
        Dx = sk[0].x+L[0];
        s = 1;
        //printf("pre %d : %.2f %.2f\n",s,Dx,Ang);
        bool find = false;
        while (sign(Dx-tL-rP.x) < 0)
        {
            pt o = P[id[s]];
            pt ro = rP-pt(Dx,0.0);
            db r = ro.len();
            db sa = (sk[s]-sk[s+sn-1]).ang()+ro.ang();
            db ta = sa+A[s];
            db cr = oo;
            //printf("s = %d(%.2f,%.2f) | r = %f,[%f,%f]\n",s,o.x,o.y,r,sa,ta);
            for (int j = 0; j < N; j++)
            {
                db a,b;
                cross(o,r,P[j],P[j+1],a,b);
                //printf("j = %d : %f %f\n",j,a < oo / 2?a:-100,b < oo / 2?b:-100);
                if (a < oo / 2) update(cr,a,sa,ta);
                if (b < oo / 2) update(cr,b,sa,ta);
            }
            //printf("cr = %f\n",cr);
            if (cr < oo / 2)
            {
                Ang += cr-sa;
                find = true;
                break;
            }
            //cout << A[s] << endl;
            Dx += L[s],Ang += A[s];
            if (++s >= sn) s-= sn;
        }
        if (find)
            printf("%.2f\n",Ang*180.0 / PI);
        else
            puts("Impossible");
    }
    return 0;
}
