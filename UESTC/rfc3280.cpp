#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

map<string,int> times;
char now[100];

int main()
{
    freopen("rfc3280.txt","r",stdin);
    times.clear();
    while (scanf("%s",now) != EOF)
    {
        int len = strlen(now);
        if (len == 9)
        {
            for (int i = 0; i < len; i++)
                if (now[i] >= 'A' && now[i] <= 'Z')
                    now[i] = now[i]-'A'+'a';
            times[now]++;
        }
    }
    string res = "";
    for (map<string,int>::iterator it = times.begin(); it != times.end(); it++)
        if (times[res] < it->second)
            res = it->first;
    cout << res << endl;
    return 0;
}
