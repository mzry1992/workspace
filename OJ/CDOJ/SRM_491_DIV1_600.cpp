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

class PrefixTree {
public:
	int getNumNodes(vector <string>);
};

int ans;
vector <string> word;
struct tire
{
    int next[26];
    int sum;
}buf[50000];
int totbuf;

void init()
{
    totbuf = 0;
    memset(buf,0,sizeof(buf));
}

void del(string w)
{
    int now;
    now = 0;
    for (int i = 0;i < w.size();i++)
    {
        int next = buf[now].next[w[i]-'a'];
        if (buf[next].sum == 1)
            buf[now].next[w[i]-'a'] = 0;
        buf[now].sum--;
        now = next;
    }
}

void rdel(string w)
{
    int now;
    now = 0;
    for (int i = w.size()-1;i >= 0;i--)
    {
        int next = buf[now].next[w[i]-'a'];
        if (buf[next].sum == 1)
            buf[now].next[w[i]-'a'] = 0;
        buf[now].sum--;
        now = next;
    }
}

int insert(string w)
{
    int res = 0;
    int now = 0;
    for (int i = 0;i < w.size();i++)
    if (buf[now].next[w[i]-'a'] == 0)
    {
        res++;
        totbuf++;
        buf[now].next[w[i]-'a'] = totbuf;
        now = totbuf;
        buf[now].sum++;
    }
    else
    {
        now = buf[now].next[w[i]-'a'];
        buf[now].sum++;
    }
    return res;
}

int rinsert(string w)
{
    int res = 0;
    int now = 0;
    for (int i = w.size()-1;i >= 0;i--)
    if (buf[now].next[w[i]-'a'] == 0)
    {
        res++;
        totbuf++;
        buf[now].next[w[i]-'a'] = totbuf;
        now = totbuf;
        buf[now].sum++;
    }
    else
    {
        now = buf[now].next[w[i]-'a'];
        buf[now].sum++;
    }
    return res;
}

void DFS(int now,int totnode)
{
    cout << now << ' ' << totnode << endl;
    if (totnode > ans)  return;
    if (now == word.size())
    {
        if (ans > totnode)
            ans = totnode;
        return;
    }
    DFS(now+1,totnode+insert(word[now]));
    del(word[now]);
    DFS(now+1,totnode+rinsert(word[now]));
    rdel(word[now]);
}

int PrefixTree::getNumNodes(vector <string> words) {
    word.resize(words.size());
    for (int i = 0;i < words.size();i++)
        word[i] = words[i];
    init();
    ans = 19921005;
    DFS(0,0);
    int res = ans;
    return res+1;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	string t0[] = {"topcoder"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PrefixTree * obj = new PrefixTree();
	clock_t start = clock();
	int my_answer = obj->getNumNodes(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 9;
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
	string t0[] = {"topcoder","topcoder"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PrefixTree * obj = new PrefixTree();
	clock_t start = clock();
	int my_answer = obj->getNumNodes(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 9;
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
	string t0[] = {"aab","ca"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PrefixTree * obj = new PrefixTree();
	clock_t start = clock();
	int my_answer = obj->getNumNodes(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 5;
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
	string t0[] = {"aab","ca","ba"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PrefixTree * obj = new PrefixTree();
	clock_t start = clock();
	int my_answer = obj->getNumNodes(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 5;
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
	string t0[] = {"ab","cd","ef"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PrefixTree * obj = new PrefixTree();
	clock_t start = clock();
	int my_answer = obj->getNumNodes(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 7;
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
	string t0[] = {"a","aa","aaa"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PrefixTree * obj = new PrefixTree();
	clock_t start = clock();
	int my_answer = obj->getNumNodes(p0);
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
