#include <iostream>
#include <stdio.h>
#define LESS 0
#define EQUAL 1
#define GREATER 2
using namespace std;

int n,k,fk,i,j,tp[110],pl[110][1010],pr[110][1010],po[110],result,wl,wr,allright,re,tot;
char order;
bool coin[1010],flag;

int main()
{
    while (scanf("%d %d",&n,&k) == 2)
    {
        for (fk = 1;fk <= k;fk++)
        {
            cin >> tp[fk];
            for (i = 1;i <= tp[fk];i++)
                cin >> pl[fk][i];
            for (i = 1;i <= tp[fk];i++)
                cin >> pr[fk][i];
            cin >> order;
            if (order == '<')    po[fk] = LESS;
            if (order == '=')    po[fk] = EQUAL;
            if (order == '>')    po[fk] = GREATER;
        }
        tot = 0;
        result = 0;
        for (re = 1;re <= n;re++)
        {
            allright = 0;
            for (fk = 1;fk <= k;fk++)
            {
                wl = 1;
                wr = 1;
                for (i = 1;i <= tp[fk];i++)
                {
                    if (pl[fk][i] == re)
                       wl = 0;
                    if (pr[fk][i] == re)
                       wr = 0;
                }
                if ((po[fk] == LESS) && (wl < wr)) allright++;
                if ((po[fk] == EQUAL) && (wl == wr)) allright++;
                if ((po[fk] == GREATER) && (wl > wr)) allright++;
            }
            if (allright == k)
            {
                      tot++;
                      result = re;
            }
            allright = 0;
            for (fk = 1;fk <= k;fk++)
            {
                wl = 1;
                wr = 1;
                for (i = 1;i <= tp[fk];i++)
                {
                    if (pl[fk][i] == re)
                       wl = 2;
                    if (pr[fk][i] == re)
                       wr = 2;
                }
                if ((po[fk] == LESS) && (wl < wr)) allright++;
                if ((po[fk] == EQUAL) && (wl == wr)) allright++;
                if ((po[fk] == GREATER) && (wl > wr)) allright++;
            }
            if (allright == k)
            {
                         if (result != re) tot++;
                         result = re;
            }
        }
        if (tot == 1)
           cout << result << endl;
        else
            cout << 0 << endl;
        //system("pause");
    }
    return 0;
}
