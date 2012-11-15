#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

string s;
int n,l,r;

int main()
{
    cin >> s;
    scanf("%d",&n);
    for (int i = 1;i <= n;i++)
    {
        scanf("%d%d",&l,&r);
        cout << s.substr(l,r) << endl;
    }
}
