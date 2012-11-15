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
    int nextid;
    node *next,*fail;
    node(int _id,int _nextid) {fail = NULL;isend = false; id = _id; nextid = _nextid; next = NULL;}
};
struct ACautomation
{
    node *q[MaxL],*root;
    void init() {root = new node(-1,-1);}
    inline int id(char ch) {return ch-'a';}
    node* insert(char *str)
    {
        int i = 0;
        node *tmp = root;
        while (str[i])
        {
            if (tmp->next == NULL)
                tmp->next = new node(i,id(str[i]));
            tmp = tmp->next;
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
                if (tmp->next != NULL)
                {
                    if (tmp == root) tmp->next->fail = root;
                    else
                    {
                        p = tmp->fail;
                        while (p->nextid != tmp->nextid)
                        {
                            if (p->next != NULL)
                            {
                                tmp->next->fail = p->next;
                                break;
                            }
                            p = p->fail;
                        }
                        if (p == NULL) tmp->next->fail = root;
                    }
                    q[tail++] = tmp->next;
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

