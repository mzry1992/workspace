#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>
using namespace std;

int n,m;
int data[150][150],z1[110000],z2[110000],z[110000],y[110000];
const int tt[20]= {-1,1,-2,2,-3,3}; //

void preview()
{
    getchar();
    memset(data,0,sizeof(data));
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            char ch;
            scanf("%c",&ch);
            if (ch=='G')
                for (int k=0; k<=1; k++)
                {
                    if (j+tt[k]>=1&&j+tt[k]<=n)
                        if (data[i][j+tt[k]]>=0) data[i][j+tt[k]]+=1;
                    if (i+tt[k]>=1&&i+tt[k]<=n)
                        if (data[i+tt[k]][j]>=0) data[i+tt[k]][j]+=1;
                    data[i][j]=-1;
                }
            if (ch=='M')
                for (int k=0; k<=3; k++)
                {
                    if (j+tt[k]>=1&&j+tt[k]<=n)
                        if (data[i][j+tt[k]]>=0) data[i][j+tt[k]]+=3;
                    if (i+tt[k]>=1&&i+tt[k]<=n)
                        if (data[i+tt[k]][j]>=0) data[i+tt[k]][j]+=3;
                    data[i][j]=-1;
                }
            if (ch=='F')
                for (int k=0; k<=5; k++)
                {
                    if (j+tt[k]>=1&&j+tt[k]<=n)
                        if (data[i][j+tt[k]]>=0) data[i][j+tt[k]]+=5;
                    if (i+tt[k]>=1&&i+tt[k]<=n)
                        if (data[i+tt[k]][j]>=0) data[i+tt[k]][j]+=5;
                    data[i][j]=-1;
                }
        }
        getchar();
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)==2)//
    {
        preview();
        if(data[n][n]<0||data[1][1]<0)
        {
            printf("Die..\n");
            continue;
        }
        int p1=1,p2=1;
        memset(y,0,sizeof(y));
        memset(z,63,sizeof(z));
        z1[1]=1;
        z2[1]=1;
        y[1]=1;
        z[1]=data[1][1];
        while (p1<=p2)
        {
            int a=z1[p1 % 10000],b=z2[p1 % 10000];
            if (a==n&&b==n) break;
            int now=(a-1)*n+b;
            for (int k=0; k<=1; k++)
            {
                if (a+tt[k]>=1&&a+tt[k]<=n)
                    if (data[a+tt[k]][b]>=0)
                        if (z[(a+tt[k]-1)*n+b]>z[now]+data[a+tt[k]][b])
                        {
                            z[(a+tt[k]-1)*n+b]=z[now]+data[a+tt[k]][b];
                            if (!y[(a+tt[k]-1)*n+b])
                            {
                                y[(a+tt[k]-1)*n+b]=1;
                                p2++;
                                z1[p2]=a+tt[k];
                                z2[p2]=b;
                            }
                        }
                if (b+tt[k]>=1&&b+tt[k]<=n)
                    if (data[a][b+tt[k]]>=0)
                        if (z[(a-1)*n+b+tt[k]]>z[now]+data[a][b+tt[k]])
                        {
                            z[(a-1)*n+b+tt[k]]=z[now]+data[a][b+tt[k]];
                            if (!y[(a-1)*n+b+tt[k]])
                            {
                                y[(a-1)*n+b+tt[k]]=1;
                                p2++;
                                z1[p2]=a;
                                z2[p2]=b+tt[k];
                            }
                        }
            }
            y[now]=0;
            p1++;
        }
        if (z[n*n]>=m/*||(z[n*n]==m&&data[n][n]==0)*/)printf("Die..\n");
        else printf("Girl~\n");
    }
}
