#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int mod = 100000LL;

struct Matrix
{
    unsigned long long a[110][110],n;
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
                    ret.a[i][j] += a[i][k]*b.a[k][j];
        return ret;
    }
};

struct trie
{
    int next[40][26],fail[40];
    bool end[40];
    int root,L;
    int newnode(int pos)
    {
        for (int i = 0; i < 26; i++)
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
        return ch-'a';
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
        for (int i = 0; i < 26; i++)
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
            for (int i = 0; i < 26; i++)
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
        Matrix res = Matrix(L+1);
        for (int i = 0; i < L; i++)
            for (int j = 0; j < 26; j++)
                if (end[next[i][j]] == false)
                    res.a[next[i][j]][i] += 1;
        for (int i = 0;i < L+1;i++)
            res.a[L][i] = 1;
        return res;
    }
};

int n,m;
trie ac;
char buf[8];
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
        base = power(base,m);
        unsigned long long res = 0;
        for (int i = 0;i < base.n;i++)
            res += base.a[i][0];
        res--;

        base = Matrix(2);
        base.a[0][0] = 26;
        base.a[1][0] = base.a[1][1] = 1;
        base = power(base,m);
        unsigned long long tot = 0;
        for (int i = 0;i < base.n;i++)
            tot += base.a[i][0];
        tot--;

        cout << tot-res << endl;
    }
    return 0;
}
