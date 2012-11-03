#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct bigint
{
    int num[120],len;
    bigint(){}
    bigint(char s[])
        {
            len = strlen(s);
            for (int i = len-1;i >= 0;i--)
                num[len-1-i] = s[i]-'0';
            while (len > 1 && num[len-1] == 0)  len--;
        }
    void println()
        {
            while (len > 1 && num[len-1] == 0)  len--;
            for (int i = len-1;i >= 0;i--)
                printf("%d",num[i]);
            printf("\n");
        }
    int compareto(bigint b)
        {
            while (len > 1 && num[len-1] == 0)  len--;
            while (b.len > 1 && b.num[b.len-1] == 0)  b.len--;
            if (len > b.len)    return 1;
            else if (len < b.len)   return -1;
            for (int i = len-1;i >= 0;i--)
                if (num[i] > b.num[i])  return 1;
                else if (num[i] < b.num[i]) return -1;
            return 0;
        }
    bigint dec(bigint b)
        {
            bigint res;
            res.len = len;
            for (int i = 0;i < res.len;i++)
                res.num[i] = num[i];
            for (int i = 0;i < b.len;i++)
            {
                if (res.num[i] < b.num[i])
                {
                    res.num[i+1]--;
                    res.num[i] += 10;
                }
                res.num[i] -= b.num[i];
            }
            for (int i = b.len;i < res.len;i++)
                if (res.num[i] < 0)
                {
                    res.num[i+1]--;
                    res.num[i] += 10;
                }
            while (res.len > 1 && res.num[res.len-1] == 0)  res.len--;
            return res;
        }
    bigint subnum(int pos,int l)
        {
            bigint res;
            res.len = l;
            for (int i = 0;i < l;i++)
                res.num[i] = num[pos+i];
            while (res.len > 1 && res.num[res.len-1] == 0)  res.len--;
            if (res.len == 0)
            {
                res.len++;
                res.num[0] = 0;
            }
            return res;
        }
    void addone()
        {
            num[0]++;
            bool up = false;
            for (int i = 0;i < len;i++)
                if (num[i] > 9)
                {
                    num[i+1]++;
                    num[i] -= 10;
                    if (i+1 == len) up = true;
                }
                else
                    break;
            if (up == true)
            {
                num[len] = 1;
                len++;
            }
        }
    bigint numcat(bigint b)
        {
            bigint res;
            res.len = b.len;
            for (int i = 0;i < res.len;i++)
                res.num[i] = b.num[i];
            for (int i = 0;i < len;i++)
                res.num[res.len++] = num[i];
            return res;
        }
};

char sa[120],sb[120];
bigint a,b,res,tmp,las,pre,now;
bool first;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%s%s",sa,sb);
        a = bigint(sa);
        b = bigint(sb);
        printf("Case #%d: ",ft);
        if (strstr(sa,sb) != NULL)
        {
            printf("0\n");
            continue;
        }
        if (a.compareto(b) <= 0)
            b.dec(a).println();
        else
        {
            first = true;
            a.num[a.len] = 0;
            for (int i = b.len-1;i <= a.len;i++)
            {
                tmp.len = i+1;
                for (int j = 0;j < b.len;j++)
                    tmp.num[tmp.len-b.len+j] = b.num[j];
                for (int j = 0;j < tmp.len-b.len;j++)
                    tmp.num[j] = 0;
                las = a.subnum(0,i+1);
                pre = a.subnum(i+1,a.len-i);
                if (tmp.compareto(las) < 0)
                    pre.addone();
                now = pre.numcat(tmp);
                now = now.dec(a);
                if (first || res.compareto(now) > 0)
                {
                    first = false;
                    res = now;
                }
            }
            res.println();
        }
    }
}
