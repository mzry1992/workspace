#include <stdio.h>
#include <iostream>
using namespace std;

void f(int *p1,int *p2)
{
    int i,j;
    *p2 = 0;
    for (i = 0;i < 3;i++)
    for (j = i;j < 3;j++)
    {
        *p2 += *(p1+i*3+j);
        cout << i << ' ' << j << endl;
        printf("%d\n",*p2);
    }
    return;
}

int main()
{
    int a[3][3] = {{1,2},{3,4},{5,6}};
    int s;
    f(a,&s);
    printf("%d",s);
}
