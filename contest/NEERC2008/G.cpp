#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

struct ships
{
	int id;
    double pos,dis,v;
    bool operator <(const ships& b)const
    {
        return pos < b.pos;
    }
};

ships a[1100];
double spos,w;
int n;
bool flag[1100][1100][2];
double dp[1100][1000][2];

double calcdis(double pa,double pb)
{
    double res = fabs(pa-pb);
    if (res > 180)
        res = 360-res;
    return res;
}

int pre[1100][1100][2][4];
const double eps = 1e-8;
double DP(int l,int r,int sp)
{
    if (flag[l][r][sp] == true)
        return dp[l][r][sp];
    flag[l][r][sp] = true;
    double& res = dp[l][r][sp];
    if (l == r)
    {
        double movtim = calcdis(spos,a[l].pos)/w;
        double dist = a[l].dis-a[l].v*movtim;
        if (dist < 1-eps)
            res = 1e100;
        else
            res = movtim;
    }
    else
    {
        res = 1e100;
        int attpos,tl,tr;
        if (sp == 0)
        {
        	tl = l+1;
        	tr = r;
            attpos = l;
        }
        else
        {
        	tl = l;
        	tr = r-1;
            attpos = r;
        }
        for (int j = 0; j < 2; j++)
        {
            double tmp = DP(tl,tr,j);
            if (tmp < 1e100)
            {
                int dispos;
                if (j == 0)
                    dispos = tl;
                else
                    dispos = tr;
                double movtim = calcdis(a[attpos].pos,a[dispos].pos)/w;
                double dist = a[attpos].dis-(tmp+movtim)*a[attpos].v;
                //printf("tl = %d, tr = %d, j = %d, dist = %.10f\n",tl,tr,j,dist);
                if (dist > 1-eps)
                {
                    if (tmp+movtim < res)
                    {
                        res = tmp+movtim;
                        pre[l][r][sp][0] = tl;
                        pre[l][r][sp][1] = tr;
                        pre[l][r][sp][2] = j;
                        pre[l][r][sp][3] = attpos;
                    }
                }
            }
        }
    }
    return res;
}

void output(int l,int r,int sp)
{
    if (l == r)
    {
        printf("%d\n",a[l].id+1);
        return;
    }
    output(pre[l][r][sp][0],pre[l][r][sp][1],pre[l][r][sp][2]);
    printf("%d\n",a[pre[l][r][sp][3]].id+1);
}

int main()
{
    scanf("%lf%lf%d",&spos,&w,&n);
    for (int i = 0; i < n; i++)
    {
    	a[i].id = i;
        scanf("%lf%lf%lf",&a[i].pos,&a[i].dis,&a[i].v);
    }
    w = w*60*360;
    sort(a,a+n);
    for (int i = 0; i < n; i++)
        a[n+i] = a[i];
    memset(flag,false,sizeof(flag));
    double ans = 1e100;
    int retl,retr,retsp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            if (DP(i,i+n-1,j) < ans)
            {
                ans = DP(i,i+n-1,j);
                retl = i;
                retr = i+n-1;
                retsp = j;
            }
    if (ans < 1e100)
    {
        printf("%.10f\n",ans*60);
        output(retl,retr,retsp);
    }
    else
        puts("Impossible");
    return 0;
}

