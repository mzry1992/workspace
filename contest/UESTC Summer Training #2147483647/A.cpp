#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,totl,totd,totm,okl,okd,okm;

void output(int ok,int tot)
{
    if (tot == 0)
        puts("no guest");
    else
        printf("%d\n",(ok*100)/tot);
}

int hh,mm,MM;

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        totl = totd = totm = okl = okd = okm = 0;
        for (int i = 0;i < n;i++)
        {
            scanf("%d%*c%d%d",&hh, &mm, &MM);
            int tim = MM-mm;
            if (tim < 0)
                tim += 60;
            if (hh >= 11 && hh < 15)
            {
                totl++;
                if (tim <= 8)
                    okl++;
            }
            else if (hh >= 18 && hh < 21)
            {
                totd++;
                if (tim <= 8)
                    okd++;
            }
            else if ((hh >= 21 && hh < 24) || (hh >= 0 && hh < 2))
            {
                totm++;
                if (tim <= 8)
                    okm++;
            }
        }
        printf("lunch ");
        output(okl,totl);

        printf("dinner ");
        output(okd,totd);

        printf("midnight ");
        output(okm,totm);
    }
    return 0;
}

