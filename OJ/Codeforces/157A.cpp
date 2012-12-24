#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[100005];

int main(int argc,char* argv[])
{
	while (scanf("%s",s) != EOF)
	{
		int len = strlen(s);
		bool flag = false;
		for (int i = 0;i < len;i++)
		{
			if (flag == false && (i == len-1 || s[i] == '0'))
				flag = true;
			else
				putchar(s[i]);
		}
		puts("");
	}
	return 0;
}

