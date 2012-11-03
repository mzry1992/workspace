#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<set>
#include<algorithm>
#include<iostream>
using namespace std;

struct Circle
{
    int x,y,r;
} cirs[50010];
struct Node
{
    int id;
    int type;
    Node() {}
    Node(int _id ,int _tp)
    {
        id = _id ;
        type = _tp;
    }
};
struct Event
{
    int x,id,type;
} events[50010*2];
bool operator<(const Event &a ,const Event &b)
{
    return a.x < b.x;
}
int xline;

inline double getY(int x,int y ,int r ,int type)
{
    int dx = x-xline;
    return y +type*sqrt((double)r*r - (double)dx*dx);
}
bool operator<(const Node &a,const Node &b)   // type = 1 up //type = -1 down
{
    double ya =getY(cirs[a.id].x , cirs[a.id].y,cirs[a.id].r,a.type) ,
               yb = getY(cirs[b.id].x , cirs[b.id].y,cirs[b.id].r , b.type);
    if(fabs(ya - yb) < 1e-15) return a.type < b.type;
    else return ya < yb ;
}

set<Node> tree;
int dep[50010];
int main()
{
    int T;
    int n ;
    while(scanf("%d",&n) == 1)
    {
        tree.clear();
        int eL = 0;
        for(int i = 0; i < n ; i++)
        {
            scanf("%d%d%d",&cirs[i].x,&cirs[i].y ,&cirs[i].r);
            dep[i] = 0;
            events[eL].id = i;
            events[eL].type = 1;
            events[eL].x = cirs[i].x -cirs[i].r;
            eL++;
            events[eL].id = i;
            events[eL].type = -1;
            events[eL].x = cirs[i].x +cirs[i].r;
            eL++;
        }
        sort(events, events + eL);
        for(int i = 0 ; i < eL; i++)
        {
            xline = events[i].x;
            int id = events[i].id;
            if(events[i].type == -1)
            {
                tree.erase(Node(id,1));
                tree.erase(Node(id,-1));
                continue;
            }
            set<Node>::iterator itu = tree.insert(Node(id,1)).first;
            set<Node>::iterator tmp = itu , nxt;
            nxt = ++tmp;
            if(itu == tree.begin() || nxt == tree.end())
            {
                dep[id] = 1;
            }
            else
            {
                --itu;
                if(itu->id == nxt->id)
                    dep[id] = dep[itu->id]+1;
                else dep[id] = max(dep[itu->id] , dep[nxt->id]);
            }
            tree.insert(Node(id , -1));
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans = max(ans,dep[i]);
        printf("%d\n",ans);
    }
    return 0;
}
