#include<iostream>
#include<cmath>
#include<algorithm>
#define N 100000
using namespace std;

bool f[N+10];
__int64 prime[42000];
__int64 cnt,cc,pn,fac;
__int64 pfac[100000];
__int64 pcnt[100000];
__int64 ans[100000];

void init()
{
      int i,j;
      int m=(int)sqrt(double(N));
      cnt=0;
      for(i=2;i<=m;i++)
      {
             if(!f[i])
             {
                     prime[cnt++]=i;
                     for(j=i*i;j<=N;j+=i)
                             f[j]=true;
             }
      }
      if(m&1)
             m++;
      for(i=m+1;i<=N;i+=2)
             if(!f[i])
                     prime[cnt++]=i;
}

__int64 gcd(__int64 a,__int64 b)
{
      if(b==0) return a;
      return gcd(b,a%b);
}

__int64 eular(__int64 n)
{
      __int64 res=1;
      __int64 i;
      for(i=2;i*i<=n;i++)
      {
             if(n%i==0)
             {
                     res*=i-1;
                     n/=i;
                     while(n%i==0)
                     {
                             res*=i;
                             n/=i;
                     }
             }
      }
      if(n>1) 
             res*=n-1;
      return res;
}

void split(__int64 n)
{
    __int64 i,j;
    i=0;
    for(i=0;prime[i]*prime[i]<=n&&i<cnt;i++)
    {
          if(n%prime[i]==0)
          {
                 pcnt[cc]=1;
                 pfac[cc]=prime[i];
                 n/=prime[i];
                 while(n%prime[i]==0)
                 {
                         pcnt[cc]++;
                         n/=prime[i];
                 }
                 cc++;
          }
    }
    if(n>1)
    {
          pcnt[cc]=1;
        pfac[cc++]=n;
    }
    return ;
}

void dfs(__int64 depth)
{
    __int64 i;
    if(depth==cc)
    {
      ans[pn++]=fac;
       return;
    }
    for(i=1;i<=pcnt[depth];i++)
    {
       fac*=pfac[depth];
        dfs(depth+1);
    }
    for(i=1;i<=pcnt[depth];i++)
    {
       fac/=pfac[depth];
    }
    dfs(depth+1);
}

//Çó a * b % m;
__int64 mod(__int64 a, __int64 b,__int64 m) 
{
      __int64 res = 0;
      while(b) 
       {
           if(b & 1) 
               {
               res = res + a;
               if(res >= m) res -= m;
           }
           a += a;
           if(a >= m) a -= m;
           b >>= 1;
      }
      return res;
}

//Çó¡¡a ^ b % m
__int64 mod_exp(__int64 a, __int64 n,__int64 m) 
{
      __int64 res = 1;
      while(n)
       {
           if(n & 1) res = mod(res, a, m);
           a = mod(a, a, m);
           n >>= 1;
      }
      return res;
}

int main()
{
      __int64 n;
      int cas=1;
      __int64 i,j;
      init();
      while(scanf("%I64d",&n),n)
      {
        __int64 m=9*n/gcd(8,n);
        if(gcd(10,m)!=1)
        {
                 printf("Case %d: 0\n",cas++);
                 continue;
        }
        cc=0;
        split(eular(m));
        pn=0;
          fac=1;
          dfs(0);
          sort(ans,ans+pn);
        for(i=0;i<pn;i++)
          {
                 if(mod_exp(10,ans[i],m)==1)
                 {
               printf("Case %d: %I64d\n",cas++,ans[i]);
                       break;
                 }
          }
      }
      return 0;
}
