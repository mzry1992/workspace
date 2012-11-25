#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Edge
{
    int to,next;
};

Edge edge[1000010];
int n;
char w1[101],w2[101],s[100001];
int len1,len2,lens,minlen,dif[101],dif2[101],now,tree[11000100][26],head[11000100],L,tote,totres,res[101],reslen;
int pnow,next[101];
bool check;

int newnode()
{
    for (int i = 0; i < 26; i++)
        tree[L][i] = 0;
    head[L++] = -1;
    return L-1;
}

void addedge(int u,int v)
{
    edge[tote].to = v;
    edge[tote].next = head[u];
    head[u] = tote++;
}

void gao(int dif[],int len,int i)
{
    for (int j = 0; j < len; j++)
        dif2[(i+j)%len] = dif[j];

    now = 0;
    for (int j = 0; j < len; j++)
    {
        if (tree[now][dif2[j]] == 0)
            tree[now][dif2[j]] = newnode();
        now = tree[now][dif2[j]];
    }
    addedge(now,i);
}

void ac(int dif[],int len,int i)
{
    for (int j = 0; j < len; j++)
        dif2[(i+j)%len] = dif[j];
    now = 0;
    check = true;
    for (int j = 0; j < len; j++)
    {
        if (tree[now][dif2[j]] == 0)
        {
            check = false;
            break;
        }
        now = tree[now][dif2[j]];
    }
    if (check == false) return;

    check = false;
    for (int j = head[now]; j != -1; j = edge[j].next)
        if (i+len2-1 < edge[j].to || edge[j].to+len1-1 < i)
        {
            check = true;
            break;
        }

    if (check == false) return;

    head[now] = -1;
    totres++;
    reslen = len;
    for (int j = 0; j < len; j++)
        res[j] = dif2[j];

}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        scanf("%s%s%s",w1,w2,s);
        len1 = strlen(w1);
        len2 = strlen(w2);
        lens = strlen(s);
        totres = 0;
        L = tote = 0;
        newnode();
        for (int i = 0; i+len1 <= lens; i++)
        {
            for (int j = 0; j < len1; j++)
                dif[j] = (s[i+j]-'A'-(w1[j]-'A')+25)%26;
            pnow = next[0] = -1;
            for (int j = 1; j < len1; j++)
            {
                while (pnow >= 0 && dif[pnow+1] != dif[j])    pnow = next[pnow];
                if (dif[pnow+1] == dif[j]) pnow++;
                next[j] = pnow;
            }
            minlen = len1-next[len1-1]-1;
            if (minlen <= n)
                gao(dif,minlen,i);
            if (len1%minlen != 0 && len1 <= n)
                gao(dif,len1,i);
        }

        for (int i = 0; i+len2 <= lens && totres < 2; i++)
        {
            for (int j = 0; j < len2; j++)
                dif[j] = (s[i+j]-'A'-(w2[j]-'A')+25)%26;
            pnow = next[0] = -1;
            for (int j = 1; j < len2; j++)
            {
                while (pnow >= 0 && dif[pnow+1] != dif[j])    pnow = next[pnow];
                if (dif[pnow+1] == dif[j]) pnow++;
                next[j] = pnow;
            }
            minlen = len2-next[len2-1]-1;
            if (minlen <= n)
                ac(dif,minlen,i);
            if (len2%minlen != 0 && len2 <= n)
                ac(dif,len2,i);
        }
        if (totres == 0)
            puts("impossible");
        else if (totres == 1)
        {
            for (int j = 0,k = 0; j < lens; j++,k = (k+1)%reslen)
                printf("%c",(s[j]-'A'-(res[k]+1)+26)%26+'A');
            puts("");
        }
        else
            puts("ambiguous");
    }
    return 0;
}

