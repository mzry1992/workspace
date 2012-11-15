#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

int a,b,ta,tb;
set<int> hash,hash2;
vector<int> ga;
char tmp[20];
int len;

int Gao(int a)
{
    sprintf(tmp,"%d",a);
    len = strlen(tmp);
    int res = 0;
    for (int i = 0;i < len;i++)
        res += (tmp[i]-'0')*(tmp[i]-'0');
    return res;
}

int main()
{
    while (true)
    {
        scanf("%d%d",&a,&b);
        ta = a;
        tb = b;
        if (a == 0 && b == 0)   break;
        hash.clear();
        ga.clear();
        for (;;)
        {
            hash.insert(a);
            ga.push_back(a);
            a = Gao(a);
            if (hash.find(a) != hash.end()) break;
        }
        int res,sumb,tres;
        hash2.clear();
        bool flag = false;
        sumb = 0;
        for (;;)
        {
            hash2.insert(b);
            sumb++;
            if (hash.find(b) != hash.end())
            {
                tres = sumb;
                for (int i = 0;i < ga.size();i++)
                {
                    tres++;
                    if (ga[i] == b) break;
                }
                if (flag == false)  res = tres;
                else res = min(res,tres);
                flag = true;
            }
            b = Gao(b);
            if (hash2.find(b) != hash2.end()) break;
        }
        if (flag == false)  res = 0;
        printf("%d %d %d\n",ta,tb,res);
    }
    return 0;
}
