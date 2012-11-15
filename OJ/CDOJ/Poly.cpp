#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int cnt[40];
int main()
{
    memset(cnt,0,sizeof(cnt));
    for (int a=1;a<=7;a++)
        for (int b=1;b<=7;b++)
            for (int c=1;c<=7;c++)
                for (int d=1;d<=7;d++)
                    for (int e=1;e<=7;e++)
            {
                cnt[a+b]++;
            }
    for (int i=2;i<=14;i++) printf("%d ",cnt[i]);
}
