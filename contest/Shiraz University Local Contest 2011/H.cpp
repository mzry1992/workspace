#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
int L,prime[100000];
bool isPrime[2000000];
int a[100000];
void getPrime()
{
    L=0;
    memset(isPrime,1,sizeof(isPrime));
    for (int i=2;L<100000;i++)
        if (isPrime[i])
        {
            prime[L++]=i;
            for (int j=i*2;j<2000000;j+=i)
                isPrime[j]=0;
        }
}
int main()
{
    getPrime();
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n,mod;
        scanf("%d%d",&n,&mod);
        for (int i=0;i<n;i++)
            a[i]=prime[i]%mod;
        stack<int> st;
        int ans=0;
        for (int i=0;i<n;i++)
        {
            while (!st.empty() && a[st.top()]<=a[i])
                st.pop();
            if (st.empty())
                ans+=i+1;
            else
                ans+=i-st.top();
            if (ans>=mod)
                ans-=mod;
            st.push(i);
        }
        printf("%d\n",ans);
    }
    return 0;
}
