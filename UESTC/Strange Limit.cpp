#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;

long long fact[15]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800ll,479001600ll};
int main()
{
    int p,m,flag=true;
    while (scanf("%d%d",&p,&m)>0)
    {
        if (flag) flag=0;else puts("");
        long long ans=1,fac=fact[m];
        long long tmp=p,temp;
        for (int i=2;tmp<=fac;i++)
        {
            temp=1;
            for (int j=1;j<=tmp;j++)
                temp*=p;
            tmp=temp;
            cout<<tmp<<endl;
        }
        printf("%d\n",tmp%fac);
    }
}
