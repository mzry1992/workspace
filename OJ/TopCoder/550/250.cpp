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

class RotatingBot {
public:
	int minArea(vector <int>);
};

const int step[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
pair<int,int> p[51];
#define x first
#define y second

bool go[500][500];

int RotatingBot::minArea(vector <int> moves) {
    int n = moves.size();
    int x,y;
    x = y = 250;
    memset(go,false,sizeof(go));
    go[x][y] = true;
    for (int i = 0;i < n;i++)
        for (int j = 0;j < moves[i];j++)
        {
            x += step[i%4][0];
            y += step[i%4][1];
            if (go[x][y] == true)   return -1;
            go[x][y] = true;
        }
    int xa,xb,ya,yb;
    xa = xb = ya = yb = 250;
    for (int i = 0;i < 500;i++)
        for (int j = 0;j < 500;j++)
            if (go[i][j])
            {
                xa = min(xa,i);
                xb = max(xb,i);
                ya = min(ya,j);
                yb = max(yb,j);
            }
    x = y = 250;
    for (int i = 0;i+1 < n;i++)
    {
        x += step[i%4][0]*moves[i];
        y += step[i%4][1]*moves[i];
        if (i%4 == 0)
        {
            if (x < xb && go[x+1][y] == false)  return -1;
        }
        else if (i%4 == 1)
        {
            if (y < yb && go[x][y+1] == false)  return -1;
        }
        else if (i%4 == 2)
        {
            if (x > xa && go[x-1][y] == false)  return -1;
        }
        else
        {
            if (y > ya && go[x][y-1] == false)  return -1;
        }
    }
    return (xb-xa+1)*(yb-ya+1);
}

//Powered by [KawigiEdit] 2.0!
double test0() {
	int t0[] = {1,1,2,2,2,1,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	RotatingBot * obj = new RotatingBot();
	clock_t start = clock();
	int my_answer = obj->minArea(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 16;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {3,10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	RotatingBot * obj = new RotatingBot();
	clock_t start = clock();
	int my_answer = obj->minArea(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 44;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {1,1,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	RotatingBot * obj = new RotatingBot();
	clock_t start = clock();
	int my_answer = obj->minArea(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {9,5,11,10,11,4,10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	RotatingBot * obj = new RotatingBot();
	clock_t start = clock();
	int my_answer = obj->minArea(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 132;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = {12,1,27,14,27,12,26,11,25,10,24,9,23,8,22,7,21,6,20,5,19,4,18,3,17,2,16,1,15};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	RotatingBot * obj = new RotatingBot();
	clock_t start = clock();
	int my_answer = obj->minArea(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 420;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int t0[] = {8,6,6,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	RotatingBot * obj = new RotatingBot();
	clock_t start = clock();
	int my_answer = obj->minArea(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test6() {
	int t0[] = {8,6,6};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	RotatingBot * obj = new RotatingBot();
	clock_t start = clock();
	int my_answer = obj->minArea(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 63;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test7() {
	int t0[] = {5,4,5,3,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	RotatingBot * obj = new RotatingBot();
	clock_t start = clock();
	int my_answer = obj->minArea(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 30;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
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

	time = test6();
	if (time < 0)
		errors = true;

	time = test7();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
