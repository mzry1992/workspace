#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=1000;
int mp1[MAXN][MAXN],mp2[MAXN][MAXN];
int num[MAXN][MAXN];
int in1[MAXN],in2[MAXN];
int ranks[MAXN];
vector <int>  to,fr;
inline int readint()
{
    char ch = getchar();
    while (ch < '0' || ch > '9')    ch = getchar();
    int wg = ch-'0';
    ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        wg = wg*10+ch-'0';
        ch = getchar();
    }
    return wg;
}
vector <int> topsort(int mp[][MAXN],int in[],int n)
{
    queue<int> que;
    for (int i=0;i<n;i++)
        if (!in[i]) que.push(i);
    vector<int> ret;
    while (!que.empty())
    {
        int u=que.front();
        ret.push_back(u);
        que.pop();
        for (int i=0;i<n;i++)
            if (mp[u][i])
            {
                in[i]--;
                if (!in[i])
                    que.push(i);
            }
    }
    return ret;
}
vector <int> get_sort(vector<int> s,vector<int> t)
{
    vector<int> ret;
    for (int i=0;i<t.size();i++)
        ranks[t[i]]=i;
    for (int i=0;i<s.size();i++)
        for (int j=0;j<(int)s.size()-1;j++)
            if (ranks[s[j]]>ranks[s[j+1]])
            {
                if (mp1[s[j]][s[j+1]]>1)
                    ret.push_back(num[s[j]][s[j+1]]);
                swap(s[j],s[j+1]);
            }
    return ret;
}
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        bool flag=1;
        memset(mp1,0,sizeof(mp1));
        memset(mp2,0,sizeof(mp2));
        memset(in1,0,sizeof(in1));
        memset(in2,0,sizeof(in2));
        for (int i=0;i<m;i++)
        {
            int x,y,z;
            x=readint()-1;
            y=readint()-1;
            z=readint();
            if (mp1[x][y] && z)
                flag=0;
            if (z)
            {
                mp2[y][x]=1;
                in2[x]++;
            }
            else
            {
                mp2[x][y]=1;
                in2[y]++;
            }
            mp1[x][y]=z+1;
            num[x][y]=i+1;
            in1[y]++;
        }
        if (!flag)
        {
            puts("-1\n");
            continue;
        }
        fr=topsort(mp1,in1,n);
        to=topsort(mp2,in2,n);
        vector<int> ans=get_sort(fr,to);
        printf("%d\n",ans.size());
        for (int i=0;i<ans.size();i++)
            printf("%d ",ans[i]);
        puts("");
        puts("");
    }
    return 0;
}
