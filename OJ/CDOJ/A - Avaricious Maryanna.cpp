#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

struct BigInt
{
    int num[1101],len;
    BigInt(){}
    BigInt modlen(int l)
        {
            BigInt res;
            for (int i = 0;i < l;i++)
                res.num[i] = num[i];
            for (int i = len;i < l;i++)
                res.num[i] = 0;
            res.len = l;
            return res;
        }
    BigInt mult(BigInt b)
        {
            BigInt res;
            memset(res.num,0,sizeof(res.num));
            for (int i = 0;i < b.len;i++)
                for (int j = 0;j < len;j++)
                    res.num[i+j] += num[j]*b.num[i];
            res.len = b.len-1+len;
            for (int i = 0;i < res.len;i++)
            {
                res.num[i+1] += res.num[i]/10;
                res.num[i] %= 10;
            }
            while (res.num[res.len] > 0)
            {
                res.len++;
                res.num[res.len] = res.num[res.len-1]/10;
                res.num[res.len-1] %= 10;
            }
            while (res.len > 0 && res.num[res.len-1] == 0)
                res.len--;
            return res;
        }
    void output()
        {
            printf(" ");
            for (int i = len-1;i >= 0;i--)
                printf("%d",num[i]);
        }
    int getlen()
        {
            while (len > 0 && num[len-1] == 0)
                len--;
            return len;
        }
    int cmp(BigInt b)
        {
            for (int i = len-1;i >= 0;i--)
                if (num[i] > b.num[i])  return 1;
                else if (num[i] < b.num[i]) return -1;
            return 0;
        }
};

BigInt a[501],b[501];

void init()
{
    a[1].len = 1;
    a[1].num[0] = 5;
    b[1].len = 1;
    b[1].num[0] = 6;
    for (int i = 2;i <= 500;i++)
        a[i] = (a[i-1].mult(a[i-1]).modlen(i));
    for (int i = 2;i <= 500;i++)
    {
        b[i] = (b[i-1].mult(b[i-1]).modlen(i));
        if (b[i].num[b[i].len-1] != 0)
            b[i].num[b[i].len-1] = 10-b[i].num[b[i].len-1];
    }
}

int n,totres;
BigInt res[2];

int main()
{
    init();
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        printf("Case #%d:",ft);
        if (n == 1)
            printf(" 0 1 5 6\n");
        else
        {
            totres = 0;
            if (a[n].getlen() == n)
                res[totres++] = a[n];
            if (b[n].getlen() == n)
                res[totres++] = b[n];
            if (totres == 0)
                printf("Impossible");
            else if (totres == 1)
                res[0].output();
            else
            {
                if (res[0].cmp(res[1]) < 0)
                {
                    res[0].output();
                    res[1].output();
                }
                else
                {
                    res[1].output();
                    res[0].output();
                }
            }
            printf("\n");
        }
    }
    return 0;
}
