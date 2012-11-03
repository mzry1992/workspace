#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf = 0x3f3f3f3f;
char s[4097],t[4][65];
bool can[4097][4];
int lens,lent[4];
int dpmin[4097][1<<4][65];
int dpmax[4097][1<<4][65];

int main()
{
    while (scanf("%s",s) != EOF)
    {
        lens = strlen(s);
		int maxlen = 0;
        for (int i = 0; i < 4; i++)
        {
            scanf("%s",t[i]);
            lent[i] = strlen(t[i]);
			maxlen = max(maxlen,lent[i]);
        }

        for (int i = 0; i < lens; i++)
            for (int j = 0; j < 4; j++)
            {
                bool flag = true;
                if (i+lent[j] > lens)
                    flag = false;
                for (int k = 0; k < lent[j] && flag; k++)
                    if (s[i+k] != t[j][k])
                        flag = false;
                can[i][j] = flag;
            }

        for (int i = 0; i <= lens; i++)
            for (int j = 0; j < 16; j++)
                for (int len = 0; len < 65; len++)
                {
                    dpmin[i][j][len] = inf;
                    dpmax[i][j][len] = -inf;
                }

        dpmin[0][0][0] = dpmax[0][0][0] = 0;

        for (int i = 0; i < lens; i++)
            for (int j = 0; j < 16; j++)
                for (int len = 0; len <= maxlen; len++)
                {
                    for (int now = 0; now < 4; now++)
						if (((j>>now)&1) == 0 && can[i][now])
                        {
                            int newj = j|(1<<now);
                            int newlen = max(len,lent[now]);

                            dpmin[i][newj][newlen] = min(dpmin[i][newj][newlen],dpmin[i][j][len]);
                            dpmax[i][newj][newlen] = max(dpmax[i][newj][newlen],dpmax[i][j][len]);
                        }
                    int newlen = max(0,len-1);
                    int add = (len > 0);

                    dpmin[i+1][j][newlen] = min(dpmin[i+1][j][newlen],dpmin[i][j][len]+add);
                    dpmax[i+1][j][newlen] = max(dpmax[i+1][j][newlen],dpmax[i][j][len]+add);
                }

        int ansmin = inf;
        int ansmax = -inf;

        for (int i = 0; i <= maxlen; i++)
        {
            ansmin = min(ansmin,dpmin[lens][15][i]+i);
            ansmax = max(ansmax,dpmax[lens][15][i]+i);
        }

        printf("%d %d\n",ansmin,ansmax);
    }
    return 0;
}
