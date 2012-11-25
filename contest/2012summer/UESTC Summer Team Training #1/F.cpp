#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

string a,b,mp[26];
int n;

bool hasres;

void Gao(int na,int nb)
{
    if (hasres == true) return;
    if (na == a.length())
    {
        if (nb == b.length())
        {
            hasres = true;
        }
        return;
    }
    string tmp = mp[a[na]-'a'];
    if (tmp != "")
    {
        if (nb+tmp.length() > b.length())   return;
        if (b.substr(nb,tmp.length()) == tmp)
            Gao(na+1,nb+tmp.length());
    }
    else
    {
        for (int i = 1;i <= n;i++)
            if (nb+i <= b.length())
            {
                mp[a[na]-'a'] = b.substr(nb,i);
                Gao(na+1,nb+i);
                mp[a[na]-'a'] = "";
            }
    }
}

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    cin >> n >> a >> b;
	    if (a.length()*n < b.length())
        {
            puts("0");
            continue;
        }
        hasres = false;
        for (int i = 0;i < 26;i++)
            mp[i] = "";
        Gao(0,0);
        if (hasres)
            puts("1");
        else
            puts("0");
	}
	return 0;
}
