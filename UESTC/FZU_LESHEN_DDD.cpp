#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long a,c;
char b[1001000];
int prime[10100 ],tot;
bool isprime[101000];
long long ans;

void getprime()
{
     tot = 0;
     memset(isprime,true,sizeof(isprime));
     for (int i = 2;i <= 100000;i++)
     {
         if (isprime[i] == true)
         {
                        tot++;
                        prime[tot] = i;
         }
         for (int j = 1;j <= tot && i*prime[j] <= 100000;j++)
         {
             isprime[i*prime[j]] = false;
             if (i%prime[j] == 0) break;
         }
     }
}

long long ol(long long n)
{
	long long res = n;
	for (int i = 1;i <= tot;i++)
		if (n%prime[i] == 0)
		{
			while (n%prime[i] == 0)
				n /= prime[i];
			res = (res/prime[i])*(prime[i]-1);
		}
	if (n != 1)
		res = (res/n)*(n-1);
	return res;
}

bool cmp(char *a,char *b)
{
    int la,lb;
    la = strlen(a);
    lb = strlen(b);
    if (la > lb)
        return true;
    if (la < lb)
        return false;
    for (int i = 0;i < la;i++)
        if (a[i] < b[i])
            return false;
    return true;
}

long long MOD(char *s,long long k)
{
    long long now;
    long long res;
    now = 0;
    res = 0;
    int l = strlen(s);
    for (int i = 0;i < l;i++)
    {
        now = now*10+s[i]-'0';
        res = now%k;
        now = res;
    }
    return res;
}

void solve(int now)
{
    if (now == 1)
    {
        ans = a%c;
        return;
    }
    solve(now/2);
    ans = ((ans%c)*(ans%c))%c;
    if (now%2 == 1)
        ans = ((ans%c)*(a%c))%c;
}

int main()
{
    getprime();
    while (scanf("%d%s%d",&a,&b,&c) != EOF)
    {
        int phic = ol(c);
        int times;
        char ts[100];
        sprintf(ts,"%d",phic);
        if (cmp(ts,b) == true)
            sscanf(b,"%d",&times);
        else
            times = MOD(b,phic)+phic;
        solve(times);
        //cout << a << ' ' << phic << ' ' << c << endl;
        cout << ans%c << endl;
    }
}
