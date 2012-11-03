/*
ID: muziriy3
PROG: preface
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <deque>
#include <string>
using namespace std;

int n;
int res[7];
string base = "IVXLCDM";
string num;

string getnum(int now,char MI,char V,char I)
{
    string res = "";
    if (now == 9)   res = res+I+MI;
    if (now == 8)   res = res+V+I+I+I;
    if (now == 7)   res = res+V+I+I;
    if (now == 6)   res = res+V+I;
    if (now == 5)   res = res+V;
    if (now == 4)   res = res+I+V;
    if (now == 3)   res = res+I+I+I;
    if (now == 2)   res = res+I+I;
    if (now == 1)   res = res+I;
    return res;
}

string toroman(int now)
{
    string res = "";
    if (now >= 1000)
        res += getnum(now/1000,'?','?','M');
    now %= 1000;
    if (now >= 100)
        res += getnum(now/100,'M','D','C');
    now %= 100;
    if (now >= 10)
        res += getnum(now/10,'C','L','X');
    now %= 10;
    if (now >= 1)
        res += getnum(now/1,'X','V','I');
    return res;
}

int main()
{
    freopen("preface.in","r",stdin);
    freopen("preface.out","w",stdout);
    scanf("%d",&n);
    memset(res,0,sizeof(res));
    for (int i = 1;i <= n;i++)
    {
        num = toroman(i);
        for (int j = 0;j < num.size();j++)
        for (int k = 0;k < base.size();k++)
        if (num[j] == base[k])
        {
            res[k]++;
            break;
        }
    }
    for (int i = 0;i < base.size();i++)
    if (res[i] > 0)
        printf("%c %d\n",base[i],res[i]);
}
