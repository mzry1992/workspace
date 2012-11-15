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

class NewItemShop {
public:
	double getMaximum(int, vector <string>);
};

struct Event
{
    int tim,val,cus,p;
}e[25];
int tote;

bool cmp(const Event& a,const Event& b)
{
    return a.tim < b.tim;
}

double Gao(int now,int sta,int tots,int swords,int totval)
{
    double res;
    if (now == tote || tots == swords)
        res = 1.0*totval;
    else
    {
        //他来了
        //不卖
        res = Gao(now+1,sta,tots,swords,totval);
    cout << "1: " << 0.01*e[now].p << endl;
    cout << "1: " << now << ' ' << sta << ' ' << tots << ' ' << swords << ' ' << totval << ' ' << res << endl;
        //卖
        if (((sta>>e[now].cus)&1) == 0)
            res = max(res,Gao(now+1,sta|(1<<e[now].cus),tots+1,swords,totval+e[now].val));

        res *= 0.01*e[now].p;
        //他没来
    //cout << "2: " << now << ' ' << sta << ' ' << tots << ' ' << swords << ' ' << totval << ' ' << res << endl;

        res += Gao(now+1,sta,tots,swords,totval)*0.01*(100-e[now].p);
    }

    //cout << "Final : " << now << ' ' << sta << ' ' << tots << ' ' << swords << ' ' << totval << ' ' << res << endl;

    return res;
}

double NewItemShop::getMaximum(int swords, vector <string> customers) {
    int n = customers.size();
    tote = 0;
    for (int i = 0;i < n;i++)
    {
        int len = customers[i].size();
        int pre = 0;
        for (int j = 0;j <= len;j++)
            if (j == len || customers[i][j] == ' ')
            {
                sscanf(customers[i].substr(pre,j-pre+1).c_str(),"%d,%d,%d",&e[tote].tim,&e[tote].val,&e[tote].p);
                e[tote++].cus = i;
                pre = j+1;
            }
    }
    sort(e,e+tote,cmp);
    double res = Gao(0,0,0,swords,0);
    /*cout << tote << endl;
    for (int i = 0;i < tote;i++)
        cout << e[i].tim << ' ' << e[i].val << ' ' << e[i].p << ' ' << e[i].cus << endl;*/
    getchar();
    return res;
}

//Powered by [KawigiEdit] 2.0!
double test0() {
	int p0 = 1;
	string t1[] = { "8,1,80 16,100,11", "12,10,100" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	NewItemShop * obj = new NewItemShop();
	clock_t start = clock();
	double my_answer = obj->getMaximum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 19.0;
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
	string t1[] = { "8,1,80 16,100,11", "12,10,100" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	NewItemShop * obj = new NewItemShop();
	clock_t start = clock();
	double my_answer = obj->getMaximum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 21.8;
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
	int p0 = 1;
	string t1[] = { "0,90,25 2,90,25 4,90,25 6,90,25", "7,100,80" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	NewItemShop * obj = new NewItemShop();
	clock_t start = clock();
	double my_answer = obj->getMaximum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 90.0;
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
	int p0 = 3;
	string t1[] = { "17,31,41 20,59,26 23,53,5", "19,89,79", "16,32,38 22,46,26", "18,43,38 21,32,7" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	NewItemShop * obj = new NewItemShop();
	clock_t start = clock();
	double my_answer = obj->getMaximum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 135.5121414;
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
	int p0 = 5;
	string t1[] = { "1,1,10", "2,2,9", "3,3,8", "4,4,7", "5,5,6", "6,6,5", "7,7,4", "8,8,3", "9,9,2", "10,10,1" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	NewItemShop * obj = new NewItemShop();
	clock_t start = clock();
	double my_answer = obj->getMaximum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 2.1999744634845344;
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
