#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int P;
int _g[25];
int BIT_CNT;

int power(int x,int y,int mod)
{
    int ret=1;
    for (int a=x%mod; y; y>>=1,a=a*a%mod)
        if (y&1)
            ret=ret*a%mod;
    return ret;
}

bool is_prime(int n)
{
    for (int i = 2; i*i <= n; i++)
        if (n%i == 0)   return false;
    return true;
}

int getP(int Lim)
{
    for (int c = 3;; c++)
    {
        int t = c<<21|1;
        if (is_prime(t) && t >= Lim)    return t;
    }
    return -1;
}

bool is_g(int a,int P)
{
    int p0 = P-1;
    for (int i = 1; i*i <= p0; i++)
        if (p0%i == 0)
        {
            if (power(a,i,P) == 1 && i < p0)    return false;
            if (power(a,p0/i,P) == 1 && p0/i < p0)  return false;
        }
    return true;
}

int getG(int P)
{
    int g;
    for (g = 2; !is_g(g,P); g++);
    return g;
}

void get_g(int G,int P,int blim,int _g[])
{
    for (int i = 0; i < blim; i++)
        _g[i] = power(G,(P-1)/(1<<i),P);
}

int reverse(int j)
{
    int k = 0;
    for (int i = 0; i < BIT_CNT; i++)
        if (j&(1<<i))
            k |= 1<<(BIT_CNT-i-1);
    return k;
}

void FFT(int x[],int n)
{
    int i0,j0,t0,t1;
    for (int m = 1; m <= BIT_CNT; m++)
    {
        i0 = 1<<m;
        j0 = i0>>1;
        for (int i = 0; i < n; i += i0)
            for (int j = 0,tt = 1; j < j0; j++,tt = (long long)tt*_g[m]%P)
            {
                t0 = tt;
                t1 = (long long)x[i+j+j0]*t0%P;
                t0 = (x[i+j]+t1)%P;
                t1 = (x[i+j]-t1)%P;
                if (t1 < 0) t1 += P;
                x[i+j] = t0;
                x[i+j+j0] = t1;
            }
    }
}

int Inv(int n)
{
    return power(n,P-2,P);
}

void conv(int a[],int b[],int n)
{
    FFT(a,n);
    FFT(b,n);
    for (int i = 0; i < n; i++)
        b[i] = (long long)a[i]*b[i]%P;
    for (int i = 0; i < n; i++)
        a[reverse(i)] = b[(i == 0)?0:(n-i)];
    FFT(a,n);
    for (int i = 0; i < n; i++)
        a[i] = (long long)a[i]*Inv(n)%P;
}

void init()
{
    P = getP(1000000000);
    get_g(getG(P),P,21,_g);
}

char A[1000],B[1000];
int a[1000],b[1000],n,la,lb,ta[1000],tb[1000];

int main()
{
    init();
    while (scanf("%s%s",A,B) != EOF)
    {
        la = strlen(A);
        lb = strlen(B);
        n = max(la,lb);
        for (int i =0;i < la;i++)
            ta[n-la+i] = A[i]-'0';
        for (int i = 0;i < lb;i++)
            tb[n-lb+i] = B[i]-'0';
        for (int i = 0;i < n-la;i++)
            ta[i] = 0;
        for (int i = 0;i < n-lb;i++)
            tb[i] = 0;
        int av,bv,bit = 1;
        int c = 0,k = 0,j;
        av = bv = 0;
        int on = n/1+(n%1 != 0);
        for (BIT_CNT = 1;on+on > (1<<BIT_CNT);BIT_CNT++);
        for (int i = n-1;i >= 0;i--)
        {
            av = av+bit*ta[i];
            bv = bv+bit*tb[i];
            c++;
            if (c == 1 || i == 0)
            {
                j = reverse(k);
                a[j] = av;
                b[j] = bv;
                k++;
                c = av = bv = 0;
                bit = 1;
            }
            else bit *= 10;
        }
        n = 1<<BIT_CNT;
        conv(a,b,n);
        for (int i = 0;i < n;i++)
            cout << a[i] << ' ';
        cout << endl;
    }
    return 0;
}
