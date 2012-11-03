#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char ma[12],mb[12];
int da,db,ya,yb;

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    scanf("%s%d,%d",ma,&da,&ya);
	    scanf("%s%d,%d",mb,&db,&yb);
	    int xa = (ya-1)/4-(ya-1)/100+(ya-1)/400;
	    int xb = yb/4-yb/100+yb/400;
	    int res = xb-xa;
	    if ((ya%4 == 0 && ya%100 != 0) || (ya%400 == 0))
        {
            if (!(strcmp(ma,"January") == 0 ||
                strcmp(ma,"February") == 0))
                    res--;
        }
	    if ((yb%4 == 0 && yb%100 != 0) || (yb%400 == 0))
        {
            if (strcmp(mb,"January") == 0 ||
                (strcmp(mb,"February") == 0 && db < 29))
                    res--;
        }
        printf("Case %d: %d\n",cas,res);
	}
	return 0;
}
