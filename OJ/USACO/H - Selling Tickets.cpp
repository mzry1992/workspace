#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MIN(X,Y) (((X)>(Y))?(Y):(X))
using namespace std;

int m;
struct group
{
    int fc;
    int p[5];
}n1[50],n2[50],n3[50],n4[50],t1[50],t2[50],t3[50],t4[50];
int tot1,tot2,tot3,tot4;
int d1,d2,d3,d4;
int ttot1,ttot2,ttot3,ttot4;
int ansm[10][10];

bool cmp(group a,group b)
{
    return a.fc > b.fc;
}

int main()
{
    while (scanf("%d",&m) != EOF)
    {
        int ans = 0;
        tot4 = tot3 = tot2 = tot1 = 0;
        for (int fm = 1;fm <= m;fm++)
        {
            int tn,tfc;
            scanf("%d%d",&tn,&tfc);
            if (tn == 1)
            {
                tot1++;
                n1[tot1].fc = tfc;
                for (int i = 1;i <= tn;i++)
                    scanf("%d",&n1[tot1].p[i]);
            }
            if (tn == 2)
            {
                tot2++;
                n2[tot2].fc = tfc;
                for (int i = 1;i <= tn;i++)
                    scanf("%d",&n2[tot2].p[i]);
            }
            if (tn == 3)
            {
                tot3++;
                n3[tot3].fc = tfc;
                for (int i = 1;i <= tn;i++)
                    scanf("%d",&n3[tot3].p[i]);
            }
            if (tn == 4)
            {
                tot4++;
                n4[tot4].fc = tfc;
                for (int i = 1;i <= tn;i++)
                    scanf("%d",&n4[tot4].p[i]);
            }
        }
        sort(n4+1,n4+tot4+1,cmp);
        for (d4 = 0;d4 <= tot4;d4++)
        {
            for (int i = 1;i <= d4;i++)
                t4[i] = n4[i];
            for (int i = 1;i <= tot3;i++)
                t3[i] = n3[i];
            for (int i = 1;i <= tot2;i++)
                t2[i] = n2[i];
            for (int i = 1;i <= tot1;i++)
                t1[i] = n1[i];
            ttot4 = d4;
            for (int c4 = 0;c4 <= (1<<(tot4-d4))-1;c4++)
            {
                ttot3 = tot3;
                ttot2 = tot2;
                ttot1 = tot1;
                cout << d4 << ' ' << tot4 << ' ' << c4 << "XX" << endl;
                for (int p = 1;p <= tot4-d4;p++)
                {
                    if (((c4>>(p-1))&1) == 1)
                    {
                        cout << ttot2 << ' ';
                        ttot2++;
                        t2[ttot2].fc = n4[d4+p].fc;
                        t2[ttot2].p[1] = n4[d4+p].p[1];
                        t2[ttot2].p[2] = n4[d4+p].p[2];
                        ttot2++;
                        t2[ttot2].fc = n4[d4+p].fc;
                        t2[ttot2].p[1] = n4[d4+p].p[3];
                        t2[ttot2].p[2] = n4[d4+p].p[4];
                        cout << p << ' ' << "xxxx" << ttot2 << endl;
                        cout << t2[ttot2].p[1] << ' ' << t2[ttot2].p[2] << ' '<< t2[ttot2-1].p[1] << ' ' << t2[ttot2-1].p[2] << endl;
                    }
                    else
                    {
                        ttot3++;
                        t3[ttot3].fc = n4[d4+p].fc;
                        t3[ttot3].p[1] = n4[d4+p].p[1];
                        t3[ttot3].p[2] = n4[d4+p].p[2];
                        t3[ttot3].p[3] = n4[d4+p].p[3];
                        ttot1++;
                        t1[ttot1].fc = n4[d4+p].fc;
                        t1[ttot1].p[1] = n4[d4+p].p[4];
                    }
                    int temptot2 = ttot2;
                    int temptot1 = ttot1;
                    sort(t3+1,t3+ttot3+1,cmp);
                    for (int d3 = 0;d3 <= MIN(9-d4,ttot3);d3++)
                    {
                        ttot2 = temptot2;
                        ttot1 = temptot1;
                        for (int p3 = 1;p3 <= ttot3-d3;p3++)
                        {
                            ttot2++;
                            t2[ttot2].fc = t3[d3+p3].fc;
                            t2[ttot2].p[1] = t3[d3+p3].p[1];
                            t2[ttot2].p[2] = t3[d3+p3].p[2];
                            ttot1++;
                            t1[ttot1].fc = t3[d3+p3].fc;
                            t1[ttot1].p[1] = t3[d3+p3].p[3];
                        }
                        int tres = 0;
                        int tm[10][10];
                        memset(tm,0,sizeof(tm));
                        for (int i = 1;i <= d4;i++)
                        {
                            tres += t4[i].fc*4*3;
                            for (int j = 1;j <= 4;j++)
                                tm[i][j] = t4[i].p[j];
                        }
                        for (int i = 1;i <= d3;i++)
                        {
                            tres += t3[i].fc*3*2;
                            for (int j = 1;j <= 3;j++)
                                tm[d4+i][j] = t3[i].p[j];
                        }
                        int cur = d4+d3;
                        sort(t2+1,t2+ttot2+1,cmp);
                        d2 = (9-d4-d3)*2;
                        if (d2 > ttot2)
                        {
                            for (int i = 1;i <= ttot2;i++)
                            {
                                tres += t2[i].fc*2*1;
                                if (i%2 == 1)
                                {
                                    tm[cur][1] = t2[i].p[1];
                                    tm[cur][2] = t2[i].p[2];
                                }
                                else
                                {
                                    tm[cur][3] = t2[i].p[1];
                                    tm[cur][4] = t2[i].p[2];
                                    cur++;
                                }
                            }
                        }
                        else
                        {
                            for (int i = 1;i <= d2;i++)
                            {
                                tres += t2[i].fc*2*1;
                                if (i%2 == 1)
                                {
                                    tm[cur][1] = t2[i].p[1];
                                    tm[cur][2] = t2[i].p[2];
                                }
                                else
                                {
                                    tm[cur][3] = t2[i].p[1];
                                    tm[cur][4] = t2[i].p[2];
                                    cur++;
                                }
                            }
                            for (int i = d2+1;i <= ttot2;i++)
                            {
                                ttot1++;
                                t1[ttot1].p[1] = t2[i].p[1];
                                ttot1++;
                                t1[ttot1].p[1] = t2[i].p[2];
                            }
                        }
                        int tcur = 0;
                        for (int x = 1;x <= 9;x++)
                        for (int y = 1;y <= 4;y++)
                        if (tm[x][y] == 0)
                        {
                            tcur++;
                            if (tcur > ttot1)
                                break;
                            tm[x][y] = t1[tcur].p[1];
                        }
                        if (ans < tres)
                        {
                            ans = tres;
                            for (int x = 1;x <= 9;x++)
                            for (int y = 1;y <= 4;y++)
                                ansm[x][y] = tm[x][y];
                        }
                    }
                }
            }
        }
        printf("%d\n",ans);
        for (int i = 1;i <= 9;i++)
        {
            for (int j = 1;j <= 4;j++)
                printf("%d ",ansm[i][j]);
            printf("\n");
        }
    }
}
