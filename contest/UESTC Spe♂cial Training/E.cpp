#include <cstdio>
#include <algorithm>
using namespace std;
struct NUM
{
    int a,b;
    NUM() {}
    NUM(int _a,int _b)
    {
        a=_a;
        b=_b;
    }
    NUM operator*(const NUM &x)
    {
        return NUM(a*x.a-2*b*x.b,a*x.b+b*x.a);
    }
    bool operator<(const NUM &x)const
    {
        return a*a+b*b*2<x.a*x.a+x.b*x.b*2;
    }
    bool operator==(const NUM &x)
    {
        return a==x.a && b==x.b;
    }
    bool operator!=(const NUM &x)
    {
        return !((*this)==x);
    }
} num[20000];
int a[200][200];
int main()
{
    int L=0;
    for (int i=-99; i<100; i++)
        for (int j=-99; j<100; j++)
            num[L++]=NUM(i,j);
    sort(num,num+L);
    for (int i=0; i<200; i++)
        for (int j=0; j<200; j++)
            a[i][j]=1;
    for (int i=0; i<L; i++)
        if (num[i]!=NUM(0,0) && num[i]!=NUM(1,0) && num[i]!=NUM(-1,0))
            for (int j=0; j<i; j++)
                if (num[j]!=NUM(0,0) && num[j]!=NUM(1,0) && num[j]!=NUM(-1,0))
                {
                    NUM tmp=num[i]*num[j];
                    if (tmp.a>-100 && tmp.a<100 && tmp.b<100 && tmp.b>-100)
                        a[tmp.a+100][tmp.b+100]=0;
                }
    for (int i=-9; i<10; i++)
        for (int j=-9; j<10; j++)
            if (a[i+100][j+100])
                printf("%d %d\n",i,j);
    return 0;
}
