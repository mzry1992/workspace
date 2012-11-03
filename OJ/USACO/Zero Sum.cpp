/*
ID: muziriy3
PROG: zerosum
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <deque>
#include <string>
using namespace std;

int n;

void DFS(int now,int pre,int pre_pre,int op,string res)
{
    if (now == n+1)
    {
        int sum;
        if (op == 0)
            sum = pre_pre+pre;
        else
            sum = pre_pre-pre;
        if (sum == 0)
            printf("%s\n",res.c_str());
    }
    else
    {
        DFS(now+1,pre*10+now,pre_pre,op,res+" "+char(now+'0'));
        int t_pre_pre;
        if (op == 0)
            t_pre_pre = pre_pre+pre;
        else
            t_pre_pre = pre_pre-pre;
        DFS(now+1,now,t_pre_pre,0,res+"+"+char(now+'0'));
        DFS(now+1,now,t_pre_pre,1,res+"-"+char(now+'0'));
    }
}

int main()
{
    freopen("zerosum.in","r",stdin);
    freopen("zerosum.out","w",stdout);
    scanf("%d",&n);
    DFS(2,1,0,0,"1");
}
