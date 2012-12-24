#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
using namespace std;
#define MAXN 10000

const double eps = 1e-8;
#define M_PI acos(-1.0)
inline double sqr(double x) {
	return x * x;
}

struct P {
	double x, y, z;
	P(): x(0.0), y(0.0), z(0.0) {}
	P(double x, double y, double z): x(x), y(y), z(z) {}
	P(double lat, double lon) {
		x = cos(lon / 180.0 * M_PI) * cos(lat / 180.0 * M_PI);
		y = sin(lon / 180.0 * M_PI) * cos(lat / 180.0 * M_PI);
		z = sin(lat / 180.0 * M_PI);
	}
	friend P operator +(const P& p1, const P& p2) {
		return P(p1.x + p2.x, p1.y + p2.y, p1.z + p2.z);
	}
	friend P operator -(const P& p1, const P& p2) {
		return P(p1.x - p2.x, p1.y - p2.y, p1.z - p2.z);
	}
	friend P operator *(const P& p, double a) {
		return P(p.x * a, p.y * a, p.z * a);
	}
	friend P operator /(const P& p, double a) {
		return P(p.x / a, p.y / a, p.z / a);
	}
	friend double operator ^(const P& a, const P& b) { // dot product
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}
	double norm() {
		return sqrt(*this ^ *this);
	}
} p[MAXN];

inline int sgn(double x) {
	return x < -eps ? -1 : x > eps;
}

int main() {
	int n, m; double r;
	while (scanf("%d%d%lf", &n, &m, &r) != EOF) {
		assert(0 < n && n <= MAXN && 0 < m && m <= 1000 && 0 < r && r < 1e11);
		for (int i = 0; i < n; ++i) {
			double x, y;
			scanf("%lf%lf", &x, &y);
			assert(-90 <= x && x <= 90 && -180 <= y && y <= 180);
			p[i] = P(x, y);
		}
		for (int i = 0; i < m; ++i) {
			int a, b;
			scanf("%d%d", &a, &b);
			assert(0 <= a && a < n && 0 <= b && b < n && a != b);
			P v = p[a] - p[b];
			double x, y;
			scanf("%lf%lf", &x, &y);
			assert(-90 <= x && x <= 90 && -180 <= y && y <= 180);
			P u(x, y);
			double cosA = fabs((u ^ v) / v.norm());
			double sinA = 1.0 - sqr(cosA);
			if (sinA < 0.0) sinA = 0.0;
			sinA = sqrt(sinA);
			double k, v0;
			scanf("%lf%lf", &k, &v0);
			assert(0 <= k && k <= 5 && 0 <= v0 && v0 <= 5);
			if (sgn(sinA) == 0) {
				puts("0.000");
				continue;
			}
			if (sgn(cosA) == 0 || sgn(k) == 0 || sgn(v0) == 0)
				puts("God Bless Him!");
			else
				printf("%.3f\n", log((sinA + 1.0) / cosA) / k / v0);
		}
		puts("");
	}
	return 0;
}
