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
using namespace std;

class RandomColoring {
public:
	double getProbability(int, int, int, int, int, int, int, int, int);
};

bool debug;
double dp[2][50][50][50],a[2][51][51][51];
int nx,ny,nz;
bool pos;

void updata(int x,int y,int z,double val)
{
	int tmp=y,tmp1=z;
	while (x<=nx)
	{
		y=tmp;
		while (y<=ny)
		{
			z=tmp1;
			while (z<=nz)
			{
				a[pos][x][y][z]+=val;
				z+=z&(-z);
			}
			y+=y&(-y);
		}
		x+=x&(-x);
	}
}

double read(int x,int y,int z)
{
	if (x < 1 || y < 1 || z < 1)	
		return 0;
	int tmp=y,tmp1=z;
	double sum=0;
	while (x>0)
	{
		y=tmp;
		while (y>0)
		{
			z=tmp1;
			while (z>0)
			{
				sum+=a[!pos][x][y][z];
				z-=z&(-z);
			}
			y-=y&(-y);	
		}	
		x-=x&(-x);
	}	
	return sum;
}

double read(int xa,int ya,int za,int xb,int yb,int zb)
{
	return read(xb,yb,zb)-(read(xa-1,yb,zb)+read(xb,ya-1,zb)+read(xb,yb,za-1))+(read(xa-1,yb,za-1)+read(xb,ya-1,za-1)+read(xa-1,ya-1,zb))-read(xa-1,ya-1,za-1);
}

double read(int x,int y,int z,int dis)
{
	/*if (debug)
	{
		printf("read : %d,%d,%d,%d,%d,%d\n",max(1,x-dis),max(1,y-dis),max(1,z-dis),min(nx,x+dis),min(ny,y+dis),min(nz,z+dis));
		printf("res = %d\n",read(max(1,x-dis),max(1,y-dis),max(1,z-dis),min(nx,x+dis),min(ny,y+dis),min(nz,z+dis)));
	}*/
	return read(max(1,x-dis),max(1,y-dis),max(1,z-dis),min(nx,x+dis),min(ny,y+dis),min(nz,z+dis));
}

bool check(int x,int y,int z,int sx,int sy,int sz,int d1,int d2)
{
	if (abs(x-sx) > d2 || abs(y-sy) > d2 || abs(z-sz) > d2)	return false;
	if (abs(x-sx) < d1 && abs(y-sy) < d1 && abs(z-sz) < d1)	return false;
	return true;
}

int calc(int x,int y,int z,int dis)
{
	return (min(nx,x+dis)-max(1,x-dis)+1)*(min(ny,y+dis)-max(1,y-dis)+1)*(min(nz,z+dis)-max(1,z-dis)+1);
}

double RandomColoring::getProbability(int N, int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2) {
	if (d1 == d2)	return 1.0;
	memset(dp,0,sizeof(dp));
	memset(a,0,sizeof(a));
	nx = maxR;
	ny = maxG;
	nz = maxB;
	int tot = calc(startR+1,startG+1,startB+1,d2);
	if (d1 > 0)
		tot -= calc(startR+1,startG+1,startB+1,d1-1);
	dp[0][startR][startG][startB] = 1.0/tot;
	pos = 0;
	updata(startR+1,startG+1,startB+1,dp[0][startR][startG][startB]);
	for (int i = 1;i < N;i++)
	{
		pos = !pos;
		memset(dp[pos],0,sizeof(dp[pos]));
		memset(a[pos],0,sizeof(a[pos]));
		for (int x = 0;x < nx;x++)
			for (int y = 0;y < ny;y++)
				for (int z = 0;z < nz;z++)
				{
					dp[pos][x][y][z] = read(x+1,y+1,z+1,d2);
					if (d1 > 0)
						dp[pos][x][y][z] -= read(x+1,y+1,z+1,d1-1);
						
					int tot = calc(x+1,y+1,z+1,d2);
					if (d1 > 0)
						tot -= calc(x+1,y+1,z+1,d1-1);
					if (i+1 < N)
						dp[pos][x][y][z] /= (double)tot;
					
					updata(x+1,y+1,z+1,dp[pos][x][y][z]);
				}
	}
	double res = 0.0;
	for (int x = 0;x < nx;x++)
		for (int y = 0;y < ny;y++)
			for (int z = 0;z < nz;z++)
			{
				if (check(x,y,z,startR,startG,startB,d1,d2) == false)
					res += dp[pos][x][y][z];
			}
	return res;
}


double test0() {
	int p0 = 2;
	int p1 = 5;
	int p2 = 1;
	int p3 = 1;
	int p4 = 2;
	int p5 = 0;
	int p6 = 0;
	int p7 = 0;
	int p8 = 1;
	RandomColoring * obj = new RandomColoring();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1, p2, p3, p4, p5, p6, p7, p8);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p9 = 0.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p9 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p9 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 3;
	int p1 = 5;
	int p2 = 1;
	int p3 = 1;
	int p4 = 2;
	int p5 = 0;
	int p6 = 0;
	int p7 = 0;
	int p8 = 1;
	RandomColoring * obj = new RandomColoring();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1, p2, p3, p4, p5, p6, p7, p8);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p9 = 0.22222222222222227;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p9 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p9 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 7;
	int p1 = 4;
	int p2 = 2;
	int p3 = 2;
	int p4 = 0;
	int p5 = 0;
	int p6 = 0;
	int p7 = 3;
	int p8 = 3;
	RandomColoring * obj = new RandomColoring();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1, p2, p3, p4, p5, p6, p7, p8);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p9 = 1.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p9 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p9 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 10;
	int p1 = 7;
	int p2 = 8;
	int p3 = 9;
	int p4 = 1;
	int p5 = 2;
	int p6 = 3;
	int p7 = 0;
	int p8 = 10;
	RandomColoring * obj = new RandomColoring();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1, p2, p3, p4, p5, p6, p7, p8);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p9 = 0.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p9 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p9 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 10;
	int p1 = 7;
	int p2 = 8;
	int p3 = 9;
	int p4 = 1;
	int p5 = 2;
	int p6 = 3;
	int p7 = 4;
	int p8 = 10;
	RandomColoring * obj = new RandomColoring();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1, p2, p3, p4, p5, p6, p7, p8);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p9 = 0.37826245943967396;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p9 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p9 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int p0 = 3;
	int p1 = 3;
	int p2 = 2;
	int p3 = 2;
	int p4 = 1;
	int p5 = 0;
	int p6 = 0;
	int p7 = 1;
	int p8 = 2;
	RandomColoring * obj = new RandomColoring();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1, p2, p3, p4, p5, p6, p7, p8);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p9 = 0.09090909090909148;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p9 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p9 != my_answer) {
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
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
