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

class MovieSeating {
public:
	long long getSeatings(int, vector <string>);
};

long long MovieSeating::getSeatings(int numFriends, vector <string> hall) {
    int n,m;

    n = hall.size();
    m = hall[0].size();
    long long res = 0;
    if (numFriends == 1)
    {
        int count = 0;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                count++;
        return count;
    }
    for (int i = 0;i < n;i++)
    {
        int count = 0;
        for (int j = 0;j < m;j++)
            if (hall[i][j] == '.')
                count++;
        //cout << i << ' ' << count << endl;
        if (count >= numFriends)
        {
            long long tt = 1;
            for (int j = count;j >= count-numFriends+1;j--)
                tt *= j;
            res += tt;
        }
    }
    for (int i = 0;i < m;i++)
    {
        int count = 0;
        for (int j = 0;j < n;j++)
            if (hall[j][i] == '.')
                count++;
        if (count >= numFriends)
        {
            long long tt = 1;
            for (int j = count;j >= count-numFriends+1;j--)
                tt *= j;
            res += tt;
        }
    }
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int p0 = 2;
	string t1[] = { ".#..",
  ".##.",
  "...." };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	MovieSeating * obj = new MovieSeating();
	clock_t start = clock();
	long long my_answer = obj->getSeatings(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 34LL;
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
	string t1[] = { "..#",
  ".##",
  "..." };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	MovieSeating * obj = new MovieSeating();
	clock_t start = clock();
	long long my_answer = obj->getSeatings(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 16LL;
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
	int p0 = 5;
	string t1[] = { "..####..",
  ".###.##.",
  ".######.",
  "#.#.#.#." };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	MovieSeating * obj = new MovieSeating();
	clock_t start = clock();
	long long my_answer = obj->getSeatings(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 0LL;
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
	int p0 = 1;
	string t1[] = { "." };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	MovieSeating * obj = new MovieSeating();
	clock_t start = clock();
	long long my_answer = obj->getSeatings(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 40320LL;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
