#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
char dic[2500][1100],diclen[2500],qs[5200000],qslen,buf[5200000],tmp[5200000];

void getstr()
{
    scanf("%s",tmp);
    int len = strlen(tmp);
    int l = 0;
    for (int i = 0;i < len;i++)
        if (tmp[i] == '[')
        {
            int tim = 0;
            for (int j = i+1;;j++)
                if (tmp[j] >= '0' && tmp[j] <= '9')
                    tim = tim*10+(tmp[j]-'0');
                else
                {
                    for (int k = 0;k < tim;k++)
                        buf[l++] = tmp[j];
                    i = j+1;
                    break;
                }
        }
        else
            buf[l++] = tmp[i];
    buf[l] = 0;
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1;cas <= totcas;cas++)
    {
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
        {
            getstr();
            strcpy(dic[i],buf);
            diclen[i] = strlen(dic[i]);
            //puts(dic[i]);
        }
        getstr();
        strcpy(qs,buf);
        qslen = strlen(qs);
        //puts(qs);
    }
	return 0;
}
