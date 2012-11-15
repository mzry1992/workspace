#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int mod1 = 1007;
const int mod2 = 9973;
int n;
char s[1100][110];
char RK[mod1+10][mod2+10];
char tpos[mod1+10][mod2+10];
int len[1100];
int res[1100];
int pos[1100];

void setRK(int ss,int pos,int a,int b)
{
    //cout << ss << ' ' << pos << ' ' << a << ' ' << b << endl;
    if (RK[a][b] == 0)
    {
        RK[a][b] = ss;
        tpos[a][b] = pos;
        return;
    }
    if (RK[a][b] == ss)    return;
    RK[a][b] = -1;
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 1;i <= n;i++)
        {
            scanf("%s",s[i]);
            res[i] = len[i] = strlen(s[i]);
            pos[i] = 0;
        }
        for (int i = 1;i <= 100;i++)
        {
            memset(RK,0,sizeof(RK));
            for (int j = 1;j <= n;j++)
            {
                if (len[j] < i) break;
                int RK1 = 0;    int RK2 = 0;
                int base1 = 1;  int base2 = 1;
                for (int k = 1;k <= i-1;k++)
                {
                    base1 = (base1*31)%mod1;
                    base2 = (base2*29)%mod2;
                }
                for (int k = 0;k < i;k++)
                {
                    RK1 = (RK1*31+s[j][k]-'a')%mod1;
                    RK2 = (RK2*29+s[j][k]-'a')%mod2;
                }
                setRK(j,0,RK1,RK2);
                for (int k = 1;k+i-1 < len[j];k++)
                {
                    RK1 = (RK1-((s[j][k-1]-'a')*base1)%mod1)%mod1;
                    RK2 = (RK2-((s[j][k-1]-'a')*base2)%mod1)%mod2;
                    if (RK1 < 0)    RK1 += mod1;
                    if (RK2 < 0)    RK2 += mod2;
                    RK1 = (RK1*31+s[j][k+i-1]-'a')%mod1;
                    RK2 = (RK2*29+s[j][k+i-1]-'a')%mod2;
                    setRK(j,k,RK1,RK2);
                }
            }
            for (int j = 1;j <= n;j++)
            {
                if (len[j] < i) break;
                int RK1 = 0;    int RK2 = 0;
                int base1 = 1;  int base2 = 1;
                for (int k = 1;k <= i-1;k++)
                {
                    base1 = (base1*31)%mod1;
                    base2 = (base2*29)%mod2;
                }
                for (int k = 0;k < i;k++)
                {
                    RK1 = (RK1*31+s[j][k]-'a')%mod1;
                    RK2 = (RK2*29+s[j][k]-'a')%mod2;
                }
                if (RK[RK1][RK2] > 0)
                {
                    if (res[RK[RK1][RK2]] > i)
                    {
                        res[RK[RK1][RK2]] = i;
                        pos[RK[RK1][RK2]] = tpos[RK1][RK2];
                    }
                }
                for (int k = 1;k+i-1 < len[j];k++)
                {
                    RK1 = (RK1-((s[j][k-1]-'a')*base1)%mod1)%mod1;
                    RK2 = (RK2-((s[j][k-1]-'a')*base2)%mod1)%mod2;
                    if (RK1 < 0)    RK1 += mod1;
                    if (RK2 < 0)    RK2 += mod2;
                    RK1 = (RK1*31+s[j][k+i-1]-'a')%mod1;
                    RK2 = (RK2*29+s[j][k+i-1]-'a')%mod2;
                    if (RK[RK1][RK2] > 0)
                    {
                        if (res[RK[RK1][RK2]] > i)
                        {
                            res[RK[RK1][RK2]] = i;
                            pos[RK[RK1][RK2]] = tpos[RK1][RK2];
                        }
                    }
                }
            }
        }
        for (int i = 1;i <= n;i++)
        {
            for (int j = pos[i];j < pos[i]+res[i];j++)
                printf("%c",s[i][j]);
            printf("\n");
        }
    }
}
