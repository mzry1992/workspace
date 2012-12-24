#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define bint long long
using namespace std;

const int TIME = 8;//测试次数，8~10够了
int factor[100],fac_top = -1;

//计算两个数的gcd
bint gcd(bint small,bint big)
{
	while(small)
	{
		swap(small,big);
		small%=big;
	}
	return abs(big);
}

//ret = (a*b)%n (n<2^62)
bint muti_mod(bint a,bint b,bint n)
{
	bint exp = a%n, res = 0;
	while(b)
	{
		if(b&1)
		{
			res += exp;
			if(res>n) res -= n;
		}
		exp <<= 1;
		if (exp>n) exp -= n;
		b>>=1;
	}
	return res;
}

// ret = (a^b)%n
bint mod_exp(bint a,bint p,bint m)
{
	bint exp=a%m, res=1; //
	while(p>1)
	{
		if(p&1)
			res=muti_mod(res,exp,m);
		exp = muti_mod(exp,exp,m);
		p>>=1;
	}
	return muti_mod(res,exp,m);
}

//miller-rabin法测试素数, time 测试次数
bool miller_rabin(bint n, int times)
{
	if(n==2)return 1;
	if(n<2||!(n&1))return 0;
	bint a, u=n-1, x, y;
	int t=0;
	while(u%2==0)
	{
		t++;
		u/=2;
	}
	srand(time(0));
	for(int i=0; i<times; i++)
	{
		a = rand() % (n-1) + 1;
		x = mod_exp(a, u, n);
		for(int j=0; j<t; j++)
		{
			y = muti_mod(x, x, n);
			if ( y == 1 && x != 1 && x != n-1 )
				return false; //must not
			x = y;
		}
		if( y!=1) return false;
	}
	return true;
}

bint pollard_rho(bint n,int c)//找出一个因子
{
	bint x,y,d,i = 1,k = 2;
	srand(time(0));
	x = rand()%(n-1)+1;
	y = x;
	while(true)
	{
		i++;
		x = (muti_mod(x,x,n) + c) % n;
		d = gcd(y-x, n);
		if (1 < d && d < n) return d;
		if( y == x) return n;
		if(i == k)
		{
			y = x;
			k <<= 1;
		}
	}
}

void findFactor(bint n,int k)//二分找出所有质因子，存入factor
{
	if(n==1)return;
	if(miller_rabin(n, TIME))
	{
		factor[++fac_top] = n;
		return;
	}
	bint p = n;
	while(p >= n)
		p = pollard_rho(p,k--);//k值变化，防止死循环
	findFactor(p,k);
	findFactor(n/p,k);
}

class TheDivisionGame {
public:
	long long countWinningIntervals(int, int);
};

int cnt[1000010];
int sum[1000010];
int tot[10000];

long long TheDivisionGame::countWinningIntervals(int L, int R) {

    for (int i = L;i <= R;i++)
    {
		fac_top = -1;
		if(miller_rabin(i,TIME))
            cnt[i-L] = 1;
		else
		{
			findFactor(i,107);
            cnt[i-L] = fac_top+1;
		}
    }

    sum[0] = cnt[0];
    for (int i = L+1;i <= R;i++)
        sum[i-L] = sum[i-L-1]^cnt[i-L];

    long long nn = R-L+1;
    long long res = nn*(nn+1)/2;
    memset(tot,0,sizeof(tot));
    tot[0] = 1;
    for (int i = L;i <= R;i++)
    {
        res -= tot[sum[i-L]];
        tot[sum[i-L]]++;
    }
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int p0 = 1000000000;
	int p1 = 1001000000;
	TheDivisionGame * obj = new TheDivisionGame();
	clock_t start = clock();
	long long my_answer = obj->countWinningIntervals(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 2LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 2;
	int p1 = 5;
	TheDivisionGame * obj = new TheDivisionGame();
	clock_t start = clock();
	long long my_answer = obj->countWinningIntervals(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 9LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 2;
	int p1 = 6;
	TheDivisionGame * obj = new TheDivisionGame();
	clock_t start = clock();
	long long my_answer = obj->countWinningIntervals(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 13LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 2;
	int p1 = 100;
	TheDivisionGame * obj = new TheDivisionGame();
	clock_t start = clock();
	long long my_answer = obj->countWinningIntervals(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 4345LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 12566125;
	int p1 = 12567777;
	TheDivisionGame * obj = new TheDivisionGame();
	clock_t start = clock();
	long long my_answer = obj->countWinningIntervals(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 1313432LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
int main() {
	int time;
	bool errors = false;

	time = test0();
	if (time < 0)
		errors = true;

	time = test1();
	if (time < 0)
		errors = true;

	time = test2();
	if (time < 0)
		errors = true;

	time = test3();
	if (time < 0)
		errors = true;

	time = test4();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
