#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int f[3][3] = {{2,1,4},{4,2,1},{1,4,2}};
int n,m,mk,mp[5][5],s[3],t,x[2][6],y[2][6],str[2][6],typ[2][6],tot[2];

int Gao(int deep,int x[2][6],int y[2][6],int str[2][6],int typ[2][6],int tot[2],int player,int totmax,int totmin)
{
    int nowmin,nowmax,nowval,now;
    nowmin = 19921005;
    nowmax = -19921005;
    if (deep < mk)
    {
        int nx[2][6],ny[2][6],nstr[2][6],ntyp[2][6],ntot[2];
        for (int i = 0; i < tot[player]; i++)
        {
            //Ë­°ïÎÒÀ©Õ¹×´Ì¬°¡...
            nowval = Gao(deep+1,nx,ny,nstr,ntyp,ntot,!player,nowmax,nowmin)+now;
            nowmin = min(nowmin,nowval);
            nowmax = max(nowmax,nowval);
            if (player == 1 && nowmin < totmin) return nowmin;
            else if (player == 0 && nowmax > totmax)    return nowmax;
        }
    }
    if (player == 0)    return nowmax;
    else    return nowmin;
}

int main()
{
    while (true)
    {
        scanf("%d%d%d",&n,&m,&mk);
        if (n == 0 && m == 0 && mk == 0)    break;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d",&mp[i][j]);
        scanf("%d",&t);
        for (int i = 0; i < 3; i++)   scanf("%d",&s[i]);
        tot[0] = tot[1] = 0;
        for (int i = 0; i < t; i++)
        {
            int tx,ty,a,b,c;
            scanf("%d%d%d%d",&tx,&ty,&a,&b,&c);
            x[a][tot[a]] = tx;
            y[a][tot[a]] = ty;
            str[a][tot[a]] = b*2;
            typ[a][tot[a]] = c;
        }
        printf("%d\n",Gao(0,x,y,str,typ,tot,0,19921005,-19921005));
    }
    return 0;
}
