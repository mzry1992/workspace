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

class KindAndCruel {
public:
	int crossTheField(string, int, int);
};

struct node
{
    int pos,tim;
};
deque<node> Q;
bool visit[60][60][60];

node getnode(int pos,int tim)
{
    node res;
    res.pos = pos;
    res.tim = tim;
    return res;
}
const int step[3] = {-1,0,1};

int KindAndCruel::crossTheField(string field, int k, int c) {
    int n = field.size();
    Q.clear();
    memset(visit,false,sizeof(visit));
    visit[0][0][0] = true;
    Q.push_back(getnode(0,0));
    while (!Q.empty())
    {
        node now = Q.front();
        Q.pop_front();
        if (now.pos == n-1) return now.tim;
        int newpos;
        for (int i = 0;i < 3;i++)
        {
            newpos = now.pos+step[i];
            if (newpos >= 0 && newpos < n)
            {
                if ((now.tim+1)%c != 0 && field[newpos] == 'C') continue;
                if ((now.tim+1)%k == 0 && field[newpos] == 'K') continue;
                if (visit[newpos][(now.tim+1)%c][(now.tim+1)%k] == false)
                {
                    visit[newpos][(now.tim+1)%c][(now.tim+1)%k] = true;
                    Q.push_back(getnode(newpos,now.tim+1));
                }
            }
        }
    }
    return -1;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	string p0 = ".C.C.C.C.C.C.C.C.C.C.C.C.C.C.C.C.C.C.C.C.C.C.C.C..";
	int p1 = 50;
	int p2 = 50;
	KindAndCruel * obj = new KindAndCruel();
	clock_t start = clock();
	int my_answer = obj->crossTheField(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string p0 = ".KKKKKKKKKK...KCKCK.";
	int p1 = 11;
	int p2 = 7;
	KindAndCruel * obj = new KindAndCruel();
	clock_t start = clock();
	int my_answer = obj->crossTheField(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string p0 = ".CKC.CKC.CKC.CKC.CKC.CKC.CKC.CKC.CKC.CKC.CKC.CKC.";
	int p1 = 50;
	int p2 = 49;
	KindAndCruel * obj = new KindAndCruel();
	clock_t start = clock();
	int my_answer = obj->crossTheField(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string p0 = ".CKKKKCKKKKC.KKKKCKKKKC.CKKKKCKKKKCKKKKCKKKKCKKKK.";
	int p1 = 5;
	int p2 = 5;
	KindAndCruel * obj = new KindAndCruel();
	clock_t start = clock();
	int my_answer = obj->crossTheField(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 60;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
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
