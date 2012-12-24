#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int a[10];
char s[100];

int main()
{
    scanf("%s",s);
    int cnt = 0;
    for (int i = 0;s[i] != 0;i++)
        for (int j = i+1;s[j] != 0;j++)
            if (s[i] > s[j])
                cnt++;
    cout << cnt << endl;
	return 0;
}
