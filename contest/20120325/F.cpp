#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

char s[100000];
int n,cur;
const string OP = "+-*";

char next_char()
{
    if (cur >= n) return EOF;
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
        return a+b;
    if (op == '-')
        return a-b;
    if (op == '*')
        return a*b;
}

int calc_exp(int p)
{
    int a = P();
    while ((OP.find(next_char()) != OP.npos) && (get_priority(next_char()) >= p))
    {
        char op = next_char();
        cur++;
        a = calc(a,op,calc_exp(get_priority(op)+1));
    }
    return a;
}

int totvar,m,var[26],varid[26];

int P()
{
    if (next_char() == '-')
    {
        cur++;
        return -P();
    }
    else if (next_char() == '+')
    {
        cur++;
        return P();
    }
    else if (next_char() == '(')
    {
        cur++;
        int res = calc_exp(0);
        cur++;
        return res;
    }
    else
    {
        cur++;
        //cout << "getvar at " << cur << ' ' << var[varid[s[cur]-'a']] << endl;
        return var[varid[s[cur-1]-'a']];
    }
}

int id[26],minid;

int main()
{
    while (true)
    {
        scanf("%d%d",&totvar,&var[0]);
        if (totvar == 0 && var[0] == 0)  break;
        for (int i = 1;i < totvar;i++)
            scanf("%d",&var[i]);
        scanf("%d",&m);
        scanf("%s",s);
        for (int i = 0;i < 26;i++)
            id[i] = -1;
        minid = 0;
        n = strlen(s);
        for (int i = 0;i < n;i++)
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                if (id[s[i]-'a'] == -1)
                {
                    id[s[i]-'a'] = minid;
                    minid++;
                }
                s[i] = 'a'+id[s[i]-'a'];
            }
        for (int i = 0;i < totvar;i++)
            varid[i] = i;
        int res = 0;
        do
        {
            cur = 0;
            int tmp = calc_exp(0);
            if (tmp == m)
            {
                res++;
                break;
            }
        }
        while (next_permutation(varid,varid+totvar));
        //puts(s);
        if (res > 0)
            puts("YES");
        else
            puts("NO");
    }
	return 0;
}
