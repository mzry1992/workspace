#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char s[210000],a[420000];
int len,l,p[420000],pnow,pid;

int main()
{
    int totcas;
    scanf("%d",&totcas);
    while (totcas--)
    {
        scanf("%s",s);
        len = strlen(s);
        l = 0;
        a[l++] = '.';
        a[l++] = ',';
        for (int i = 0;i < len;i++)
        {
            a[l++] = s[i];
            a[l++] = ',';
        }
        pnow = 0;
        for (int i = 1;i < l;i++)
        {
            if (pnow > i)
                p[i] = min(p[2*pid-i],pnow-i);
            else
                p[i] = 1;
            for (;a[i-p[i]] == a[i+p[i]];p[i]++);
            if (i+p[i] > pnow)
            {
                pnow = i+p[i];
                pid = i;
            }
        }
//        for (int i = 0;i < l;i++)
//            printf("%c",a[i]);
//        puts("");
//        for (int i = 0;i < l;i++)
//            printf("%d",p[i]);
//        puts("");
        bool isp,isa;
        isp = isa = false;
        for (int i = 2;i < l;i++)
            if (i-p[i]+2 == 2)
            {
                if (i+p[i]-2 == l-2)
                    isp = true;
                else
                {
                    int pl = i+p[i]-1;
                    int pr = l-1;
                    int mid = pl+pr>>1;
                    if (mid-p[mid]+1 == pl)
                        isa = true;
                }
            }
        if (isa)
            puts("alindrome");
        else if (isp)
            puts("palindrome");
        else
            puts("simple");
    }
	return 0;
}
