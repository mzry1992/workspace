#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct node
{
    int a,b,c;
    node(){}
    node(int _a,int _b,int _c)
    {
        a = _a;
        b = _b;
        c = _c;
    }
};
int n,a[100000],t[3];
priority_queue<pair<int,int> > Q;
vector<node> res;

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    for (int i = 0; i < n;)
    {
        int cnt = 0,v = a[i];
        for (; i < n && a[i] == v; i++,cnt++);
        Q.push(make_pair(cnt,v));
    }
    pair<int,int> now1,now2,now3;
    while (true)
    {
        if (Q.empty() == true)  break;
        now1 = Q.top();
        Q.pop();
        if (Q.empty() == true)  break;
        now2 = Q.top();
        Q.pop();
        if (Q.empty() == true)  break;
        now3 = Q.top();
        Q.pop();
        t[0] = now1.second;
        t[1] = now2.second;
        t[2] = now3.second;
        sort(t,t+3);
        res.push_back(node(t[2],t[1],t[0]));
        now1.first--;
        now2.first--;
        now3.first--;
        if (now1.first > 0)
            Q.push(now1);
        if (now2.first > 0)
            Q.push(now2);
        if (now3.first > 0)
            Q.push(now3);
    }
    printf("%d\n",res.size());
    for (int i = 0;i < res.size();i++)
        printf("%d %d %d\n",res[i].a,res[i].b,res[i].c);
    return 0;
}
