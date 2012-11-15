#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
char commad[20],ch;
struct node
{
    char ch;
    int left,right;
}buf[2000000];
int totbuf,cur;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        totbuf = 0;
        cur = 0;
        memset(buf,0,sizeof(buf));
        bool first = true;
        buf[0].left = -1;
        buf[0].right = -1;
        for (int i = 1;i <= n;i++)
        {
            scanf("%s",commad);
            if (commad[0] == 'I')
            {
                scanf(" %c",&ch);
                char tch = ch;
                if (first)
                {
                    totbuf++;
                    buf[totbuf].left = 0;
                    buf[totbuf].right = -1;
                    buf[totbuf].ch = tch;
                    buf[0].right = totbuf;
                    cur = totbuf;
                    first = false;
                }
                else
                {
                    totbuf++;
                    buf[totbuf].left = cur;
                    buf[totbuf].right = buf[cur].right;
                    buf[buf[cur].right].left = totbuf;
                    buf[totbuf].ch = tch;
                    buf[cur].right = totbuf;
                    cur = totbuf;
                }
            }
            else if (commad[0] == 'L')
            {
                if (buf[cur].left != -1)
                    cur = buf[cur].left;
            }
            else if (commad[0] == 'R')
            {
                if (buf[cur].right != -1)
                    cur = buf[cur].right;
            }
            else
            {
                if (buf[cur].right != -1)
                {
                    int tcur = buf[cur].right;
                    buf[buf[tcur].left].right = buf[tcur].right;
                    buf[buf[tcur].right].left = buf[tcur].left;
                }
            }
        }
        printf("Case #%d: ",ft);
        if (buf[0].right != -1)
        for (cur = buf[0].right;cur != -1;cur = buf[cur].right)
            putchar(buf[cur].ch);
        puts("");
    }
}
