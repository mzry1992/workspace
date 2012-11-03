#include <cstdio>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
struct Block
{
    int x,h;
    bool operator<(const Block &a)const
    {
        return x<a.x;
    }
}block[100000];
int lef[100000],rig[100000];
int dp[100001];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
            scanf("%d%d",&block[i].x,&block[i].h);
        sort(block,block+n);
        stack<int> st;
        lef[0]=0;
        st.push(0);
        for (int i=1;i<n;i++)
        {
            lef[i]=i;
            while (!st.empty() && block[i].x-block[i].h<=block[st.top()].x)
            {
                lef[i]=lef[st.top()];
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty())
            st.pop();
        rig[n-1]=n-1;
        st.push(n-1);
        for (int i=n-2;i>=0;i--)
        {
            rig[i]=i;
            while (!st.empty() && block[i].x+block[i].h>=block[st.top()].x)
            {
                rig[i]=rig[st.top()];
                st.pop();
            }
            st.push(i);
        }
        dp[0]=0;
        priority_queue<pair<int,int> > que;
        for (int i=1;i<=n;i++)
        {
            dp[i]=dp[lef[i-1]]+1;
            if (!que.empty())
            while (!que.empty() && que.top().second<i-1)
                que.pop();
            if (!que.empty())
                dp[i]=min(dp[i],-que.top().first+1);
            que.push(make_pair(-dp[i-1],rig[i-1]));
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
