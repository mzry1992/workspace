#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const char mp[27] = "yhesocvxduiglbkrztnwjpfmaq";
char s[110];

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int t;
    scanf("%d",&t);
    gets(s);
    for (int ft = 1;ft <= t;ft++)
    {
        gets(s);
        printf("Case #%d: ",ft);
        for (int i = 0;s[i] != 0;i++)
            if (s[i] == ' ')
                printf(" ");
            else
                printf("%c",mp[s[i]-'a']);
        printf("\n");
    }
	return 0;
}
