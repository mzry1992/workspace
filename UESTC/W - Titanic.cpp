#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

const double pi = acos(-1.0);
const double R = 6875.0/2.0;
char s[50],pos[50];
int tmp1,tmp2,tmp3;
double d0,d1,a0,a1,b0,b1,c0,c1;
double lab,rab;

int main()
{
    while (gets(s))
    {
        gets(s);
        gets(s);
        scanf("%d^%d'%d\"%s\n",&tmp1,&tmp2,&tmp3,pos);
        d0 = 1.0*tmp1+1.0*tmp2/60.0+1.0*tmp3/3600.0;
        if (strcmp(pos,"SL") == 0)
            d0 = 90.0+d0;
        else
            d0 = 90.0-d0;
        scanf("%*s%d^%d'%d\"%s\n",&tmp1,&tmp2,&tmp3,pos);
        d1 = 1.0*tmp1+1.0*tmp2/60.0+1.0*tmp3/3600.0;
        if (strcmp(pos,"WL.") == 0)
            d1 = 360.0-d1;
        d0 = pi*d0/180.0;
        d1 = pi*d1/180.0;
        a0 = R*sin(d0)*cos(d1);
        b0 = R*sin(d0)*sin(d1);
        c0 = R*cos(d0);
        gets(s);
        scanf("%d^%d'%d\"%s\n",&tmp1,&tmp2,&tmp3,pos);
        d0 = 1.0*tmp1+1.0*tmp2/60.0+1.0*tmp3/3600.0;
        if (strcmp(pos,"SL") == 0)
            d0 = 90.0+d0;
        else
            d0 = 90.0-d0;
        scanf("%*s%d^%d'%d\"%s\n",&tmp1,&tmp2,&tmp3,pos);
        d1 = 1.0*tmp1+1.0*tmp2/60.0+1.0*tmp3/3600.0;
        if (strcmp(pos,"WL.") == 0)
            d1 = 360.0-d1;
        d0 = pi*d0/180.0;
        d1 = pi*d1/180.0;
        a1 = R*sin(d0)*cos(d1);
        b1 = R*sin(d0)*sin(d1);
        c1 = R*cos(d0);
        gets(s);
        lab = sqrt((a0-a1)*(a0-a1)+(b0-b1)*(b0-b1)+(c0-c1)*(c0-c1));
        a0 = lab/2.0;
        b0 = sqrt(R*R-a0*a0);
        c0 = atan2(a0,b0)*2.0;
        rab = c0*R;
        printf("The distance to the iceberg: %.2f miles.\n",rab);
        rab = floor(rab*100.0+0.5);
        if (rab < 10000.0)
            printf("DANGER!\n");
    }
}
