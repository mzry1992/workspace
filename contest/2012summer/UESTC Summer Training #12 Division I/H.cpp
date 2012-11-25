#include<cstdio>
#include<cstring>
using namespace std;
char s[15];
bool judge(int i,int j)
{
    for(int k=0; s[i+k]&&s[j+k]; k++)
        if(s[i+k]!=s[j+k])
            return false;
    return true;
}
int main()
{
    int cas;
    scanf("%d",&cas);
    for(int c=1; c<=cas; c++)
    {
        if(c!=1)puts("");

        long long res=0;
        int n;
        scanf("%d%s",&n,s);
        for(int i=0; s[i]; i++)
        {
            if(judge(0,i))
                res++;
            res=res*n;
        }
        printf("Case %d:\n%lld\n",c,res);
    }
    return 0;
}
