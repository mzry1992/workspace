#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const char res[12][10] = {
"I",
"II",
"III",
"IV",
"V",
"VI",
"VII",
"VIII",
"IX",
"X",
"XI",
"XII"
};

char buf[10];

int main()
{
    int cas = 0;
    while (scanf("%s",buf) != EOF)
    {
        for (int i = 0;i < 12;i++)
            if (strcmp(buf,res[i]) == 0)
                printf("Case %d: %d\n",++cas,i+1);
    }
	return 0;
}
