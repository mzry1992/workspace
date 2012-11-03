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

class OneRegister {
public:
	string getProgram(int, int);
};

struct node
{
    long long now;
    string op;
    node set(long long now,string op)
    {
        node temp;
        temp.now = now;
        temp.op = op;
        return temp;
    }
};
map<long long,string> visit;
map<long long,string>::iterator it;
deque<node> Q;
string BFS(int s,int t)
{
    visit.clear();
    Q.clear();
    node temp;
    Q.push_back(temp.set(s,""));
    visit[s] = "";
    while (!Q.empty())
    {
        node now = Q.front();
        //cout << now.now << ' ' << now.op << endl;
        Q.pop_front();
        if (now.now == t)
            return now.op;
        temp = temp.set(now.now*now.now,now.op+"*");
        it = visit.find(now.now*now.now);
        if (it != visit.end())
            if ((*it).second > temp.op)
            {
                visit[temp.now] = temp.op;
                Q.push_back(temp);
            }
        if (it == visit.end())
        {
            visit[temp.now] = temp.op;
            Q.push_back(temp);
        }
        temp = temp.set(now.now+now.now,now.op+"+");
        it = visit.find(now.now+now.now);
        if (it != visit.end())
            if ((*it).second > temp.op)
            {
                visit[temp.now] = temp.op;
                Q.push_back(temp);
            }
        if (it == visit.end())
        {
            visit[temp.now] = temp.op;
            Q.push_back(temp);
        }
        temp = temp.set(now.now-now.now,now.op+"-");
        it = visit.find(now.now-now.now);
        if (it != visit.end())
            if ((*it).second > temp.op)
            {
                visit[temp.now] = temp.op;
                Q.push_back(temp);
            }
        if (it == visit.end())
        {
            visit[temp.now] = temp.op;
            Q.push_back(temp);
        }
        temp = temp.set(1,now.op+"/");
        it = visit.find(1);
        if (it != visit.end())
            if ((*it).second > temp.op)
            {
                visit[temp.now] = temp.op;
                Q.push_back(temp);
            }
        if (it == visit.end())
        {
            visit[temp.now] = temp.op;
            Q.push_back(temp);
        }
    }
    return ":-(";
}
string OneRegister::getProgram(int s, int t) {
    string res;
    res = BFS(s,t);
    return res;
}

double test0() {
	int p0 = 7;
	int p1 = 392;
	OneRegister * obj = new OneRegister();
	clock_t start = clock();
	string my_answer = obj->getProgram(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "+*+";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 7;
	int p1 = 256;
	OneRegister * obj = new OneRegister();
	clock_t start = clock();
	string my_answer = obj->getProgram(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "/+***";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 4;
	int p1 = 256;
	OneRegister * obj = new OneRegister();
	clock_t start = clock();
	string my_answer = obj->getProgram(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "**";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 7;
	int p1 = 7;
	OneRegister * obj = new OneRegister();
	clock_t start = clock();
	string my_answer = obj->getProgram(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 7;
	int p1 = 9;
	OneRegister * obj = new OneRegister();
	clock_t start = clock();
	string my_answer = obj->getProgram(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = ":-(";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int p0 = 10;
	int p1 = 1;
	OneRegister * obj = new OneRegister();
	clock_t start = clock();
	string my_answer = obj->getProgram(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "/";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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

	time = test5();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
