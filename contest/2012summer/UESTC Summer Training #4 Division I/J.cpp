#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int nxt[110000][26];
char a[110000],b[110];
int la,lb;

int main()
{
    scanf("%s%s",a,b);
    la = strlen(a);
    lb = strlen(b);
    for (int i = 0;i < 26;i++)
        nxt[la][i] = -1;
    for (int i = la-1;i >= 0;i--)
    {
        for (int j = 0;j < 26;j++)
            nxt[i][j] = nxt[i+1][j];
        nxt[i][a[i]-'a'] = i;
    }
    long long res = 0;
    for (int i = 0;i < la;i++)
    {
        int now = i;
        for (int j = 0;j < lb;j++)
        {
            now = nxt[now][b[j]-'a'];
            if (now == -1)  break;
            now++;
        }
        if (now != -1)
        {
            now--;
            //printf("%d %d\n",i,now);
            res += la-now;
        }
    }
    printf("%I64d\n",res);
	return 0;
}
