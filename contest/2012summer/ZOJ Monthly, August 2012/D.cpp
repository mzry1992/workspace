#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,k,m;
char s[32];
int num[20000];
int tot,pos[32];

bool cmp(int a,int b)
{
    return a > b;
}

void output(int num)
{
    for (int i = n-1;i >= 0;i--)
        printf("%d",(((num>>i)&1) == 1));
    puts("");
}

bool check(int val)
{
    for (int i = n-1;i >= 0;i--)
        if (((val>>i)&1) == 1)
        {
            if (pos[i] == -1)   return false;
            val ^= num[pos[i]];
        }
    return true;
}

void Gao(int num)
{
    if (check(num))
    {
        output(num);
        return;
    }
    int res = 1<<n;
    for (int i = 0;i < n;i++)
        if (check(num^(1<<i)))
            res = min(res,num^(1<<i));
    if (res < (1<<n))
    {
        output(res);
        return;
    }
    for (int i = 0;i < n;i++)
        for (int j = i+1;j < n;j++)
            if (check(num^(1<<i)^(1<<j)))
                res = min(res,num^(1<<i)^(1<<j));
    if (res < (1<<n))
    {
        output(res);
        return;
    }
    for (int i = 0;i < n;i++)
        for (int j = i+1;j < n;j++)
            for (int k = j+1;k < n;k++)
                if (check(num^(1<<i)^(1<<j)^(1<<k)))
                    res = min(res,num^(1<<i)^(1<<j)^(1<<k));
    if (res < (1<<n))
    {
        output(res);
        return;
    }
    puts("NA");
}

int main()
{
    while (scanf("%d%d%d",&n,&k,&m) != EOF)
    {
        for (int i = 0;i < k;i++)
        {
            scanf("%s",s);
            num[i] = 0;
            for (int j = 0;j < n;j++)
            {
                num[i] <<= 1;
                if (s[j] == '1')
                    num[i] |= 1;
            }
        }
        tot = 0;
        sort(num,num+k,cmp);
        memset(pos,-1,sizeof(pos));
        for (int i = n-1;i >= 0;i--)
            if (((num[tot]>>i)&1) == 1)
            {
                for (int j = 0;j < k;j++)
                    if (j != tot)
                        if (((num[j]>>i)&1) == 1)
                            num[j] ^= num[tot];
                pos[i] = tot++;
                if (tot == k)   break;
                sort(num+tot,num+k,cmp);
            }

        /*cout << "-------------- " << endl;
        for (int j = 0;j < k;j++)
            output(num[j]);
        cout << "--------------" << endl;*/


        for (int i = 0;i < m;i++)
        {
            scanf("%s",s);
            int num = 0;
            for (int j = 0;j < n;j++)
            {
                num <<= 1;
                if (s[j] == '1')
                    num |= 1;
            }
            Gao(num);
        }
    }
	return 0;
}
