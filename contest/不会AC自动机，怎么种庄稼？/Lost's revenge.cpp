#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct trie
{
    int next[600][4],fail[600],end[600];
    int L,root;
    int charid(char ch)
    {
        if (ch == 'A')  return 0;
        if (ch == 'T')  return 1;
        if (ch == 'C')  return 2;
        return 3;
    }
    int newnode()
    {
        for (int i = 0; i < 4; i++)
            next[L][i] = -1;
        end[L] = 0;
        return L++;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        for (int i = 0; i < len; i++)
        {
            if (next[now][charid(buf[i])] == -1)
                next[now][charid(buf[i])] = newnode();
            now = next[now][charid(buf[i])];
        }
        end[now]++;
    }
    void build()
    {
        queue<int> Q;
        for (int i = 0; i < 4; i++)
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
            end[now] += end[fail[now]];
            for (int i = 0; i < 4; i++)
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

int n,num[4],bin[4];
char buf[50];
trie ac;
int dp[600][20000];

int main()
{
    int cas = 0;
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        ac.init();
        for (int i = 0; i < n; i++)
        {
            scanf("%s",buf);
            ac.insert(buf);
        }
        ac.build();
        scanf("%s",buf);
        for (int i = 0; i < 4; i++)
            num[i] = 0;
        for (int i = 0; buf[i] != 0; i++)
            num[ac.charid(buf[i])]++;

        int A,B,C,D,sum;
        bin[0]=(num[1]+1)*(num[2]+1)*(num[3]+1);
        bin[1]=(num[2]+1)*(num[3]+1);
        bin[2]=(num[3]+1);
        bin[3]=1;
        sum=bin[0]*num[0]+bin[1]*num[1]+bin[2]*num[2]+bin[3]*num[3];
        for(int i=0; i<ac.L; i++)
            for(int j=0; j<=sum; j++)
                dp[i][j]=-1;
        dp[0][0]=0;
        for(A=0; A<=num[0]; A++)
        {
            for(B=0; B<=num[1]; B++)
            {
                for(C=0; C<=num[2]; C++)
                {
                    for(D=0; D<=num[3]; D++)
                    {
                        sum=bin[0]*A+bin[1]*B+bin[2]*C+bin[3]*D;
                        for(int i=0; i<ac.L; i++)
                        {
                            if(A>=1&&dp[i][sum-bin[0]]!=-1)
                                dp[ac.next[i][0]][sum]=max(dp[ac.next[i][0]][sum],dp[i][sum-bin[0]]+ac.end[ac.next[i][0]]);
                            if(B>=1&&dp[i][sum-bin[1]]!=-1)
                                dp[ac.next[i][1]][sum]=max(dp[ac.next[i][1]][sum],dp[i][sum-bin[1]]+ac.end[ac.next[i][1]]);
                            if(C>=1&&dp[i][sum-bin[2]]!=-1)
                                dp[ac.next[i][2]][sum]=max(dp[ac.next[i][2]][sum],dp[i][sum-bin[2]]+ac.end[ac.next[i][2]]);
                            if(D>=1&&dp[i][sum-bin[3]]!=-1)
                                dp[ac.next[i][3]][sum]=max(dp[ac.next[i][3]][sum],dp[i][sum-bin[3]]+ac.end[ac.next[i][3]]);
                        }
                    }
                }
            }
        }
        int ans=0;
        int tmp=num[0]*bin[0]+num[1]*bin[1]+num[2]*bin[2]+num[3]*bin[3];
        for(int i=0; i<ac.L; i++)
            if(dp[i][tmp]!=-1)
                ans=ans>dp[i][tmp]?ans:dp[i][tmp];
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}
