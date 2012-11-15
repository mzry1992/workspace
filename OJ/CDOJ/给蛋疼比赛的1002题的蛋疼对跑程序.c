#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

const string sz    = "0123456789";
const int    hf[10] = {6,2,5,5,4,5,6,3,7,6};
string a,b;
bool ha,hb;

void DFS(int n,strint c)
{
    if (c.size() > 0)
        if (c[0] == '0')
            return;
    if (n == 0)
    {
        if (ha == false)
            a = b = c;
        else
        {
            if (a > c)
                a = c;
            if (b < c)
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
