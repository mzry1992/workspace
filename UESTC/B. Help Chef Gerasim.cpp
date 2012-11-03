#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a[1000],sum,avg,dif,bd,ld;
bool check;

int main()
{
    scanf("%d",&n);
    for (int i = 0;i < n;i++)
        scanf("%d",&a[i]);
    sum = 0;
    check = true;
    for (int i = 0;i < n;i++)
    {
        sum += a[i];
        if (a[i] != a[0])   check = false;
    }
    if (check == true)
        printf("Exemplary pages.\n");
    else if (sum%n != 0)
        printf("Unrecoverable configuration.\n");
    else
    {
        avg = sum/n;
        dif = 0;
        for (int i = 0;i < n;i++)
            if (a[i] != avg)
                dif++;
        if (dif != 2)
            printf("Unrecoverable configuration.\n");
        else
        {
            for (int i = 0;i < n;i++)
            {
                if (a[i] > avg)
                    bd = i;
                if (a[i] < avg)
                    ld = i;
            }
            printf("%d ml. from cup #%d to cup #%d.\n",a[bd]-avg,ld+1,bd+1);
        }
    }
    return 0;
}
