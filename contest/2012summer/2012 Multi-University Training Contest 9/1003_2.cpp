#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int mod = 1000000007;

struct Matrix
{
    int a[3][3];
    Matrix operator *(const Matrix &b)const
    {
        Matrix res;
        for (int i = 0;i < 3;i++)
            for (int j = 0;j < 3;j++)
            {
                res.a[i][j] = 0;
                for (int k = 0;k < 3;k++)
                    res.a[i][j] = (res.a[i][j]+(long long)a[i][k]*b.a[k][j]%mod)%mod;
            }
        return res;
    }
};

Matrix base;
int v;
char ca[20],cb[20],cc[20];

Matrix GetMatrix(char ca[],char cb[],char cc[])
{
    Matrix res;
    for (int i = 0;i < 3;i++)
    {
        for (int j = 0;j < 3;j++)
            res.a[i][j] = 0;
        res.a[i][i] = 1;
    }
    int pa = 0;
    if (strcmp(cb,"C2") == 0)   pa = 1;

    if (strcmp(ca,"SET") == 0)
    {
        res.a[pa][pa] = 0;
        if (strcmp(cc,"C1") == 0)
            res.a[pa][0] = 1;
        else if (strcmp(cc,"C2") == 0)
            res.a[pa][1] = 1;
        else
        {
            int v;
            sscanf(cc,"%d",&v);
            res.a[pa][2] = (v%mod+mod)%mod;
        }
    }
    else if (strcmp(ca,"ADD") == 0)
    {
        if (strcmp(cc,"C1") == 0)
            res.a[pa][0]++;
        else if (strcmp(cc,"C2") == 0)
            res.a[pa][1]++;
        else
        {
            int v;
            sscanf(cc,"%d",&v);
            res.a[pa][2] = (v%mod+mod)%mod;
        }
    }
    else
    {
        int v;
        sscanf(cc,"%d",&v);
        res.a[pa][pa] = (v%mod+mod)%mod;
    }
    return res;
}

Matrix res,ten[110],start,final;
char s[200];

Matrix One()
{
    Matrix res;
    for (int i = 0;i < 3;i++)
    {
        for (int j = 0;j < 3;j++)
            res.a[i][j] = 0;
        res.a[i][i] = 1;
    }
    return res;
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1;cas <= totcas;cas++)
    {
        scanf("%d",&v);

        for (int i = 0;i < 3;i++)
            for (int j = 0;j < 3;j++)
                start.a[i][j] = 0;
        start.a[0][0] = v;
        start.a[2][0] = 1;

        base = One();
        while (true)
        {
            scanf("%s",ca);
            if (strcmp(ca,"END") == 0)  break;
            scanf("%s%s",cb,cc);
            cb[strlen(cb)-1] = 0;
            base = GetMatrix(ca,cb,cc)*base;
        }
        ten[0] = base;
        for (int i = 1;i <= 100;i++)
        {
            ten[i] = One();
            for (int j = 0;j < 10;j++)
                ten[i] = ten[i]*ten[i-1];
        }
        printf("Case %d:\n",cas);
        int q;
        scanf("%d",&q);
        for (int i = 0;i < q;i++)
        {
            scanf("%s",s);
            int len = strlen(s);
            res = One();
            for (int j = len-1;j >= 0;j--)
                for (int k = 0;k < s[j]-'0';k++)
                    res = res*ten[len-j-1];
            final = res*start;
            printf("%d\n",final.a[1][0]);
        }
    }
	return 0;
}
