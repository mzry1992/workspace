#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
bool flag[800];
int len[801];
char buf[10];

bool check(int i)
{
    sprintf(buf,"%d",i);
    for (int j = 0;buf[j] != 0;j++)
        if (buf[j] == '7')  return true;
    return false;
}

int main()
{
    for (int i = 7; i < 800; i++)
        if (check(i) || i%7 == 0)
            flag[i] = true;
    len[800] = 0;
    for (int i = 799;i >= 7;i--)
        if (flag[i])
            len[i] = len[i+1]+1;
        else
            len[i] = 0;
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%d",&n);
        for (int i = 7;i < 800;i++)
            if (len[i] >= n)
            {
                printf("%d\n",i);
                break;
            }
    }
    return 0;
}
