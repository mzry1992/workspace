#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const char tg[10][5] = {"Jia","Yi","Bing","Ding","Wu","Ji","Geng","Xin","Ren","Gui"};
const char dz[12][5] = {"zi","chou","yin","mao","chen","si","wu","wei","shen","you","xu","hai"};

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        int n;
        scanf("%d",&n);
        if (n < 0)  n++;
        int pa,pb;
        pa = (n-3)%10;
        pb = (n-3)%12;
        if (pa <= 0) pa += 10;
        if (pb <= 0) pb += 12;
        pa--;
        pb--;
        printf("%s%s\n",tg[pa],dz[pb]);
    }
	return 0;
}
