#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int getId(char *s)
{
    int l=strlen(s);
    int ret=0;
    for (int i=l-1;i>=0;i--)
        ret=ret*128+s[i];
    return ret;
}

void getS(int id)
{
    do
    {
        putchar(id%128);
        id/=128;
    }while (id);
}

vector<int> s;
int k;
int a[40000];

void add(int id)
{
    s.push_back(id);
}

void rotate()
{
    if (s.size() <= k)
        reverse(s.begin(),s.end());
    else
        reverse(s.end()-k,s.end());
}

int main()
{
	freopen("F.in","r",stdin);
	freopen("F2.out","w",stdout);
    s.clear();

    int n,m;
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0;i<n;i++)
    {
        char s[4];
        scanf("%s",s);
        a[i]=getId(s);
    }

    for (int i=n-1;i>=0;i--)
        add(a[i]);
    while (m--)
    {
        char s[10];
        scanf("%s",s);
        if (s[0]=='R')
            rotate();
        else
        {
            char t[5];
            sscanf(s,"ADD(%s)",t);
            t[strlen(t)-1]=0;
            add(getId(t));
        }
    }

    for (int i = s.size()-1;i >= 0;i--)
    {
        getS(s[i]);
        puts("");
    }
    return 0;
}

