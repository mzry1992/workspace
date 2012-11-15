#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MaxL = 10100;
const int MaxC = 26;
const int NIL = -1;
struct node
{
    bool isend;
    int next[MaxC],fail;
}buf[MaxL*MaxC];
int q[MaxL*MaxC],root,totbuf;
struct ACautomation
{
    void initnode(int pos)
    {
        buf[pos].isend = false;
        for (int i = 0;i < MaxC;i++)    buf[pos].next[i] = NIL;
    }
    void init(){root = totbuf = 0;initnode(root);}
    int newnode(){totbuf++;initnode(totbuf);return totbuf;}
    inline int id(char ch) {return ch-'A';}
    void insert(char *str)
    {
        int i = 0;
        int tmp = root;
        while (str[i])
        {
            if (buf[tmp].next[id(str[i])] == NIL)
                buf[tmp].next[id(str[i])] = newnode();
            tmp = buf[tmp].next[id(str[i])];
            i++;
        }
        buf[tmp].isend = true;
    }
    void build_AC_automation()
    {
        int head=0,tail=1;
        buf[root].fail = NIL;
        q[head] = root;
        while (head < tail)
        {
            int tmp = q[head];
            int p = NIL;
            head++;
            for (int i = 0;i < MaxC;i++)
            {
                if (buf[tmp].next[i] != NIL)
                {
                    if (tmp == root) buf[buf[tmp].next[i]].fail = root;
                    else
                    {
                        p = buf[tmp].fail;
                        while (p != NIL)
                        {
                            if (buf[p].next[i] != NIL)
                            {
                                buf[buf[tmp].next[i]].fail = buf[p].next[i];
                                break;
                            }
                            p = buf[p].fail;
                        }
                        if (p == NIL) buf[buf[tmp].next[i]].fail = root;
                    }
                    q[tail++] = buf[tmp].next[i];
                }
            }
        }
    }
    int query(char *str)
    {
        int i = 0,ans = 0;
        int p = root;
        while (str[i])
        {
            while (buf[p].next[id(str[i])] == NIL && p != root) p = buf[p].fail;
            p = buf[p].next[id(str[i])];
            if (p == NIL) p = root;
            int tmp = p;
            while (tmp != root && buf[tmp].isend == true)
            {
                ans++;
                tmp = buf[tmp].fail;
            }
            i++;
        }
        return ans;
    }

}g;
char W[10100],T[1000100];

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%s",W);
        scanf("%s",T);
        g.init();
        g.insert(W);
        g.build_AC_automation();
        int res = g.query(T);
        printf("%d\n",res);
    }
}
