#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define Maxn 200000
#define PI 3.141592653

typedef struct Virt {
    double r;
    double i;
}Virt;

Virt bitRevTemp[2*Maxn];
Virt va[Maxn*2],vb[2*Maxn];
int ans[Maxn*2];

Virt Virt_Add(Virt a,Virt b)
{
    Virt t;
    t.r = a.r+b.r;
    t.i = a.i+b.i;
    return t;
}

Virt Virt_Sub(Virt a,Virt b)
{
    Virt t;
    t.r = a.r-b.r;
    t.i = a.i-b.i;
    return t;
}

Virt Virt_Multi(Virt a,Virt b)
{
    Virt t;
    t.r = a.r*b.r - a.i*b.i;
    t.i = a.r*b.i + a.i*b.r;
    return t;
}

int rev(int x,int l)   //位反置：将长度l的那几位倒过来就是
{
    int i,sum;
    sum = 0;
    while (l--) {
        sum |= (x&1);
        x>>=1;
        sum<<=1;
    }
    sum>>=1;
    return sum;
}
void bitRevCpy(Virt *a,int len)
{
    int k,bits,t;
    t = 1;
    bits = 0;
    while (t<len){       //计算位长度
        ++bits;
        t = t<<1;
    }
    for (k = 0;k < len; k++)
        bitRevTemp[rev(k,bits)] = a[k];
    for (k = 0; k < len; k++)
        a[k] = bitRevTemp[k];
    return;
}

void FFT(Virt *Fourier,int len,int on)
{
    int i,j,k,loop,m;
    Virt u,t;
    Virt wm,w;
    bitRevCpy(Fourier,len);                                 //利用位反置生成输入序列
    for (loop = 2; loop <= len; loop = loop<<1) {
        m = loop;                                           //分治后计算长度为m的DFT
        wm.r = cos(on*2*PI/m);wm.i = sin(on*2*PI/m);        //这次单位复根 e^(2*pi/m) 用欧拉公式展开
        for (k = 0; k < len; k+=m) {                        //FFT过程
            w.r = 1; w.i = 0;                               //旋转因子
            for (j = 0; j < m/2; j++) {
                t = Virt_Multi(w,Fourier[k+j+m/2]);
                u = Fourier[k+j];
                Fourier[k+j] = Virt_Add(u,t);
                Fourier[k+j+m/2] = Virt_Sub(u,t);           //蝴蝶操作合并
                w = Virt_Multi(w,wm);                       //更新旋转因子
            }
        }
    }
    if (on==-1) {
        for (i = 0; i < len; i++)
            Fourier[i].r = Fourier[i].r/len;   //IDFT
    }
}

void conv(Virt *a,Virt *b,int len)
{
    //求卷积
    FFT(a,len,1);
    FFT(b,len,1);
    for (int i = 0;i < len;i++)
        printf("(%.2f,%.2f) ",a[i].r,a[i].i);
    printf("\n");
    for (int i = 0;i < len;i++)
        printf("(%.2f,%.2f) ",b[i].r,b[i].i);
    printf("\n");
    for (int i = 0; i < len; i++)
        a[i] = Virt_Multi(a[i],b[i]);
    for (int i = 0;i < len;i++)
        printf("(%.2f,%.2f) ",a[i].r,a[i].i);
    printf("\n");
    FFT(a,len,-1);
    for (int i = 0;i < len;i++)
        printf("(%.2f,%.2f) ",a[i].r,a[i].i);
    printf("\n");
}

int main()
{
    char str1[Maxn*2],str2[Maxn*2];
    int i,j,top;
    int lena,lenb,lenc;
    while (scanf("%s%s",str1,str2)!=EOF)
    {
        lena = strlen(str1);lenb = strlen(str2);
        lenc = 1;
        while (lenc < lena*2 || lenc < lenb*2 ) {lenc = lenc<<1;}
        for (i = 0; str1[i]!='\0';i++) {
            va[i].r = str1[lena-i-1]-'0';
            va[i].i = 0.0;
        }
        while (i < lenc) {
            va[i].r = va[i].i = 0.0;
            i++;
        }
        for (i = 0; str2[i]!='\0';i++) {
            vb[i].r = str2[lenb-i-1]-'0';
            vb[i].i = 0.0;
        }
        while (i < lenc) {
            vb[i].r = vb[i].i = 0;
            i++;
        }
        conv(va,vb,lenc);    //FFT卷积 相当于不进位乘法
        for (i = 0; i < lenc; i++)
            ans[i] = va[i].r+0.5;
        for (i = 0; i < lenc; i++) {
            ans[i+1] += ans[i]/10;
            ans[i]%=10;
        }
        for (top = lena+lenb-1;ans[top]<=0 && top>0; top--);
        top+=1;
        while (top-- >= 1)
            printf("%d",ans[top]);
        printf("\n");
    }
    return 0;
}
