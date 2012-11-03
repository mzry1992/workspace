#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const int NSIZE = 50010;
int tree[1][NSIZE*4];
int lazy[1][NSIZE*4];

int N , M;
void init() {
    memset(tree[0],-1,M*16);
    memset(lazy[0],-1,M*16);
}

void clear(int n,int x,int l,int r) {
    n = 0;
    if (lazy[n][x]==-1)
        return ;
    tree[n][x]=lazy[n][x];
    if (l<r)
        lazy[n][x*2]=lazy[n][x*2+1]=lazy[n][x];
    lazy[n][x]=-1;
}
void update(int n,int x,int l,int r,int s,int t,int v) {
    n = 0;
    if (s<=l && r<=t) {
        lazy[n][x]=v;
        clear(n,x,l,r);
        return ;
    }
    int mid=l+r>>1;
    if (s<=mid)
        update(n,x*2,l,mid,s,t,v);
    else
        clear(n,x*2,l,mid);
    if (t>mid)
        update(n,x*2+1,mid+1,r,s,t,v);
    else
        clear(n,x*2+1,mid+1,r);
    if (tree[n][x*2]==tree[n][x*2+1])
        tree[n][x]=tree[n][x*2];
    else
        tree[n][x]=-2;
}
vector<int> read(int n,int x,int l,int r) {
    n = 0;
    vector<int> ret;
    for (int i=0; i<9; i++)
        ret.push_back(0);
    if (tree[n][x]!=-2) {
        if (tree[n][x]==-1)
            return ret;
        ret[tree[n][x]]=r-l+1;
        return ret;
    }
    int mid=l+r>>1;
    vector<int> tmp1=read(n,x*2,l,mid),tmp2=read(n,x*2+1,mid+1,r);
    for (int i=0; i<9; i++)
        ret[i]=tmp1[i]+tmp2[i];
    return ret;
}

int ix;
void paintCircle(int xc,int yc,int r,int col) {
    int xl = max(xc-r ,0) , xr = min(xc+r,N-1);
    if(ix < xl || ix > xr) return;
    for(int x = ix ; x <=ix ; x++) {
        int ymin = ceil(yc - (sqrt((double)(r*r - (x -xc)*(x-xc)) )));
        int ymax = floor(yc + (sqrt((double)(r*r - (x -xc)*(x-xc)) )));
        ymin = max(0,ymin);
        ymax = min(M-1,ymax);
//        test(ix,ymin,ymax,col);
        update(x,1,0,M-1,ymin , ymax,col);
    }
}
void paintDiamond(int xc,int yc,int r,int col) {
    int xl = max(xc-r , 0) , xr = min(xc+r,N-1);
    if(ix < xl || ix > xr) return;
    for(int x = ix ; x <=ix ; x++) {
        int ymin = yc - r + abs(xc-x);
        int ymax = yc + r- abs(xc-x);
        ymin = max(0,ymin);
        ymax = min(M-1,ymax);
//        test(ix,ymin,ymax,col);
        update(x,1,0,M-1,ymin,ymax,col);
    }
}
void paintRect(int xc,int yc,int l,int w,int col) {
    int xl = max(xc,0) , xr = min(xc+l-1,N-1);
    if(ix < xl || ix > xr) return;
    for(int x = ix ; x <=ix ; x++) {
        int ymin = yc;
        int ymax = yc + w-1;
        ymin = max(0,ymin);
        ymax = min(M-1,ymax);
        //printf("ymin = %d ymax = %d M = %d l = %d w= %d \n",ymin,ymax,M,l,w);
//        test(ix,ymin,ymax,col);
        update(x,1,0,M-1,ymin,ymax,col);
    }
}
void paintTri(int xc,int yc,int w,int col) {
    int h = (w+1)/2;
    int xl = max(xc-w/2 , 0) , xr = min(xc+w/2,N-1);
    if(ix < xl || ix > xr) return;
    for(int x = ix ; x <=ix ; x++) {
        int ymin = yc;
        int ymax = yc + h-abs(xc-x) -1;
        ymin = max(0,ymin);
        ymax = min(M-1,ymax);
//        test(ix,ymin,ymax,col);
        update(x,1,0,M-1,ymin,ymax,col);
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
int ans_cnt[9];
char cmd[50010][20];
int data[50010][5];
int main() {
    freopen("in.txt","r",stdin);
    freopen("out2.txt","w",stdout);
    int Qn;
    vector<int> vec;
    while(scanf("%d%d%d",&N,&M,&Qn) == 3) {
        memset(ans_cnt , 0, sizeof(ans_cnt));
        for(int i = 0 ; i < Qn; i++){
            scanf("%s",cmd[i]);
            if(cmd[i][0] == 'R')
                for(int j = 0 ; j< 5;j++)
                    data[i][j] = readint();
            else
                for(int j = 0 ;j < 4;j++)
                    data[i][j] = readint();
        }

        for(ix = 0 ; ix< N; ix++) {
            init();
            for(int i = 0 ; i < Qn; i++) {

                if(cmd[i][0] == 'D') {
                    int xc,yc,r,c;
                    xc = data[i][0];
                    yc = data[i][1];
                    r = data[i][2];
                    c = data[i][3];
                    //scanf("%d%d%d%d",&xc,&yc,&r,&c);
                    --c;
                    paintDiamond(xc,yc,r,c);
                } else if(cmd[i][0] == 'T') {
                    int xc, yc, w, c;
                    xc = data[i][0];
                    yc = data[i][1];
                    w = data[i][2];
                    c = data[i][3];
                    //scanf("%d%d%d%d",&xc,&yc,&w,&c);
                    --c;
                    paintTri(xc,yc,w,c);
                } else if(cmd[i][0] == 'R') {
                    int xc,yc,w,l,c;
                    xc = data[i][0];
                    yc = data[i][1];
                    l = data[i][2];
                    w = data[i][3];
                    c = data[i][4];
                    //scanf("%d%d%d%d%d",&xc, &yc, &l, &w, &c);
                    --c;
                    paintRect(xc,yc,l,w,c);
                } else if(cmd[i][0] == 'C') {
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
            vec = read(0,1,0,M-1);
            for(int c = 0 ;c < 9 ; c++)
                ans_cnt[c] += vec[c];
        }

        printf("%d",ans_cnt[0]);
        for(int i = 1 ; i < 9 ; i++)
            printf(" %d",ans_cnt[i]);
        puts("");
    }
    return 0;
}
