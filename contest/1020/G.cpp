#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<cmath>
#include<cstring>
const int SIZE = 100010;
int n,m;
int f[SIZE][30];
int rank_s[SIZE],height[SIZE] ,sa[SIZE];
int cmp2(int x,int y)
{
    if(x < y) return x;
    else return y;
}
void init(int *a)
{
    int i , j ;
    for(i = 0 ; i < n ; i++)
        f[i][0] = a[i];
    for(j = 1 ; i+(1<<j) - 1<n ; i++)
        f[i][j] = cmp2(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}
int query(int x,int y)
{
    int k = 0 ;
    x = rank_s[x];
    y = rank_s[y];
    if(x> y)
    {
        int t = x;
        x = y;
        y = t;
    }
    x++;
    while((1<<k) <=y-x+1)k++;
    k--;
    return cmp2(f[x][k] ,f[y-(1<<k)+1][k]);
}
int str[SIZE];
int wx[SIZE] , wy[SIZE];
int *x, *y;
int wss[SIZE] ,wv[SIZE];
bool cmp(int *r ,int a,int b ,int l)
{
    return a+l < n && b+l <n && r[a]==r[b] && r[a+l] == r[b+l];
}
void da()
{
    int *s = str;
    int *x = wx,*y= wy,*t,p;
    int i ,j;
    for(i = 0 ; i < m ; i++) wss[i] = 0;
    for(i = 0; i < n  ; i++) wss[x[i] = s[i]] ++;
    for(i = 1; i < m; i ++)wss[i]+=wss[i-1];
    for(i = n-1; i>=0; i--)sa[--wss[x[i]]] = i;
    for(j =1 ,p =1 ; p<n && j< n; j*=2,m=p)
    {
        for(i =n -j ,p = 0; i<n; i++)y[p++]=i;
        for(i =0; i<n; i++)if(sa[i]-j>=0)y[p++]=sa[i]-j;
        for(i = 0; i<n; i++)wv[i]=x[y[i]];
        for(i = 0 ; i< m ; i++)wss[i] = 0;
        for(i =0 ; i< n ; i++) wss[wv[i]]++;
        for(i=1; i<m; i++)wss[i]+=wss[i-1];
        for(i=n-1; i>=0; i--)sa[--wss[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,i=1,x[sa[0]]=0; i<n; i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    return ;
}
void calcHeight(){
    for(int i = 0 ; i < n ; i++)rank_s[sa[i]] = i;
    for(int i = 0 , j= 0 , k = 0 ;i < n ;height[rank_s[i++]] = k)
        if(rank_s[i] > 0)
            for(k ? k --:0,j=sa[rank_s[i]-1] ; str[i+k] == str[j+k];k++);
}
int ts1[SIZE],ts2[SIZE];
int arr[SIZE];
int main(){
    int n1,n2,K;
    while(scanf("%d%d%d",&n1,&n2,&K) == 3){
        for(int i= 0; i<n1 ; i++)
            scanf("%d",&ts1[i]);
        for(int i =0;i < n2 ; i++)
            scanf("%d",&ts2[i]);
        n = n1+n2+1;
        m = 10001;
        for(int i = 0 ; i < n1 ;i++)
            str[i] = ts1[i];
        str[n1] = 10001;
        for(int i = 0 ;i < n2 ; i++)
            str[n1+1+i] = ts2[i];
        str[n] = -1;


        da();
        calcHeight();
        init(height);
        puts("---");
        for(int i = 0 ; i < n ;i++){
            for(int j = sa[i] ; j < n ; j++)
                printf("%d ",str[j]);
            puts("");
        }
        puts("---");
        for(int i = 0 ; i < n ; i++)
            printf("%d = %d\n",i,height[i]);
        puts("---");

    }
    return 0;
}
