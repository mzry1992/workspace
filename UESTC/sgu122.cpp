#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
char buf[10000];
int buflen;
int ans[2000],ansn,tans[2000];
bool visit[1000],e[1000][1000];

void Gao(int now)
{
    visit[now] = true;
    ans[ansn++] = now;
    for (int i = 0; i < n; i++)
        if (e[now][i] == true && visit[i] == false)
        {
            Gao(i);
            return;
        }
}

int main()
{
    scanf("%d",&n);
    gets(buf);
    memset(e,false,sizeof(e));
    for (int i = 0; i < n; i++)
    {
        gets(buf);
        buflen = strlen(buf);
        for (int j = 0; j < buflen;)
            if (buf[j] >= '0' && buf[j] <= '9')
            {
                int v = 0;
                for (; buf[j] >= '0' && buf[j] <= '9'; j++)
                    v = v*10+buf[j]-'0';
                v--;
                e[i][v] = e[v][i] = true;
            }
            else    j++;
    }
    ansn = 0;
    memset(visit,false,sizeof(visit));
    bool flag1,flag2;
    Gao(0);
    while (true)
    {
        for (int i = 1; i < ansn; i++)
            if (e[ans[0]][ans[i]] && e[ans[i-1]][ans[ansn-1]])
            {
                for (int j = 0; j < i; j++)   tans[j] = ans[j];
                for (int j = i; j < ansn; j++)    tans[j] = ans[ansn-1-(j-i)];
                for (int j = 0; j < ansn; j++)    ans[j] = tans[j];
                break;
            }
        if (ansn == n)  break;
        memset(visit,false,sizeof(visit));
        for (int i = 0;i < ansn;i++)
            visit[ans[i]] = true;
        for (int i = 0; i < n; i++)
            if (visit[i] == false)
            {
                bool check = false;
                for (int j = 0; j < ansn; j++)
                    if (e[i][ans[j]])
                    {
                        for (int k = 0; k < ansn; k++)    tans[k] = ans[(j+1+k)%ansn];
                        tans[ansn++] = i;
                        for (int k = 0; k < ansn; k++)    ans[k] = tans[k];
                        check = true;
                        break;
                    }
                if (check)  break;
            }
    }
    for (int i = 0; i < n; i++)
        if (ans[i] == 0)
        {
            for (int j = 0; j < n; j++)   tans[j] = ans[(i+j)%ansn];
            for (int j = 0; j < n; j++)   ans[j] = tans[j];
            break;
        }
    for (int i = 0; i < n; i++)
        printf("%d ",ans[i]+1);
    printf("%d\n",ans[0]+1);
    return 0;
}
