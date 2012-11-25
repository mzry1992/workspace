#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

map<string,int> names;
int a[60][60];
int n,m,totname;

int getid(char s[])
{
	if (names.find(s) == names.end())
		names[s] = totname++;
	return names[s];
}

int main()
{
	while (scanf("%*d%d",&n) != EOF)
	{
		totname = 0;
		memset(a,0,sizeof(a));
		
		for (int i = 0;i < n;i++)
		{
		}
	}
	return 0;
}
