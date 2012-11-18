#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char num[100][20];
int cnt[1001];

int calc(char *num)
{
	int ans = 0;
	for (int i = 0;num[i] != 0;i++)
		if (num[i] >= 'a' && num[i] <= 'z')
			ans++;
	return ans;
}

int main()
{
	FILE *fnum = fopen("num.txt","r");
	for (int i = 1;i <= 99;i++)
		fscanf(fnum,"%s",num[i]);
	fclose(fnum);

	cnt[1000] = 11;//one thousand
	for (int i = 1;i < 100;i++)
		cnt[i] = calc(num[i]);
	for (int i = 100;i <= 999;i++)
	{
		if (i%100 != 0)
		{
			//X hundred and XX
			cnt[i] = cnt[i/100]+10+cnt[i%100];
		}
		else
		{
			cnt[i] = cnt[i/100]+7;
		}
	}
	int ans = 0;
	for (int i = 1;i <= 1000;i++)
		ans += cnt[i];
	printf("%d\n",ans);
	return 0;
}
