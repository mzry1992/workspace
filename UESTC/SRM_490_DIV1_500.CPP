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

class QuickT9 {
public:
	int minimumPressings(vector <string>, string);
};

struct status
{
    string now;
    int step;
};
deque<status> Q;
status getit(string now,int step)
{
    status res;
    res.now = now;
    res.step = step;
}
map<string,int> hash;
map<string,int>::iterator it;

const string t[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
const int a[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};

vector <string> T9;

status press(status now,int pos)
{
    status res;
    res.now = now.now+t[pos][0];
    res.step = now.step+1;
    int tnow[100];
    for (int i = 0;i < res.now.size();i++)
        tnow[i] = a[res.now[i]-'a'];
    bool flag;
    for (int i = 0;i < T9.size();i++)
    {
        flag = true;
        for (int j = 0;j < res.now.size();j++)
            if (tnow[j] != a[T9[i][j]-'a'])
            {
                flag = false;
                break;
            }
        if (flag == true)
            {
                res.now = T9[i].substr(0,res.now.size());
                return res;
            }
    }
    return res;
}

status del(status now)
{
    status res;
    if (now.now.size() == 0)    return now;
    res.now = now.now.substr(0,now.now.size()-1);
    res.step = now.step+1;
    int tnow[100];
    for (int i = 0;i < res.now.size();i++)
        tnow[i] = a[res.now[i]-'a'];
    bool flag;
    for (int i = 0;i < T9.size();i++)
    {
        flag = true;
        for (int j = 0;j < res.now.size();j++)
            if (tnow[j] != a[T9[i][j]-'a'])
            {
                flag = false;
                break;
            }
        if (flag == true)
            {
                res.now = T9[i].substr(0,res.now.size());
                return res;
            }
    }
    return res;
}

status next(status now)
{
    status res;
    if (now.now.size() == 0)    return now;
    res.now = now.now;
    res.step = now.step+1;
    int tnow[100];
    for (int i = 0;i < res.now.size();i++)
        tnow[i] = a[res.now[i]-'a'];
    bool flag;
    int two = 0;
    for (int i = 0;i < T9.size();i++)
    {
        flag = true;
        for (int j = 0;j < res.now.size();j++)
            if (tnow[j] != a[T9[i][j]-'a'])
            {
                flag = false;
                break;
            }
        if (flag == true)
            {
                res.now = T9[i].substr(0,res.now.size());
                two++;
                if (two == 2)
                return res;
            }
    }
    return res;

}

int BFS(vector <string> t9, string word)
{
    Q.clear();
    Q.push_back(getit("",0));
    status now,updata;
    hash.clear();
    hash[""] = 0;
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop_front();
        if (now.now == word)
            return now.step;
        for (int i = 2;i <= 9;i++)
        {
            updata = press(now,i);
            it = hash.find(updata.now);
            if (it == hash.end())
            {
                Q.push_back(updata);
                hash[updata.now] = 0;
            }
        }
        updata = del(now);
            it = hash.find(updata.now);
            if (it == hash.end())
            {
                Q.push_back(updata);
                hash[updata.now] = 0;
            }
        updata = next(now);
            it = hash.find(updata.now);
            if (it == hash.end())
            {
                Q.push_back(updata);
                hash[updata.now] = 0;
            }
    }
    return -1;
}

int QuickT9::minimumPressings(vector <string> t9, string word) {
    T9 = t9;
    return BFS(t9,word);
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	string t0[] = {"aae", "bab", "abad", "bdbd", "beta"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "babe";
	QuickT9 * obj = new QuickT9();
	clock_t start = clock();
	int my_answer = obj->minimumPressings(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 9;
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
	string t0[] = {"ann","ie"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "annie";
	QuickT9 * obj = new QuickT9();
	clock_t start = clock();
	int my_answer = obj->minimumPressings(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 7;
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
	string t0[] = {"ann","amm"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "annie";
	QuickT9 * obj = new QuickT9();
	clock_t start = clock();
	int my_answer = obj->minimumPressings(p0, p1);
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
	string t0[] = {"aaa aab","aac aba abb ccca"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "aba";
	QuickT9 * obj = new QuickT9();
	clock_t start = clock();
	int my_answer = obj->minimumPressings(p0, p1);
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
double test4() {
	string t0[] = {"acac aba aaab","aab aa baa","bba bacade abb","baba"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "abbaca";
	QuickT9 * obj = new QuickT9();
	clock_t start = clock();
	int my_answer = obj->minimumPressings(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 10;
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
double test5() {
	string t0[] = {"aaa aab aac","aba abb","ccca"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "ccc";
	QuickT9 * obj = new QuickT9();
	clock_t start = clock();
	int my_answer = obj->minimumPressings(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 5;
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

	time = test5();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

