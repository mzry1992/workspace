#include <stdio.h>
#include <string.h>

char result,left1[20],right1[20],info1[20],left2[20],right2[20],info2[20],left3[20],right3[20],info3[20];
int n,fn,len,i,j,wl,wr,tot;

int getinfo(char *info)
{
    int len = strlen(info);
    if (len == 2) return 2;
    if (info[0] == 'e') return 1;
    return 0;
}

int main()
{
    scanf("%d",&n);
    for (fn = 1;fn <= n;fn++)
    {
        scanf("%s %s %s",&left1,&right1,&info1);
        scanf("%s %s %s",&left2,&right2,&info2);
        scanf("%s %s %s",&left3,&right3,&info3);
        for (result = 'A';result <= 'L';result++)
        {
            tot = 0;
            
            wl = 1;
            wr = 1;
            len = strlen(left1);
            for (i = 0;i < len;i++)
            {
                if (left1[i] == result)          wl = 0;
                if (right1[i] == result)         wr = 0;
            }
            if ((getinfo(info1) == 0) && (wl < wr))  tot++;
            if ((getinfo(info1) == 1) && (wl == wr))  tot++;
            if ((getinfo(info1) == 2) && (wl > wr))  tot++;
            
            wl = 1;
            wr = 1;
            len = strlen(left2);
            for (i = 0;i < len;i++)
            {
                if (left2[i] == result)          wl = 0;
                if (right2[i] == result)         wr = 0;
            }
            if ((getinfo(info2) == 0) && (wl < wr))  tot++;
            if ((getinfo(info2) == 1) && (wl == wr))  tot++;
            if ((getinfo(info2) == 2) && (wl > wr))  tot++;
            wl = 1;
            wr = 1;
            len = strlen(left3);
            for (i = 0;i < len;i++)
            {
                if (left3[i] == result)          wl = 0;
                if (right3[i] == result)         wr = 0;
            }
            if ((getinfo(info3) == 0) && (wl < wr))  tot++;
            if ((getinfo(info3) == 1) && (wl == wr))  tot++;
            if ((getinfo(info3) == 2) && (wl > wr))  tot++;
            
            if (tot == 3)
            {
                    printf("%c is the counterfeit coin and it is light.\n",result);
                    break;
            }
            
            tot = 0;
            
            wl = 1;
            wr = 1;
            len = strlen(left1);
            for (i = 0;i < len;i++)
            {
                if (left1[i] == result)          wl = 2;
                if (right1[i] == result)         wr = 2;
            }
            if ((getinfo(info1) == 0) && (wl < wr))  tot++;
            if ((getinfo(info1) == 1) && (wl == wr))  tot++;
            if ((getinfo(info1) == 2) && (wl > wr))  tot++;
            
            wl = 1;
            wr = 1;
            len = strlen(left2);
            for (i = 0;i < len;i++)
            {
                if (left2[i] == result)          wl = 2;
                if (right2[i] == result)         wr = 2;
            }
            if ((getinfo(info2) == 0) && (wl < wr))  tot++;
            if ((getinfo(info2) == 1) && (wl == wr))  tot++;
            if ((getinfo(info2) == 2) && (wl > wr))  tot++;
            wl = 1;
            wr = 1;
            len = strlen(left3);
            for (i = 0;i < len;i++)
            {
                if (left3[i] == result)          wl = 2;
                if (right3[i] == result)         wr = 2;
            }
            if ((getinfo(info3) == 0) && (wl < wr))  tot++;
            if ((getinfo(info3) == 1) && (wl == wr))  tot++;
            if ((getinfo(info3) == 2) && (wl > wr))  tot++;
            
            if (tot == 3)
            {
                    printf("%c is the counterfeit coin and it is heavy.\n",result);
                    break;
            }
        }
    }
    return 0;
}
