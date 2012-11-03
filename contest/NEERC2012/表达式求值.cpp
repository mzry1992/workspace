#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int MAX = 4096;
const int Left = 0;
const int Right = 1;

struct Parser
{
	static map<string,int> pred;
	static map<string,int> ass;
	map<string,int> mp;
	double val[MAX];
	const char* pbuf;

	inline int getid(const string& s)
	{
		if (mp.find(s) == mp.end())
		{
			int id = mp.size();//Careful
			mp[s] = id;
		}
		return mp[s];
	}

	inline static double calc(const double& lhs,const string& op,const double& rhs)
	{
	}

	inline static int isop(int c)
	{
		return ispunct(c) && c != '(' && c != ')';
	}

	Parser()
	{
	}

	void reset(const char* s)
	{
		pbuf = s;
	}

	inline static void addOp(const string& s,int p,int a)
	{
		pred[s] = p;
		ass[s] = a;
	}

	double exp(int p)
	{
		double a = P();
		const char* ptr;

		while (isop(*pbuf))
		{
			string op = "";
			ptr = pbuf;
			op += *ptr++;
			if (pred.find(op) == pred.end())	throw 0;
			if (pred[op] >= p)
			{
				pbuf = ptr;
				int q = pred[op];
				if (ass[op] == Left)	q++;
				double b = exp(q);
				a = calc(a,op,b);
			}
			else
				break;
		}
		return a;
	}

	double P()
	{
		double ret = 0;

		if (*pbuf == '-')
		{
			pbuf++;
			double r = P();
			r = -r;
			return r;
		}
		else if (*pbuf == '(')
		{
			pbuf++;
			ret = exp(0);
			if (*pbuf++ != ')')	throw 0;
			return ret;
		}
		else if (isalnum(*pbuf))
		{
		}
		else throw(0);
	}
};


int main()
{

    return 0;
}
