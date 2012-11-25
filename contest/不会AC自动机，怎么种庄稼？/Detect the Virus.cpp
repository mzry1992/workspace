#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct trie
{
    int next[40000][256],fail[40000],end[40000];
    int L,root;
    int newnode()
    {
        for (int i = 0;i < 256;i++)
            next[L][i] = -1;
        end[L++] = 0;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(int buf[],int len)
    {
        int now = root;
        for (int i = 0;i < len;i++)
        {
            if (next[now][buf[i]] == -1)
                next[now][buf[i]] = newnode();
            now = next[now][buf[i]];
        }
        end[now]++;
    }
    void build()
    {
        queue<int> Q;
        for (int i = 0;i < 256;i++)
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
            for (int i = 0;i < 256;i++)
                if (next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    int tmp[40000];
    int query(int buf[],int len)
    {
        for (int i = 0;i < L;i++)
            tmp[i] = end[i];
        int res = 0,now = root;
        for (int i = 0;i < len;i++)
        {
            now = next[now][buf[i]];
            for (int failnow = now;failnow != root;failnow = fail[failnow])
            {
                res += tmp[failnow];
                tmp[failnow] = 0;
            }
        }
        return res;
    }
};

int n;
char s[3000];
int buf[3000],buflen;
trie ac;

int getval(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
        return ch-'A';
    if (ch >= 'a' && ch <= 'z')
        return 26+ch-'a';`
    if (ch >= '0' && ch <= '9')
        return 52+ch-'0';
    if (ch == '+')
        return 62;
    return 63;
}

bool bit[25000];

void decoder()
{
    int len = strlen(s);
    int l = 0;
    for (int i = 0;i < len;i++)
    {
        if (s[i] == '=')    break;
        int val = getval(s[i]);
        for (int j = 0;j < 6;j++)
            bit[l++] = ((val>>(5-j))&1);
    }
    l = (l/8)*8;
    len = 0;
    for (int i = 0;i < l;i += 8)
    {
        int val = 0;
        for (int j = 0;j < 8;j++)
        {
            val <<= 1;
            val |= bit[i+j];
        }
        buf[len++] = val;
    }
    buflen = len;
}

int main()
{
    freopen("in.txt", "r", stdin);
    while (scanf("%d",&n) != EOF)
    {
        ac.init();
        for (int i = 0;i < n;i++)
        {
            scanf("%s",s);
            decoder();
            ac.insert(buf,buflen);
        }
        ac.build();
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
        {
            scanf("%s",s);
            decoder();
            printf("%d\n",ac.query(buf,buflen));
        }
        printf("\n");
    }
	return 0;
}
