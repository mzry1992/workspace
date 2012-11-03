#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[200];
int len,val,pre;

int main()
{
    gets(s);
    len = strlen(s);
    pre = 0;
    for (int i = 0;i < len;i++)
    {
        val = 0;
        for (int j = 0;j < 8;j++,val <<= 1)
            val |= ((s[i]>>j)&1);
        val >>= 1;
        val = (pre-val+256)%256;
        printf("%d\n",val);
        pre = 0;
        for (int j = 0;j < 8;j++,pre <<= 1)
            pre |= ((s[i]>>j)&1);
        pre >>= 1;
    }
    return 0;
}
