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

const double PI = 3.14159265358979323846;

class ParticleCollision {
public:
	vector <double> collision(int, int, int, int, int, int);
};

vector <double> ParticleCollision::collision(int vx, int vy, int vz, int x0, int y0, int z0) {

}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int p0 = 0;
	int p1 = 0;
	int p2 = 0;
	int p3 = 0;
	int p4 = 0;
	int p5 = 0;
	ParticleCollision * obj = new ParticleCollision();
	clock_t start = clock();
	vector <double> my_answer = obj->collision(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	vector <double> p6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p6.size() > 0) {
		cout <<p6[0];
		for (int i=1; i<p6.size(); i++)
			cout <<", " <<p6[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p6) {
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
	int p1 = 4;
	int p2 = 1;
	int p3 = -1;
	int p4 = -1;
	int p5 = 0;
	ParticleCollision * obj = new ParticleCollision();
	clock_t start = clock();
	vector <double> my_answer = obj->collision(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double t6[] = {0.0, 1.0, 0.5 };
	vector <double> p6(t6, t6+sizeof(t6)/sizeof(double));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p6.size() > 0) {
		cout <<p6[0];
		for (int i=1; i<p6.size(); i++)
			cout <<", " <<p6[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p6) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 4;
	int p1 = 4;
	int p2 = 2;
	int p3 = 5;
	int p4 = 4;
	int p5 = 0;
	ParticleCollision * obj = new ParticleCollision();
	clock_t start = clock();
	vector <double> my_answer = obj->collision(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double t6[] = {0.0, 0.0, 0.0 };
	vector <double> p6(t6, t6+sizeof(t6)/sizeof(double));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p6.size() > 0) {
		cout <<p6[0];
		for (int i=1; i<p6.size(); i++)
			cout <<", " <<p6[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p6) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 0;
	int p1 = 0;
	int p2 = 1;
	int p3 = 1;
	int p4 = 0;
	int p5 = 0;
	ParticleCollision * obj = new ParticleCollision();
	clock_t start = clock();
	vector <double> my_answer = obj->collision(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double t6[] = {0.0, 0.0, 0.0 };
	vector <double> p6(t6, t6+sizeof(t6)/sizeof(double));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p6.size() > 0) {
		cout <<p6[0];
		for (int i=1; i<p6.size(); i++)
			cout <<", " <<p6[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p6) {
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
}
