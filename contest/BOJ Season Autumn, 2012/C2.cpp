#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool calced[100000];
int dp[100000];
const int k=6;
int solve(int x)
{
    if (calced[x])
        return dp[x];
    int &ret=dp[x];
    calced[x]=1;
    if (!x)
        return ret=0;
    vector<int> ans;
    for (int i=1;i<=x;i*=k)
        ans.push_back(solve(x-i));
    sort(ans.begin(),ans.end());
    ans.resize(unique(ans.begin(),ans.end())-ans.begin());
    ret=ans.size();
    for (int i=0;i<ans.size();i++)
        if (ans[i]!=i)
        {
            ret=i;
            break;
        }
    return ret;
}
int main()
{
    int n;
    while (scanf("%d",&n),n)
        printf("%d\n",solve(n));
}
