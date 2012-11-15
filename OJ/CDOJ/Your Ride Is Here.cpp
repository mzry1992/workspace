/*
	ID: muziriy3
	PROG: ride
	LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    freopen("ride.in","r",stdin);
    freopen("ride.out","w",stdout);
    string a,b;
    cin >> a;
    cin >> b;
    int t1,t2;
    t1 = t2 = 1;
    for (int i = 0;i < a.size();i++)
        t1 = (t1*(a[i]-'A'+1))%47;
    for (int i = 0;i < b.size();i++)
        t2 = (t2*(b[i]-'A'+1))%47;
    if (t1 == t2)
        cout << "GO" << endl;
    else
        cout << "STAY" << endl;
}
