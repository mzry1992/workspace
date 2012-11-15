#include <iostream>
#include <cstring>
using namespace std;

char a[1010],b[10000];
int ac[1010][26],tmin[2][1010][2];

void init_AC(char *p) 
{
    int pi[1010], k = -1, len = strlen(p);
    pi[0] = -1;
    memset(ac, 0, sizeof(ac));
    ac[0][*p - 'a'] = 1;
    for(int i = 1; i < len; ++i) 
    {
            while(k >= 0 && p[k + 1] != p[i]) k = pi[k];
            if(p[k + 1] == p[i]) ++k;
            pi[i] = k;
            memcpy(ac[i], ac[pi[i - 1] + 1], sizeof(ac[0]));
            ac[i][p[i] - 'a'] = i + 1;
    }
}

int solve() 
{
    int i, j, l, k, re = -1;
    memset(tmin,-1,sizeof(tmin));
    tmin[0][0][0] = 0; tmin[0][0][1] = -1;
    tmin[1][0][0] = 0; tmin[1][0][1] = -1;
    for(i = 0; b[i]; ++i) 
    {
        l = b[i] - 'a';
        for(j = 0; a[j] && tmin[0][j][0] != -1; ++j) 
        {
            k = ac[j][l];
            if(tmin[1][k][0] == - 1 || tmin[1][k][0] - tmin[1][k][1] > tmin[0][j][0] - tmin[0][j][1] - 1) 
            {
                    tmin[1][k][0] = tmin[0][j][0] + i - tmin[0][j][1] - 1;
                    tmin[1][k][1] = i;
            }
        }
        memcpy(tmin[0], tmin[1], sizeof(tmin[0]));
    }
    for(j = 0; a[j] && tmin[0][j][0] != -1; ++j) 
    {
        if(re == -1 || tmin[0][j][0] + i - tmin[0][j][1] - 1 < re) 
        {
            re = tmin[0][j][0] + i - tmin[0][j][1] - 1;
        }
    }
    return re;
}

int main() 
{
    int t,ft;
    char blank[300];
    scanf("%d\n",&t);
    for (ft = 1;ft <= t;ft++)
    {
        gets(b);
        gets(a);
        gets(blank);
        init_AC(a);
        printf("%d\n",solve());
    }
    return 0;
}
