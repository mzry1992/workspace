#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int l;
long long a,b,mm;
char sa[20],sb[20],s[20],resa[40],resb[40];
int la,lb,rla,rlb;

int main()
{
    while (scanf("%s%s",sa,sb) != EOF)
    {
        l = strlen(sa);
        sa[0] = sa[l-1] = sb[0] = sb[l-1] = ' ';
        l -= 2;
        mm = 1;
        for (int i = 0; i < l; i++)
            mm *= 10;

        sscanf(sa,"%I64d",&a);
        sscanf(sb,"%I64d",&b);

        if ((a+b)/mm == 0)
        {
            sprintf(s,"%0*I64d",l,a+b);
            for (int i = 1; i <= l; i++)
                if (l%i == 0)
                {
                    bool flag = true;
                    for (int j = 0; j < l && flag; j++)
                        if (s[j%i] != s[j])
                            flag = false;
                    if (flag)
                    {
                        s[i] = 0;
                        printf("(%s)\n",s);
                        break;
                    }
                }
        }
        else
        {
            //1(a+b+1)(a+b)
            sprintf(sa,"%0*I64d",l,(a+b)%mm);
            sprintf(sb,"%0*I64d",l,(a+b+1)%mm);

            la = l;
            for (int i = 1; i <= l; i++)
                if (l%i == 0)
                {
                    bool flag = true;
                    for (int j = 0; j < l && flag; j++)
                        if (sb[j%i] != sb[j])
                            flag = false;
                    if (flag)
                    {
                        sb[i] = 0;
                        lb = i;
                        break;
                    }
                }

            resb[0] = '(';
            for (int i = 0; i < lb; i++)
                resb[1+i] = sb[i];
            resb[1+lb] = ')';
            rlb = 1+lb+1;

            for (int i = 0; i < la;)
            {
                bool flag = true;
                for (int j = 0; j < lb && flag; j++)
                    if (sa[i+j] != sb[j])
                        flag = false;
                if (flag == false)
                {
                    for (int j = i; j < la; j++)
                        resb[rlb++] = sa[j];
                    break;
                }
                else
                    i += lb;
            }
            resb[rlb] = 0;

            puts(resb);
        }
    }
    return 0;
}
