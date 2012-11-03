#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const char mon[12][10] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
const int mday[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int n,m;
char smonth[10];
int month,date,year,H,R,tid,b[100000],c[100000],Q[100000],head,tail;
int T,S;

int main()
{
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        memset(b,0,sizeof(b));
        for (int i = 0;i < n;i++)
        {
            scanf("%s%d%d%d%d",smonth,&date,&year,&H,&R);
            date--;
            for (int j = 0;j < 12;j++)
                if (strcmp(smonth,mon[j]) == 0)
                    month = j;
            tid = 0;
            for (int j = 2000;j < year;j++)
                if (j%4 == 0)
                    tid += 366*24;
                else
                    tid += 365*24;
            for (int j = 0;j < month;j++)
                if (year%4 == 0 && j == 1)
                    tid += 29*24;
                else
                    tid += mday[j]*24;
            for (int j = 0;j < date;j++)
                tid += 24;
            for (int j = 0;j < H;j++)
                tid ++;
            b[tid] = R;
        }
        scanf("%d%d",&T,&S);
        head = tail = 100000;
        long long res = 0;
        for (int i = 0;i < m;i++)
        {
            scanf("%d",&c[i]);
            while (head < tail)
            {
                if (c[Q[head]]-Q[head]*S >= c[i]-i*S)   head++;
                else    break;
            }
            Q[--head] = i;
            while (head < tail)
            {
                if (i-Q[tail-1] > T)    tail--;
                else    break;
            }
            res += (long long)b[i]*((i-Q[tail-1])*S+c[Q[tail-1]]);
        }
        printf("%I64d\n",res);
    }
    return 0;
}
