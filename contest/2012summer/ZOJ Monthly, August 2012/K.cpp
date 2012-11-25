#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int getid(char ch)
{
    if (ch >= 'a' && ch <= 'z') return ch-'a';
    return ch-'A'+26;
}

struct AC
{
    int next[300][52],fail[300];
    bool end[300];
    int L,root;

    int newNode()
    {
        for (int i = 0; i < 52; i++)
            next[L][i] = -1;
        end[L] = false;
        return L++;
    }

    void init()
    {
        L = 0;
        root = newNode();
    }

    void insert(char ch[])
    {
        int now = root;
        for (int i = 0; ch[i] != 0; i++)
        {
            if (next[now][getid(ch[i])] == -1)
                next[now][getid(ch[i])] = newNode();
            now = next[now][getid(ch[i])];
        }
        end[now] = true;
    }

    void build()
    {
        queue<int> Q;
        for (int i = 0; i < 52; i++)
            if (next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while (!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for (int i = 0; i < 52; i++)
                if (next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
};

char A[300],B[600000];
AC ac;
int stack[600000],top,res;

int main()
{
    while (scanf("%s%s",A,B) != EOF)
    {
        ac.init();
        ac.insert(A);
        ac.build();
        top = 0;
        stack[top++] = ac.root;
        res = 0;
        int len = strlen(A);
        for (int i = 0; B[i] != 0; i++)
        {
            int now = stack[top-1];
            now = ac.next[now][getid(B[i])];
            stack[top++] = now;
            if (ac.end[now])
            {
                top -= len;
                res++;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
