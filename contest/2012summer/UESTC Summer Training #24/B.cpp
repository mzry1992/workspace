#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int p,q,n[10],a[10][100],b[10][100];
bool know[100];
char name[10][40],ing[10][100][40],buf[100],per[40];
int qa[10],qb[10];

int main()
{
    while (true)
    {
        scanf("%d",&p);
        if (p == 0) break;
        for (int i = 0;i < p;i++)
        {
            scanf("%s",name[i]);
            scanf("%d",&n[i]);
            gets(buf);
            memset(know,false,sizeof(know));
            for (int j = 0;j < n[i];j++)
            {
                gets(buf);
                if (sscanf(buf,"%s%s",ing[i][j],per) == 2)
                {
                    int tmp;
                    sscanf(per,"%d%",&tmp);
                    a[i][j] = b[i][j] = tmp;
                    know[j] = true;
                }
            }
            int pre,l,r,mid;

            int premin = 1;
            for (int j = n[i]-1;j >= 0;j--)
            {
                if (!know[j])
                {
                    l = premin;
                    r = 100;
                    while (l < r)
                    {
                        mid = l+r>>1;
                        int cnt = 0;
                        pre = 100;
                        for (int k = 0;k < j;k++)
                        {
                            if (know[k])
                                pre = b[i][k];
                            cnt += pre;
                        }
                        pre = mid;
                        for (int k = j;k < n[i];k++)
                        {
                            if (know[k])
                                pre = b[i][k];
                            cnt += pre;
                        }
                        if (cnt >= 100)
                            r = mid;
                        else
                            l = mid+1;
                    }
                    a[i][j] = l;
                }
                premin = a[i][j];
            }

            int premax = 100;
            for (int j = 0;j < n[i];j++)
            {
                if (!know[j])
                {
                    l = 1;
                    r = premax;
                    while (l < r)
                    {
                        mid = l+r+1>>1;
                        int cnt = 0;
                        pre = 1;
                        for (int k = n[i]-1;k > j;k--)
                        {
                            if (know[k])
                                pre = a[i][k];
                            cnt += pre;
                        }
                        pre = mid;
                        for (int k = j;k >= 0;k--)
                        {
                            if (know[k])
                                pre = a[i][k];
                            cnt += pre;
                        }
                        if (cnt <= 100)
                            l = mid;
                        else
                            r = mid-1;
                    }
                    b[i][j] = l;
                }
                premax = b[i][j];
            }
            //for (int j = 0;j < n[i];j++)
            //    printf("%s [%d ,%d]\n",ing[i][j],a[i][j],b[i][j]);
        }
        scanf("%d",&q);
        for (int i = 0;i < q;i++)
        {
            scanf("%s%s",buf,per);
            for (int j = 0;j < p;j++)
            {
                qa[j] = qb[j] = 0;
                for (int k = 0;k < n[j];k++)
                    if (strcmp(ing[j][k],per) == 0)
                        qa[j] = a[j][k],qb[j] = b[j][k];
            }
            if (strcmp(buf,"most") == 0)
            {
                bool first = true;
                for (int j = 0;j < p;j++)
                {
                    bool flag = true;
                    for (int k = 0;k < p && flag;k++)
                        if (qb[j] < qa[k])
                            flag = false;
                    if (flag)
                    {
                        if (!first)
                            printf(" ");
                        first = false;
                        printf("%s",name[j]);
                    }
                }
                puts("");
            }
            else
            {
                bool first = true;
                for (int j = 0;j < p;j++)
                {
                    bool flag = true;
                    for (int k = 0;k < p && flag;k++)
                        if (qa[j] > qb[k])
                            flag = false;
                    if (flag)
                    {
                        if (!first)
                            printf(" ");
                        first = false;
                        printf("%s",name[j]);
                    }
                }
                puts("");
            }
        }
    }
	return 0;
}
