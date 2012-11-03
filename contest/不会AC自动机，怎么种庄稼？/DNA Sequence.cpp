#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int mod = 100000LL;

struct Matrix
{
    int a[110][110],n;
    Matrix() {}
    Matrix(int _n)
    {
        n = _n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = 0;
    }
    Matrix operator *(const Matrix& b)const
    {
        Matrix ret = Matrix(n);
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                for (int k = 0;k < n;k++)
                {
                    int mut = (long long)a[i][k]*(long long)b.a[k][j]%mod;
                    ret.a[i][j] = (ret.a[i][j]+mut)%mod;
                }
        return ret;
    }
};

struct trie
{
    int next[110][4],fail[110];
    bool end[110];
    int root,L;
    int newnode(int pos)
    {
        for (int i = 0; i < 4; i++)
            next[pos][i] = -1;
        end[pos] = false;
        return pos;
    }
    void init()
    {
        L = 0;
        root = newnode(L++);
    }
    int getch(char ch)
    {
        switch (ch)
        {
        case 'A':
            return 0;
            break;
        case 'C':
            return 1;
            break;
        case 'T':
            return 2;
            break;
        default:
            return 3;
            break;
        }
    }
    void insert(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        for (int i = 0; i < len; i++)
        {
            if (next[now][getch(buf[i])] == -1)
                next[now][getch(buf[i])] = newnode(L++);
            now = next[now][getch(buf[i])];
        }
        end[now] = true;
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
            if (end[fail[now]] == true)
                end[now] = true;
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
    Matrix getMatrix()
    {
        Matrix res = Matrix(L);
        for (int i = 0; i < L; i++)
            for (int j = 0; j < 4; j++)
                if (end[next[i][j]] == false)
                    res.a[next[i][j]][i] += 1;
        return res;
    }
};

int n,m;
trie ac;
char buf[11];
Matrix base;

Matrix power(Matrix x,int y)
{
    Matrix ret = Matrix(x.n);
    for (int i = 0; i < ret.n; i++)
        ret.a[i][i] = 1;
    for (Matrix a = x; y; y >>= 1,a = a*a)
        if (y&1)
            ret = ret*a;
    return ret;
}

#define DEBUG

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        ac.init();
        for (int i = 0; i < n; i++)
        {
            scanf("%s",buf);
            ac.insert(buf);
        }
        ac.build();
        base = ac.getMatrix();
#ifdef DEBUG
        for (int i = 0; i < ac.L; i++)
        {
            printf("id = %3d ,fail = %3d ,end = %3d, chi = [",i,ac.fail[i],ac.end[i]);
            for (int j = 0; j < 4; j++)
                printf("%2d ",ac.next[i][j]);
            printf("]\n");
        }
        for (int i = 0;i < base.n;i++)
        {
            for (int j = 0;j < base.n;j++)
                printf("%2d",base.a[i][j]);
            printf("\n");
        }
#endif
        base = power(base,m);
        int res = 0;
        for (int i = 0;i < base.n;i++)
            res = (res+base.a[i][0])%mod;
        printf("%d\n",res);
    }
    return 0;
}
