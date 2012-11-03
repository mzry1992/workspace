/*
ID: muziriy3
PROG: beads
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
char s[400];
int a[800];

int main()
{
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);
    scanf("%d",&n);
    scanf("%s",s);
    bool flag = true;
    for (int i = 0;i < n;i++)
    if (s[i] != s[0])   flag = false;
    int res = 0;
    if (flag == true)
        res = n;
    else
    {
        for (int i = 0;i < n;i++)
            a[i] = a[n+i] = ((s[i] == 'w')?0:(s[i] == 'b'?1:2));
        for (int i = 0;i < n;i++)
        {
            int head,tail;
            head = i;
            tail = i+n-1;
            int tres = 0;
            int k1,k2;
            if (a[head] == 0)
            {
                for (int j = 0;j < n;j++)
                if (a[head+j] != 0)
                {
                    k1 = a[head+j];
                    break;
                }
            }
            else k1 = a[head];
            if (a[tail] == 0)
            {
                for (int j = 0;j < n;j++)
                if (a[tail-j] != 0)
                {
                    k2 = a[tail-j];
                    break;
                }
            }
            else k2 = a[tail];
            int q1,q2;
            for (int j = 0;j < n;j++)
            if (a[head+j] == ((k1) == 1?2:1))
            {
                q1 = head+j;
                break;
            }
            for (int j = 0;j < n;j++)
            if (a[tail-j] == ((k2) == 1?2:1))
            {
                q2 = tail-j;
                break;
            }
            if (q1 <= q2)
                tres = n-(q2-q1+1);
            else
                tres = n;
            if (tres > res) res = tres;
        }
    }
    printf("%d\n",res);
}
