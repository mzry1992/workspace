#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int kth;
char mp[6][6],s[6];

struct Trie
{
    int next[40000][26];
    bool flag[40000];
    int L,root;

    int newNode()
    {
        for (int i = 0;i < 26;i++)
            next[L][i] = -1;
        flag[L] = false;
        return L++;
    }
    void Init()
    {
        L = 0;
        root = newNode();
    }
    void Insert(char s[])
    {
        int now = root;
        for (int i = 0;i < 5;i++)
        {
            if (next[now][s[i]-'A'] == -1)
                next[now][s[i]-'A'] = newNode();
            now = next[now][s[i]-'A'];
        }
    }
    void Find(char s[])
    {
        int now = root;
        for (int i = 0;i < 5;i++)
        {
            if (next[now][s[i]-'A'] == -1)
                return;
            now = next[now][s[i]-'A'];
        }
        flag[now] = true;
    }

    char s[10];
    int find;
    bool DFS(int now,int pos)
    {
        if (pos == 5)
        {
            if (flag[now] == true)
            {
                s[pos] = 0;

                find++;
                if (find == kth)
                {
                    puts(s);
                    return true;
                }
            }
            return false;
        }
        for (int i = 0;i < 26;i++)
            if (next[now][i] != -1)
            {
                s[pos] = 'A'+i;
                if (DFS(next[now][i],pos+1))
                    return true;
            }
        return false;
    }
    void Solve(int kth)
    {
        find = 0;
        if (DFS(root,0) == false)
            puts("NO");
    }
};
Trie ac;
void gen(int now,int haha)
{
    if (now == 5)
    {
        s[now] = 0;
        if (haha == 0)
            ac.Insert(s);
        else
            ac.Find(s);
        return;
    }
    for (int i = 0;i < 6;i++)
    {
        s[now] = mp[i][now];
        gen(now+1,haha);
    }
}

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
        scanf("%d",&kth);
        ac.Init();

        for (int i = 0;i < 6;i++)
            scanf("%s",mp[i]);
        gen(0,0);

        for (int i = 0;i < 6;i++)
            scanf("%s",mp[i]);
        gen(0,1);

        ac.Solve(kth);
	}
    return 0;
}
