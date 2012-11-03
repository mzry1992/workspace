#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int step[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

int n;
char mp[15][15],tmp[15][15];
int id[10][10],rid[20][2],totid;
bool gaoguo[1<<20];
string res,tres;

void updata(int sta,int tot)
{
    int tn = totid/tot;
    int mx,my,x,y;
    mx = my = n;
    for (int i = 0;i < totid;i++)
        if (((sta>>i)&1) == 1)
            if (rid[i][0] < mx || (rid[i][0] == mx && rid[i][1] < my))
            {
                mx = rid[i][0];
                my = rid[i][1];
            }
    /*cout << sta << ' ' << tot << endl;
    cout << mx << ' ' << my << endl;*/
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
            tmp[i][j] = mp[i][j];
    for (int i = 0;i < tn;i++)
    {
        for (int j = 0;j < totid;j++)
            if (tmp[rid[j][0]][rid[j][1]] == '*')
            {
                for (int k = 0;k < totid;k++)
                    if (((sta>>k)&1) == 1)
                    {
                        x = rid[k][0]-mx+rid[j][0];
                        y = rid[k][1]-my+rid[j][1];
                        if (tmp[x][y] != '*')   return;
                        tmp[x][y] = 'A'+i;
                        tres[id[x][y]] = tmp[x][y];
                    }
                break;
            }
        /*for (int j = 0;j < n;j++)
        {
            for (int k = 0;k < n;k++)
                cout << tmp[j][k];
            cout << endl;
        }
        cout << "========" << endl;*/
    }
    res = min(res,tres);
}

void Gao(int sta,int tot)
{
    int x,y,tx,ty,nid;
    if (gaoguo[sta] == true)    return;
    gaoguo[sta] = true;
    if (tot*2 > totid)  return;
    if (totid%tot == 0)
        updata(sta,tot);
    for (int i = 0;i < totid;i++)
        if (((sta>>i)&1) == 1)
        {
            x = rid[i][0];
            y = rid[i][1];
            for (int j = 0;j < 4;j++)
            {
                tx = x+step[j][0];
                ty = y+step[j][1];
                if (tx < 0 || tx >= n || ty < 0 || ty >= n) continue;
                if (mp[tx][ty] != '*')  continue;
                nid = id[tx][ty];
                if (((sta>>nid)&1) == 0)
                    Gao(sta|(1<<nid),tot+1);
            }
        }
}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        for (int i = 0;i < n;i++)
            scanf("%s",mp[i]);
        totid = 0;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                if (mp[i][j] == '*')
                {
                    rid[totid][0] = i;
                    rid[totid][1] = j;
                    id[i][j] = totid++;
                }
        memset(gaoguo,false,sizeof(gaoguo));
        res.resize(totid);
        for (int i = 0;i < totid;i++)
            res[i] = 'A'+i;
        tres = res;
        Gao(1,1);
        for (int i = 0;i < totid;i++)
            mp[rid[i][0]][rid[i][1]] = res[i];
        for (int i = 0;i < n;i++)
            printf("%s\n",mp[i]);
        printf("\n");
    }
    return 0;
}
