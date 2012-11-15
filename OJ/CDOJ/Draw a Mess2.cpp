#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int ans_cnt[9];
const int NSIZE = 50010;
int fa[NSIZE + 1];
int N , M;
void init()
{
    for(int i = 0 ; i <= M; i++)
        fa[i] = i ;
}
int find(int x)
{
    if (fa[x]==x)
        return x;
    else
        return fa[x]=find(fa[x]);
}
void update(int l,int r,int c)
{
    for (int i=l; i<=r; i++)
    {
        i=find(i);
        if (i>r) return;
        ans_cnt[c]++;
        fa[i]=find(i+1);
    }
}

int ix;
void paintCircle(int xc,int yc,int r,int col)
{
    int xl = max(xc-r ,0) , xr = min(xc+r,N-1);
    if(ix < xl || ix > xr) return;
    for(int x = ix ; x <=ix ; x++)
    {
        int ymin = ceil(yc - (sqrt((double)(r*r - (x -xc)*(x-xc)) )));
        int ymax = floor(yc + (sqrt((double)(r*r - (x -xc)*(x-xc)) )));
        ymin = max(0,ymin);
        ymax = min(M-1,ymax);
//        test(ix,ymin,ymax,col);
        update(ymin,ymax,col);
    }
}
void paintDiamond(int xc,int yc,int r,int col)
{
    int xl = max(xc-r , 0) , xr = min(xc+r,N-1);
    if(ix < xl || ix > xr) return;
    for(int x = ix ; x <=ix ; x++)
    {
        int ymin = yc - r + abs(xc-x);
        int ymax = yc + r- abs(xc-x);
        ymin = max(0,ymin);
        ymax = min(M-1,ymax);
//        test(ix,ymin,ymax,col);
        update(ymin,ymax,col);
    }
}
void paintRect(int xc,int yc,int l,int w,int col)
{
    int xl = max(xc,0) , xr = min(xc+l-1,N-1);
    if(ix < xl || ix > xr) return;
    for(int x = ix ; x <=ix ; x++)
    {
        int ymin = yc;
        int ymax = yc + w-1;
        ymin = max(0,ymin);
        ymax = min(M-1,ymax);
        //printf("ymin = %d ymax = %d M = %d l = %d w= %d \n",ymin,ymax,M,l,w);
//        test(ix,ymin,ymax,col);
        update(ymin,ymax,col);
    }
}
void paintTri(int xc,int yc,int w,int col)
{
    int h = (w+1)/2;
    int xl = max(xc-w/2 , 0) , xr = min(xc+w/2,N-1);
    if(ix < xl || ix > xr) return;
    for(int x = ix ; x <=ix ; x++)
    {
        int ymin = yc;
        int ymax = yc + h-abs(xc-x) -1;
        ymin = max(0,ymin);
        ymax = min(M-1,ymax);
//        test(ix,ymin,ymax,col);
        update(ymin,ymax,col);
    }
}
int wg;
char ch;
bool ng;

inline int readint()
{
    ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9'))    ch = getchar();
    if (ch == '-')
    {
        ng = true;
        ch = getchar();
    }
    else ng = false;
    wg = ch-'0';
    ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        wg = wg*10+ch-'0';
        ch = getchar();
    }
    if (ng == true) wg = -wg;
    return wg;
}
char ts[20];
char cmd[50010][20];
int data[50010][5];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out1.txt","w",stdout);
    int Qn;
    while(scanf("%d%d%d",&N,&M,&Qn) == 3)
    {
        memset(ans_cnt , 0, sizeof(ans_cnt));
        for(int i = 0 ; i < Qn; i++)
        {
            scanf("%s",cmd[i]);
            if(cmd[i][0] == 'R')
                for(int j = 0 ; j< 5; j++)
                    data[i][j] = readint();
            else
                for(int j = 0 ; j < 4; j++)
                    data[i][j] = readint();
        }

        for(ix = 0 ; ix< N; ix++)
        {
            init();
            for(int i = Qn-1 ; i >=0 ; i--)
            {

                if(cmd[i][0] == 'D')
                {
                    int xc,yc,r,c;
                    xc = data[i][0];
                    yc = data[i][1];
                    r = data[i][2];
                    c = data[i][3];
                    //scanf("%d%d%d%d",&xc,&yc,&r,&c);
                    --c;
                    paintDiamond(xc,yc,r,c);
                }
                else if(cmd[i][0] == 'T')
                {
                    int xc, yc, w, c;
                    xc = data[i][0];
                    yc = data[i][1];
                    w = data[i][2];
                    c = data[i][3];
                    //scanf("%d%d%d%d",&xc,&yc,&w,&c);
                    --c;
                    paintTri(xc,yc,w,c);
                }
                else if(cmd[i][0] == 'R')
                {
                    int xc,yc,w,l,c;
                    xc = data[i][0];
                    yc = data[i][1];
                    l = data[i][2];
                    w = data[i][3];
                    c = data[i][4];
                    //scanf("%d%d%d%d%d",&xc, &yc, &l, &w, &c);
                    --c;
                    paintRect(xc,yc,l,w,c);
                }
                else if(cmd[i][0] == 'C')
                {
                    int xc, yc, r, c;
                    xc  = data[i][0];
                    yc  = data[i][1];
                    r   = data[i][2];
                    c   = data[i][3];
                    //scanf("%d%d%d%d",&xc, &yc, &r, &c);
                    --c;
                    paintCircle(xc,yc,r,c);
                }
            }
        }

        printf("%d",ans_cnt[0]);
        for(int i = 1 ; i < 9 ; i++)
            printf(" %d",ans_cnt[i]);
        puts("");
    }
    return 0;
}
