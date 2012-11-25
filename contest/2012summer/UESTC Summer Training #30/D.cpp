#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

vector<long long> a;

int main()
{
    for (int i = 0;i < 3;i++)
    {
        long long v;
        scanf("%I64d",&v);
        a.push_back(v);
    }
    int tot = 0;
    while (true)
    {
        tot++;
        sort(a.begin(),a.end());
        long long mind = a[1]-a[0];
        for (int i = 2;i < a.size();i++)
            mind = min(mind,a[i]-a[i-1]);
        if (mind == 0)
            break;
        a.push_back(mind);
    }
    printf("%d\n",tot);
	return 0;
}
