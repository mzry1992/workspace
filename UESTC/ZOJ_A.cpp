#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <sstream>
using namespace std;

char s[100000];
int aa[10000];
int a[10000],buf[10000];
int tot,btot;

int main()
{
    tot = 0;
    while (gets(s))
    {
        int len = strlen(s);
        int taa = 0;
        for (int i = 0;i < len;i++)
        if (s[i] != '-')
        if ((s[i] < '0') || (s[i] > '9')) s[i] = ' ';
        int ti = 0;
        while (ti < len)
        {
            if (s[ti] == ' ') ti++;
            else
            {
                int tj = ti;
                taa++;
                aa[taa] = 0;
                if (s[ti] == '-') tj++;
                while ((s[tj] >= '0') && (s[tj] <= '9'))
                {
                    aa[taa] = aa[taa]*10+s[tj]-'0';
                    tj++;
                }
                if (s[ti] == '-')
                    aa[taa] = -aa[taa];
                ti = tj;
            }
        }
        int begin = aa[1],end = aa[2];
        if (begin < end)
            printf("%d",a[begin]);
        for (int i = begin+1;i < end;i++)
            printf(", %d",a[i]);
        printf("\n");
        for (int i = end;i < tot;i++)
            a[begin+i-end] = a[i];
        tot = tot-(end-begin);
        btot = 0;
        //cout << 'A';
        for (int i = 0;i < begin;i++)
        {
            buf[btot] = a[i]; btot++;
          //  cout << a[i] << ' ';
        }
        //cout << 'B';
        for (int i = 3;i <= taa;i++)
        {
            buf[btot] = aa[i]; btot++;
          //  cout << aa[i] << ' ';
        }
        //cout << 'C';
        for (int i = begin;i < tot;i++)
        {
            buf[btot] = a[i]; btot++;
          //  cout << a[i] << ' ';
        }
        tot = btot;
        for (int i = 0;i < tot;i++)
            a[i] = buf[i];
    }
}

