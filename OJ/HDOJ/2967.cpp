#include "iostream"
#include "cstdio"
#include "cstring"
#include "algorithm"
#include "vector"
using namespace std;

int n, col[26], last[26];
int len[26];
char rule[26][110];
bool ans, vis[26];

bool check(int x)
{
	col[x] = 1;
	if (last[x] == -1)
	{
		ans = false;
		return true;
	}
	if (len[last[x]] > 1)
		return true;
	vector<int> s;
	int now = x;
	while (now != last[x])
	{
		s.push_back(now);
		now = rule[now][0]-'a';
	}
	for (int i = s.size()-1;i >= 0;i--)
		for (int j = 1;j < len[s[i]];j++)
			if (col[rule[s[i]][j]-'a'] == 1)
				return true;
			else if (col[rule[s[i]][j]-'a'] == 0)
			{
				if (check(rule[s[i]][j]-'a'))
					return true;
			}
	col[x] = 2;
	return false;
}

int main(int argc, char const *argv[])
{
    //freopen("data.in", "r", stdin);
    int totcas;
    scanf("%d", &totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%s", rule[i]);
            len[i] = strlen(rule[i]);
        }
        for (int i = 0; i < n; i++)
        {
            memset(vis, false, sizeof(vis));
            int now = i;
            while (true)
            {
                vis[now] = true;
                int pre = now;
                now = rule[now][0] - 'a';
                if (vis[now])
                {
                    if (now != pre)
                        last[i] = -1;
                    else
                        last[i] = now;
                    break;
                }
            }
        }
        ans = true;
        memset(col,0,sizeof(col));
        check(0);
        if (ans)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
