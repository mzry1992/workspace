#include <iostream>
using namespace std;

class fuck
{
public:
    virtual double fa(double a)
    {
        cout << "fuck : ";
        return a+1.0;
    }
	double fb(double b)
	{
		cout << "fuckb : ";
		return b+2.0;
	}
};

class fuckfuck: fuck
{
public:
    double fa(double a)
    {
        cout << "fuckfuck : ";
        return a+1.1;
    }
	double fb(double b)
	{
		cout << "fuckfuckb : ";
		return b+2.1;
	}
};

int main()
{
    fuckfuck *aa = new fuckfuck;
    cout << aa->fa(1.0) << endl;
	cout << aa->fb(2.0) << endl;
    return 0;
}
