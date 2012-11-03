#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
char s[50];
int res[10];

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        scanf("%s",s);
        memset(res,0,sizeof(res));
        for (int i = 0;i < strlen(s)-2;i++)
        {
            if (s[i] == 'T' && s[i+1] == 'T' && s[i+2] == 'T')
                res[1]++;
            if (s[i] == 'T' && s[i+1] == 'T' && s[i+2] == 'H')
                res[2]++;
            if (s[i] == 'T' && s[i+1] == 'H' && s[i+2] == 'T')
                res[3]++;
            if (s[i] == 'T' && s[i+1] == 'H' && s[i+2] == 'H')
                res[4]++;
            if (s[i] == 'H' && s[i+1] == 'T' && s[i+2] == 'T')
                res[5]++;
            if (s[i] == 'H' && s[i+1] == 'T' && s[i+2] == 'H')
                res[6]++;
            if (s[i] == 'H' && s[i+1] == 'H' && s[i+2] == 'T')
                res[7]++;
            if (s[i] == 'H' && s[i+1] == 'H' && s[i+2] == 'H')
                res[8]++;
        }
        printf("%d",n);
        for (int i = 1;i <= 8;i++)
            printf(" %d",res[i]);
        printf("\n");
    }
}
