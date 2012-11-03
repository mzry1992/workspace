#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double eps = 1e-8;
int n,m,s,t,d;
double p[100];
double a[200][200],b[200];
int next[200][101];

void solve(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
            if (fabs(a[j][i]) > fabs(a[i][i]))
            {
                for (int k = 0; k < n; k++)
                    swap(a[i][k],a[j][k]);
                swap(b[i],b[j]);
                break;
            }
        if (fabs(a[i][i]) < eps)	continue;
        for (int j = 0; j < n; j++)
            if (j != i)
            {
                double det = a[j][i]/a[i][i];
                if (fabs(det) < eps)	continue;
                for (int k = i; k < n; k++)
                    a[j][k] -= det*a[i][k];
                b[j] -= det*b[i];
            }
    }
}

pair<int,bool> getId(int x)
{
    pair<int,bool> ret;
    if (x<n-1)
        ret.second=0;
    else
        ret.second=1;
    if (x<n-1)
        ret.first=x;
    else
        ret.first=2*n-x-2;
    return ret;
}

bool to[101];
bool mp[201][201];

int main()
{
    freopen("data.in","r",stdin);
    //freopen("data_2.out","w",stdout);
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%d%d%d%d%d",&n,&m,&t,&s,&d);

        if (s==0)
            d=0;
        if (s==n-1)
            d=1;
        for (int i = 0; i < m; i++)
        {
            int x;
            scanf("%d",&x);
            if (x)
                to[i]=1;
            else
                to[i]=0;
            p[i] =(double)x/100;
        }
        if (n <= 1 || s == t)
        {
            puts("0.00");
            continue;
        }
        for (int i = 0; i < n*2-2; i++)
        {
            next[i][0]=i;
            for (int j = 1; j <= m; j++)
            {
                next[i][j] = next[i][j-1]+1;
                if (next[i][j] == n*2-2)
                    next[i][j]=0;
            }
        }
        for (int i=0; i<n*2-2; i++)
            for (int j=0; j<n*2-2; j++)
                mp[i][j]=0;
        for (int i = 0; i <n*2-2; i++)
        {
            for (int j=1; j<=m; j++)
                if (to[j-1])
                    mp[i][next[i][j]]=1;
            mp[i][i] = 1;
        }
        for (int k=0; k<n*2-2; k++)
            for (int i=0; i<n*2-2; i++)
                for (int j=0; j<n*2-2; j++)
                    if (mp[i][k] && mp[k][j])
                        mp[i][j]=1;
        bool flag = 0;
        for (int i=0; i<n*2-2; i++)
            if (getId(i).first==s && getId(i).second==d)
                for (int j=0; j<n*2-2; j++)
                    if (getId(j).first==t)
                        flag|=mp[i][j];
        if (!flag)
        {
            puts("Impossible !");
            continue;
        }
        for (int i=0; i<n*2-2; i++)
            b[i]=0;
        for (int i=0; i<n*2-2; i++)
            for (int j=0; j<n*2-2; j++)
                a[i][j]=0;
        for (int i=0; i<n*2-2; i++)
            if (getId(i).first==t)
            {
                a[i][i]=-1;
                b[i]=0;
            }
            else
            {
                a[i][i]=-1;
                for (int j=1; j<=m; j++)
                    b[i]-=j*p[j-1];
                for (int j=1; j<=m; j++)
                    a[i][next[i][j]]+=p[j-1];
            }
        solve(n*2-2);
        double ans;
        for (int i=0; i<n*2-2; i++)
            if (getId(i).first==s && getId(i).second==d)
                ans=b[i]/a[i][i];
        printf("%.2f\n",ans);
    }
    return 0;
}
