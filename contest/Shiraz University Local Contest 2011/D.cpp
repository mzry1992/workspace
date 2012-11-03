#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[3005];
int last,mx,len;
bool dfs(int deep)
{
    mx=max(mx,deep);
    int sum=0,num=0;
    int i;
    for(i=0;i<4;i++)
    {
        if(last>=len)
            return false;
        if(s[last]=='2')
        {
            last++;
            if(!dfs(deep+1))
                return false;
        }
        else
        {
            num++;
            sum+=s[last++]-'0';
        }
    }
    if(num==4&&sum%4==0)
        return false;
    return true;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
    {
        scanf("%s",s);
        len=strlen(s);
        if(s[0]!='2')
        {
            if(len>1)
                printf("Not Possible\n");
            else
                printf("2^0*2^0\n");
        }
        else
        {
            mx=0;
            last=1;
            if(dfs(1)&&last==len)
                printf("2^%d*2^%d\n",mx,mx);
            else
                printf("Not Possible\n");
        }
    }
    return 0;
}

