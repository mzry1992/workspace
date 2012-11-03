#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct Trie
{
    int next[50][10],fail[50];
    bool end[50];
    int L,root;

    int newNode()
    {
        for (int i = 0;i < 10;i++)
            next[L][i] = -1;
        end[L] = false;
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
        for (int i = 0;s[i] != 0;i++)
        {
            if (next[now][s[i]-'0'] == -1)
                next[now][s[i]-'0'] = newNode();
            now = next[now][s[i]-'0'];
        }
        end[now] = true;
    }

    void Build()
    {
        queue<int> Q;
        for (int i = 0;i < 10;i++)
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
            end[now] |= end[fail[now]];
            for (int i = 0;i < 10;i++)
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

long long nl,nr;
char tmp[22],A[22],B[22];
Trie ac;

long long dp[20][2][2][2][50];
long long DP(int pos,int u,int d,int start,int acpos)
{
    if (pos == 20)
        return start == 1 && ac.end[acpos];

    long long& res = dp[pos][u][d][start][acpos];
    if (res != -1)  return res;

    res = 0;

    int op = 0,ed = 9;
    if (u == 1) ed = B[pos]-'0';
    if (d == 1) op = A[pos]-'0';

    for (int i = op;i <= ed;i++)
    {
        int nu = (u == 1 && i == ed),nd = (d == 1 && i == op),ns = start;
        if (i == 0)
        {
            if (ns == 1)    continue;
        }
        else
            ns = 1;

        res += DP(pos+1,nu,nd,ns,ac.next[acpos][i]);
    }

    return res;
}

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    scanf("%lld%lld",&nl,&nr);
        sprintf(A,"%020lld",nl);
        sprintf(B,"%020lld",nr);

	    ac.Init();
	    for (int i = 0;i < 2;i++)
	    {
            scanf("%s",tmp);
            ac.Insert(tmp);
	    }
	    ac.Build();

        for (int i = 0;i < ac.L;i++)
        {
            if (ac.end[i])
                for (int j = 0;j < 10;j++)
                    ac.next[i][j] = i;
        }

        memset(dp,-1,sizeof(dp));
        printf("%lld\n",DP(0,1,1,0,0));
	}
    return 0;
}

