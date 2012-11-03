#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
using namespace std;

int len,n,out[20000],go[2000][40],totid;
char s[20000];
string tmp;
map<string,int> id;
int root,myid,toid;
queue<int> Q;
bool flag[2000];

void Gao(int root)
{
    while (!Q.empty())  Q.pop();
    Q.push(root);
    int now;
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop();
        for (int i = 0;i < out[now];i++)
            if (go[now][i] != now)
            {
                if (out[go[now][i]] != 0)
                    Q.push(go[now][i]);
                else
                    flag[go[now][i]] = true;
            }
    }
}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        id.clear();
        memset(out,0,sizeof(out));
        totid = 0;
        for (int i = 0;i < n;i++)
        {
            scanf("%s",s);
            len = strlen(s);
            for (int j = 0;j < len;j++)
                if (s[j] == ':')
                {
                    tmp = "";
                    for (int k = 0;k < j;k++)
                        tmp = tmp+s[k];
                    if (id.find(tmp) == id.end())
                        id[tmp] = ++totid;
                    myid = id[tmp];
                    if (i == 0)
                        root = myid;
                    int pre = j+1;
                    for (int k = j+1;k < len;k++)
                        if (s[k] == ',' || s[k] == '.' || k == len-1)
                        {
                            tmp = "";
                            for (int q = pre;q < k;q++)
                                tmp = tmp+s[q];
                            pre = k+1;
                            if (id.find(tmp) == id.end())
                                id[tmp] = ++totid;
                            toid = id[tmp];
                            go[myid][out[myid]++] = toid;
                        }
                    break;
                }
        }
        /*for (int i = 1;i <= totid;i++)
        {
            cout << i << ' ' << out[i] << endl;
            for (int j = 0;j < out[i];j++)
                cout << go[i][j] << ' ';
            cout << endl;
        }*/
        memset(flag,false,sizeof(flag));
        Gao(root);
        int dif = 0;
        for (int i = 1;i <= totid;i++)
            if (flag[i] == true)
                dif++;
        printf("%d\n",dif);
    }
}
