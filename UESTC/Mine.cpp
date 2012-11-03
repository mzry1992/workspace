#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int step[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int n,m,totmine;
char mp[11][11];
int a[120][120],b[120],totl,totr;
int id[11][11],rid[120][2];

bool checkin(int x,int y)
{
    return ((x >= 0) && (x < n) && (y >= 0) && (y < m));
}

void Gao()
{
    while (true)
    {
        totl = totr = 0;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
            {
                if (mp[i][j] == '#')
                {
                    id[i][j] = totr;
                    rid[totr][0] = i;
                    rid[totr++][1] = j;
                }
            }
        if (totr == 0)
        {
            for (int i = 0;i < n;i++)
                for (int j = 0;j < m;j++)
                    if (mp[i][j] == ' ')
                    {
                        int count = 0;
                        for (int k = 0;k < 8;k++)
                            if (checkin(i+step[k][0],j+step[k][1]) == true)
                                if (mp[i+step[k][0]][j+step[k][1]] == '*')
                                    count++;
                        mp[i][j] = '0'+count;
                    }
            for (int i = 0;i < n;i++)
            {
                for (int j = 0;j < m;j++)
                    printf("%c",mp[i][j]);
                printf("\n");
            }
            return;
        }
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for (int i = 0;i < totr;i++)
            a[totl][i] = 1;
        b[totl++] = totmine;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                if (mp[i][j] >= '0' && mp[i][j] <= '8')
                {
                    int count = mp[i][j]-'0';
                    for (int k = 0;k < 8;k++)
                        if (checkin(i+step[k][0],j+step[k][1]) == true)
                        {
                            if (mp[i+step[k][0]][j+step[k][1]] == '#')
                                a[totl][id[i+step[k][0]][j+step[k][1]]] = 1;
                            if (mp[i+step[k][0]][j+step[k][1]] == '*')
                                count--;
                        }
                    b[totl++] = count;
                    if (count == 0)
                    {
                        for (int k = 0;k < 8;k++)
                            if (checkin(i+step[k][0],j+step[k][1]) == true)
                                if (mp[i+step[k][0]][j+step[k][1]] == '#')
                                {
                                    a[totl][id[i+step[k][0]][j+step[k][1]]] = 1;
                                    b[totl++] = 0;
                                }
                    }
                }
        if (totl < totr)    totl = totr;
        for (int i = 0;i < totr;i++)
        {
            if (a[i][i] == 0)
                for (int j = i;j < totl;j++)
                    if (a[j][i] != 0)
                    {
                        for (int k = i;k < totr;k++)
                            swap(a[j][k],a[i][k]);
                        swap(b[j],b[i]);
                        break;
                    }
            if (a[i][i] == 0)   continue;
            for (int j = 0;j < totl;j++)
                if (i != j)
                {
                    int tmp = a[j][i]/a[i][i];
                    for (int k = i;k < totr;k++)
                        a[j][k] -= a[i][k]*tmp;
                    b[j] -= b[i]*tmp;
                }
        }
        int know = 0;
        for (int i = 0;i < totr;i++)
            if (a[i][i] != 0)
            {
                bool tflag = true;
                for (int j = 0;j < totr;j++)
                    if (j != i)
                        if (a[i][j] != 0)
                        {
                            tflag = false;
                            break;
                        }
                if (tflag == true)
                {
                    if (b[i] == 0)
                        mp[rid[i][0]][rid[i][1]] = ' ';
                    else
                    {
                        mp[rid[i][0]][rid[i][1]] = '*';
                        totmine--;
                    }
                    know++;
                }
            }
        if (know == 0)
        {
            printf("NO\n");
            return;
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d%d",&n,&m,&totmine);
        for (int i = 0;i < n;i++)
            scanf("%s",mp[i]);
        Gao();
        printf("\n");
    }
    return 0;
}
