#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char a[32],b[32],checka[32];
int la,lb;

int main()
{
    scanf("%s%s",a,b);
    la = strlen(a);
    lb = strlen(b);
    for (int i = lb-1,j = 0;i < la;i++,j++)
    {
        if (a[j] == '1')
        {
            for (int k = 0;k < lb;k++)
            {
                int pa,pb;
                pa = a[j+k]-'0';
                pb = b[k]-'0';
                pa = pa^pb;
                a[j+k] = pa+'0';
            }
            printf("1 ");
        }
        else
            printf("0 ");
        puts(a);
    }
	return 0;
}
