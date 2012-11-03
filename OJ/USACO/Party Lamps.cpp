/*
ID: muziriy3
PROG: lamps
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <deque>
#include <string>
#define NOT(X) (((X) == true)?false:true)
using namespace std;

int n,c;
int a[120];
bool temp[120];
string res[20];
int tot;

int main()
{
    freopen("lamps.in","r",stdin);
    freopen("lamps.out","w",stdout);
    scanf("%d",&n);
    scanf("%d",&c);
    for (int i = 1;i <= n;i++)
        a[i] = 2;
    while (true)
    {
        int temp;
        scanf("%d",&temp);
        if (temp == -1) break;
        a[temp] = 1;
    }
    while (true)
    {
        int temp;
        scanf("%d",&temp);
        if (temp == -1) break;
        a[temp] = 0;
    }
    tot = 0;
    for (int b1 = 0;b1 <= 1;b1++)
    for (int b2 = 0;b2 <= 1;b2++)
    for (int b3 = 0;b3 <= 1;b3++)
    for (int b4 = 0;b4 <= 1;b4++)
    {
        if (b1+b2+b3+b4 > c)    continue;
        if ((c-(b1+b2+b3+b4))%2 == 1)   continue;
        bool isans = true;
        for (int i = 1;i <= n;i++)
        {
            temp[i] = true;
            if (b1 == 1)  temp[i] = NOT(temp[i]);
            if (i%2 == 1)
                if (b2 == 1)  temp[i] = NOT(temp[i]);
            if (i%2 == 0)
                if (b3 == 1)  temp[i] = NOT(temp[i]);
            if (i%3 == 1)
                if (b4 == 1)  temp[i] = NOT(temp[i]);
            if (a[i] != 2)
            {
                if (temp[i] != a[i])
                {
                    isans = false;
                    break;
                }
            }
        }
        if (isans == false) continue;
        bool flag = false;
        for (int i = 1;i <= tot;i++)
        {
            bool tflag = true;
            for (int j = 1;j <= n;j++)
            if ((res[i][j-1]-'0') != temp[j])   tflag = false;
            if (tflag == true)
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            tot++;
            res[tot].resize(n);
            for (int i = 1;i <= n;i++)
                res[tot][i-1] = (char)(temp[i]+'0');
        }
    }
    if (tot == 0)
        puts("IMPOSSIBLE");
    else
    {
        sort(res+1,res+tot+1);
        for (int i = 1;i <= tot;i++)
            puts(res[i].c_str());
    }
}
