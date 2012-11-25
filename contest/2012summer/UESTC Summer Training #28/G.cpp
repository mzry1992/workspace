#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct player
{
    string name;
    int win,round;
};

char buf[20];
player p[1<<10];
int n;

bool cmp(player a,player b)
{
    return a.win > b.win;
}

bool cmp2(player a,player b)
{
    if (a.round == b.round)
    {
        return a.name < b.name;
    }
    return a.round > b.round;
}

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    scanf("%d",&n);
	    for (int i = 0;i < (1<<n);i++)
	    {
	        scanf("%s%d",buf,&p[i].win);
	        p[i].name = buf;
	    }
	    sort(p,p+(1<<n),cmp);
	    int r = 3*n-p[0].win;
        for (int i = 0;i < (1<<n);i++)
            if (2*r < p[i].win)
                p[i].round = r+(p[i].win-2*r)/3;
            else
                p[i].round = p[i].win/2;
        sort(p,p+(1<<n),cmp2);
        for (int i = 0;i < (1<<n);i++)
            printf("%s\n",p[i].name.c_str());
	}
	return 0;
}
