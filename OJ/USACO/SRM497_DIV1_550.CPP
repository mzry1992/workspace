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
#include <deque>
#include <sstream>
#include <cstring>
using namespace std;

class CssRules {
public:
	int getMinimalCssRuleCount(vector <string>);
};

struct info
{
    char tag;
    string id;
    string color;
};

int totinfo;

info solve(string code)
{
    stringstream scin;
    scin.clear();
    scin << code;
    string stag,sid,scolor;
    scin >> stag >> sid >> scolor;
    info res;
    res.tag = stag[0];
    if (stag[0] == '/') return res;
    res.id = sid.substr(4,sid.size()-5);
    res.color = scolor.substr(13,scolor.size()-14);
    cout << res.tag << ' ' << res.color << endl;
    return res;
}

int num[3][7];

int gettag(char tag)
{
    if (tag == 'b') return 0;
    if (tag == 'u') return 1;
    return 2;
}

int getcolor(string color)
{
    if (color == "black")   return 0;
    if (color == "blue")    return 1;
    if (color == "gray")   return 2;
    if (color == "green")    return 3;
    if (color == "red")   return 4;
    if (color == "white")    return 5;
    return 6;
}

void getS(string code)
{
    string temp = "";
    info itemp;
    memset(num,0,sizeof(num));
    totinfo = 0;
    for (int cur = 0;cur < code.size();cur++)
    {
        if (code[cur] == '<')
            temp = "";
        else if (code[cur] == '>')
        {
            itemp = solve(temp);
            if (itemp.tag != '/')
            {
                num[gettag(itemp.tag)][getcolor(itemp.color)]++;
                totinfo++;
            }
        }
        else
            temp += code[cur];
    }
}

int CssRules::getMinimalCssRuleCount(vector <string> xhtml) {
    string code = "";
    for (int i = 0;i < xhtml.size();i++)
        code += xhtml[i];
    getS(code);
    int res = 0;
    for (int i = 0;i < 3;i++)
    for (int j = 0;j < 7;j++)
    if (num[i][j] > 0)  res++;
    if (totinfo != res) res++;
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	string t0[] = {"<b id='x' style='color:red'></b>"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	CssRules * obj = new CssRules();
	clock_t start = clock();
	int my_answer = obj->getMinimalCssRuleCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
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
	string t0[] = {"<b id='x' style='color:red'>","<b id='y' style='color:red'>",
 "<b id='z' style='color:red'>","</b></b></b>"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	CssRules * obj = new CssRules();
	clock_t start = clock();
	int my_answer = obj->getMinimalCssRuleCount(p0);
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
double test2() {
	string t0[] = {"<b id='x' style='color:red'>",
"<b id='y' style='color:red'>",
"<b id='w' style='color:red'>",
"</b>",
"</b>",
"<u id='z' style='color:red'>",
"</u>",
"</b>"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	CssRules * obj = new CssRules();
	clock_t start = clock();
	int my_answer = obj->getMinimalCssRuleCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
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
	string t0[] = {"<b id='x' style='color:red'>",
"<i id='y' style='color:black'>",
"<u id='w' style='color:white'>",
"</u>",
"</i>",
"<u id='z' style='color:yellow'>",
"</u>",
"</b>"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	CssRules * obj = new CssRules();
	clock_t start = clock();
	int my_answer = obj->getMinimalCssRuleCount(p0);
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
double test4() {
	string t0[] = {"<b id='x' style='col", "or:red'></b>", "<b id=", "'xx' style='color", ":red'></b>"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	CssRules * obj = new CssRules();
	clock_t start = clock();
	int my_answer = obj->getMinimalCssRuleCount(p0);
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
