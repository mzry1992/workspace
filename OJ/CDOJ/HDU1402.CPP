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

void ifft(comp x[],int& n,comp y[])
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
        w0 = comp(cos(2*pi/len),sin(2*pi/len));
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
    for (int i = 0;i < n;i++)
        y[i] = y[i]/comp(n,0);
}

comp xa[220000],ya[220000],xb[220000],yb[220000];
int la,lb,n,ans[220000];
char sa[50010],sb[50010];

int main()
{
    while (scanf("%s%s",sa,sb) != EOF)
    {
        la = strlen(sa);
        lb = strlen(sb);
        n = la+lb;
        for (int i = 1;;i <<= 1)
            if (i >= n)
            {
                n = i;
                break;
            }
        for (int i = 0;i < la;i++)
            xa[i] = comp(sa[la-1-i]-'0',0);
        for (int i = la;i < n;i++)
            xa[i] = comp(0,0);
        fft(xa,n,ya);
        for (int i = 0;i < lb;i++)
            xb[i] = comp(sb[lb-1-i]-'0',0);
        for (int i = lb;i < n;i++)
            xb[i] = comp(0,0);
        fft(xb,n,yb);
        /*for (int i = 0;i < n;i++)
            ya[i].print();
        printf("\n");
        for (int i = 0;i < n;i++)
            yb[i].print();
        printf("\n");*/
        for (int i = 0;i < n;i++)
            xa[i] = ya[i]*yb[i];
        /*for (int i = 0;i < n;i++)
            xa[i].print();
        printf("\n");*/
        ifft(xa,n,ya);
        /*for (int i = 0;i < n;i++)
            ya[i].print();
        printf("\n");*/
        for (int i = 0;i < n;i++)
            ans[i] = ya[i].a+0.5;
        ans[n] = 0;
        for (int i = 0;i < n;i++)
        {
            ans[i+1] += ans[i]/10;
            ans[i] %= 10;
        }
        n++;
        while (ans[n-1] > 9)
        {
            ans[n] = ans[n-1]/10;
            ans[n-1] %= 10;
            n++;
        }
        while (n > 1 && ans[n-1] == 0)  n--;
        for (int i = n-1;i >= 0;i--)
            printf("%d",ans[i]);
        printf("\n");
    }
    return 0;
}

