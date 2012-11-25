#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char a[110],b[110],sp[110][110],tot,place[110];
int n,la,lb,ll;

bool check(int id,int pos)
{
    for (int i = 0;sp[id][i] != 0;i++)
        if (b[pos+i] != sp[id][i])
            return false;
    return true;
}

bool check()
{
    lb = strlen(b);
    int pre = 0;
    for (int i = 0;i < tot;i++)
    {
        bool find = false;
        for (int j = pre;j < lb;j++)
            if (check(i,j) == true)
            {
                place[i] = j;
                pre = place[i]+1;
                find = true;
                break;
            }
        if (find == false)  return false;
    }
    if (a[0] != '*')
        if (place[0] != 0)
            return false;
    if (a[la-1] != '*')
        if (check(tot-1,lb-ll) == false)
            return false;
    return true;
}

int main()
{
	while (scanf("%s",a) != EOF)
	{
	    tot = 0;
	    for (int i = 0;a[i] != 0;i++)
            if (a[i] != '*')
            {
                int j;
                for (j = i;a[j] != 0 && a[j] != '*';j++)
                    sp[tot][j-i] = a[j];
                sp[tot++][j-i] = 0;
                i = j;
            }
        la = strlen(a);
        ll = strlen(sp[tot-1]);
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
        {
            scanf("%s",b);
            if (check() == true)
                puts(b);
        }
	}
	return 0;
}
