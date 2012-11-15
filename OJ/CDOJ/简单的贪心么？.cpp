#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a;
struct tnode
{
    int num,tot;
    int pos[10];
}t[5000];
int tott = 0;
int ans[4000][5];

int insert(int num,int pos)
{
    for (int i = 1;i <= tott;i++)
    if (t[i].num == num)
    {
        t[i].tot++;
        t[i].pos[t[i].tot] = pos;
        return i;
    }
    tott++;
    t[tott].num = num;
    t[tott].tot = 1;
    t[tott].pos[t[tott].tot] = pos;
    return tott;
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        int flag = false;
        tott = 0;
        int total = 0;
        for (int i = 1;i <= n;i++)
        {
            scanf("%d",&a);
            int tpos = insert(a,i);
            int pre;
            if (t[tpos].tot == 2)
            {
                if (flag == true)
                {
                    flag = false;
                    total++;
                    ans[total][1] = t[pre].pos[1];
                    ans[total][2] = t[pre].pos[2];
                    ans[total][3] = t[tpos].pos[1];
                    ans[total][4] = t[tpos].pos[2];
                    tott = 0;
                }
                else
                {
                    pre = tpos;
                    flag = true;
                }
            }
            else if (t[tpos].tot == 4)
            {
                flag = false;
                total++;
                ans[total][1] = t[tpos].pos[1];
                ans[total][2] = t[tpos].pos[2];
                ans[total][3] = t[tpos].pos[3];
                ans[total][4] = t[tpos].pos[4];
                tott = 0;
            }
        }
        printf("%d\n",total);
        for (int i = 1;i <= total;i++)
        {
            sort(ans[i]+1,ans[i]+4);
            printf("%d %d %d %d\n",ans[i][1],ans[i][2],ans[i][3],ans[i][4]);
        }
        printf("\n");
    }
}
