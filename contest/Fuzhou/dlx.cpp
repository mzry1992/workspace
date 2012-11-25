#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<iostream>
using namespace std;
const int M = 42000;
const int N = 1025;
//dlx
int U[M],D[M],L[M],R[M];
int B[M],S[N];
int ox[M] , oy[M] , onum[M];
int head;
//dlx


int mp[81*81][81*81];
int rx[5000]  , ry[5000]  , rnum[5000];
int bid[17][17];
int use;
int rcnt = 0;
int m;
void clr()
{
    use = 0;
    head = 0;
    rcnt = 0;
    memset(mp,0,sizeof(mp));
}
void add(int x,int y,int num)
{
    rcnt++;
    //block
    mp[rcnt][bid[x][y]*9+num+1] = 1;
    //row
    mp[rcnt][9*9+9*y+num+1] =1;
    mp[rcnt][9*9+9*9+9*x + num +1] =1;
    mp[rcnt][9*9+9*9+9*9 +x*9+y+1] = 1;

    rx[rcnt] =x;
    ry[rcnt] = y;
    rnum[rcnt] = num;
}

int node(int l,int r,int u,int d)
{
    L[use] = l;
    R[use] = r;
    U[use] = u;
    D[use] = d;

    R[l] = L[r] = D[u] = U[d] = use;

    return use++;
}
void build()
{
    head = node(0,0,0,0);
    for(int i=1; i<=m; i++)
    {
        int tp = node(L[head] , head , i,i);
        B[tp] = i;
        S[i] = 0;
    }
    for(int i=1,row = -1; i<=rcnt; i++,row = -1)
        for(int j=1; j<=m; j++)
        {
            if(!mp[i][j])continue;
            if(row == -1)
            {
                row = node(use,use,U[j],j);
                ox[row] = rx[i];
                oy[row] = ry[i];
                onum[row] = rnum[i];
                B[row] = j;
                S[j]++;
            }
            else
            {
                int tp = node(L[row] , row ,U[j],j);
                ox[tp] = rx[i];
                oy[tp] = ry[i];
                onum[tp] = rnum[i];
                B[tp] = j;
                S[j]++;
            }
        }

}
void remove(int c)
{
    int t = c;
    L[R[t]] = L[t];
    R[L[t]] = R[t];

    for(int p=D[t]; p!=t; p=D[p])
        for(int p2= R[p]; p2!=p; p2=R[p2])
        {
            U[D[p2]] = U[p2];
            D[U[p2]] = D[p2];
            S[B[p2]] --;
        }
}
void resume(int c)
{
    int t = c;

    for(int p = U[t]; p!=t; p=U[p])
        for(int p2= L[p]; p2!=p; p2=L[p2])
        {
            D[U[p2]] = U[D[p2]] = p2;
            S[B[p2]] ++;
        }
    R[L[t]] = L[R[t]] = t;
}
int ans[17][17];
bool ext_sol;
int dfs()
{
    if(R[head] == head)
    {
        if(ext_sol == true)
        {
            return 2;
        }
        ext_sol = true;
        return 1;
    }
    int mm = 1000000000 , ps = -1;
    for(int i=R[head]; i!=head; i=R[i])
    {
        if(S[i] < mm)
        {
            mm = S[i];
            ps = i;
        }
    }
    remove(ps);
    bool eext = false;

    for(int pt = D[ps]; pt !=ps; pt = D[pt])
    {
        for(int p2 = R[pt] ; p2!=pt; p2=R[p2])
            remove(B[p2]);
        int dst = dfs();
        if(dst > 0) eext = true;
        if(dst >= 1)
        {
            ans[ox[pt]][oy[pt]] = onum[pt];
        }
        if(dst == 2) return 2;
        for(int p2 = L[pt]; p2!=pt; p2 = L[p2])
            resume(B[p2]);
    }
    resume(ps);

    return eext;
}
int grid[9][9];
int dx[4] = {-1,0,1,0};
int dy[4] = {0, 1,0,-1};
void Gdfs(int x,int y,int id)
{
    bid[x][y] = id;
    for(int di = 0 ; di < 4; di++)
    {
        int nx = x + dx[di];
        int ny = y + dy[di];
        if(nx >=0 && ny >=0 && nx<9 && ny < 9 && ((grid[x][y]>>(4+di))&1)!=1 && bid[nx][ny] == -1)
            Gdfs(nx,ny,id);
    }
}
void gen_belong()
{
    memset(bid,-1,sizeof(bid));
    int id_cnt = 0;
    for(int i = 0 ; i < 9 ; i++)
        for(int j = 0; j < 9 ; j++)
            if(bid[i][j] == -1)
                Gdfs(i,j,id_cnt++);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int ii = 1; ii<=T; ii++)
    {
        ext_sol = false;
        for(int i = 0 ; i < 9 ; i++)
            for(int j= 0; j<9; j++)
                scanf("%d",&grid[i][j]);
        m = (9+9+9)*9 + 9*9;
        gen_belong();

        clr();
        for(int i=0; i<9; i++)
        {
            for(int j = 0; j < 9 ;j++)
                if(grid[i][j]&15)
                    add(i,j,(grid[i][j]&15)-1);
                else
                    for(int c = 0 ; c < 9 ;c++)
                        add(i,j,c);
        }
        /*for(int i = 1 ;i <=rcnt; i++,puts(""))
            for(int j = 1; j <= m ;j ++)
                printf("%d",mp[i][j]);*/
        build();
        int dst = dfs();
        printf("Case %d:\n",ii);
        if(dst == 2){
            printf("Multiple Solutions\n");
        }else if(dst == 0){
            printf("No solution\n");
        }else{
        for(int i=0; i<9; i++,putchar('\n'))
            for(int j=0; j<9; j++)
                printf("%d",ans[i][j]+1);
        }
    }
    return 0;
}
