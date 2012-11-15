#include<cstdio>
#include<map>
using namespace std;
map<int,int> mp[100001];
bool check(int idx,int x,int y)
{
    if (!idx) return 1;
    if (mp[idx].begin()->first>=x) return 0;
    map<int,int> ::iterator it=mp[idx].lower_bound(x);
    it--;
    if (it->second<y) return 1;
    else return 0;
}
int main()
{
    int n;
    while (scanf("%d",&n) != EOF)
    {
        int l=0,r=0;
        for (int i = 0;i <= n;i++)
            mp[i].clear();
        for (int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            int tl=l,tr=r;
            while (tl<tr)
            {
                int mid=(tl+tr+1)/2;
                if (check(mid,x,y))
                    tl=mid;
                else
                    tr=mid-1;
            }
            if (tl==r) r++;
            int idx=tl+1;
            map<int,int> ::iterator itl=mp[idx].lower_bound(x),itr=itl;
            while (itr!=mp[idx].end() && itr->second>y) itr++;
            if (mp[idx].find(x)!=mp[idx].end())
                y=min(y,mp[idx][x]);
            if (itl!=itr) mp[idx].erase(itl,itr);
            if (mp[idx].find(x)==mp[idx].end() || mp[idx][x]>y)
                mp[idx][x]=y;
        }
        printf("%d\n",r);
    }
    return 0;
}
