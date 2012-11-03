#include <iostream.h>
#include <stdio.h>
#include <math.h>
//#include <algorithm.h>
//using namespace std;

const int Max = 100;
int bp[Max + 1]; //记录每个数是否是素数
int p[30]; //记录筛选出来的素数
int pCnt; //记录当前筛选出来的素数个数

void sievePrime()
{
int i, j;
memset(bp, 1, sizeof(bp));
bp[0] = bp[1] = 0;
for (i = 2; i <= Max; i++)
{
   if (bp[i]) p[pCnt++] = i;

   for (j = 0; j < pCnt && i * p[j] <= Max; j++)
   {
    bp[i * p[j]] = 0;
    if (i % p[j] == 0) break;
   }
}
}

int main()
{
int i;
sievePrime();
printf("%d\n", pCnt);
for (i = 0; i < pCnt; i++)
   printf("%d,", p[i]);
getchar();
getchar();
return 0;
}

