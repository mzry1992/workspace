#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int maxn = 100000000;
bool isPrime[maxn];
vector<int> prime;

void getPrime()
{
    memset(isPrime,1,sizeof(isPrime));
    prime.clear();
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i < maxn; i++)
    {
        if (isPrime[i])
            prime.push_back(i);
        for (int j = 0; j < prime.size() && (long long)prime[j]*i < maxn; j++)
        {
            isPrime[i*prime[j]] = 0;
            if (i%prime[j] == 0)
                break;
        }
    }
}

int ten[20];
map<int,int> len;
map<int,vector<int> > con;
bool check(int a,int b)
{
	if (len[a]+len[b] > 8)	return false;
	return isPrime[a*ten[len[b]]+b] && isPrime[b*ten[len[a]]+a];
}

char buf[20];
int main()
{
	ten[0] = 1;
	for (int i = 1;i < 20;i++)
		ten[i] = ten[i-1]*10;
    getPrime();
    printf("totprime: %d\n",prime.size());

	con.clear();
	int cnt = 0;
    for (int i = 0; i < prime.size(); i++)
    {
        sprintf(buf,"%d",prime[i]);
		len[prime[i]] = strlen(buf);
		if (len[prime[i]] < 2)	continue;
        //divide into two part
        for (int j = 1; buf[j] != 0; j++)
            if (buf[j] != '0')
            {
                int pa,pb;
                pa = pb = 0;
                for (int k = 0; k < j; k++)
                    pa = pa*10+buf[k]-'0';
                for (int k = j; buf[k] != 0; k++)
                    pb = pb*10+buf[k]-'0';

                if (pa < pb && isPrime[pa] && isPrime[pb])
                {
					int pc = pb;
                    for (int k = 0; k < j; k++)
                        pc = pc*10+buf[k]-'0';
                    if (isPrime[pc])
                    {
						cnt++;
						con[pa].push_back(pb);
//						printf("pa = %d, pb = %d\n",pa,pb);
                    }
                }
            }
    }
	printf("totedge: %d\n",cnt);

	int ans = 0x3f3f3f3f;
	for (int i = 0;i < prime.size();i++)
	{
		int	a = prime[i];
		if (a*5 >= ans)	break;
		if (con[a].size() >= 4)
		{
			sort(con[a].begin(),con[a].end());
			for (int pb = 0;pb < con[a].size();pb++)
			{
				int b = con[a][pb];
				if (a+4*b >= ans)	break;
				if (len[b]*2 > 8)	break;
				for (int pc = pb+1;pc < con[a].size();pc++)
				{
					int c = con[a][pc];
					if (a+b+c*3 >= ans)	break;
					if (len[c]*2 > 8)	break;
					if (check(b,c) == false)	continue;
					for (int pd = pc+1;pd < con[a].size();pd++)
					{
						int d = con[a][pd];
						if (a+b+c+d*2 >= ans)	break;
						if (len[d]*2 > 8)	break;
						if (check(b,d) == false)	continue;
						if (check(c,d) == false)	continue;
						for (int pe = pd+1;pe < con[a].size();pe++)
						{
							int e = con[a][pe];
							if (a+b+c+d+e >= ans)	break;
							if (check(b,e) == false)	continue;
							if (check(c,e) == false)	continue;
							if (check(d,e) == false)	continue;

							printf("a = %d, b = %d, c = %d, d = %d, e = %d\n",a,b,c,d,e);
							ans = a+b+c+d+e;
						}
					}
				}
			}
		}
	}
	printf("%d\n",ans);
    return 0;
}
