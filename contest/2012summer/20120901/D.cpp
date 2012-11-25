#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int n, tot, id[30000], page[30000];
char buf[30000][300], tmp[300];
map<string, vector<int> > res;
vector<int> ls;

int main(int argc, char const *argv[])
{
    freopen("data.in", "r", stdin);
    freopen("data1.out", "w", stdout);

    bool firstcas = true;
    while (scanf("%d", &n) != EOF)
    {
        if (!firstcas)
            puts("");
        firstcas = false;

        gets(buf[0]);

        res.clear();

        tot = 0;
        int parid = 0;
        while (gets(buf[tot]))
        {
            if (strlen(buf[tot]) == 0)
                parid = -1;
            for (int i = 0; buf[tot][i] != 0; i++)
                if (buf[tot][i] >= 'a' && buf[tot][i] <= 'z')
                    buf[tot][i] = buf[tot][i] - 'a' + 'A';
                else if (buf[tot][i] >= 'A' && buf[tot][i] <= 'Z')
                    continue;
                else
                    buf[tot][i] = ' ';
            id[tot++] = parid++;
            if (id[tot - 1] == -1 && tot > 1 && id[tot - 2] == -1)  break;
        }

        id[tot] = id[tot + 1] = id[tot + 2] = -1;

        int pageid = 0, pagecnt = 0;

        for (int i = 0; i < tot; i++)
        {
            if (pagecnt == n-1)
            {
                if (id[i+1] == -1)
                {
                    page[i++] = pageid;
                    pageid++;
                    pagecnt = 0;
                }
                else if (id[i] == 0)
                {
                    pageid++;
                    pagecnt = 0;

                    page[i] = pageid;
                    pagecnt++;
                }
                else if (id[i] != -1 && id[i]+1 == id[i+1] && id[i+2] == -1)
                {
                    pageid++;
                    pagecnt = 0;
                    if (id[i + 1] > 2)
                    {
                        page[i] = pageid;
                        pagecnt++;
                    }
                    else
                    {
                        for (int j = i - id[i]; j <= i; j++)
                        {
                            page[j] = pageid;
                            pagecnt++;
                        }
                    }
                }
                else
                {
                    page[i] = pageid;
                    pageid++;
                    pagecnt = 0;
                }
            }
            else
            {
                page[i] = pageid;
                pagecnt++;
                if (pagecnt == n)
                {
                    pageid++;
                    pagecnt = 0;
                }
            }
        }

        for (int i = 0; i < tot; i++)
        {
            int npos, pos = 0;
            while (sscanf(buf[i] + pos, "%s%n", tmp, &npos) != EOF)
            {
                pos += npos;
                res[tmp].push_back(page[i]);
            }
        }
        for (map<string, vector<int> >::iterator it = res.begin(); it != res.end(); it++)
        {
            ls = it->second;
            sort(ls.begin(),ls.end());
            ls.resize(unique(ls.begin(), ls.end())-ls.begin());
            bool first = true;
            int pre = 0;

            printf("%s ", it->first.c_str());
            for (int i = 1; i <= ls.size(); i++)
                if (i == ls.size() || ls[i] > ls[i - 1] + 1)
                {
                    if (i - pre > 2)
                    {
                        if (!first)
                            printf(",");
                        first = false;
                        printf("%d-%d", ls[pre] + 1, ls[i - 1] + 1);
                    }
                    else
                    {
                        for (int j = pre; j < i; j++)
                        {
                            if (!first)
                                printf(",");
                            first = false;
                            printf("%d", ls[j] + 1);
                        }
                    }
                    pre = i;
                }
            puts("");
        }

    }
    return 0;
}
