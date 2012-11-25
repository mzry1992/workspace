#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

const string OP = "&|^";
char s[210],a[210],b[210];
int len,l,n,cur;

char next_char()
{
    if (cur >= n-1) return EOF;
    return s[cur+1];
}

int get_priority(char ch)
{
    if (ch == '&')  return 3;
    if (ch == '|')  return 2;
    return 1;
}

bool P();

bool calc(bool a,char op,bool b)
{
    if (op == '&')  return a&b;
    if (op == '|')  return a|b;
    if (op == '^')  return a^b;
}

bool calc_exp(int p)
{
    bool a = P();
    while ((OP.find(next_char()) != OP.npos) && (get_priority(next_char()) >= p))
    {
        char op = next_char();
        cur++;
        a = calc(a,op,calc_exp(get_priority(op)+1));
    }
    return a;
}

bool P()
{
    if (next_char() == '!')
    {
        cur++;
        return !P();
    }
    else if (next_char() == '(')
    {
        cur++;
        bool res = calc_exp(0);
        while (s[cur] != ')')
            cur++;
        return res;
    }
    else
    {
        bool res = (next_char() == '0')?false:true;
        cur++;
        return res;
    }
}

int lena,lenb;
map<string,char> va,vb;
map<string,char>::iterator it;
set<string> verb;
set<string>::iterator vit;

void gao(char s[],int& len,map<string,char>& v)
{
    int l = strlen(s);
    len = 0;
    for (int i = 0; i < l; i++)
        if (s[i] != ' ')
            s[len++] = s[i];
    s[len] = 0;
    v.clear();
    string tmp;
    int totv = 0;
    int pre = 0;
    l = 0;
    for (int i = 0; i <= len; i++)
        if (i == len || s[i] == '(' || s[i] == ')' || s[i] == '!' || s[i] == '&' || s[i] == '|' || s[i] == '^')
        {
            if (pre < i)
            {
                tmp.resize(i-pre);
                for (int j = pre; j < i; j++)
                    tmp[j-pre] = s[j];
                if (v.find(tmp) == v.end())
                {
                    v[tmp] = 'a'+totv;
                    totv++;
                }
                char vid = v[tmp];
                s[l++] = vid;
            }
            s[l++] = s[i];
            pre = i+1;
        }
    len = l;
}

bool check(char s[],int len)
{
    int cnt = 0;
    for (int i = 0;i < len;i++)
        if (s[i] == '(')
            cnt++;
        else if (s[i] == ')')
        {
            cnt--;
            if (cnt < 0)    return false;
        }
    if (cnt != 0)   return false;
    return true;
}

string verbs[20];

int main()
{
    while (true)
    {
        gets(a);
        if (strlen(a) == 0)  break;
        gets(b);
        gao(a,lena,va);
        gao(b,lenb,vb);
        bool res = true;
        if (check(a,lena) == false || check(b,lenb) == false)
        {
            puts("TRUE");
            continue;
        }
        if (res == true)
        {
            verb.clear();
            for (it = va.begin(); it != va.end(); it++)
                verb.insert(it->first);
            for (it = vb.begin(); it != vb.end(); it++)
                verb.insert(it->first);
            int sz = verb.size();
            int id = 0;
            for (vit = verb.begin();vit != verb.end();vit++)
                verbs[id++] = *vit;
            for (int i = 0; i < (1<<sz); i++)
            {
                int sta = i;
                strcpy(s,a);
                n = lena;
                for (int j = 0;j < sz;j++)
                {
                    if (va.find(verbs[j]) != va.end())
                    {
                        char vid = va[verbs[j]];
                        for (int k = 0; k < lena; k++)
                            if (s[k] == vid)
                                s[k] = '0'+((sta>>j)&1);
                    }
                }
                cur = -1;
                bool resa = calc_exp(0);
                strcpy(s,b);
                n = lenb;
                for (int j = 0;j < sz;j++)
                {
                    if (vb.find(verbs[j]) != vb.end())
                    {
                        char vid = vb[verbs[j]];
                        for (int k = 0; k < lenb; k++)
                            if (s[k] == vid)
                                s[k] = '0'+((sta>>j)&1);
                    }
                }
                cur = -1;
                bool resb = calc_exp(0);
                if (resa != resb)
                {
                    res = false;
                    break;
                }
            }
        }
        if (res == true)
            printf("TRUE\n");
        else
            printf("FALSE\n");
    }
    return 0;
}
