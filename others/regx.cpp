#include <stdio.h>
#include <sys/types.h>
#include <regex.h>

const char *pattern = "regx[a-z]";
char buf[1024];

regex_t reg;
const size_t nmatch = 1024;
regmatch_t pm[nmatch];
char ebuf[128];

bool init()
{
	int res = regcomp(&reg,pattern,0);
	if (res != 0)
	{
		regerror(res,&reg,ebuf,sizeof(ebuf));
		printf("Error : %s\n",ebuf);
		return false;
	}
	return true;
}

void match(char *buf)
{
	int res = regexec(&reg,buf,nmatch,pm,0);
	if (res == REG_NOMATCH)	return;
	else if (res != 0)
	{
		regerror(res,&reg,ebuf,sizeof(ebuf));
		printf("Error : %s\n",ebuf);
		return;
	}

	int x;
	for (x = 0;x < nmatch && pm[x].rm_so != -1;x++)
	{
		int i;
		for (i = pm[x].rm_so;i < pm[x].rm_eo;i++)
			putchar(buf[i]);
		puts("");
	}
}

int main()
{
	if (init())
	{
		while (scanf("%s",buf) != EOF)
			match(buf);
	}
	return 0;
}
 
