#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

char buf[10000];
bool replace[256][256];

int main()
{
	memset(replace,false,sizeof(replace));
	while (true)
	{
		gets(buf);
		if (strlen(buf) == 0)	break;
		char ch = buf[0];
		for (int i = 2;buf[i] != 0;i++)
			replace[ch][buf[i]] = true;
	}
	int totlen = 0;
	while (true)
	{
		gets(buf);
		if (strlen(buf) == 0)	break;
		totlen += strlen(buf);
	}
	return 0;
}
