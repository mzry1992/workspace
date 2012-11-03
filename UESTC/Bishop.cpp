#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
    char s1[1000],s2[1000];
    bool flag=true;
    while (scanf("%s%s",s1,s2)>0)
    {
        if (flag) flag=false;else puts("");
        int len1=strlen(s1),len2=strlen(s2);
        if ((s1[len1-1]-'0')%2==(s1[len2-1]-'0')%2) printf("2\n");
        else printf("1\n");
    }
}
