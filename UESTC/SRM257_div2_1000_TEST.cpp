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

class TimeCard {
public:
	string leave(vector <string>);
};

string TimeCard::leave(vector <string> time) {
	int n,i,hour,mint,all;
	string res;
    bool come;
    int t1,t2;
    int th,tm;
    th = tm = 0;
	n = time.size();
	come = false;
	all = 0;
	for (i = 0;i < n;i++)
	{
        hour = (time[i][0]-'0')*10+(time[i][1]-'0');
        mint = (time[i][3]-'0')*10+(time[i][4]-'0');
        hour %= 12;
        if (time[i][6] != 'a')                      hour += 12;     
        if (come == false)
        {
                 th = hour;
                 tm = mint;
                 come = true;
        }
        else
        {
            come = false;
            t1 = hour*60+mint;
            t2 = th*60+tm;
            if (t2 <= t1)
               all += t1-t2;
            else
                all += 24*60+t1-t2;
        }
    }
    if (all > 40*60)
       return "ABOVE 40";
    all = 40*60-all;
    if (all > 20*60)
       return "BELOW 40";
    t1 = th*60+tm+all;
    t1 %= 24*60;
    hour = t1/60;
    mint = t1-hour*60;
    if (hour < 12)
    {
             if (hour == 0)  hour = 12;
             res = "";
             res += hour/10+'0';
             res += hour%10+'0';
             res += ':';
             res += mint/10+'0';
             res += mint%10+'0';
             res += ',';
             res += 'a';
             res += 'm';
             return res;
             return res;
    }
    hour -= 12;
    if (hour == 0)  hour = 12;
    res = "";
    res += hour/10+'0';
    res += hour%10+'0';
    res += ':';
    res += mint/10+'0';
    res += mint%10+'0';
    res += ',';
    res += 'p';
    res += 'm';
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	string t0[] = {"03:00,pm"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TimeCard * obj = new TimeCard();
	clock_t start = clock();
	string my_answer = obj->leave(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "BELOW 40";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"09:00,am","05:00,pm","09:00,am","05:00,pm",
    "09:00,am","05:00,pm","09:00,am","05:00,pm","09:00,am"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TimeCard * obj = new TimeCard();
	clock_t start = clock();
	string my_answer = obj->leave(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "05:00,pm";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"12:00,am","08:00,pm","12:00,am","08:00,pm","12:00,am"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TimeCard * obj = new TimeCard();
	clock_t start = clock();
	string my_answer = obj->leave(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "12:00,am";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"12:00,pm","08:00,pm","12:00,am","08:00,pm","12:00,am"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TimeCard * obj = new TimeCard();
	clock_t start = clock();
	string my_answer = obj->leave(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "12:00,pm";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"12:09,am", "12:07,pm", "01:03,pm", "11:02,pm", "01:03,pm", "11:02,pm", "11:59,pm"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TimeCard * obj = new TimeCard();
	clock_t start = clock();
	string my_answer = obj->leave(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "08:03,am";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
		
	system("pause");
}
