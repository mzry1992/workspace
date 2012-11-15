#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const long long MOD = 10000;

struct num
{
    long long w[100000];
    bool sign;
    int length;
    void init(long long val);
    void maintain();
    void multipy(long long val);
    int compareTo(num val);
    void output();
};

void num::output()
{
    if (sign == false)  printf("-");
    for (int i = length;i >= 1;i--)
        printf("%d",w[i]);
    printf("\n");
}

void num::init(long long val)
{
    if (val >= 0)    sign = true;
    else
    {
        sign = false;
        val = -val;
    }
    length = 1;
    w[1] = val;
    while (w[length] >= MOD)
    {
        w[length+1] = w[length]/MOD;
        w[length] = w[length]%MOD;
        length++;
    }
}

void num::maintain()
{
    while (w[length] == 0)
    {
        length--;
        if (length == 0)
        {
            length++;
            sign = true;
            break;
        }
    }
}

num tval;
int t[100000];

void num::multipy(long long val)
{
    if (val < 0)
    {
        val = -val;
        if (sign == true)
            sign = false;
        else
            sign = true;
    }
    tval.init(val);
    memset(t,0,sizeof(t));
    maintain();
    int maxp = 0;
    for (int i = 1;i <= tval.length;i++)
    for (int j = 1;j <= length;j++)
    {
        t[j+i-1] += w[j]*tval.w[i];
        maxp = j+i-1;
        if (t[j+i-1] >= MOD)
        {
            t[j+i] += t[j+i-1]/MOD;
            t[j+i-1] %= MOD;
            maxp = i+j;
        }
    }
    for (int i = 1;i <= maxp;i++)
        w[i] = t[i];
    for (int i = 1;i < maxp;i++)
    {
        w[i+1] += w[i]/MOD;
        w[i] %= MOD;
    }
    while (w[maxp] == 0)
    {
        maxp--;
        if (maxp == 0)
        {
            w[0] = 0;
            length = 1;
            sign = true;
            return;
        }
    }
    while (w[maxp] >= MOD)
    {
        w[maxp+1] = w[maxp]/10;
        w[maxp] %= 10;
        maxp++;
    }
    length = maxp;
}

int num::compareTo(num val)
{
    val.maintain();
    maintain();
    if (val.sign == true && sign == false)  return -1;
    if (val.sign == false && sign == true)  return 1;
    if (val.sign == true && sign == true)
    {
        if (val.length > length)   return -1;
        if (val.length < length)   return 1;
        for (int i = length;i >= 1;i--)
        if (val.w[i] > w[i])    return -1;
        else if (val.w[i] < w[i])  return 1;
        return 0;
    }
    if (val.length > length)   return 1;
    if (val.length < length)   return -1;
    for (int i = length;i >= 1;i--)
    if (val.w[i] > w[i])   return 1;
    else if (val.w[i] < w[i])  return -1;
    return 0;
}

int m,n;
long long a[1100][1100];
num cur,maxa;
int ans;

int main()
{
    while (scanf("%d%d",&m,&n) != EOF)
    {
        for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            scanf("%lld",&a[i][j]);
        ans = 1;
        maxa.init(1);
        for (int i = 1;i <= n;i++)
            maxa.multipy(a[i][1]);
        for (int i = 2;i <= m;i++)
        {
            cur.init(1);
            for (int j = 1;j <= n;j++)
                cur.multipy(a[j][i]);
            int tcode = cur.compareTo(maxa);
            if (tcode >= 0)
            {
                maxa = cur;
                ans = i;
            }
        }
        printf("%d\n",ans);
    }
}
