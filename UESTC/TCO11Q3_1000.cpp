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

class ComplementMachine2D {
public:
	int largestSubmatrix(vector <string>);
};

int ComplementMachine2D::largestSubmatrix(vector <string> matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int res = 0;
    bool check;
    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
            for (int k = j;k < m;k++)
                for (int p = i;p < n;p++)
                {
                    check = true;
                    for (int q = j;q <= k;q++)
                    {
                        if (matrix[i][j] == matrix[p][j])
                            if (matrix[i][q] != matrix[p][q])
                            {
                                check = false;
                                break;
                            }
                        if (matrix[i][j] != matrix[p][j])
                            if (matrix[i][q] == matrix[p][q])
                            {
                                check = false;
                                break;
                            }
                    }
                    if (check == false) break;
                    //cout << i << ' ' << j << ' ' << k << ' ' << p << ' ' << (k-j+1)*(p-i+1) << endl;
                    if (res < (k-j+1)*(p-i+1))  res = (k-j+1)*(p-i+1);
                }
    //getchar();
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	string t0[] = {"0011",
 "0011",
 "1100",
 "0111"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ComplementMachine2D * obj = new ComplementMachine2D();
	clock_t start = clock();
	int my_answer = obj->largestSubmatrix(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 12;
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
	string t0[] = {"0011",
 "1011",
 "0101",
 "1010"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ComplementMachine2D * obj = new ComplementMachine2D();
	clock_t start = clock();
	int my_answer = obj->largestSubmatrix(p0);
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
	string t0[] = {"1011",
 "0011",
 "0101",
 "1010"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ComplementMachine2D * obj = new ComplementMachine2D();
	clock_t start = clock();
	int my_answer = obj->largestSubmatrix(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 8;
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
	string t0[] = {"0000110101010",
 "0111101010111",
 "1110110111011"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ComplementMachine2D * obj = new ComplementMachine2D();
	clock_t start = clock();
	int my_answer = obj->largestSubmatrix(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 13;
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
	string t0[] = {"11000000000110101101",
 "00111111011101101101",
 "00110011110111100010",
 "10011110111110000111",
 "00111010000000110111",
 "00001101011011010110",
 "11010010100100101100",
 "11101101011011000001",
 "11000010100100111001",
 "11011010100100101010",
 "10110010100100110110",
 "01100010100100111001",
 "10110010100100110011",
 "01110101011011001010",
 "01111101011011001011",
 "00001000010010101011",
 "11100101100100110001",
 "10100100111001010101",
 "11111000001010011110",
 "01110100001110011111"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ComplementMachine2D * obj = new ComplementMachine2D();
	clock_t start = clock();
	int my_answer = obj->largestSubmatrix(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 100;
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
