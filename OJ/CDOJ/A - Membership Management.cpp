#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <cstring>
using namespace std;

int n,len,totgroup;
char s[10000];
map<string,int> id;
set<string> res;
string mem[200][20];
int totmem[200];
string tmp;

void Gao(int now)
{
    for (int i = 1;i <= totmem[now];i++)
        if (id.find(mem[now][i]) != id.end())
            Gao(id[mem[now][i]]);
        else
            res.insert(mem[now][i]);
}

int main()
{
    freopen("a.txt","r",stdin);
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        totgroup = 0;
        id.clear();
        res.clear();
        for (int i = 1;i <= n;i++)
            totmem[i] = 0;
        for (int i = 1;i <= n;i++)
        {
            scanf("%s",s);
            len = strlen(s);
            totgroup++;
            for (int j = 0;j < len;j++)
                if (s[j] == ':')
                {
                    tmp = "";
                    for (int k = 0;k < j;k++)
                        tmp = tmp+s[k];
                    id[tmp] = totgroup;
                    int pre = j+1;
                    for (int k = j+1;k < len;k++)
                        if (s[k] == ',' || s[k] == '.' || k == len-1)
                        {
                            tmp = "";
                            for (int q = pre;q < k;q++)
                                tmp = tmp+s[q];
                            totmem[totgroup]++;
                            mem[totgroup][totmem[totgroup]] = tmp;
                            pre = k+1;
                        }
                }
        }
        Gao(1);
        printf("%d\n",res.size());
    }
    return 0;
}
