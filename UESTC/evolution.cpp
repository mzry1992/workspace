#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
struct Matrix
{
    int m,n;
    double a[205][205];
}ini;

Matrix mult(Matrix a,Matrix b)
{
    Matrix c;
    c.m=a.m;c.n=b.n;
    for (int i=0;i<a.m;i++)
        for (int j=0;j<b.n;j++) c.a[i][j]=0.0;
    for (int i=0;i<a.m;i++)
        for (int j=0;j<b.n;j++)
            for (int k=0;k<a.n;k++)
                c.a[i][j]+=a.a[i][k]*b.a[k][j];
    return c;
}

Matrix pow(Matrix a,int n)
{
    puts("########");
    Matrix c=a,res;
    res.n=a.n;res.m=a.m;
    puts("");
    for (int i=0;i<res.m;i++)
        for (int j=0;j<res.n;j++)
        {
            if (i==j) res.a[i][j]=1.0;
            else res.a[i][j]=0.0;
        }
    puts("#!@#");
    //while (n>0)
    //{
      //  if (n&1) res=mult(res,c);
       // printf("%d\n",n);
       // n>>=1;
       // c=mult(c,c);
    //}
    return res;
}

int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)>0)
    {
        ini.m=n;
        ini.n=1;
        for (int i=0;i<n;i++) scanf("%lf",&ini.a[i][0]);
        int T;
        scanf("%d",&T);
        Matrix change;
        change.m=change.n=n;
        for (int i=0;i<T;i++)
        {
            int x,y;
            double p;
            scanf("%d%d%lf",&x,&y,&p);
            change.a[y][x]+=p;
            change.a[x][y]+=1-p;
        }
        for (int i=0;i<n;i++)
            change.a[i][i]=1.0;
        //puts("###");
        Matrix res=pow(change,m);
        puts("####");
        Matrix end=mult(res,ini);
        printf("%.lf\n",end.a[n-1][0]);
    }
}
