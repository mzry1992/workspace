#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
const int a[8][2]={-1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1};
int mp[4][4];
int pow[17];
struct hash_map
{
    const static int mod=1000007;
    int head[mod];
    struct hash_tables
    {
        int next;
        int s;
        bool col;
        int value;
    } ele[500000];
    int N;
    int getHash(int s,bool col)
    {
        return (s*2+col)%mod;//小心负数
    }
    void init()
    {
        memset(head,255,sizeof(head));
        N=0;
    }
    int find(int s,bool col)
    {
        for (int i=head[getHash(s,col)]; i!=-1; i=ele[i].next)
            if (ele[i].s==s && ele[i].col==col) return i;
        return -1;
    }
    int len(int s,bool col)
    {
        int idx=find(s,col);
        return ele[idx].value;
    }
    void insert(int s,bool col,int len)
    {
        int tmp=getHash(s,col);
        ele[N].s=s;
        ele[N].col=col;
        ele[N].value=len;
        ele[N].next=head[tmp];
        head[tmp]=N++;
    }
}dis;
void getMap(int x)
{
    for (int i=0;i < 16;x/=3,i++)
        mp[i/4][i%4]=x%3;
}
bool check(int x,int y)
{
    if (x==-1 || y==-1 || x==4 || y==4)
        return 0;
    else
        return mp[x][y]==2;
}
int setBit(int s,int pos,int num)
{
    return s/pow[pos+1]*pow[pos+1]+num*pow[pos]+s%pow[pos];
}
int bfs(int s,int t)
{
    queue<pair<int,bool> >que;
    que.push(make_pair(s,0));
    dis.init();
    dis.insert(s,0,0);
    while (!que.empty())
    {
        int u=que.front().first;
        bool col=que.front().second;
        int len=dis.len(u,col);
        if (u==t)
            return len;
        que.pop();
        getMap(u);
        for (int i=0;i<16;i++)
        {
            int ux=i/4,uy=i%4;
            if (mp[ux][uy]==col)
                for (int j=0;j<8;j++)
                {
                    int vx=ux,vy=uy;
                    while (check(vx+a[j][0],vy+a[j][1]))
                    {
                        vx+=a[j][0];
                        vy+=a[j][1];
                    }
                    int v=setBit(setBit(u,i,2),vx*4+vy,col);
                    if (dis.find(v,col)==-1)
                    {
                        dis.insert(v,!col,len+1);
                        que.push(make_pair(v,!col));
                    }
                }

        }
    }
    return -1;
}
int getBit(string s)
{
    int ret=0;
    for (int i=0;i<16;i++)
    {
        ret*=3;
        if (s[i]=='b')
            ret++;
        else if (s[i]=='*')
            ret+=2;
    }
    return ret;
}
int main()
{
    pow[0]=1;
    for (int i=1;i<=16;i++)
        pow[i]=pow[i-1]*3;
    int t;
    scanf("%d",&t);
    while (t--)
    {
        string s="";
        for (int i=0;i<4;i++)
        {
            char c[5];
            scanf("%s",c);
            s+=c;
        }
        int S=getBit(s);
        s="";
        for (int i=0;i<4;i++)
        {
            char c[5];
            scanf("%s",c);
            s+=c;
        }
        int T=getBit(s);
        printf("%d\n",bfs(S,T));
    }
    return 0;
}
