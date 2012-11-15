#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char buf[2000];
int len,app[26];

int main()
{
    int t;
    scanf("%d",&t);
    gets(buf);
    for (int ft = 0;ft < t;ft++)
    {
        gets(buf);
        len = strlen(buf);
        memset(app,0,sizeof(app));
        for (int i = 0;i < len;i++)
            if (buf[i] != ' ')
                app[buf[i]-'A']++;
        int mos,tim;
        mos = tim = 0;
        for (int i = 0;i < 26;i++)
            if (app[i] == mos)
                tim++;
            else if (app[i] > mos)
            {
                mos = app[i];
                tim = 1;
            }
        if (tim != 1)
            printf("NOT POSSIBLE\n");
        else
        {
            for (int i = 0;i < 26;i++)
                if (app[i] == mos)
                {
                    int dis = (i-4+26)%26;
                    printf("%d ",dis);
                    for (int j = 0;j < len;j++)
                        if (buf[j] != ' ')
                            printf("%c",(buf[j]-'A'-dis+26)%26+'A');
                        else
                            printf(" ");
                    printf("\n");
                }
        }
    }
    return 0;
}
