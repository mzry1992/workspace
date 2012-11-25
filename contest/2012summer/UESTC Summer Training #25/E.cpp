#include<cstdio>
#include<map>
#include<set>
#include<cstring>
using namespace std;
int inte[1000];
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int k,n;
        scanf("%d%d",&k,&n);
        map<int,int> pre;
        memset(inte,-1,4*n);
        for (int i=0; i<n; i++)
        {
            int x;
            scanf("%d",&x);
            if (pre.find(x)!=pre.end())
                inte[pre[x]]=i-1;
            pre[x]=i;
        }
        int tot=n;
        multiset<int> st;
        for (int i=0; i<n; i++)
        {
            while (!st.empty() && *st.begin()<i)
                st.erase(st.begin());
            if (st.size()>=k)
            {
                tot--;
                multiset<int> ::iterator it=st.end();
                it--;
                st.erase(it);
            }
            if (inte[i]==-1)
                continue;
            st.insert(inte[i]);
        }
        printf("%d\n",n+pre.size()-tot);
    }
    return 0;
}
