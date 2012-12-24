#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
const int CHAR=9;
const int TOTLEN=40;
struct Vertex
{
    Vertex *fail,*next[CHAR];
    bool end[2];
    int id;
    Vertex(){}
    Vertex(int _id)
    {
        fail=0;
        end[0]=end[1]=0;
        id=_id;
        memset(next,0,sizeof(next));
    }
};
int size;
Vertex vertex[TOTLEN+1];
void init()
{
    vertex[0]=Vertex(0);
    size=1;
}
void add(Vertex *pos,int cha)
{
    vertex[size]=Vertex(size);
    pos->next[cha]=&vertex[size++];
}
void add(string s,bool flag)
{
    int l=s.size();
    Vertex *pos=&vertex[0];
    for (int i=0; i<l; i++)
    {
        if (pos->next[s[i]-'1']==NULL)
            add(pos,s[i]-'1');
        pos=pos->next[s[i]-'1'];
    }
    pos->end[flag]=1;
}
void bfs()
{
    queue<Vertex *> que;
    Vertex *u=&vertex[0];
    for (int i=0; i<CHAR; i++)
        if (u->next[i]!=NULL)
        {
            que.push(u->next[i]);
            u->next[i]->fail=u;
        }
        else
            u->next[i]=u;
    u->fail=NULL;
    while (!que.empty())
    {
        u=que.front();
        que.pop();
        for (int i=0; i<CHAR; i++)
            if (u->next[i]!=NULL)
            {
                que.push(u->next[i]);
                u->next[i]->fail=u->fail->next[i];
            }
            else
                u->next[i]=u->fail->next[i];
    }
}
string bot,top;
bool calced[20][2][2][2][2][3][2][40];
long long dp[20][2][2][2][2][3][2][40];
long long solve(int len,bool b,bool t,bool rb,bool rt,int flag,bool rflag,int pos)
{
    if (calced[len][b][t][rb][rt][flag][rflag][pos])
        return dp[len][b][t][rb][rt][flag][rflag][pos];
    calced[len][b][t][rb][rt][flag][rflag][pos]=1;
    long long &ret=dp[len][b][t][rb][rt][flag][rflag][pos]=0;
    if (len==bot.length())
        return ret=(flag==1||(rb&&rt&&rflag));
    for (int i=0;i<9;i++)
    {
        int npos=vertex[pos].next[i]->id,nflag=flag;
        if (!flag && vertex[npos].end[0])
            nflag=1;
        if (b && i+'1'<bot[len])
            nflag=2;
        if (t && i+'1'>top[len])
            nflag=2;
        ret+=solve(len+1,b&&(i+'1'==bot[len]),t&&(i+'1'==top[len]),(i+'1'>bot[bot.size()-len-1])||(i+'1'==bot[bot.size()-len-1]&&rb),(i+'1'<top[top.size()-len-1])||(i+'1'==top[top.size()-len-1] && rt),nflag,rflag||vertex[npos].end[1],npos);
    }
    return ret;
}
int main()
{
//	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
    int t;
    scanf("%d",&t);
    for (int cas=1;cas<=t;cas++)
    {
        init();
        long long a,b,c,d;
        cin>>a>>b>>c>>d;
        string s;
        stringstream s1,s2;
        s1<<c;
        s2<<d;
        s=s1.str();
        add(s,0);
        s=s2.str();
        reverse(s.begin(),s.end());
        add(s,1);
        bfs();
        stringstream s3,s4;
        s3<<a;
        s4<<b;
        long long ans=0;
        for (int i=s3.str().length();i<=s4.str().length();i++)
        {
            if (i==s3.str().length())
                bot=s3.str();
            else
                bot=string(i,'1');
            if (i==s4.str().length())
                top=s4.str();
            else
                top=string(i,'9');
            memset(calced,0,sizeof(calced));
            ans+=solve(0,1,1,1,1,0,0,0);
        }
        cout<<"Case #"<<cas<<": "<<ans<<endl;
    }
    return 0;
}
