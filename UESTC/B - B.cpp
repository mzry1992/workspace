#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int step[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m,totdel,tot,peo[40],totxl[40];
char mp[40][40];
bool del[40],app[40],xl[40][40];

bool checkin(int x,int y)
{
    if (x < 0 || x > n-1 || y < 0 || y > m-1)   return false;
    return true;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        memset(app,false,sizeof(app));
        for (int i = 0;i < n;i++)
        {
            scanf("%s",mp[i]);
            for (int j = 0;j < m;j++)
                app[mp[i][j]-'A'] = true;
        }
        tot = 0;
        for (int i = 0;i < 26;i++)
            if (app[i] == true) tot++;
        for (int i = 0;i < tot;i++)
            scanf("%d",&peo[i]);
        int emy;
        scanf("%d",&emy);
        totdel = 0;
        memset(del,false,sizeof(del));
        while (true)
        {
            memset(xl,false,sizeof(xl));
            for (int x = 0;x < n;x++)
                for (int y = 0;y < m;y++)
                    if (del[mp[x][y]-'A'] == false)
                        for (int f = 0;f < 4;f++)
                            if (checkin(x+step[f][0],y+step[f][1]) == true)
                                if (mp[x][y] != mp[x+step[f][0]][y+step[f][1]])
                                    if (del[mp[x+step[f][0]][y+step[f][1]]-'A'] == false)
                                        xl[mp[x][y]-'A'][mp[x+step[f][0]][y+step[f][1]]-'A'] = true;
            memset(totxl,0,sizeof(totxl));
            for (int i = 0;i < tot;i++)
                if (del[i] == false)
                    for (int j = 0;j < tot;j++)
                        if (del[j] == false)
                            if (xl[i][j] == true)
                                totxl[i]++;
            bool canatk = false;
            for (int i = 0;i < tot;i++)
                if (del[i] == false)
                {
                    int totpeo = peo[i];
                    for (int j = 0;j < tot;j++)
                        if (del[j] == false)
                            if (xl[i][j] == true)
                                totpeo += peo[j]/(totxl[j]+1);
                    if (emy > totpeo)
                    {
                        canatk = true;
                        del[i] = true;
                        peo[i] = 0;
                        totdel++;
                        for (int j = 0;j < tot;j++)
                            if (del[j] == false)
                                if (xl[i][j] == true)
                                    peo[j] -= peo[j]/(totxl[j]+1);
                        break;
                    }
                }
            if (canatk == false)    break;
        }
        if (totdel == tot)
            printf("Saruman\n");
        else
            printf("Human\n");
    }
    return 0;
}
