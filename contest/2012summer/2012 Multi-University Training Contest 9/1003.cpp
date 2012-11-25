#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

struct BigInt
{
    const static int mod = 10;
    int a[2000],len;
    BigInt (){}
    BigInt (int v)
    {
        len = 0;
        do
        {
            a[len++] = v%mod;
            v /= mod;
        }while(v);
    }
    BigInt (char s[])
    {
        len = strlen(s);
        for (int i = len-1;i >= 0;i--)
            a[len-i-1] = s[i]-'0';
    }
    BigInt operator *(const int& b) const
    {
        BigInt res;
        res.len = len;
        for (int i = 0; i <= len; ++i)
            res.a[i] = 0;
        for (int i = 0; i < len; ++i)
        {
            res.a[i] += a[i]*b;
            res.a[i+1] += res.a[i]/mod;
            res.a[i] %= mod;
        }
        if (res.a[len] > 0)  res.len++;
        return res;
    }
    BigInt operator +(const BigInt& b) const
    {
        BigInt res;
        res.len = max(len,b.len);
        for (int i = 0; i <= res.len; ++i)
            res.a[i] = 0;
        for (int i = 0; i < res.len; ++i)
        {
            res.a[i] += ((i < len)?a[i]:0)+((i < b.len)?b.a[i]:0);
            res.a[i+1] += res.a[i]/mod;
            res.a[i] %= mod;
        }
        if (res.a[res.len] > 0)  res.len++;
        return res;
    }
    void output()
    {
        printf("%d",a[len-1]);
        for (int i = len-2; i >= 0; --i)
            printf("%08d",a[i]);
        printf("\n");
    }
};

BigInt c[2],tc;
char com[20],com1[20],com2[20],tmp[200];

struct Command
{
    int typ,va,vb;
    Command(){}
    Command(char a[],char b[],char c[])
    {
        if (strcmp(a,"SET") == 0)   typ = 0;
        else if (strcmp(a,"ADD") == 0)  typ = 1;
        else typ = 2;
        if (strcmp(b,"C1") == 0)    va = -1;
        else if (strcmp(b,"C2") == 0)   va = -2;
        else    sscanf(b,"%d",&va);
        if (strcmp(c,"C1") == 0)    vb = -1;
        else if (strcmp(c,"C2") == 0)   vb = -2;
        else    sscanf(c,"%d",&vb);
    }
};

vector<Command> co;

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
        int v;
        scanf("%d",&v);
        c[0] = BigInt(v);
        c[1] = BigInt(0);
        co.clear();
        while (true)
        {
            scanf("%s",com);
            if (strcmp(com,"END") == 0)
                break;
            scanf("%s%s",com1,com2);
            com1[strlen(com1)-1] = 0;
            co.push_back(Command(com,com1,com2));
        }
        printf("Case %d:\n",cas);
        int q;
        scanf("%d",&q);
        for (int i = 0;i < q;i++)
        {
            scanf("%s",tmp);
            c[0] = BigInt(tmp);
            c[1] = BigInt(0);
            for (int j = 0;j < co.size();j++)
                if (co[j].typ == 0)
                {
                    if (co[j].vb < 0)
                        tc = c[-co[j].vb-1];
                    else
                        tc = BigInt(co[j].vb);
                    c[-co[j].va-1] = tc;
                }
                else if (co[j].typ == 1)
                {
                    if (co[j].vb < 0)
                        tc = c[-co[j].vb-1];
                    else
                        tc = BigInt(co[j].vb);
                    c[-co[j].va-1] = c[-co[j].va-1]+tc;
                }
                else if (co[j].typ == 2)
                    c[-co[j].va-1] = c[-co[j].va-1]*co[j].vb;
            printf(": ");
            c[1].output();
        }
	}
	return 0;
}
