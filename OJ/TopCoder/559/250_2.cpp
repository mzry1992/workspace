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

class HyperKnight
{
public:
    long long countCells(int, int, int, int, int);
};

const int step[8][2] = {{3,4},{4,3},{4,2},{3,1},{2,1},{1,2},{1,3},{2,4}};
int cov[5][5];
int lx[6],ly[6];

long long HyperKnight::countCells(int a, int b, int numRows, int numColumns, int k)
{
	if (a < b)
		swap(a,b);
	lx[0] = 0;
	lx[1] = b;
	lx[2] = a;
	lx[3] = numRows-a;
	lx[4] = numRows-b;
	lx[5] = numRows;

	ly[0] = 0;
	ly[1] = b;
	ly[2] = a;
	ly[3] = numColumns-a;
	ly[4] = numColumns-b;
	ly[5] = numColumns;

	memset(cov,0,sizeof(cov));
	for (int i = 0;i < 2;i++)
		for (int x = 0;x < step[i][0];x++)
			for (int y = 0;y < step[i][1];y++)
				cov[x][y]++;

	for (int i = 2;i < 4;i++)
		for (int x = 0;x < step[i][0];x++)
			for (int y = step[i][1];y < 5;y++)
				cov[x][y]++;


	for (int i = 4;i < 6;i++)
		for (int x = step[i][0];x < 5;x++)
			for (int y = step[i][1];y < 5;y++)
				cov[x][y]++;

	for (int i = 6;i < 8;i++)
		for (int x = step[i][0];x < 5;x++)
			for (int y = 0;y < step[i][1];y++)
				cov[x][y]++;

//	for (int i = 0;i < 5;i++)
//	{
//		for (int j = 0;j < 5;j++)
//			printf("%d ",cov[i][j]);
//		printf("\n");
//	}

//	for (int i = 0;i <= 5;i++)
//		printf("%d ",lx[i]);
//	printf("\n");
//	for (int i = 0;i <= 5;i++)
//		printf("%d ",ly[i]);
//	printf("\n");

    long long res = 0;

	for (int i = 0;i < 5;i++)
		for (int j = 0;j < 5;j++)
			if (cov[i][j] == k)
			{
				res += (long long)(lx[i+1]-lx[i])*(ly[j+1]-ly[j]);
			}

    return res;
}

//Powered by [KawigiEdit] 2.0!
double test0()
{
    int p0 = 2;
    int p1 = 1;
    int p2 = 8;
    int p3 = 8;
    int p4 = 4;
    HyperKnight * obj = new HyperKnight();
    clock_t start = clock();
    long long my_answer = obj->countCells(p0, p1, p2, p3, p4);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p5 = 20LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p5 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p5 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test1()
{
    int p0 = 3;
    int p1 = 2;
    int p2 = 8;
    int p3 = 8;
    int p4 = 2;
    HyperKnight * obj = new HyperKnight();
    clock_t start = clock();
    long long my_answer = obj->countCells(p0, p1, p2, p3, p4);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p5 = 16LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p5 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p5 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test2()
{
    int p0 = 1;
    int p1 = 3;
    int p2 = 7;
    int p3 = 11;
    int p4 = 0;
    HyperKnight * obj = new HyperKnight();
    clock_t start = clock();
    long long my_answer = obj->countCells(p0, p1, p2, p3, p4);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p5 = 0LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p5 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p5 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test3()
{
    int p0 = 3;
    int p1 = 2;
    int p2 = 10;
    int p3 = 20;
    int p4 = 8;
    HyperKnight * obj = new HyperKnight();
    clock_t start = clock();
    long long my_answer = obj->countCells(p0, p1, p2, p3, p4);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p5 = 56LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p5 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p5 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test4()
{
    int p0 = 1;
    int p1 = 4;
    int p2 = 100;
    int p3 = 10;
    int p4 = 6;
    HyperKnight * obj = new HyperKnight();
    clock_t start = clock();
    long long my_answer = obj->countCells(p0, p1, p2, p3, p4);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p5 = 564LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p5 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p5 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test5()
{
    int p0 = 2;
    int p1 = 3;
    int p2 = 1000000000;
    int p3 = 1000000000;
    int p4 = 8;
    HyperKnight * obj = new HyperKnight();
    clock_t start = clock();
    long long my_answer = obj->countCells(p0, p1, p2, p3, p4);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p5 = 999999988000000036LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p5 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p5 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
int main()
{
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
