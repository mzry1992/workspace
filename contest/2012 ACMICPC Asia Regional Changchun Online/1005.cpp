#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int len,l0,resf;
char s[300000],a[20];
string ress;
int n;

int dist[101010][11];
int cnt = 0;

int Q0[1100000][2],Q1[1100000][2];
int head0,tail0,head1,tail1;

int Calc()
{
    head0 = tail0 = head1 = tail1 = 0;

    int l = strlen(a);
    for (int i = 0; i < len; i++)
    {
        dist[i][0] = 0;
        for (int j = 1; j <= l; j++)
            dist[i][j] = -1;

        Q0[tail0][0] = i;
        Q0[tail0++][1] = 0;
    }
    while (head0 < tail0)
    {
        while (head0 < tail0)
        {
            cnt++;
            int nowx = Q0[head0][0];
            int nowy = Q0[head0++][1];

            Q1[tail1][0] = nowx;
            Q1[tail1++][1] = nowy;

            if (dist[nowx][nowy] > resf) return 19921005;
            if (nowy == l)    return dist[nowx][nowy];

            if (nowx == len)    continue;

            if (a[nowy] == s[nowx])
            {
                int nxtx = nowx+1;
                int nxty = nowy+1;

                if (dist[nxtx][nxty] == -1)
                {
                    Q0[tail0][0] = nxtx;
                    Q0[tail0++][1] = nxty;
                    dist[nxtx][nxty] = dist[nowx][nowy];
                }
            }
        }

        while (head1 < tail1)
        {
            cnt++;
            int nowx = Q1[head1][0];
            int nowy = Q1[head1++][1];

            if (dist[nowx][nowy] > resf) return 19921005;
            if (nowy == l)    return dist[nowx][nowy];

            int nxtx = nowx;
            int nxty = nowy+1;

            if (dist[nxtx][nxty] == -1)
            {
                    Q0[tail0][0] = nxtx;
                    Q0[tail0++][1] = nxty;
                    dist[nxtx][nxty] = dist[nowx][nowy]+1;
            }

            if (nowx == len)    continue;
            nxtx = nowx+1;
            nxty = nowy;
            if (dist[nxtx][nxty] == -1)
            {
                    Q0[tail0][0] = nxtx;
                    Q0[tail0++][1] = nxty;
                    dist[nxtx][nxty] = dist[nowx][nowy]+1;
            }

            nxtx = nowx+1;
            nxty = nowy+1;
            if (dist[nxtx][nxty] == -1)
            {
                    Q0[tail0][0] = nxtx;
                    Q0[tail0++][1] = nxty;
                    dist[nxtx][nxty] = dist[nowx][nowy]+1;
            }
        }
    }
    return -1;
}

int main()
{
    while (scanf("%s",s) != EOF)
    /*l0 = 100000;
    for (int i = 0;i < l0;i++)
        s[i] = rand()%26+'a';
    s[l0] = 0;*/
    {
        len = l0 = strlen(s);
        do
        {
            for (int i = 0; i < l0; i++)
                s[len+i] = s[i];
            len += l0;
            s[len] = 0;
        }
        while (len < 100);
        len = len/2+30;
        //puts(s);
        //n = 10;
        scanf("%d",&n);
        resf = 19921005;
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
//            for (int j = 0;j < 10;j++)
//                a[j] = rand()%26+'a';
//            a[10] = 0;
            scanf("%s",a);
            int tmp = Calc();
            string tmpa = a;
            if (tmp < resf || (tmp == resf && tmpa < ress))
            {
                resf = tmp;
                ress = tmpa;
            }

            //printf(" = %s %d\n",tmpa.c_str(),resf);
        }
        //printf("%d\n",cnt);
        printf("%s %d\n",ress.c_str(),resf);
    }
    return 0;
}
