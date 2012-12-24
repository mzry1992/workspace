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

class StrIIRec {
public:
	string recovstr(int, int, string);
};

bool use[20];
int a[20];

string StrIIRec::recovstr(int n, int mi, string ms) {
    for (int i = 0;i < n;i++)
        use[i] = false;
    for (int i = 0;i < ms.size();i++)
        use[ms[i]-'a'] = true;
    for (int i = 0;i < n;i++)
        if (use[i] == false)
            ms.push_back('a'+i);
    for (int i = 0;i < n;i++)
    {
        a[i] = ms[i]-'a';
        use[i] = true;
    }
    int cnt;
    cnt = 0;
    for (int i = 0;i < n;i++)
        for (int j = i+1;j < n;j++)
            if (a[i] > a[j])
                cnt++;
    if (cnt >= mi)
        return ms;
    for (int i = n-1;i >= 0;i--)
    {
        int op = a[i];
        use[op] = false;
        for (int j = op+1;j < n;j++)
            if (use[j] == false)
            {
                a[i] = j;
                use[a[i]] = true;
                cnt = 0;
                for (int k = 0;k <= i;k++)
                    for (int q = 0;q < n;q++)
                        if (use[q] == false && a[k] > q)
                            cnt++;
                for (int k = 0;k <= i;k++)
                    for (int q = k+1;q <= i;q++)
                        if (a[k] > a[q])
                            cnt++;
                string res = "";
                for (int k = 0;k <= i;k++)
                    res.push_back('a'+a[k]);

                int last = mi-cnt;
                int leavnum = 0;
                for (int k = 0;k < n;k++)
                    if (use[k] == false)
                        leavnum++;
                if (leavnum*(leavnum-1)/2 >= last)
                {
                    for (int k = leavnum;k > 0;k--)
                        for (int q = 0;q < k;q++)
                            if (q+(k-1)*(k-2)/2 >= last)
                            {
                                int tmp = 0;
                                for (int p = 0;p < n;p++)
                                    if (use[p] == false)
                                    {
                                        if (tmp == q)
                                        {
                                            res.push_back('a'+p);
                                            last -= q;
                                            use[p] = true;
                                            break;
                                        }
                                        tmp++;
                                    }
                            }
                    return res;
                }

                use[a[i]] = false;
            }
    }
    return "";
}

//Powered by [KawigiEdit] 2.0!
double test0() {
	int p0 = 2;
	int p1 = 1;
	string p2 = "ab";
	StrIIRec * obj = new StrIIRec();
	clock_t start = clock();
	string my_answer = obj->recovstr(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "ba";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 9;
	int p1 = 1;
	string p2 = "efcdgab";
	StrIIRec * obj = new StrIIRec();
	clock_t start = clock();
	string my_answer = obj->recovstr(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "efcdgabhi";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 11;
	int p1 = 55;
	string p2 = "debgikjfc";
	StrIIRec * obj = new StrIIRec();
	clock_t start = clock();
	string my_answer = obj->recovstr(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "kjihgfedcba";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 15;
	int p1 = 0;
	string p2 = "e";
	StrIIRec * obj = new StrIIRec();
	clock_t start = clock();
	string my_answer = obj->recovstr(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "eabcdfghijklmno";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 9;
	int p1 = 20;
	string p2 = "fcdebiha";
	StrIIRec * obj = new StrIIRec();
	clock_t start = clock();
	string my_answer = obj->recovstr(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "fcdehigba";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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

	time = test4();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
