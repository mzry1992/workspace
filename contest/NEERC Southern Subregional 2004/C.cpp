#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;

map<string,int> dist;
set<string> inq;
queue<string> Q;

int main()
{
    string tmp = "ABCD";
    dist[tmp] = 0;
    Q.push(tmp);
    inq.insert(tmp);

    while (!Q.empty())
    {
        string now = Q.front();
        Q.pop();
        inq.erase(now);

        //printf("%s -> %d\n",now.c_str(),dist[now]);

        for (int i = 0;i < now.length();i++)
        {
            string nxt = now.substr(i+1,now.length()-i-1);
            nxt.push_back(now[i]);
            nxt = nxt+now.substr(0,i);

            if (dist.find(nxt) == dist.end() ||
                dist[nxt] > dist[now]+i+1)
                {
                    dist[nxt] = dist[now]+i+1;
                    if (inq.find(nxt) == inq.end())
                    {
                        Q.push(nxt);
                        inq.insert(nxt);
                    }
                }
        }
    }

    int maxlen = 0;
    for (map<string,int>::iterator it = dist.begin();it != dist.end();it++)
        //maxlen = max(maxlen,it->second);
        printf("%s : %d\n",it->first.c_str(),it->second+4);
    printf("%d\n",maxlen);
    return 0;
}

