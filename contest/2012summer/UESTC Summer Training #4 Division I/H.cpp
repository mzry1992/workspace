#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m;
char s[705][705];
char mp[1405][1405],ss[1405];
int ma[2][1405][1405];
int lent[1405];
int col[1405][1405][11],hor[1405][1405][11];
int odd[705],even[705],Onum,Enum;
void init(int kind,int x)
{
    int i,j;
    int N=2*max(n,m)+1,k=1,l=0;
    for (i=0; i<N; i++)
    {
        if(kind==0)
            hor[x][i][0]=ma[1][x][i];
        else
            col[x][i][0]=ma[0][i][x];
        if (i+1>k*2)
        {
            k*=2;
            l++;
        }
        lent[i+1]=l;
    }
    if(kind==0)
    {
        for (j=1; (1<<j)-1<N; j++)
            for (i=0; i+(1<<j)-1<N; i++)
                hor[x][i][j]=min(hor[x][i][j-1],hor[x][i+(1<<(j-1))][j-1]);
    }
    else
    {
        for (j=1; (1<<j)-1<N; j++)
            for (i=0; i+(1<<j)-1<N; i++)
                col[x][i][j]=min(col[x][i][j-1],col[x][i+(1<<(j-1))][j-1]);
    }
}
int fint(int kind,int l,int x,int y)
{
    int k=lent[y-x+1];
    if(kind==0)
        return min(hor[l][x][k],hor[l][y-(1<<k)+1][k]);
    else
        return min(col[l][x][k],col[l][y-(1<<k)+1][k]);
}

char str[1500];
int P[1500];

void manacher()
{
    int nlen = 0;
    str[nlen++] = '$';
    for (int i = 0; ss[i] != 0; i++)
        str[nlen++] = ss[i];
    P[1] = 1;
    int mx = 0;
    int id = 0;
    for (int i = 1; i < nlen; i++)
    {
        if (mx > i)
            P[i] = min(P[id*2-i],mx-i);
        else
            P[i] = 1;
        for (; str[i-P[i]] == str[i+P[i]]; P[i]++);
        if (P[i]+i > mx)
        {
            mx = P[i]+i;
            id = i;
        }
    }
}

void solve(int l,int k)
{
    int i;
    if(l==0)
        for(i=0; i<2*m+1; i++)
            ss[i]=mp[k][i];
    else
        for(i=0; i<2*n+1; i++)
            ss[i]=mp[i][k];
    ss[i]='\0';
    manacher();
    int j,len=strlen(ss);
    for(i=0; i<len; i++)
    {
        if(l==0)
            ma[0][k][i]=P[i+1];
        else
            ma[1][i][k]=P[i+1];
    }
}
int main()
{
    int i;
    Onum=Enum=0;
    for(i=0; i<=700; i++)
    {
        if(i%2==0)
            even[Enum++]=i;
        else
            odd[Onum++]=i;
    }
    while(scanf("%d%d",&n,&m)==2)
    {
        gets(s[0]);
        for(i=0; i<n; i++)
            gets(s[i]);
        int j;
        for(i=0; i<2*n+1; i++)
        {
            for(j=0; j<2*m+1; j++)
            {
                if(i%2==0)
                    mp[i][j]='#';
                else
                {
                    if(j%2==0)
                        mp[i][j]='#';
                    else
                        mp[i][j]=s[i/2][j/2];
                }
            }
        }
        for(i=0; i<2*n+1; i++)
            solve(0,i);
        for(j=0; j<2*m+1; j++)
            solve(1,j);
        for(i=0; i<2*n+1; i++)
            init(0,i);
        for(j=0; j<2*m+1; j++)
            init(1,j);
        int Omidx,Omidy,ans1=1;
        for(i=1; i<2*n+1; i+=2)
            for(j=1; j<2*m+1; j+=2)
            {
                while(ans1<=ma[0][i][j]&&ans1<=min(n,m))
                {
                    int k1=fint(0,i,j-ans1+1,j+ans1-1);
                    int k2=fint(1,j,i-ans1+1,i+ans1-1);
                    if(min(k1,k2)>=ans1)
                    {
                        Omidx=i;
                        Omidy=j;
                        ans1+=2;
                    }
                    else
                        break;
                }
            }
        int Emidx,Emidy,ans2=2;
        for(i=0; i<2*n+1; i+=2)
            for(j=0; j<2*m+1; j+=2)
            {
                while(ans2<=ma[0][i][j]&&ans2<=min(n,m))
                {
                    int k1=fint(0,i,j-ans2+1,j+ans2-1);
                    int k2=fint(1,j,i-ans2+1,i+ans2-1);
                    if(min(k1,k2)>=ans2)
                    {
                        Emidx=i;
                        Emidy=j;
                        ans2+=2;
                    }
                    else
                        break;
                }
            }
        ans1-=2;ans2-=2;
        if(ans1>ans2)
            printf("%d %d %d %d\n",(Omidx-ans1+1)/2+1,(Omidy-ans1+1)/2+1,(Omidx+ans1-1)/2+1,(Omidy+ans1-1)/2+1);
        else
            printf("%d %d %d %d\n",(Emidx-ans2+1)/2+1,(Emidy-ans2+1)/2+1,(Emidx+ans2-1)/2+1,(Emidy+ans2-1)/2+1);
    }
    return 0;
}
