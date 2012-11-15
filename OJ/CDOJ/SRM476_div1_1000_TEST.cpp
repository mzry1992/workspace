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

class SubAnagrams {
public:
	int maximumParts(vector <string>);
};

bool can(string a,string b)
{
     int alph[26];
     int l1,l2,i,j;
     l1 = a.size();
     l2 = b.size();
     for (i = 0;i < 26;i++)
         alph[i] = 0;
     for (i = 0;i < l2;i++)
         alph[b[i]-'A']++;
     for (i = 0;i < l1;i++)
     {
         alph[a[i]-'A']--;
         if (alph[a[i]-'A'] < 0)
            return false;
     }
     return true;
}

int SubAnagrams::maximumParts(vector <string> suppliedWord) {
	string word;
	int i,j,k,l,dp[600][600];
	for (i = 0;i < suppliedWord.size();i++)
	    word = word+suppliedWord[i];
    l = word.size();
    for (i = 0;i < l;i++)
    for (j = i;j < l;j++)
    {
        dp[i][j] = 0;
        for (k = 0;k < i;k++)
        if (dp[i][j] < dp[k][i-1]+1)
        if (can(word.substr(k,i-k),word.substr(i,j-i+1)) == true)
        if (i-k <= j-i+1)     
        {       
           dp[i][j] = dp[k][i-1]+1;
                cout << i << ' ' << j << ' ' << k << ' ' << i-1 << dp[i][j] << endl;
        }
    }
    int res = 0;
    for (i = 0;i < l;i++)
    if (res < dp[i][l-1])
       res = dp[i][l-1];
    if (res == 0)      res = 1;
    return res;  
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	string t0[] = {"ABABAB"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SubAnagrams * obj = new SubAnagrams();
	clock_t start = clock();
	int my_answer = obj->maximumParts(p0);
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
double test1() {
	string t0[] = {"AAXAAAABX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SubAnagrams * obj = new SubAnagrams();
	clock_t start = clock();
	int my_answer = obj->maximumParts(p0);
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
double test2() {
	string t0[] = {"ABCDEFGHIJKL"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SubAnagrams * obj = new SubAnagrams();
	clock_t start = clock();
	int my_answer = obj->maximumParts(p0);
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
double test3() {
	string t0[] = {"ABBAB","B","BBX","Z"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SubAnagrams * obj = new SubAnagrams();
	clock_t start = clock();
	int my_answer = obj->maximumParts(p0);
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
	system("pause");
}
