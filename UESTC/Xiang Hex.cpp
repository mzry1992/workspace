#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

char map[1005][1005];
int cnt[15]={7,8,9,10,11,10,9,8,7},bot[15]={17,18,19,20,21,20,19,18,17},up[15]={4,3,2,1,0,1,2,3,4};
int bot1[15]={17,18,19,20,21,21,20,19,18,17};
int sharp[15]={5,4,3,2,1,1,2,3,4,5};
int last[25]={11,13,15,17,19,20,20,20,20,20,20,20,20,20,20,20,20,20,20,19,17,15,13,11};
char fuck[4]={'/','\\'};
//int last[]
int main()
{
    //freopen("c:\\tab.out","w",stdout);
    int n;
    while (scanf("%d",&n)>0,n!=0)
    {
        int cha=getchar();
        memset(map,' ',sizeof(map));
        for (int i=1;i<=17;i+=2)
            for (int j=up[i/2];j<=bot[i/2]+2;j+=2) map[j][i]='_';
        int now;
        for (int i=0;i<10;i++)
        {
            if (i<5) now=0;
            else now=1;
            for (int j=sharp[i];j<=bot1[i]+1;j++)
            {
                map[j][i*2]=fuck[now];
                now=1-now;
            }
        }
        char x;int y;
        char ch,gch;
        for (int i=0;i<23;i++)
            map[i][last[i]-1]=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%c%d %c%c",&x,&y,&ch,&gch);
            int dx=(x-'A')*2+1;
            int tmp=(x-'A');
            map[bot[tmp]-y*2][dx]=ch;
        }
        for (int i=0;i<23;i++) puts(map[i]);
    }
}
