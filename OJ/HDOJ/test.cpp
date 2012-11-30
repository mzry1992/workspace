#include"cstdio"
#include"cstring"
using namespace std;
char mp[210][210];
char d[210],cmp[210];
int h,w,mil,mal,aD,aR;
int in(int x,int y)
{
    if(x<h&&y<w)
        return 1;
    return 0;
}
int can_go(int x,int y)
{
    while(in(x,y))
    {
        if(mp[x][y]=='X')
            return 0;
        x+=aD;
        y+=aR;
    }
    return 1;
}
int dfs(int x,int y,int D,int R)
{
    if(!can_go(x,y))
        return 0;
    if (D==0&&R==0)
    {
        d[x+y]='\0';
        if(strcmp(d,cmp)<0)
            strcpy(cmp,d);
        return 1;
    }
    if (D>0)
    {
        d[x+y]='D';
        if (dfs(x+1,y,D-1,R))
            return 1;
    }
    if (R>0)
    {
        d[x+y]='R';
        if (dfs(x,y+1,D,R-1))
            return 1;
    }
    return 0;

}
int main()
{
    while(scanf("%d%d%d%d",&h,&w,&mil,&mal) != EOF)
    {
        memset(mp,0,sizeof(mp));
        int i,j;
        for (int i=0; i<h; i++)
            scanf("%s", mp[i]);
        int find =0,flag=1;
        for (int L=mil; flag&&L<=mal; L++)
        {
            cmp[0]='Z';
            cmp[1]='\0';
            for (aD=L; aD>=0; aD--)
            {
                find=dfs(0,0,aD,aR=L-aD);
                if(find)
                    flag=0;
            }
        }
        printf("%s\n",cmp);
    }
    return 0;
}

