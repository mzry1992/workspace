/*
ID: muziriy3
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const char num[] = "0123456789ABCDEFGHIJK";
int base;
char n[10];
char nn[20];

int main()
{
    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout);
    scanf("%d",&base);
    for (int i = 1;i <= 300;i++)
    {
        int tn = i;
        int ntot = 0;
        while (tn > 0)
        {
            ntot++;
            n[ntot] = num[tn%base];
            tn /= base;
        }
        int tnn = i*i;
        int nntot = 0;
        while (tnn > 0)
        {
            nntot++;
            nn[nntot] = num[tnn%base];
            tnn /= base;
        }
        bool nnflag = true;
        for (int j = 1;j <= nntot/2;j++)
        if (nn[j] != nn[nntot+1-j])
            nnflag = false;
        if (nnflag == false) continue;
        for (int j = ntot;j >= 1;j--)
            printf("%c",n[j]);
        printf(" ");
        for (int j = nntot;j >= 1;j--)
            printf("%c",nn[j]);
        puts("");
    }
}
