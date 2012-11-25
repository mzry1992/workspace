#include <cstdio>
#include <cstring>
#include <set>
#include <map>
using namespace std;
int next[100000];
bool flag[100001];
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        memset(next,-1,4*n);
        multiset<int> heap;
        map<int,int> pre;
        int ans=0;
        memset(flag,0,m+1);
        for (int i=0; i<n; i++)
        {
            int x;
            scanf("%d",&x);
            if (pre.find(x)!=pre.end())
                next[pre[x]]=i;
            else if (x<=m)
            {
                heap.insert(i);
                flag[x]=1;
            }
            pre[x]=i;
        }
        for (int i=1; i<=m; i++)
            if (!flag[i])
                heap.insert(n);
        for (int i=0; i<n; i++)
            if (next[i]==-1)
                next[i]=n;
        for (int i=0; i<n; i++)
        {
            while (!heap.empty() && *heap.begin()==i)
                heap.erase(heap.begin());
            heap.insert(next[i]);
            if (heap.size()>m)
            {
                ans++;
                multiset<int> :: iterator it=heap.end();
                --it;
                heap.erase(it);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
