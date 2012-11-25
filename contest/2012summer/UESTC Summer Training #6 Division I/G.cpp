#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char num[20][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char num10[10][10] = {"ten","twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
char buf[2000],a[2000][100];
int cnt;

int getval(int l,int r)
{
    int res = 0;
    for (int i = l;i < r;i++)
        if (strcmp(a[i],"hundred") == 0)
        {
            res += getval(l,i)*100;
            if (i+1 < r)
                res += getval(i+2,r);
            return res;
        }
    if (l+1 == r)
    {
        for (int i = 0;i < 20;i++)
            if (strcmp(a[l],num[i]) == 0)
                return i;
        for (int i = 1;i <= 9;i++)
            if (strcmp(a[l],num10[i-1]) == 0)
                return i*10;
    }
    else if (l+1 < r)
        res = getval(l,l+1)+getval(l+1,r);
    return res;
}

int main()
{
	int totcas;
	scanf("%d",&totcas);
	gets(buf);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    gets(buf);
	    cnt = 0;
	    int pre = 0,nown;
	    while (buf[pre] != 0 && sscanf(buf+pre,"%s%n",a[cnt++],&nown))
            pre += nown;
        pre = 0;
        int res = 0;
        for (int i = 0;i <= cnt;i++)
            if (i == cnt || strcmp(a[i],"million") == 0 || strcmp(a[i],"thousand") == 0)
            {
                int val = getval(pre,i);
                //printf("%d %s\n",val,a[i]);
                if (i < cnt && strcmp(a[i],"million") == 0)
                    res += val*1000000;
                else if (i < cnt && strcmp(a[i],"thousand") == 0)
                    res += val*1000;
                else
                    res += val;
                pre = i;
            }
        printf("%d\n",res);
	}
	return 0;
}
