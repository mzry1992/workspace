#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[200001],sta[200001];
int top;

int main()
{
	while (scanf("%s",s) != EOF)
	{
		top = 0;
		for (int i = 0;s[i] != 0;i++)
		{
			sta[top++] = s[i];
			while (top > 1 && sta[top-1] == sta[top-2])
				top -= 2;
		}
		sta[top] = 0;
		puts(sta);
	}
    return 0;
}

