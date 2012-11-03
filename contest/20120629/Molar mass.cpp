#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

double res;
char buf[5000];
int len;

int main()
{
    int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    scanf("%s",buf);
	    len = strlen(buf);
	    res = 0;
	    for (int i = 0;i < len;i++)
            if (buf[i] == 'C' || buf[i] == 'H' || buf[i] == 'O' || buf[i] == 'N')
            {
                double val = 0;
                if (buf[i] == 'C')  val = 12.01;
                else if (buf[i] == 'H') val = 1.008;
                else if (buf[i] == 'O') val = 16.00;
                else    val = 14.01;
                int cnt = 0;
                if (buf[i+1] >= '0' && buf[i+1] <= '9')
                {
                    while (buf[i+1] >= '0' && buf[i+1] <= '9')
                    {
                        cnt = cnt*10+buf[i+1]-'0';
                        i++;
                    }
                }
                else
                    cnt = 1;
                //cout << buf[i] << ' ' << val << ' ' << cnt << endl;
                res += val*cnt;
            }
        printf("%.3f\n",res);
	}
	return 0;
}
