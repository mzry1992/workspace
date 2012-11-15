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

class DropCoins {
public:
	int getMinimum(vector <string>, int);
};

int n,m,sum[30][30];

int DropCoins::getMinimum(vector <string> board, int K) {
    n = board.size();
    m = board[0].size();
    int res = -1;
    for (int xa = 0;xa < n;xa++)
    {
        sum[xa][0] = 0;
        for (int ya = 1;ya <= m;ya++)
            sum[xa][ya] = sum[xa][ya-1]+((board[xa][ya-1] == 'o')?1:0);
    }
    for (int xa = 0;xa < n;xa++)
        for (int ya = 1;ya <= m;ya++)
            for (int yb = ya;yb <= m;yb++)
            {
                int count = 0;
                for (int xb = xa;xb < n;xb++)
                {
                    count += sum[xb][yb]-sum[xb][ya-1];
                    if (count == K)
                    {
                        int sxa = xa,sxb = n-1-xb,sya = ya-1,syb = m-yb;
                        int step = sxa+sxb+sya+syb+min(sxa,sxb)+min(sya,syb);
                        if (res == -1 || res > step)
                            res = step;
                    }
                }
            }
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	string t0[] = {".o.."
,"oooo"
,"..o."}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 3;
	DropCoins * obj = new DropCoins();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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
	string t0[] = {".....o"
,"......"
,"oooooo"
,"oooooo"
,"......"
,"o....."}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 12;
	DropCoins * obj = new DropCoins();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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
	string t0[] = {"...."
,".oo."
,".oo."
,"...."}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 3;
	DropCoins * obj = new DropCoins();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
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
	string t0[] = {"......."
,"..ooo.."
,"ooooooo"
,".oo.oo."
,"oo...oo"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 12;
	DropCoins * obj = new DropCoins();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 4;
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
	string t0[] = {"................."
,".ooooooo...oooo.."
,".ooooooo..oooooo."
,".oo.......oo..oo."
,".oo.......oo..oo."
,".ooooo.....oooo.."
,".ooooooo...oooo.."
,".....ooo..oo..oo."
,"......oo..oo..oo."
,".ooooooo..oooooo."
,".oooooo....oooo.."
,"................."}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 58;
	DropCoins * obj = new DropCoins();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 6;
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
