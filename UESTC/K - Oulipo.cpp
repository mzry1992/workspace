#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MaxL = 10100;
const int MaxC = 26;
struct ACautomation
{
    struct node
    {
        bool isend;
        node *next[MaxC],*fail;
        node() {fail = NULL;isend = false; memset(next,NULL,sizeof(next));}
    }*q[MaxL*MaxC],*root;
    void init() {root = new node();}
    inline int id(char ch) {return ch-'A';}
    void insert(char *str)
    {
        int i = 0;
        node *tmp = root;
        while (str[i])
        {
            if (tmp->next[id(str[i])] == NULL)
                tmp->next[id(str[i])] = new node();
            tmp = tmp->next[id(str[i])];
            i++;
        }
        tmp->isend = true;
    }
    void build_AC_automation()
    {
        int head=0,tail=1;
        root->fail = NULL;
        q[head] = root;
        while (head < tail)
        {
            node *tmp = q[head];
            node *p = NULL;
            head++;
            for (int i = 0;i < MaxC;i++)
            {
                if (tmp->next[i] != NULL)
                {
                    if (tmp == root) tmp->next[i]->fail = root;
                    else
                    {
                        p = tmp->fail;
                        while (p != NULL)
                        {
                            if (p->next[i] != NULL)
                            {
                                tmp->next[i]->fail = p->next[i];
                                break;
                            }
                            p = p->fail;
                        }
                        if (p == NULL) tmp->next[i]->fail = root;
                    }
                    q[tail++] = tmp->next[i];
                }
            }
        }
    }
    int query(char *str)
    {
        int i = 0,ans = 0;
        node *p = root;
        while (str[i])
        {
            while (p->next[id(str[i])] == NULL && p != root) p = p->fail;
            p = p->next[id(str[i])];
            if (p == NULL) p = root;
            node *tmp = p;
            while (tmp != root && tmp->isend == true)
            {
                ans++;
                tmp = tmp->fail;
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
