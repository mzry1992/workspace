#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <deque>
using namespace std;

string s,t,now,updata;
int n;
string a[15],b[15];
char tmp1[15],tmp2[15];
struct node
{
    string now;
    int step;
}tnow;
deque<node> Q;
bool hash[10000010];

node getnode(string now,int step)
{
    node res;
    res.now = now;
    res.step = step;
    return res;
}

int RK(string s)
{
    int res = 0;
    for (int i = 0;i < s.size();i++)
        res = (res*29+(s[i]-'a'+1))%10000009;
    return res;
}

int BFS()
{
    Q.clear();
    memset(hash,false,sizeof(hash));
    Q.push_back(getnode(s,0));
    hash[RK(s)] = true;
    while (!Q.empty())
    {
        tnow = Q.front();
        Q.pop_front();
        now = tnow.now;
        //cout << tnow.now << ' ' << tnow.step << endl;
        if (now.size() > t.size()) continue;
        if (now == t)   return tnow.step;
        for (int i = 1;i <= n;i++)
        {
            updata = "";
            for (int j = 0;j < now.size();)
                if (j+a[i].size()-1 < now.size())
                {
                    if (now.substr(j,a[i].size()) == a[i])
                    {
                        updata = updata+b[i];
                        j += a[i].size();
                    }
                    else
                    {
                        updata = updata+now[j];
                        j++;
                    }
                }
                else
                {
                    updata = updata+now[j];
                    j++;
                }
            int tRK = RK(updata);
            //cout << updata << ' ' << tRK << endl;
            if (hash[tRK] == false)
            {
                hash[tRK] = true;
                Q.push_back(getnode(updata,tnow.step+1));
            }
        }
    }
    return -1;
}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        for (int i = 1;i <= n;i++)
        {
            scanf("%s%s",tmp1,tmp2);
            a[i] = tmp1;
            b[i] = tmp2;
        }
        scanf("%s%s",tmp1,tmp2);
        s = tmp1;
        t = tmp2;
        printf("%d\n",BFS());
    }
}
