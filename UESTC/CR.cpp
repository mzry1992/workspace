#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iostream>
using namespace std;
int flag = 0;
typedef long long typec;
typec MOD = 999983;
const int RANKLIM = 50;
const int EQLIM = 10;

typec gcd(typec a, typec b)
{
    return b ? gcd(b, a % b) : a;
}

typec extendGCD(typec a, typec b, typec& x, typec& y)
{
    if(!b) return x = 1, y = 0, a;
    typec res = extendGCD(b, a % b, x, y), tmp = x;
    x = y, y = tmp - (a / b) * y;
    return res;
}
///ax = b mod m, be sure that (b, m) = (a, m)
typec modEquation(typec a, typec b, typec m)
{
	typec x, y;
	y = extendGCD(a, m, x, y);
	while(x < 0) x += m;
	return (x * (b / y)) % m;
}

class Polynomial
{
public:
	Polynomial();
	void set(int ra, typec* coe);
	void simplify();
	int getRank() const { return rank; }
	typec getValue(typec x) const;
	bool isOne() const { return rank == 0 && coefficient[0]; }
	bool isZero() const { return rank == 0 && coefficient[0] == 0; }
	bool operator==(const Polynomial& a) const;
	bool operator!=(const Polynomial& a) const  { return !(*this == a); }
	bool rankEqual(const Polynomial& a) const { return rank == a.rank; }
	bool operator>(const Polynomial& a) const { return rank > a.rank; }
	bool operator<(const Polynomial& a) const { return rank < a.rank; }
	bool operator>=(const Polynomial& a) const { return rank >= a.rank; }
	bool operator<=(const Polynomial& a) const { return rank <= a.rank; }
	Polynomial& operator+=(const Polynomial&);
	Polynomial operator+(const Polynomial&) const;
	Polynomial& operator-=(const Polynomial&);
	Polynomial operator-(const Polynomial&) const;
	Polynomial operator*(const Polynomial&) const;
	Polynomial& operator*=(typec ti) { for(int i = 0; i <= rank; i++) coefficient[i] *= ti; return *this; }
	Polynomial operator*(typec ti) const { Polynomial res = *this; return res *= ti; }
	Polynomial& mulAtRank(typec ti, int ra);
	Polynomial nMulAtRank(typec ti, int ra) const;
	Polynomial& operator%=(const Polynomial&);
	Polynomial operator%(const Polynomial&) const;
	void print() const;
	void print2() const;

private:
	typec coefficient[RANKLIM + 1];
	int rank;
};

Polynomial::Polynomial():rank(0)
{
	for(int i = 0; i < RANKLIM + 1; i++)
		coefficient[i] = 0;
}
void Polynomial::set(int ra, typec* coe)
{
	for(int i = 0; i <= rank; i++)
		coefficient[i] = 0;
	rank = ra;
	for(int i = 0; i <= rank; i++)
		coefficient[ra - i] = (coe[i] % MOD + MOD) % MOD;
    while(rank > MOD - 2)
    {
        coefficient[rank % (MOD - 1)] += coefficient[rank];
        coefficient[rank % (MOD - 1)] %= MOD;
        coefficient[rank--] = 0;
    }
    while(coefficient[rank] == 0 && rank) rank--;
}
void Polynomial::simplify()
{
    typec g = coefficient[rank];
    if(g == 0) return;
    for(int i = 1; i <= rank; i++)
        g = gcd(g, coefficient[i]);
    for(int i = 0; i <= rank; i++)
        coefficient[i] /= g;
}

typec Polynomial::getValue(typec x) const
{
    typec res = 0;
    for(int i = rank; i >= 0; i++)
        res *= x, res += coefficient[i], res %= MOD;
    return res;
}

bool Polynomial::operator==(const Polynomial& a) const
{
    if(rank != a.rank) return false;
    for(int i = 0; i <= rank; i++)
        if(coefficient[i] != a.coefficient[i])
            return false;
    return true;
}
Polynomial& Polynomial::operator+=(const Polynomial& a)
{
	if(a.rank > rank) rank = a.rank;
	for(int i = 0; i <= rank; i++)
		coefficient[i] += a.coefficient[i], coefficient[i] %= MOD;
    while(coefficient[rank] == 0 && rank) rank--;
	return *this;
}
Polynomial Polynomial::operator+(const Polynomial& a) const
{
	Polynomial res = *this;
	return res += a;
}
Polynomial& Polynomial::operator-=(const Polynomial& a)
{
	if(a.rank > rank) rank = a.rank;
	for(int i = rank; i >= 0; i--)
    {
        coefficient[i] -= a.coefficient[i];
        while(coefficient[i] < 0)
            coefficient[i] += MOD;
    }
	while(coefficient[rank] == 0 && rank) rank--;
	return *this;
}
Polynomial Polynomial::operator-(const Polynomial& a) const
{
	Polynomial res = *this;
	return res -= a;
}
Polynomial Polynomial::operator*(const Polynomial& a) const
{
	Polynomial res;
	res.rank = rank + a.rank;
	if(res.rank > MOD - 2) res.rank = MOD - 2;
	for(int i = 0; i <= rank; i++)
		for(int j = 0; j <= a.rank; j++)
        {
            res.coefficient[(i + j) % (MOD - 1)] += coefficient[i] * a.coefficient[j];
            res.coefficient[(i + j) % (MOD - 1)] %= MOD;
        }
    while(res.coefficient[res.rank] == 0 && res.rank) res.rank--;
	return res;
}
Polynomial& Polynomial::mulAtRank(typec ti, int ra)
{
	for(int i = 0; i <= rank; i++)
		coefficient[rank + ra - i] = (coefficient[rank - i] * ti) % MOD;
	for(int i = 0; i < ra; i++)
		coefficient[i] = 0;
    rank += ra;
    if(ti == 0) rank = 0;
    while(rank >= MOD - 1)
    {
        coefficient[rank % (MOD - 1)] += coefficient[rank];
        coefficient[rank % (MOD - 1)] %= MOD;
        coefficient[rank--] = 0;
    }
	return *this;
}
Polynomial Polynomial::nMulAtRank(typec ti, int ra) const
{
	Polynomial res = *this;
	return res.mulAtRank(ti, ra);
}
Polynomial& Polynomial::operator%=(const Polynomial& divisor)
{
	typec ti;
	while(*this >= divisor && !(this->isZero()))
	{
	    print();
        ti = modEquation(divisor.coefficient[divisor.rank], coefficient[rank], MOD);
        cout << ti << endl;
        cout << divisor.coefficient[divisor.rank] << ' ' << coefficient[rank] << endl;
        *this -= divisor.nMulAtRank(ti, rank - divisor.rank);
	}
	return *this;
}

