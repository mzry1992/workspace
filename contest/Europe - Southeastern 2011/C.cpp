#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char p[110],s[1111111];
bool can[110][200];

int tot,lenp,lens;
bool hasres,check;

int main()
{
    freopen("C.IN","r",stdin);
	int t;
	scanf("%d",&t);
	for (int ft = 1;ft <= t;ft++)
	{
        scanf("%s%s",p,s);
        lenp = strlen(p);
        lens = strlen(s);
        memset(can,false,sizeof(can));
        tot = 0;
        for (int i = 0;i < lenp;i++,tot++)
            if (p[i] == '[')
            {
                for (i = i+1;;i++)
                {
                    if (p[i] == ']')    break;
                    can[tot][p[i]] = true;
                }
            }
            else if (p[i] == '{')
            {
                for (int j = 0;j < 200;j++)
                    can[tot][j] = true;
                for (i = i+1;;i++)
                {
                    if (p[i] == '}')    break;
                    can[tot][p[i]] = false;
                }
            }
            else if (p[i] == '?')
            {
                for (int j = 0;j < 200;j++)
                    can[tot][j] = true;
            }
            else
                can[tot][p[i]] = true;
        hasres = false;
        for (int i = 0;i+tot <= lens;i++)
        {
            check = true;
            for (int j = 0;j < tot;j++)
                if (can[j][s[i+j]] == false)
                {
                    check = false;
                    break;
                }
            if (check == true)
            {
                if (hasres == true) printf(" ");
                printf("%d",i+1);
                hasres = true;
            }
        }
        if (hasres == false)    puts("no match");
        else
            puts("");
	}
	return 0;
}
