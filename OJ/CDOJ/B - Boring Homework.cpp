#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct node
{
    int ltree,rtree,key;
}buf[100];
int n,totbuf,tmp,root,w,h;
char mp[2000][2000];

int Gao(int root,int nowh)
{
    if (nowh > h)   h = nowh;
    if (buf[root].ltree != -1)
    {
        tmp = Gao(buf[root].ltree,nowh+2);
        for (int i = tmp+1;i <= w;i++)
            mp[nowh][i] = '-';
        mp[nowh][tmp] = '+';
        mp[nowh+1][tmp] = '|';
    }
    int mid = w;
    mp[nowh][mid] = 'o';
    w++;
    if (buf[root].rtree != -1)
    {
        tmp = Gao(buf[root].rtree,nowh+2);
        for (int i = mid+1;i < tmp;i++)
            mp[nowh][i] = '-';
        mp[nowh][tmp] = '+';
        mp[nowh+1][tmp] = '|';
    }
    return mid;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int i = 0;i < 2000;i++)
        for (int j = 0;j < 2000;j++)
            mp[i][j] = ' ';
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        totbuf = 0;
        root = -1;
        for (int i = 0;i < n;i++)
        {
            scanf("%d",&tmp);
            buf[totbuf].ltree = buf[totbuf].rtree = -1;
            if (root == -1)
            {
                buf[totbuf].key = tmp;
                root = totbuf;
            }
            else
            {
                int cur = root;
                while (true)
                {
                    if (tmp > buf[cur].key)
                    {
                        if (buf[cur].rtree == -1)
                        {
                            buf[cur].rtree = totbuf;
                            buf[totbuf].key = tmp;
                            break;
                        }
                        else
                            cur = buf[cur].rtree;
                    }
                    else
                    {
                        if (buf[cur].ltree == -1)
                        {
                            buf[cur].ltree = totbuf;
                            buf[totbuf].key = tmp;
                            break;
                        }
                        else
                            cur = buf[cur].ltree;
                    }
                }
            }
            totbuf++;
        }
        h = w = 0;
        Gao(0,0);
        printf("Case #%d:\n",ft);
        for (int i = 0;i <= h;i++)
        {
            int nw = w;
            while (nw >= 0 && mp[i][nw] == ' ')    nw--;
            for (int j = 0;j <= nw;j++)
            {
                printf("%c",mp[i][j]);
                mp[i][j] = ' ';
            }
            printf("\n");
        }
    }
    return 0;
}
