#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

const int step[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
const int ys[9][2] = {{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
const int tys[3][3] = {{0,1,2},{3,4,5},{6,7,8}};
struct node
{
    string now;
    int step,curpos;
}now;
string updata;
map<string,int> res;
deque<node> Q;
char s[50];

node getnode(string now,int step,int curpos)
{
    node res;
    res.now = now;
    res.step = step;
    res.curpos = curpos;
    return res;
}

void BFS(string s,int curpos)
{
    int nx,ny,tx,ty;
    Q.clear();
    res.clear();
    Q.push_back(getnode(s,0,curpos));
    res[s] = 0;
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop_front();
        nx = ys[now.curpos][0];
        ny = ys[now.curpos][1];
        for (int i = 0;i < 4;i++)
        {
            tx = nx+step[i][0];
            ty = ny+step[i][1];
            if (tx >= 0 && tx <= 2 && ty >= 0 && ty <= 2)
            {
                updata = now.now;
                swap(updata[tys[nx][ny]],updata[tys[tx][ty]]);
                if (res.find(updata) == res.end())
                {
                    res[updata] = now.step+1;
                    Q.push_back(getnode(updata,now.step+1,tys[tx][ty]));
                }
            }
        }
    }
}

int main()
{
    BFS("12345678x",8);
    while (gets(s))
    {
        updata = "";
        for (int i = 0;i < 9;i++)
            updata = updata+s[2*i];
        if (res.find(updata) == res.end())  printf("unsolvable\n");
        else printf("%d\n",res[updata]);
    }
}
