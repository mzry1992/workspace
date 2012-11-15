#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<cstring>
#include<queue>
#include<iostream>
#include<cmath>
using namespace std;
const int AN = 20*20;
int que[AN*100];
int pre[AN];
bool mask[AN];
int edge[AN][27];
//int value[200];
int ecnt;
void init()
{
    ecnt = 0;
    memset(edge,-1,sizeof(edge));
    memset(mask,0,sizeof(mask));
}
void add(char *s)
{
    int sl = strlen(s);
    //printf("sl = %d\n",sl);
    int pos = 0;
    for(int i = 0 ; i < sl ; i++)
    {
        if(edge[pos][s[i]-'a'] == -1)
        {
            edge[pos][s[i]-'a'] = ++ecnt;
        }
        pos = edge[pos][s[i]-'a'];
        if(mask[pos] == true) break;
    }
    mask[pos] = true;
}
void build()
{
    pre[0] = 0;
    int s,t;
    s = t = 0;
    for(int c = 0 ; c< 26 ; c++)
    {
        if(edge[0][c] == -1)
        {
            edge[0][c] = 0;
        }
        else
        {
            pre[edge[0][c]] = 0;
            que[s++] = edge[0][c];
        }
    }
    while(s != t)
    {
        int ipos = que[t];
        t++;
        for(int c = 0 ; c < 26; c++)
            if(edge[ipos][c] == -1)
            {
                edge[ipos][c] = edge[pre[ipos]][c];
            }
            else
            {
                pre[edge[ipos][c]] = edge[pre[ipos]][c];
                mask[edge[ipos][c]] |= mask[edge[pre[ipos]][c]];
                que[s++] = edge[ipos][c];
            }
    }
}
double prob[26];
char ts[100];
double matA[300][300] , matB[300];
const double eps = 1e-12;
int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}
double Gao(int n)
{
    double tmp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
            if (cmp(matA[j][i],0) != 0)
            {
                for (int k = i; k < n; k++)
                    swap(matA[j][k],matA[i][k]);
                swap(matB[j],matB[i]);
                break;
            }
        if (cmp(matA[i][i],0) == 0) return -1.0;
        for (int j = 0; j < n; j++)
            if (i != j && cmp(matA[j][i],0) != 0)
            {
                tmp = matA[j][i]/matA[i][i];
                for (int k = i; k < n; k++)
                    matA[j][k] -= matA[i][k]*tmp;
                matB[j] -= matB[i]*tmp;
            }
    }
    return matB[0]/matA[0][0];
}
int main()
{
    int n ;
    while(scanf("%d",&n) == 1 )
    {
        init();
        for(int i = 0 ; i  < 26 ; i++)
            scanf("%lf",&prob[i]);
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%s",ts);
            add(ts);
        }
        build();
        ecnt++;
        //printf("ecnt = %d\n",ecnt);
        for(int i  = 0 ; i <ecnt; i++)
        {
            for(int j = 0 ; j < ecnt;j++)
                matA[i][j] = 0.0;
            matB[i] = 0.0;
            if(mask[i] == 0)
            {
                for(int c = 0; c<26; c++)
                {
                    int np = edge[i][c];
                    matA[i][np] += prob[c];
                }
                matA[i][i] -=1.0;
                matB[i] = -1.0;
            }
            else
            {
                matA[i][i] = 1.0;
                matB[i] = 0.0;
            }
        }
        /*for(int i  = 0 ; i <ecnt; i++,puts(""))
            for(int j = 0 ; j < ecnt;j++)
                printf("%.3f ",matA[i][j]);
        for(int j = 0 ; j < ecnt;j++)
            printf("%.3f\n",matB[j]);
            */
        double ans = Gao(ecnt);
        if(ans < -1e-6) printf("Infinity\n");
        else printf("%.6f\n",ans);
    }
    return 0;
}
