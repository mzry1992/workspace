#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char a[100100];
int n,zero,one,unknow;
bool res[4];

int main()
{
    while (scanf("%s",a) != EOF)
    {
        n = strlen(a);
        zero = one = unknow = 0;
        for (int i = 0;i < n;i++)
            if (a[i] == '?')
                unknow++;
            else if (a[i] == '0')
                zero++;
            else if (a[i] == '1')
                one++;
        for (int i = 0;i < 4;i++)
            res[i] = false;
        for (int i = 0;i <= unknow;i++)
        {
            zero += i;
            one += unknow-i;

            if (zero+2 <= one)  res[3] = true;
            if (zero+1 == one)
            {
                if (a[n-1] == '?' || a[n-1] == '0')
                    res[2] = true;
                if (a[n-1] == '?' || a[n-1] == '1')
                    res[1] = true;
            }

            if (one+1 <= zero)  res[0] = true;
            if (one == zero)
            {
                if (a[n-1] == '?' || a[n-1] == '0')
                    res[2] = true;
                if (a[n-1] == '?' || a[n-1] == '1')
                    res[1] = true;
            }

            zero -= i;
            one -= unknow-i;
        }
        for (int i = 0;i < 4;i++)
            if (res[i] == true)
                printf("%d%d\n",i/2,i%2);
    }
    return 0;
}