Polynomial Polynomial::operator%(const Polynomial& divisor) const
{
	Polynomial res = *this;
	return res %= divisor;
}
void Polynomial::print() const
{
	for(int i = rank; i >= 0; i--)
	{
		if(coefficient[i] == 0) continue;
		if(i != rank) printf(" + ");
		if(!i || coefficient[i] != 1)
            printf("%lld", coefficient[i]);
		if(i) printf("x");
		if(i > 1) printf("^%d", i);
	}
//    printf("%d", rank);
//    for(int i = rank; i >= 0; i--)
//        printf(" %lld", coefficient[i]);
	printf("\n");
}
void Polynomial::print2() const
{
    printf("%d", rank);
    for(int i = rank; i >= 0; i--)
        printf(" %lld", coefficient[i]);
    printf("\n");
}

Polynomial Pgcd(Polynomial a, Polynomial b)
{
    Polynomial swap, zero;
    while(b != zero)
    {
        cout << "Gao a Gao" << endl;
        a.print();
        b.print();
        a %= b;
        swap = b, b = a, a = swap;
    }
    return a;
}


Polynomial getRandomOneRa(int ra)
{
    typec co[2];
    Polynomial res, g;
    for(int i = 0; i < ra; i++)
    {
        co[0] = (rand() % MOD - 1) + 1;
        co[1] = rand() % MOD;
        while(co[0] != 1 && gcd(co[0], co[1]) != 1)
            co[1] = rand() % MOD;
        if(!i) res.set(1, co);
        else g.set(1, co), res = res * g;
    }
    return res;
}
Polynomial getRandomOne(int lim = RANKLIM - 6)
{
    int ra = rand() % (lim) + 5;
    typec co[2];
    Polynomial res, g;
    for(int i = 0; i < ra; i++)
    {
        co[0] = (rand() % MOD - 1) + 1;
        co[1] = rand() % MOD;
        while(co[0] != 1 && gcd(co[0], co[1]) != 1)
            co[1] = rand() % MOD;
        if(!i) res.set(1, co);
        else g.set(1, co), res = res * g;
    }
    return res;
}

///main to get input data
//int main()
//{
//    freopen("in.txt", "w", stdout);
//    srand((unsigned)time(NULL));
//    int n;
//    Polynomial g;
//    for(int i = 1; i <= 6; i++)
//    {
//        g = getRandomOneRa(i);
//        for(int c = 0; c < 100; c++)
//        {
//            n = (rand() % (EQLIM - 2)) + 2;
//            printf("%d\n", n);
//            for(int j = 0; j < n; j++)
//                (g * getRandomOne(RANKLIM - 6 - i)).print2();
//            printf("\n");
//        }
//    }
//    for(int c = 0; c < 400; c++)
//    {
//        n = (rand() % (EQLIM - 2)) + 2;
//        printf("%d\n", n);
//        for(int j = 0; j < n; j++)
//            getRandomOne().print2();
//        printf("\n");
//    }
//    return 0;
//}


///main to solve the problem
int main()
{
    //freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	int n, ra;
	typec co[100];
	Polynomial pol[100], g;
//	int cas = 1;
	while(scanf("%d", &n) != EOF)
	{
	    if(flag) break;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &ra);
			for(int j = 0;  j <= ra; j++)
				scanf("%lld", co + j);
			pol[i].set(ra, co);
		}
		g = pol[0]%pol[1];
		g.print();
		return 0;
		g = pol[0];
		for(int i = 1; i < n; i++)
        {
            g = Pgcd(pol[i], g);
            if(g.isOne()) break;
        }
//        printf("####%d\n", cas++);
        g.simplify();
        g.print();
        if(g.isOne()) printf("NO\n");
        else printf("YES\n");
	}
	return 0;
}

