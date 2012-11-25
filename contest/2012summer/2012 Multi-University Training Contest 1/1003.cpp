#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
int num[100001];
int main()
{
    int t;
    scanf("%d",&t);
    for (int cas=1; cas<=t; cas++)
    {
        int l,n;
        scanf("%d%d",&l,&n);
        set<int> st;
        long long ans=0;
        memset(num,0,sizeof(num));
        for (int i=0,pos=0,vec=0; i<n; i++)
        {
            int typ;
            scanf("%d",&typ);
            if (typ)
            {
                if (num[pos])
                {
                    num[pos]--;
                    if (!num[pos])
                        st.erase(pos);
                    continue;
                }
                set<int> :: iterator pre,next,now;
                now=pre=next=st.insert(pos).first;
                next++;
                if (pre==st.begin() && next==st.end())
                {
                    st.erase(pre);
                    continue;
                }
                if (pre==st.begin())
                {
                    ans+=*next-pos;
                    pos=*next;
                    num[pos]--;
                    st.erase(now);
                    st.erase(next);
                    vec=1;
                }
                else if (next==st.end())
                {
                    pre--;
                    ans+=pos-*pre;
                    pos=*pre;
                    num[pos]--;
                    st.erase(pre);
                    st.erase(now);
                    vec=0;
                }
                else
                {
                    pre--;
                    if (pos-*pre+vec<=*next-pos)
                    {
                        ans+=pos-*pre;
                        pos=*pre;
                        num[pos]--;
                        st.erase(pre);
                        st.erase(now);
                        vec=0;
                    }
                    else
                    {
                        ans+=*next-pos;
                        pos=*next;
                        num[pos]--;
                        st.erase(now);
                        st.erase(next);
                        vec=1;
                    }
                }
            }
            else
            {
                int x;
                scanf("%d",&x);
                if (!num[x])
                    st.insert(x);
                num[x]++;
            }
        }
        printf("Case %d: %I64d\n",cas,ans);
    }
    return 0;
}
