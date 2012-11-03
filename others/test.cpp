#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char *s = "a b c d e f g";

void split(char *s)
{
	char tmp[100];
	int pos = 0,npos;
	while (sscanf(s+pos,"%s%n",tmp,&npos) != EOF)
	{
		puts(tmp);
		pos += npos;
	}
}

int main()
{
	split(s);
    return 0;
}

