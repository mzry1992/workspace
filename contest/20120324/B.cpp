#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char a[1001],b[100001];
int lena,lenb;

int main()
{
    while (true)
    {
        scanf("%s",a);
        if (strcmp(a,"0") == 0) break;
        scanf("%s",b);
        lena = strlen(a);
        lenb = strlen(b);
        for (int i = 0,j = 0;i < lenb;i++,j = (j+1)%lena)
            printf("%c",(b[i]-'A'+a[j]-'A'+1)%26+'A');
        puts("");
    }
	return 0;
}
