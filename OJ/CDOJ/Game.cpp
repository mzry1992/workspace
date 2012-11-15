#include <stdio.h>

short tmp[15],tot[8];
short ft,i,t;
bool now;

int main()
{
    scanf("%d",&t);
    for (ft = 1;ft <= t;ft++)
    {
        for (i = 0;i < 15;i++)
            scanf("%d",&tmp[i]);
        tot[0] = tmp[1]*2;
        tot[1] = tmp[0]*2;
        tot[2] = tmp[2]+tmp[3];
        tot[3] = tmp[4]+tmp[5];
        tot[4] = tmp[6]+tmp[7];
        tot[5] = tmp[8]+tmp[9];
        tot[6] = tmp[10]+tmp[11]+tmp[12]+tmp[13];
        tot[7] = tmp[14];
        now = 0;
        while (1)
        {
            if (now == 0)
            {
                if (tot[7] > 0)
                {
                    tot[7]--;
                    tot[1]++;
                }
                else if (tot[2] > 0)
                {
                    tot[2]--;
                }
                else if (tot[3] > 0)
                {
                    tot[3]--;
                    tot[1]++;
                }
                else if (tot[6] > 0)
                {
                    tot[6]--;
                }
                else if (tot[5] > 0)
                {
                    tot[5]--;
                    tot[0]++;
                }
                else if (tot[4] > 0)
                {
                    tot[4]--;
                }
                else if (tot[1] > 0)
                {
                    tot[1]--;
                }
                else
                    break;
            }
            else
            {
                if (tot[7] > 0)
                {
                    tot[7]--;
                    tot[0]++;
                }
                else if (tot[3] > 0)
                {
                    tot[3]--;
                }
                else if (tot[2] > 0)
                {
                    tot[2]--;
                    tot[0]++;
                }
                else if (tot[6] > 0)
                {
                    tot[6]--;
                }
                else if (tot[4] > 0)
                {
                    tot[4]--;
                    tot[1]++;
                }
                else if (tot[5] > 0)
                {
                    tot[5]--;
                }
                else if (tot[0] > 0)
                {
                    tot[0]--;
                }
                else
                    break;
            }
            now = 1-now;
        }
        printf("Case #%d: ",ft);
        if (now == 0)
            puts("Bob");
        else
            puts("Alice");
    }
    return 0;
}
