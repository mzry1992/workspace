#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct node
{
    int id;
    int next;
    int pre;
}buf[5000];
int now;
int n,m;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        buf[1].id = 1;
        buf[1].next = 2;
        buf[1].pre = n+2;
        for (int i = 2;i < n+2;i++)
            buf[i].id = i,buf[i].next = i+1,buf[i].pre = i-1;
        buf[n+2].id = n+2;
        buf[n+2].next = 1;
        buf[n+2].pre = n+1;
        now = 1;
        for (int i = 1;i <= n;i++)
        {
            for (int j = 1;j < m;j++)
                now = buf[now].next;
            buf[buf[now].pre].next = buf[now].next;
            buf[buf[now].next].pre = buf[now].pre;
            now = buf[now].next;
        }
        int a,b;
        a = buf[now].id;
        b = buf[buf[now].next].id;
        printf("%d %d\n",(a<b)?a:b,(a>b)?a:b);
    }
}
