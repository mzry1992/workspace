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
#include <queue>
using namespace std;

class PalindromizationDiv1 {
public:
	int getMinimumCost(string, vector <string>);
};

set<string> hash;
struct node
{
    string now;
    int cost;
    node(){}
    node(string _now,int _cost)
        {
            now = _now;
            cost = _cost;
        }
};

struct cmp
{
    bool operator ()(node a,node b)
    {
        return a.cost > b.cost;
    }
};

priority_queue <node,vector<node>,cmp> Q;

bool palindrome(string now)
{
    int l = now.size();
    for (int i = 0;i < l/2;i++)
        if (now[i] != now[l-i-1])   return false;
    return true;
}

struct operations
{
    int typ;
    char c1[10],c2[10];
    int cost;
}o[51];
char tmp[20];
string tmp1,tmp2;

int PalindromizationDiv1::getMinimumCost(string s, vector <string> op) {
    int n = op.size();
    for (int i = 0;i < n;i++)
    {
        if (op[i][0] == 'a')
        {
            sscanf(op[i].c_str(),"%s%s%d",tmp,o[i].c1,&o[i].cost);
            o[i].typ = 0;
        }
        else if (op[i][0] == 'e')
        {
            sscanf(op[i].c_str(),"%s%s%d",tmp,o[i].c1,&o[i].cost);
            o[i].typ = 1;
        }
        else if (op[i][0] == 'c')
        {
            sscanf(op[i].c_str(),"%s%s%s%d",tmp,o[i].c1,o[i].c2,&o[i].cost);
            o[i].typ = 2;
        }
    }
    node now;
    hash.clear();
    while (!Q.empty())  Q.pop();
    Q.push(node(s,0));
    hash.insert(s);
    int tim = 0;
    while (!Q.empty())
    {
        now = Q.top();
        Q.pop();
        if (palindrome(now.now) == true)    return now.cost;
        tmp1 = now.now;
        if (tmp1.size() > s.size()*2)   continue;
        for (int i = 0;i < n;i++)
        {
            if (o[i].typ == 0)
            {
                for (int j = 0;j <= tmp1.size();j++)
                {
                    tmp2 = tmp1.substr(0,j)+o[i].c1[0]+tmp1.substr(j,tmp1.size()-j);
                    if (hash.find(tmp2) == hash.end())
                    {
                        hash.insert(tmp2);
                        Q.push(node(tmp2,now.cost+o[i].cost));
                    }
                }
            }
            else if (o[i].typ == 1)
            {
                for (int j = 0;j < tmp1.size();j++)
                    if (tmp1[j] == o[i].c1[0])
                    {
                        tmp2 = tmp1.substr(0,j)+tmp1.substr(j+1,tmp1.size()-j-1);
                        if (hash.find(tmp2) == hash.end())
                        {
                            hash.insert(tmp2);
                            Q.push(node(tmp2,now.cost+o[i].cost));
                        }
                    }
            }
            else if (o[i].typ == 2)
            {
                for (int j = 0;j < tmp1.size();j++)
                    if (tmp1[j] == o[i].c1[0])
                    {
                        tmp2 = tmp1;
                        tmp2[j] = o[i].c2[0];
                        if (hash.find(tmp2) == hash.end())
                        {
                            hash.insert(tmp2);
                            Q.push(node(tmp2,now.cost+o[i].cost));
                        }
                    }
            }
        }
    }
    return -1;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	string p0 = "racecar";
	vector <string> p1;
	PalindromizationDiv1 * obj = new PalindromizationDiv1();
	clock_t start = clock();
	int my_answer = obj->getMinimumCost(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
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
	string p0 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaz";
	string t1[] = {"change a b 100000","change b c 100000","change c d 100000","change d e 100000","change e f 100000","change f g 100000","change g h 100000","change h i 100000","change i j 100000","change j k 100000","change k l 100000","change l m 100000","change m n 100000","change n o 100000","change o p 100000","change p q 100000","change q r 100000","change r s 100000","change s t 100000","change t u 100000","change u v 100000","change v w 100000","change w x 100000","change x y 100000","erase y 100000"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	PalindromizationDiv1 * obj = new PalindromizationDiv1();
	clock_t start = clock();
	int my_answer = obj->getMinimumCost(p0, p1);
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
double test2() {
	string p0 = "topcoder";
	string t1[] = {"erase t 10", "erase o 1", "erase p 1", "erase c 1", "erase d 1", "erase e 1", "erase r 1"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	PalindromizationDiv1 * obj = new PalindromizationDiv1();
	clock_t start = clock();
	int my_answer = obj->getMinimumCost(p0, p1);
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
double test3() {
	string p0 = "caaaaaab";
	string t1[] = {"change b a 100000", "change c a 100000", "change c d 50000", "change b e 50000", "erase d 50000", "erase e 49999"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	PalindromizationDiv1 * obj = new PalindromizationDiv1();
	clock_t start = clock();
	int my_answer = obj->getMinimumCost(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 199999;
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
	string p0 = "moon";
	string t1[] = {"erase o 5", "add u 7", "change d p 3", "change m s 12", "change n d 6", "change s l 1"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	PalindromizationDiv1 * obj = new PalindromizationDiv1();
	clock_t start = clock();
	int my_answer = obj->getMinimumCost(p0, p1);
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
