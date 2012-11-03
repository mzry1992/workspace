#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int res[100000],tot;
char s[20];

bool check(int now)
{
    sprintf(s,"%d",now);
    int len = strlen(s);
    for (int i = 1;i < len;i++)
        if (s[i-1] == '1' && s[i] == '3')   return false;
    return true;
}

int main()
{
    tot = 0;
    for (int i = 1;i < 100000;i++)
        if (check(i) == true)
            res[tot++] = i;
    cout << tot << ' ' << res[tot-1] << endl;
    return 0;
}
