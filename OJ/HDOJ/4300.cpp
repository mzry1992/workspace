#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

unsigned int ha,hb,weight;

char rule[27],_rule[26],s[210000];

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
		scanf("%s%s",rule,s);
		for (int i = 0;i < 26;i++)
			_rule[rule[i]-'a'] = 'a'+i;
		ha = hb = 0;
		int len = strlen(s);
		int j = len-1;
		int pos = len;
		weight = 1;
		for (int i = 0;i < len;i++)
		{
			if (j <= i)	break;
			ha = ha*127+s[i];
			hb = hb+rule[s[j]-'a']*weight;
			if (ha == hb)
				pos = j;
			j--;
			weight *= 127;
		}
		for (int i = 0;i < pos;i++)
			putchar(s[i]);
		for (int i = 0;i < pos;i++)
			putchar(_rule[s[i]-'a']);
		puts("");
	}
	return 0;
}
