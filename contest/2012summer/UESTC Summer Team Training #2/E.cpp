#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char a[20],b[20],c[20],d[20];
char s[50];
int len1,len2,len3;
long long dp[20][2];
int k1,k2,k3;
void dfs(int p,int num)
{
    int i;
    if(num==0)
    {
        if(p>=len1)
        {
            k1=0;
            dfs(p,num+1);
        }
        else if(a[p]!='?')
        {
            k1=a[p]-'0';
            dfs(p,num+1);
        }
        else
        {
            if(p==len1-1&&len1>1)
                for(i=1;i<10;i++)
                {
                    k1=i;
                    dfs(p,num+1);
                }
            else
                for(i=0;i<10;i++)
                {
                    k1=i;
                    dfs(p,num+1);
                }
        }
    }
    if(num==1)
    {
        if(p>=len2)
        {
            k2=0;
            dfs(p,num+1);
        }
        else if(b[p]!='?')
        {
            k2=b[p]-'0';
            dfs(p,num+1);
        }
        else
        {
            if(p==len2-1&&len2>1)
                for(i=1;i<10;i++)
                {
                    k2=i;
                    dfs(p,num+1);
                }
            else
                for(i=0;i<10;i++)
                {
                    k2=i;
                    dfs(p,num+1);
                }
        }
    }
    if(num==2)
    {
        if(p>=len3)
        {
            k3=0;
            dfs(p,num+1);
        }
        else if(c[p]!='?')
        {
            k3=c[p]-'0';
            dfs(p,num+1);
        }
        else
        {
            if(p==len3-1&&len3>1)
                for(i=1;i<10;i++)
                {
                    k3=i;
                    dfs(p,num+1);
                }
            else
                for(i=0;i<10;i++)
                {
                    k3=i;
                    dfs(p,num+1);
                }
        }
    }
    if(num==3)
    {
        //printf("%d %d %d\n",k1,k2,k3);
        if((k1+k2)%10==k3)
        {
            if(k1+k2<10)
                dp[p+1][0]+=dp[p][0];
            else
                dp[p+1][1]+=dp[p][0];
        }
        else if((k1+k2)%10==k3-1)
        {
            if(k1+k2<10)
                dp[p+1][0]+=dp[p][1];
            else
                dp[p+1][1]+=dp[p][1];
        }
        else if(k1+k2==9&&k3==0)
            dp[p+1][1]+=dp[p][1];
        return;
    }
}
int main()
{
    int cas = 1;
    while (gets(s) != NULL)
    {
        int i,j,k;
        for(i=0;i<strlen(s);i++)
            if(s[i]!='+')
                a[i]=s[i];
            else
                break;
        a[i]='\0';
        for(j=i+1;j<strlen(s);j++)
            if(s[j]!='=')
                b[j-i-1]=s[j];
            else
                break;
        b[j-i-1]='\0';
        for(k=j+1;k<strlen(s);k++)
            c[k-j-1]=s[k];
        c[k-j-1]='\0';
        len1=strlen(a);
        len2=strlen(b);
        len3=strlen(c);
        strcpy(d,a);
        for(i=0;i<len1;i++)
            a[i]=d[len1-1-i];
        strcpy(d,b);
        for(i=0;i<len2;i++)
            b[i]=d[len2-1-i];
        strcpy(d,c);
        for(i=0;i<len3;i++)
            c[i]=d[len3-1-i];
        //printf("%s\n%s\n%s\n",a,b,c);
        int ma=max(len1,max(len2,len3));
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        //printf("%d\n",ma);
        for(i=0;i<ma;i++)
            dfs(i,0);
        printf("Case %d: %lld\n",cas++,dp[ma][0]);
    }
	return 0;
}
