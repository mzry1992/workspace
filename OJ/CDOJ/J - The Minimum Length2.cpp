#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MaxL = 1010000;
const int MaxC = 26;
struct node
{
    bool isend;
    int id;
    int next[MaxC],fail;
    node(int _id) {fail = NULL;isend = false; id = _id; memset(next,NULL,sizeof(next));}
};
struct ACautomation
{
    int q[MaxL*MaxC],root;
    node buf[MaxL*MaxC];
    void init() {root = new node(-1);}
    inline int id(char ch) {return ch-'a';}
    node* insert(char *str)
    {
        int i = 0;
        node *tmp = root;
        while (str[i])
        {
            if (tmp->next[id(str[i])] == NULL)
                tmp->next[id(str[i])] = new node(i);
            tmp = tmp->next[id(str[i])];
            i++;
        }
        tmp->isend = true;
        return tmp;
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
}g;
char W[1010000];

int main()
{
    while (scanf("%s",W) != EOF)
    {
        g.init();
        node* p = g.insert(W);
        g.build_AC_automation();
        printf("%d\n",(p->id)-(p->fail->id));
    }
}
