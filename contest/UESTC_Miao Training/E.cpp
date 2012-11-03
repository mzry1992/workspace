#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

char dic[1000][110];
int cnt[1000][26];
vector<string> res;
struct value
{
	int a;
	string b;
	value(){}
	value(int _a,string _b)
	{
		a = _a;
		b = _b;
	}
	bool operator < (const value& t)const
	{
		return a < t.a;
	}
};
priority_queue<value > Q;
int n,m;
int tcnt[26];
string tmp;

int check()
{
	memset(tcnt, 0, sizeof(tcnt));
	for (int i = 0; i < tmp.size(); i++)
		tcnt[tmp[i]-'A']++;
	int res = 0;
	for (int i = 0; i < m; i++)
	{
		if (strcmp(tmp.c_str(), dic[i]) == 0)
			return -1;
		bool flag = true;
		for (int j = 0; j < 26 && flag; j++)
			if (tcnt[j] > cnt[i][j])
				flag = false;
		if (flag)
			res++;
	}
	return res;
}

int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		while (!Q.empty())
			Q.pop();
		res.clear();
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < m; i++)
		{
			scanf("%s", dic[i]);
			for (int j = 0; dic[i][j] != 0; j++)
				cnt[i][dic[i][j]-'A']++;
		}
		tmp.resize(1);
		for (int i = 0; i < 26; i++)
		{
			tmp[0] = 'A' + i;
			Q.push(value(check(), tmp));
		}
		while (!Q.empty())
		{
			value now = Q.top();
			Q.pop();

			if (check() >= 0)
				res.push_back(now.b);
			if (res.size() == n)	break;

			for (int i = 0; i < 26; i++)
			{
				tmp = now.b;
				tmp.push_back('A' + i);
				Q.push(value(check(), tmp));
			}
		}
		for (int i = 0; i < res.size(); i++)
			printf("%s\n", res[i].c_str());
	}
	return 0;
}
