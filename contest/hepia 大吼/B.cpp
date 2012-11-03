#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

int n;
string sa[10],sb[10];
char a[10][11];
char b[10][11];
char x[11],y[11];
int maxstep;
int minlen;
string sy,sx;

bool DFS(int step,string now)
{
	if (now.length() > sy.length())	return false;
	//printf("%d : %s\n",step,now.c_str());
	if (step == maxstep)
	{
		minlen = min(minlen,(int)now.length());
		return now == sy;
	}

	for (int i = 0;i < n;i++)
	{
		bool flag = false;
		for (int j = 0;j+sa[i].length() <= now.length();j++)
			if (now.substr(j,sa[i].length()) == sa[i])
			{
				flag = true;
				break;
			}
		if (flag)
		{
			string nxt = "";
			for (int j = 0;j < now.length();)
			{
				if (j+sa[i].length() <= now.length() &&
						now.substr(j,sa[i].length()) == sa[i])
				{
					nxt = nxt+sb[i];
					j += sa[i].length();
				}
				else
				{
					nxt.push_back(now[j]);
					j++;
				}
			}
			if (DFS(step+1,nxt))
				return true;
		}
	}

	return false;
}

int main()
{
	while (true)
	{
		scanf("%d",&n);
		if (n == 0)	break;

		for (int i = 0;i < n;i++)
		{
			scanf("%s%s",a[i],b[i]);
			sa[i] = a[i];
			sb[i] = b[i];
		}
		scanf("%s%s",x,y);

		sx = x;
		sy = y;
		for (maxstep = 1;;maxstep++)
		{
			minlen = 0x3f3f3f3f;
			if (DFS(0,sx))	break;
			if (minlen > sy.length())
			{
				maxstep = -1;
				break;
			}
		}
		printf("%d\n",maxstep);
	}
    return 0;
}

