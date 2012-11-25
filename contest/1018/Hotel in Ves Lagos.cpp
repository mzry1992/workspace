#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
long long dp[20];
int main()
{
    //freopen("out.txt","w",stdout);
    dp[0]=1;
    dp[1]=10;
    for (int i=2;i<20;i++)
        dp[i]=10*dp[i-1]-dp[i-2];
    //for (int i=0;i<20;i++)
    //    cout<<dp[i]<<endl;
    int t;
    scanf("%d",&t);
    while (t--)
    {
        long long x;
        cin >> x;
        string out = "";
        bool flag=0;
        for (int i=19;i>=0;i--)
        {
            if (dp[i]>x)
            {
                out+='0';
                flag=0;
                continue;
            }
            x-=dp[i];
            if (x<dp[i]-dp[i-1])
            {
                out+='1';
                flag=1;
                continue;
            }
            x-=dp[i]-dp[i-1];
            if (flag)
                if (x/dp[i])
                    out+='3'+x/dp[i];
                else
                    out+='2';
            else
                out+='2'+x/dp[i];
            x%=dp[i];
            flag=0;
        }
        for (int i = 0;i < out.size();i++)
            if (out[i] != '0')
            {
                printf("%s\n",out.c_str()+i);
                break;
            }
        //cout<<out<<endl;
    }
    return 0;
}
