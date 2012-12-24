#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

long long a,b;
int k;
int maxx[800000];
int r[800000];
int nxt[400000];
long long pos[400000],dis[400000];
int lcm;

int getid(long long now)
{
	now = now%lcm;
	if (now == 0)
		return lcm;
	return now;
}

int main()
{
    while (cin >> b >> a >> k)
    {
		if (a == b)
		{
			puts("0");
			continue;
		}
        lcm = 1;
        for (int i = 1; i <= k; i++)
            lcm = lcm/__gcd(lcm,i)*i;
		for (int i = 1;i <= lcm*2;i++)
			for (int j = k;j >= 1;j--)
				if (i%j == 0)
				{
					maxx[i] = j;
					r[i] = max(i+1,i+maxx[i]-1);
					break;
				}
		for (int i = 1;i <= lcm;i++)
		{
			pos[i] = 0;
			nxt[i] = i+1;
			for (int j = i+2;j <= r[i];j++)
				if (r[j] > r[nxt[i]])
					nxt[i] = j;
		}
		long long step = 0;
		long long circlelen = 0;
		long long circlestep = 0;
		int laststep;
		while (true)
		{
			if (a+r[getid(a)]-getid(a) >= b)
			{
				step++;
				a = b;
				break;
			}
			pos[getid(a)] = a;
			dis[getid(a)] = step;
			laststep = nxt[getid(a)]-getid(a);
			a = a+laststep;
			step++;
			if (pos[getid(a)] != 0)
			{
				//find circle!
				circlelen = a-pos[getid(a)];
				circlestep = step-dis[getid(a)];
				break;
			}
		}
		//printf("step = %lld, circlelen = %lld, circlestep = %lld, laststep = %d\n",step,circlelen,circlestep,laststep);
		
		if (a < b)
		{
			//quick jump
			long long tostep = (b-a)/circlelen;
			a = a+tostep*circlelen;
			step = step+tostep*circlestep;
			a = a-laststep;
			step = step-1;
			
			while (true)
			{
				if (a+r[getid(a)]-getid(a) >= b)
				{
					step++;
					break;
				}
				a = a+nxt[getid(a)]-getid(a);
				step++;
			}
		}

		cout << step << endl;
    }
    return 0;
}
