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

using namespace std;

class Islands {
public:
	int beachLength(vector <string>);
};

int Islands::beachLength(vector <string> kingdom) {
	int n,m;
	n = kingdom.size();
	m = kingdom[0].size();
	int i,j,res = 0;
	for (i = 0;i < n;i++)
	for (j = 0;j < m;j++)
	if (i%2 == 0)
	{
            if (j < m-1)
            if (kingdom[i][j+1] != kingdom[i][j])
               res++;
            if (i < n-1)
            {
                if (j > 0)
                if (kingdom[i+1][j-1] != kingdom[i][j])
                   res++;
                if (kingdom[i+1][j] != kingdom[i][j])
                   res++;
            }
    }
    else
    {
            if (j < m-1)
            if (kingdom[i][j+1] != kingdom[i][j])
               res++;
            if (i < n-1)
            {
                if (j < m-1)
                if (kingdom[i+1][j+1] != kingdom[i][j])
                   res++;
                if (kingdom[i+1][j] != kingdom[i][j])
                   res++;
            }
    }
    return res;
}

//Powered by [KawigiEdit] 2.0!
double test0() {
	string t0[] = {".#...#.."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Islands * obj = new Islands();
	clock_t start = clock();
	int my_answer = obj->beachLength(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 4;
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
	string t0[] = {"..#.##", 
 ".##.#.", 
 "#.#..."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Islands * obj = new Islands();
	clock_t start = clock();
	int my_answer = obj->beachLength(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 19;
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
	string t0[] = {"#...#.....",
 "##..#...#."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Islands * obj = new Islands();
	clock_t start = clock();
	int my_answer = obj->beachLength(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 15;
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
	string t0[] = {"....#.",
 ".#....",
 "..#..#",
 "####.."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Islands * obj = new Islands();
	clock_t start = clock();
	int my_answer = obj->beachLength(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 24;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
		
		system("pause");
}
