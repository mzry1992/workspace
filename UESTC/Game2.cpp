#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <hash_map>
#include <map>
using namespace std;
using namespace __gnu_cxx;
struct str_hash{
    size_t operator()(const string& str) const
    {
    unsigned long __h = 0;
    for (size_t i = 0 ; i < str.size() ; i ++)
    __h = 233*__h + str[i];
    return size_t(__h);
    }
};
//hash_map<string,int,str_hash> res;
map<string,int> res;
struct node
{
    string now;
    int step;
    node(){}
    node(string _now,int _step)
        {
            now = _now;
            step = _step;
        }
};
queue<node> Q;
node now;
string updata;

string U1(string now)
{
    string res = now;
    res[0] = now[3];
    res[3] = now[6];
    res[6] = now[0];
    return res;
}

string U2(string now)
{
    string res = now;
    res[1] = now[4];
    res[4] = now[7];
    res[7] = now[1];
    return res;
}

string U3(string now)
{
    string res = now;
    res[2] = now[5];
    res[5] = now[8];
    res[8] = now[2];
    return res;
}

string L1(string now)
{
    string res = now;
    res[0] = now[1];
    res[1] = now[2];
    res[2] = now[0];
    return res;
}

string L2(string now)
{
    string res = now;
    res[3] = now[4];
    res[4] = now[5];
    res[5] = now[3];
    return res;
}

string L3(string now)
{
    string res = now;
    res[6] = now[7];
    res[7] = now[8];
    res[8] = now[6];
    return res;
}

void BFS()
{
    while (!Q.empty())  Q.pop();
    Q.push(node("123456789",0));
    res["123456789"] = 0;
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop();
        //cout << now.now << ' ' << now.step << endl;
        updata = U1(now.now);
        if (res.find(updata) == res.end())
        {
            res[updata] = now.step+1;
            Q.push(node(updata,now.step+1));
        }
        updata = U1(updata);
        if (res.find(updata) == res.end())
        {
            res[updata] = now.step+1;
            Q.push(node(updata,now.step+1));
        }
        updata = U2(now.now);
        if (res.find(updata) == res.end())
        {
            res[updata] = now.step+1;
            Q.push(node(updata,now.step+1));
        }
        updata = U2(updata);
        if (res.find(updata) == res.end())
        {
            res[updata] = now.step+1;
            Q.push(node(updata,now.step+1));
        }
        updata = U3(now.now);
        if (res.find(updata) == res.end())
        {
            res[updata] = now.step+1;
            Q.push(node(updata,now.step+1));
        }
        updata = U3(updata);
        if (res.find(updata) == res.end())
        {
            res[updata] = now.step+1;
            Q.push(node(updata,now.step+1));
        }
        updata = L1(now.now);
        if (res.find(updata) == res.end())
        {
            res[updata] = now.step+1;
            Q.push(node(updata,now.step+1));
        }
        updata = L1(updata);
        if (res.find(updata) == res.end())
        {
            res[updata] = now.step+1;
            Q.push(node(updata,now.step+1));
        }
        updata = L2(now.now);
        if (res.find(updata) == res.end())
        {
            res[updata] = now.step+1;
            Q.push(node(updata,now.step+1));
        }
        updata = L2(updata);
        if (res.find(updata) == res.end())
        {
            res[updata] = now.step+1;
            Q.push(node(updata,now.step+1));
        }
        updata = L3(now.now);
        if (res.find(updata) == res.end())
        {
            res[updata] = now.step+1;
            Q.push(node(updata,now.step+1));
        }
        updata = L3(updata);
        if (res.find(updata) == res.end())
        {
            res[updata] = now.step+1;
            Q.push(node(updata,now.step+1));
        }
    }
}

char a[3][3][2],b[3][3][2];
string init;
int cov[9],ans;
bool use[9];

void Gao(int now)
{
    if (now == 9)
    {
        //cout << init << endl;
        if (res.find(init) != res.end())
            ans = min(ans,res[init]);
        return;
    }
    if (init[now] == '*')
    {
        for (int i = 0;i < 9;i++)
            if (use[i] == false)
            {
                use[i] = true;
                init[now] = '1'+i;
                Gao(now+1);
                init[now] = '*';
                use[i] = false;
            }
    }
    else
        Gao(now+1);
}

int main()
{
    freopen("game.txt","w",stdout);
    res.clear();
    BFS();
    for (map<string,int>::iterator it = res.begin();it != res.end();it++)
        printf("%s = %d\n",it->first.c_str(),it->second);
    return 0;
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        for (int i = 0;i < 3;i++)
            for (int j = 0;j < 3;j++)
                scanf("%s",a[i][j]);
        for (int i = 0;i < 3;i++)
            for (int j = 0;j < 3;j++)
                scanf("%s",b[i][j]);
        for (int i = 0;i < 3;i++)
            for (int j = 0;j < 3;j++)
                cov[a[i][j][0]-'1'] = i*3+j;
        init.resize(9);
        for (int i = 0;i < 3;i++)
            for (int j = 0;j < 3;j++)
                init[i*3+j] = b[i][j][0];
        ans = 19921005;
        for (int i = 0;i < 9;i++)
            use[i] = false;
        for (int i = 0;i < 9;i++)
            if (init[i] != '*')
            {
                init[i] = '1'+cov[init[i]-'1'];
                use[init[i]-'1'] = true;
            }
        Gao(0);
        printf("Case #%d: ",ft);
        if (ans == 19921005)
            printf("No Solution!\n");
        else
            printf("%d\n",ans);
    }
}
