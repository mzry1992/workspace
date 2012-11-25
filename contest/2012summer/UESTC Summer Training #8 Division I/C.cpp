#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int mod;
char s[100];
int n,cur;
const string OP = "+-*";
map<char,int> var;

char next_char()
{
    if (cur >= n)   return EOF;
    return s[cur];
}

int get_priority(char ch)
{
    if (ch == '*')  return 2;
    return 1;
}

int P();

int calc(int a,char op,int b)
{
    if (op == '+')
        return (a+b)%mod;
    if (op == '-')
        return (a-b+mod)%mod;
    if (op == '*')
        return (long long)a*b%mod;
}

int calc_exp(int p)
{
    int a = P()%mod;
    while ((OP.find(next_char()) != OP.npos) && (get_priority(next_char()) >= p))
    {
        char op = next_char();
        cur++;
        a = calc(a,op,calc_exp(get_priority(op)+1));
    }
    return a%mod;
}

int P()
{
    if (next_char() == '-')
    {
        cur++;
        return (mod-P())%mod;
    }
    else if (next_char() == '+')
    {
        cur++;
        return P()%mod;
    }
    else if (next_char() == '(')
    {
        cur++;
        int res = calc_exp(0);
        cur++;
        return res%mod;
    }
    else if (next_char() >= '0' && next_char() <= '9')
    {
        cur++;
        return s[cur-1]-'0';
    }
    else
    {
        cur++;
        return var[s[cur-1]];
    }
}

char a[100],b[100];
int la,lb;

int main()
{
    int totcas;
    scanf("%d",&totcas);
    gets(a);
    for (int cas = 1; cas <= totcas; cas++)
    {
        gets(a);
        gets(b);
        la = lb = 0;
        for (int i = 0;a[i] != 0;i++)
            if (a[i] > 32)
                a[la++] = a[i];
        a[la] = 0;
        for (int i = 0;b[i] != 0;i++)
            if (b[i] > 32)
                b[lb++] = b[i];
        b[lb] = 0;

        var.clear();
        for (int i = 0;i < la;i++)
            if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z'))
                var[a[i]] = 0;
        for (int i = 0;i < lb;i++)
            if ((b[i] >= 'a' && b[i] <= 'z') || (b[i] >= 'A' && b[i] <= 'Z'))
                var[b[i]] = 0;

        bool res = true;
        int resa,resb;

        for (int tims = 0;tims < 200;tims++)
        {
            for (map<char,int>::iterator it = var.begin();it != var.end();it++)
                it->second = rand();
            //for (map<char,int>::iterator it = var.begin();it != var.end();it++)
            //    printf("%c -> %d\n",it->first,it->second);

            mod = 100000007;
            strcpy(s,a);
            n = la;
            cur = 0;
            resa = calc_exp(0);
            strcpy(s,b);
            n = lb;
            cur = 0;
            resb = calc_exp(0);
            //printf("%d %d\n",resa,resb);

            if (resa != resb)
            {
                res = false;
                break;
            }
            mod = 100000037;
            strcpy(s,a);
            n = la;
            cur = 0;
            resa = calc_exp(0);
            strcpy(s,b);
            n = lb;
            cur = 0;
            resb = calc_exp(0);
            if (resa != resb)
            {
                res = false;
                break;
            }
            mod = 121212121;
            strcpy(s,a);
            n = la;
            cur = 0;
            resa = calc_exp(0);
            strcpy(s,b);
            n = lb;
            cur = 0;
            resb = calc_exp(0);
            if (resa != resb)
            {
                res = false;
                break;
            }
        }

        if (res)
            puts("YES");
        else
            puts("NO");
    }
	return 0;
}
