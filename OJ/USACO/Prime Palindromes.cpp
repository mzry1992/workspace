/*
ID: muziriy3
PROG: pprime
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

int a,b;
deque<string> Q;
const int base[5] = {2,3,5,7,11};

int s2i(string now)
{
    int res = 0;
    for (int i = 0;i < now.size();i++)
        res = res*10+now[i]-'0';
    return res;
}

int modexp(int a,int b,int c)
{
    if (b == 1) return a%c;
    int res = modexp(a,b/2,c);
    res = (int)(((long long)res*(long long)res)%(long long)c);
    if (b%2 == 1)   res = (int)(((long long)res*(long long)(a%c))%(long long)c);
    return res;
}

bool isprime(int a)
{
    if (a == 5 || a == 7 || a == 11)    return true;
    for (int i = 0;i < 5;i++)
    if (modexp(base[i],a-1,a) != 1) return false;
    return true;
}

void solve()
{
    Q.clear();
    Q.push_back("1");
    Q.push_back("3");
    Q.push_back("5");
    Q.push_back("7");
    Q.push_back("9");
    string now,updata;
    for (int level = 2;level <= 8;level++)
    {
        while (true)
        {
            now = Q.front();
            if (now.size() == level)    break;
            Q.pop_front();
            int nnow = s2i(now);
            if (nnow >= a)
            if (isprime(nnow))
                printf("%d\n",nnow);
            if (now.size()%2 == 1)
            {
                updata.resize(now.size()+1);
                for (int i = 0;i <= (now.size()-1)/2;i++)
                    updata[i] = updata[now.size()-i] = now[i];
                if (s2i(updata) <= b)   Q.push_back(updata);
            }
            else
            {
                updata.resize(now.size()+1);
                for (int i = 0;i < (now.size())/2;i++)
                    updata[i] = updata[now.size()-i] = now[i];
                for (int i = 0;i <= 9;i++)
                {
                    updata[now.size()/2] = '0'+i;
                    if (s2i(updata) <= b)   Q.push_back(updata);
                }
            }
            if (Q.empty())  return;
        }
    }
}

int main()
{
    freopen("pprime.in","r",stdin);
    freopen("pprime.out","w",stdout);
    scanf("%d%d",&a,&b);
    solve();
}
