#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char buf[20];
int len,res;
long long a[20],num[20][20];

void DFS(int now,int pos,int pre)
{
    if (pos == len)
    {
        if (now > 1)
        {
            long long sum = 0;
            for (int i = 0;i < now;i++)
                sum += a[i];
            long long pre = 0;
            for (int i = 0;i+1 < now;i++)
            {
                pre += a[i];
                if (sum-pre == pre)
                {
//                    for (int j = 0;j <= i;j++)
//                        printf("%I64d ",a[j]);
//                    printf(" = ");
//                    for (int j = i+1;j < now;j++)
//                        printf("%I64d ",a[j]);
//                    printf("\n");
                    res++;
                }
            }
        }
        return;
    }

    if (pos+1 < len)
        DFS(now,pos+1,pre);

    a[now] = num[pre][pos];
    DFS(now+1,pos+1,pos+1);
}

int main()
{
    while (true)
    {
        scanf("%s",buf);
        if (strcmp(buf,"END") == 0)
            break;
        len = strlen(buf);
        for (int i = 0;i < len;i++)
        {
            num[i][i-1] = 0;
            for (int j = i;j < len;j++)
                num[i][j] = num[i][j-1]*10+buf[j]-'0';
        }
        res = 0;
        DFS(0,0,0);
        printf("%d\n",res);
    }
	return 0;
}
