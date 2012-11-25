#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

bool letter(char ch)
{
    if (ch >= 'a' && ch <= 'z') return true;
    if (ch >= 'A' && ch <= 'Z') return true;
    return false;
}

bool symbol(char ch)
{
    if (letter(ch)) return true;
    if (ch >= '0' && ch <= '9') return true;
    if (ch == '_' || ch == '-') return true;
    return false;
}

bool word(string buf)
{
    int len = buf.length();
    if (len == 0)   return false;
    if (len == 1)   return symbol(buf[0]);
    return symbol(buf[0]) && word(buf.substr(1,len-1));
}

bool prefix(string buf)
{
    int len = buf.length();
    for (int i = len-1; i >= 0; i--)
        if (buf[i] == '.')
            return prefix(buf.substr(0,i)) && word(buf.substr(i+1,len-i-1));
    return word(buf);
}

bool domain(string buf)
{
    int len = buf.length();
    if (len == 2)
        return letter(buf[0]) && letter(buf[1]);
    if (len == 3)
        return letter(buf[0]) && letter(buf[1]) && letter(buf[2]);
    return false;
}

bool suffix(string buf)
{
    int len = buf.length();
    for (int i = len-1; i >= 0; i--)
        if (buf[i] == '.')
            return prefix(buf.substr(0,i)) && domain(buf.substr(i+1,len-i-1));
    return false;
}

bool address(string buf)
{
    int len = buf.length();
    int pos = -1;
    for (int i = 0; i < len; i++)
        if (buf[i] == '@')
        {
            if (pos == -1)
                pos = i;
            else
                return false;
        }
    if (pos == -1)  return false;
    return prefix(buf.substr(0,pos)) && suffix(buf.substr(pos+1,len-pos-1));
}

char buf[200];

int main()
{
    int totcas;
    scanf("%d",&totcas);
    gets(buf);
    for (int cas = 1; cas <= totcas; cas++)
    {
        gets(buf);
        string tmp = buf;

        if (address(tmp))
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}

