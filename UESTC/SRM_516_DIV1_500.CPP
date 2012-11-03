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

class RowsOrdering {
public:
	int order(vector <string>);
};

int tot[50][50];

int getid(char ch)
{
    if (ch >= 'a' && ch <= 'z') return ch-'a';
    return ch-'A'+26;
}

pair<int,int> tmp[50];
pair<vector<int>,int> roworder[50];
vector<int> tmp2;
int a[50][50],b[50][50];

const long long mod = 1000000007LL;

int RowsOrdering::order(vector <string> rows) {
    int m = rows[0].size();
    int n = rows.size();
    for (int i = 0;i < m;i++)
        for (int j = 0;j < 50;j++)
            tot[i][j] = 0;
    for (int i = 0;i < m;i++)
        for (int j = 0;j < n;j++)
            tot[i][getid(rows[j][i])]++;
    for (int i = 0;i < m;i++)
    {
        for (int j = 0;j < 50;j++)
            tmp[j] = make_pair(-tot[i][j],j);
        sort(tmp,tmp+50);
        for (int j = 0;j < 50;j++)
            for (int k = 0;k < n;k++)
                if (getid(rows[k][i]) == tmp[j].second)
                    a[k][i] = j;
        tmp2.resize(50);
        for (int j = 0;j < 50;j++)
            tmp2[j] = tmp[j].first;
        roworder[i] = make_pair(tmp2,i);
    }
    sort(roworder,roworder+m);
    for (int i = 0;i < m;i++)
        for (int j = 0;j < n;j++)
            b[j][roworder[i].second] = a[j][i];
            //b[j][i] = a[j][roworder[i].second];
    /*for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
            cout << b[i][j] << ' ';
        cout << endl;
    }*/
    long long res = 0;
    long long index;
    for (int i = 0;i < n;i++)
    {
        index = 0;
        for (int j = 0;j < m;j++)
            index = (index*50+(long long)b[i][j])%mod;
        index = (index+1)%mod;
        res = (res+index)%mod;
    }
    return res;
}

//Powered by [KawigiEdit] 2.0!
double test0() {
	string t0[] = {"dolphinigle", "ivanmetelsk", "lympandaaaa"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RowsOrdering * obj = new RowsOrdering();
	clock_t start = clock();
	int my_answer = obj->order(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 54;
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
	string t0[] = {"abcd", "ABCD"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RowsOrdering * obj = new RowsOrdering();
	clock_t start = clock();
	int my_answer = obj->order(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 127553;
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
	string t0[] = {"Example", "Problem"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RowsOrdering * obj = new RowsOrdering();
	clock_t start = clock();
	int my_answer = obj->order(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 943877448;
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
	string t0[] = {"a", "b", "c", "d", "e", "f", "g"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RowsOrdering * obj = new RowsOrdering();
	clock_t start = clock();
	int my_answer = obj->order(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 28;
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
	string t0[] = {"a", "a"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RowsOrdering * obj = new RowsOrdering();
	clock_t start = clock();
	int my_answer = obj->order(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

