#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Scanner
{
    char buf[100000],ch;
    int cur,len,last;
    void init()
    {
        len = 0;
        while (true)
        {
            ch = getchar();
            if (ch == EOF)  break;
            if (ch == '\n')
                ch = ' ';
            buf[len++] = ch;
        }
        buf[len++] = EOF;
        cur = 0;
    }
    int readint()
    {
        long long res = 0;
        last = cur;
        ch = buf[cur++];
        while (ch < '0' || ch > '9')
            ch = buf[cur++];
        if (ch != ' ')  return -1;
        while (ch >= '0' && ch <= '9')
        {
            res = res*10+ch-'0';
            if (res > 2147483647)   return -1;
            ch = buf[cur++];
        }
        if (ch != ':' && ch != ' ' && ch != EOF) return -1;
        return res;
    }
    void unread()
    {
        cur = last;
    }
    void reads(char s[])
    {
        last = cur;
        ch = buf[cur++];
        while (ch == ' ')
            ch = buf[cur++];
        int tlen = 0;
        while (ch != ' ' && ch != EOF)
            s[tlen++] = ch;
        s[tlen] = 0;
    }
};

int main()
{
}
