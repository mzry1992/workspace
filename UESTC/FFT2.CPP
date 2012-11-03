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

void fft(comp x[],int& n,comp y[])
{
    //长度扩展
    int bitlen = 1;
    for (int i = 1;;i <<= 1,bitlen++)
        if (n <= i)
        {
            for (int j = n;j < i;j++)
                x[j] = comp(0,0);
            n = i;
            bitlen--;
            break;
        }
    //位反转获得输入序列
    for (int i = 0;i < n;i++)
    {
        int revpos = 0;
        for (int j = 0;j < bitlen;j++)
            revpos = (revpos<<1)|((i>>j)&1);
        y[revpos] = x[i];
    }
    comp w0,w,low,up;
    for (int len = 2;len <= n;len <<= 1)
    {
        w0 = comp(cos(-2*pi/len),sin(-2*pi/len));
        for (int i = 0;i < n;i += len)
        {
            w = comp(1,0);//旋转因子
            for (int j = 0;j < len/2;j++,w = w*w0)
            {
                low = w*y[i+j+len/2];
                up = y[i+j];
                y[i+j] = up+low;
                y[i+j+len/2] = up-low;
            }
        }
    }
}

comp x[200000],y[200000];

int main()
{
    int n;
    while (true)
    {
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
        {
            double tmp;
            scanf("%lf",&tmp);
            x[i] = comp(tmp,0);
        }
        fft(x,n,y);
        printf("FFT : [");
        for (int i = 0; i < n; i++)
            y[i].print();
        printf("]\n");
    }
    return 0;
}

