#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

const string sz    = "0123456789";
const int    hf[10] = {6,2,5,5,4,5,6,3,7,6};
string a,b;
bool ha,hb;

bool big(string a,string b)
{
    if (a.size() > b.size())
        return true;
    if (a.size() < b.size())
        return false;
    return a > b;
}

void DFS(int n,string c)
{
    if (c.size() > 0)
        if (c[0] == '0')
            return;
    if (n == 0)
    {
        if (ha == false)
        {
            a = b = c;
            ha = hb = true;
        }
        else
        {
            if (big(a,c))
                a = c;
            if (big(c,b))
                b = c;
        }
        return;
    }
    for (int i = 0;i <= 9;i++)
    if (n >= hf[i])
        DFS(n-hf[i],c+sz[i]);
}

int main()
{
    int n;
    while (scanf("%d",&n) != EOF)
    {
        ha = hb = false;
        DFS(n,"");
        cout << a << " " << b << endl;
    }
}
