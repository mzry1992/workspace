#include <cstdio>
#include <cstring>
char s[2001];
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d%s",&n,s);
        int l=strlen(s);
        int rest=0;
        for (int i=0;i<l;i++)
            rest=(rest*10+1)%n;
        printf("%d\n",rest);
    }
    return 0;
}
