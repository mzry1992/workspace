#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

double x,y,z,q;

int main()
{
    freopen("给趣味赛出的题1的数据.txt","w",stdout);
    srand(time(NULL));
    for (int i = 1;i <= 100;i++)
    {
        x = (rand()%1000)/100.0;
        y = (rand()%1000)/100.0;
        z = (rand()%1000)/100.0;
        printf("%.2lf %.2lf %.2lf\n",x,y,z);
        int n = rand()%987+123;
        printf("%d\n",n);
        for (int j = 1;j <= n;j++)
        {
            x = (rand()%100000)/100.0;
            y = (rand()%100000)/100.0;
            z = (rand()%100000)/100.0;
            q = (rand()%100000)/100.0;
            printf("%.2lf %.2lf %.2lf %.2lf\n",x,y,z,q);
        }
    }
}
