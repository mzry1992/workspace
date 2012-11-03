#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int n,k,a[1001],b[1001];
struct node
{
    int val,id,tim;
    node(){}
    node(int _val,int _id,int _tim)
        {
            val = _val;
            id = _id;
            tim = _tim;
        }
}now;
struct cmp
{
    bool operator () (node ta,node tb)
    {
        return (ta.val > tb.val);
    }
};
priority_queue<node,vector<node>,cmp> Q;

int main()
{
    while (scanf("%d%d",&n,&k) != EOF)
    {
        while (!Q.empty())  Q.pop();
        for (int i = 1;i <= n;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            Q.push(node(a[i]+b[i],i,1));
        }
        while (true)
        {
            now = Q.top();
            Q.pop();
            for (int i = now.tim+1;now.val+b[now.id]*(i-now.tim) < Q.top().val;i++)
                Q.push(node(now.val+b[now.id]*(i-now.tim),now.id,i));
        }
    }
}
