#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double pi = acos(-1);

struct comp
{
    double a,b;
    comp() {}
    comp(double _a,double _b)
    {
        a = _a;
        b = _b;
    }
    friend comp operator +(const comp& a,const comp& b)
    {
        return comp(a.a+b.a,a.b+b.b);
    }
    friend comp operator -(const comp& a,const comp& b)
    {
        return comp(a.a-b.a,a.b-b.b);
    }
    friend comp operator *(const comp& a,const comp& b)
    {
        return comp(a.a*b.a-a.b*b.b,a.a*b.b+a.b*b.a);
    }
    friend comp operator /(const comp& a,const comp& b)
    {
        comp tmp = a*comp(b.a,-b.b);
        double tmp1 = b.a*b.a+b.b*b.b;
        tmp.a /= tmp1;
        tmp.b /= tmp1;
        return tmp;
    }
    void print()
    {
        if (fabs(b) < 1e-8)
            printf("%.4f ",a);
        else
            printf("%.4f%c%.4fi ",a,(b < 0)?'-':'+',fabs(b));
    }
    void println()
    {
        print();
        printf("\n");
    }
};

void dft(comp x[],int n,comp y[])
{
    comp w0 = comp(cos(-2*pi/n),sin(-2*pi/n)),wk,w;
    wk = comp(1,0);
    for (int k = 0; k < n; k++,wk = wk*w0)
    {
        y[k] = comp(0,0);
        w = comp(1,0);
        for (int i = 0; i < n; i++,w = w*wk)
            y[k] = y[k]+x[i]*w;
    }
}

void idft(comp x[],int n,comp y[])
{
    comp w0 = comp(cos(2*pi/n),sin(2*pi/n)),wk,w;
    wk = comp(1,0);
    for (int k = 0; k < n; k++,wk = wk*w0)
    {
        y[k] = comp(0,0);
        w = comp(1,0);
        for (int i = 0; i < n; i++,w = w*wk)
            y[k] = y[k]+x[i]*w;
        y[k] = y[k]/comp(n,0);
    }
}

comp w[200000],ty[200000];

void fft(comp x[],int& n,comp y[])
{
    //2»ùµ×
    for (int i = 1;;i <<= 1)
        if (i >= n)
        {
            for (int j = n;j < i;j++)
                x[j] = comp(0,0);
            n = i;
            break;
        }
    comp w0 = comp(cos(-2*pi/n),sin(-2*pi/n));
    w[0] = comp(1,0);
    for (int i = 1;i < n;i++)
        w[i] = w[i-1]*w0;
    for (int i = 0;i < n;i++)
    {
        int l = 0,r = n-1,cur = i;
        for (int j = 1;j < n;j <<= 1)
            if (((cur-l)&1) == 0)
            {
                cur = l+((cur-l)>>1);
                r = l+r>>1;
            }
            else
            {
                cur = (l+r+1>>1)+((cur-l)>>1);
                l = l+r+1>>1;
            }
        y[cur] = x[i];
    }
    for (int i = 1;i < n;i <<= 1)
    {
        int len = i<<1,dis = n/len;
        for (int j = 0;j < n;j++)
            if (j%len < i)
                ty[j] = y[j]+y[j+i]*w[j%len*dis];
            else
                ty[j] = y[j]*w[j%len*dis]+y[j-i];
        for (int j = 0;j < n;j++)
            y[j] = ty[j];
    }
}

comp x[200000],y[200000];

int main()
{
    int n;
    n = 100000;
    for (int i = 0;i < n;i++)
        x[i] = comp(i,0);
    fft(x,n,y);
    /*for (int i = 0;i < n;i++)
        y[i].print();*/
    printf("end\n");
    while (true)
    {
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
        {
            double tmp;
            scanf("%lf",&tmp);
            x[i] = comp(tmp,0);
        }
        /*dft(x,n,y);
        printf("FFT : [");
        for (int i = 0; i < n; i++)
            y[i].print();
        printf("]\n");
        idft(y,n,x);
        printf("IFFT : [");
        for (int i = 0; i < n; i++)
            x[i].print();
        printf("]\n");*/

        fft(x,n,y);
        printf("FFT : [");
        for (int i = 0; i < n; i++)
            y[i].print();
        printf("]\n");
    }
    return 0;
}
