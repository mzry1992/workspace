/*
ID: muziriy3
PROG: clocks
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

int a[9];
struct node
{
    int a[9];
    string step;
};
deque<node> Q;
bool hash[300000];
const string c[9] = {"ABDE","ABC","BCEF","ADG","BDEFH","CFI","DEGH","GHI","EFHI"};

int gethash(node now)
{
    int res = 0;
    int bit = 1;
    for (int i = 0;i < 9;i++)
    {
        res += now.a[i]*bit;
        bit *= 4;
    }
    return res;
}

node getnode(int a[],string step)
{
    node res;
    for (int i = 0;i < 9;i++)
        res.a[i] = a[i];
    res.step = step;
    return res;
}

node updata(node now,int w)
{
    node res;
    for (int i = 0;i < 9;i++)
        res.a[i] = now.a[i];
    res.step = now.step+(char)(w+'1');
    for (int i = 0;i < c[w].size();i++)
    {
        res.a[c[w][i]-'A']++;
        res.a[c[w][i]-'A'] %= 4;
    }
    return res;
}

string BFS()
{
    Q.clear();
    memset(hash,false,sizeof(hash));
    Q.push_back(getnode(a,""));
    hash[gethash(getnode(a,""))] = true;
    while (!Q.empty())
    {
        node now = Q.front();
        Q.pop_front();
        bool flag = true;
        for (int i = 0;i < 9;i++)
        if (now.a[i] != 3)  flag = false;
        if (flag == true)   return now.step;
        for (int i = (now.step.size() == 0)?0:(now.step[now.step.size()-1]-'1');i < 9;i++)
        {
            node upd = updata(now,i);
            if (hash[gethash(upd)] == false)
            {
                hash[gethash(upd)] = true;
                Q.push_back(upd);
            }
        }
    }
}

int main()
{
    freopen("clocks.in","r",stdin);
    freopen("clocks.out","w",stdout);
    for (int i = 0;i < 9;i++)
    {
        scanf("%d",&a[i]);
        a[i] = a[i]/3-1;
    }
    string res = BFS();
    printf("%c",res[0]);
    for (int i = 1;i < res.size();i++)
        printf(" %c",res[i]);
    printf("\n");
}
