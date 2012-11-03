#include <cstdio>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;
int a[200001],lefmax[200001],rigmax[200001],lefb[200001],rigb[200001];
long long sum[200001],suml[200001],sumr[200001];
long long ans[200000];
int main()
{
    int n,k;
    int cas=0;
    while (scanf("%d%d",&n,&k),n)
    {
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        lefmax[1]=sum[1]=a[1];
        for (int i=2;i<=n;i++)
        {
            sum[i]=sum[i-1]+a[i];
            lefmax[i]=max(lefmax[i-1],a[i]);
        }
        rigmax[n]=a[n];
        for (int i=n-1;i;i--)
            rigmax[i]=max(rigmax[i+1],a[i]);
        sum[0]=suml[0]=sumr[0]=0;
        suml[1]=0;
        for (int i=2;i<=n;i++)
            suml[i]=max(0,lefmax[i-1]-a[i]);
        for (int i=2;i<=n;i++)
            suml[i]+=suml[i-1];
        sumr[n]=0;
        for (int i=n-1;i;i--)
            sumr[i]=max(0,rigmax[i+1]-a[i]);
        for (int i=2;i<=n;i++)
            sumr[i]+=sumr[i-1];
        stack<int> st;
        lefb[1]=0;
        st.push(1);
        for (int i=2;i<=n;i++)
        {
            while (!st.empty() && a[st.top()]<=a[i])
                st.pop();
            if (st.empty())
                lefb[i]=0;
            else
                lefb[i]=st.top();
            st.push(i);
        }
        while (!st.empty())
            st.pop();
        rigb[n]=n+1;
        st.push(n);
        for (int i=n-1;i;i--)
        {
            while (!st.empty() && a[st.top()]<=a[i])
                st.pop();
            if (st.empty())
                rigb[i]=n+1;
            else
                rigb[i]=st.top();
            st.push(i);
        }
        for (int i=0;i<n;i++)
        {
            int idx=i+1;
            int lef_bound=lefb[idx],rig_bound=rigb[idx];
            if (lef_bound==0)
                ans[i]=suml[idx-1];
            else
                ans[i]=(long long)(idx-1-lef_bound)*a[idx]-sum[idx-1]+sum[lef_bound];
            if (rig_bound==n+1)
                ans[i]+=sumr[n]-sumr[idx];
            else
                ans[i]+=(long long)(rig_bound-1-idx)*a[idx]-sum[rig_bound-1]+sum[idx];
        }
        /*for (int i=0;i<n;i++)
            printf("%lld ",ans[i]);
        puts("");*/
        sort(ans,ans+n);
        printf("Case %d: ",++cas);
        cout<<ans[n-k]<<endl;
    }
    return 0;
}
