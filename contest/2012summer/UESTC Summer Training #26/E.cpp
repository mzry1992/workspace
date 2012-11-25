#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char where[20];
int x,y;

int main()
{
	int totcas;
	scanf("%d",&totcas);
	while (totcas--)
	{
	    scanf("%*s%*s%*s%s%*s%*s%d%*s%*s%*s%d%*s",where,&x,&y);
	    if (where[0] == 'h')
	    {
	        for (int xx = 0;xx <= 30;xx++)
                if (x+xx > y || (x+xx == y && xx >= y))
                {
                    printf("%d ",xx);
                    break;
                }
            for (int xx = 30;xx >= 0;xx--)
                if (x+xx < y+30 || (x+xx == y+30 && xx <= y))
                {
                    printf("%d\n",xx);
                    break;
                }
	    }
	    else
	    {
	        for (int xx = 0;xx <= 30;xx++)
                if (x+xx >= y)
                {
                    printf("%d ",xx);
                    break;
                }
            for (int xx = 30;xx >= 0;xx--)
                if (x+xx <= y+30)
                {
                    printf("%d\n",xx);
                    break;
                }
	    }
	}
	return 0;
}
