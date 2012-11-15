#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int a[1030],b[1030];
int main()
{
    int n,k;
    while (scanf("%d%d",&n,&k)>0)
    {
        int maxi=0,mini=3000;
        int cnt=(1<<n);
        for (int i=0;i<cnt;i++)
        {
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        sort(a,a+cnt);
        if (a[cnt-1]==b[k]) maxi=n;
        else maxi=0;
        int c=0;
        //printf("%d\n",cnt);
        for (int i=0;i<cnt;i++)
        {
            if (a[i]==b[k])
            {
                c=i;break;
            }
        }
        int ans=0;
        //printf("%d\n",c);
        //c=4;
        c++;
        while (c>1)
        {
            ans++;
            c/=2;
        }
        //cout<<c<<endl;
        printf("%d %d\n",maxi,ans);
    }
}
