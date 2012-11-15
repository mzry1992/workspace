#include <cassert>
#include <cmath>
#include <queue>
#include <map>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const double EPS = 1e-7;
const double PI = acos(-1.0);

struct Point
{
  double x;
  double y;

  Point() {
  }

  Point(double x, double y)
    : x(x), y(y) {
  }

  bool operator <(const Point& a) const {
    return (fabs(x - a.x) < EPS) ? (y + EPS < a.y) : (x < a.x);
  }

  bool operator ==(const Point& a) const {
    return fabs(x - a.x) < EPS && fabs(y - a.y) < EPS;
  }

  void read() {
    scanf("%lf%lf", &x, &y);
  }
};

struct Line
{
  Point a;
  Point b;
};

struct Node
{
  string color;
  vector<int> conn;
  double area;

  Node(string s, double ar = 0)
    : color(s), area(ar) {
  }

  void add(int x) {
    conn.push_back(x);
  }
};

typedef vector<Point> Polygon;
typedef pair<int, double> PIF;

int w, h, n, ps;
vector<Line> L;
vector<Point> P;
vector<int> setP;
vector<vector<PIF>> grP;
vector<vector<int>> checkP;
vector<Polygon> poly;
vector<Node> graph;
vector<Point> arb;
int c;

inline double det(double x11, double x12, double x21, double x22) {
  return x11 * x22 - x12 * x21;
}

int getCrossP(Point a, Point b, Point p, Point q, Point& cp) {
  double mdet = det(b.x - a.x, p.x - q.x, b.y - a.y, p.y - q.y);
  if (fabs(mdet) < EPS) return 0; // no intersection here
  double t1 = det(p.x - a.x, p.x - q.x, p.y - a.y, p.y - q.y) / mdet;
  double t2 = det(b.x - a.x, p.x - a.x, b.y - a.y, p.y - a.y) / mdet;
  if (t1 < -EPS || t1 > 1 + EPS || t2 < -EPS || t2 > 1 + EPS) return -1; // no intersection here
  // Now we have new intersection point
  cp.x = p.x + t2 * (q.x - p.x);
  cp.y = p.y + t2 * (q.y - p.y);
  return 1;
}

bool isOn(Point a, Point b, Point c) {
  if (b.x > a.x && b.x > c.x || b.x < a.x && b.x < c.x) return false;
  if (b.y > a.y && b.y > c.y || b.y < a.y && b.y < c.y) return false;

  double p = a.x * b.y + b.x * c.y + c.x * a.y;
  p -= (a.x * c.y + b.x * a.y + c.x * b.y);
  if (abs(p) < EPS) return true;
  return false;
}

double angle(Point a, Point b) {
  double x = b.x - a.x, y = b.y - a.y;
  double ret = atan2(y, x) * 180 / PI;
  if (ret < EPS) ret += 360;
  return ret;
}

bool angle_comp(PIF a, PIF b) {
  return a.second < b.second;
}

void make_point_set() {
  for (int i = 0; i < n; ++i) {
    P.push_back( L[i].a );
    P.push_back( L[i].b );
  }

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      Point cp;
      if (getCrossP(L[i].a, L[i].b, L[j].a, L[j].b, cp) == 1) {
        P.push_back(cp);
      }
    }
  }

  sort(P.begin(), P.end());
  P.erase(unique(P.begin(), P.end()), P.end());
  ps = P.size();
}

void unique_grP(vector<PIF>& a) {
  sort(a.begin(), a.end(), [](const PIF& a, const PIF& b) {
    return a.first < b.first;
  });
  a.erase(unique(a.begin(), a.end(), [](const PIF& a, const PIF& b) {
    return a.first == b.first;
  }), a.end());
}

void calc_angle_and_sort_point() {
  grP.resize(ps);
  for (int i = 0; i < n; ++i) {
    vector<int> vp;
    if (L[i].b < L[i].a) swap(L[i].a, L[i].b);
    for (int j = 0; j < ps; ++j)
      if (isOn(L[i].a, P[j], L[i].b))
        vp.push_back( j );
    for (int j = 1; j < vp.size(); ++j) {
      grP[vp[j - 1]].push_back( make_pair( vp[j], angle( P[vp[j-1]], P[vp[j]] ) ) );
      grP[vp[j]].push_back( make_pair( vp[j - 1], angle( P[vp[j]], P[vp[j-1]] ) ) );
    }
  }

  for (int i = 0; i < ps; ++i) {
    unique_grP(grP[i]);
    sort(grP[i].begin(), grP[i].end(), angle_comp);
  }
}

void calc_segment_set() {
  graph.push_back(Node("white", w * h));
  setP.assign(ps, -1);
  arb.push_back(Point(0.0, 0.0));
  for (int i = 0; i < ps; ++i) {
    if (setP[i] == -1) {
      queue<int> Q;
      Q.push( i );

      graph.push_back(Node("black", 0.0));
      setP[i] = ++c;
      arb.push_back(P[i]);

      while (!Q.empty()) {
        int now = Q.front(); Q.pop();
        for (int j = 0; j < grP[now].size(); ++j)
          if (setP[grP[now][j].first] == -1) {
            Q.push( grP[now][j].first );
            setP[grP[now][j].first] = c;
          }
      }
    }
  }

  poly.resize(c + 1);
}

double getArea(const vector<Point>& p) {
  double total = 0.0;
  int n = p.size();
  for (int i = 0; i < n; i++) {
    int j = (i + 1) % n;
    total += (p[i].x * p[j].y) - (p[j].x * p[i].y);
  }
  return -(total / 2.0);
}

inline double isLeft(Point a, Point b, Point c) {
  return ((b.x-a.x) * (c.y-a.y) - (c.x-a.x) * (b.y-a.y));
}

int wn_pnpoly( Point p, vector<Point> v ) {
  int n = v.size();
  v.push_back( v[0] );

  for (int i = 0; i < n; i++) {
    if (isOn(v[i], p, v[i + 1])) {
      return 0;
    }
  }

  int wn = 0;
  for (int i = 0; i < n; i++) {
    if (v[i].y <= p.y) {
      if (v[i + 1].y > p.y)
        if (isLeft(v[i], v[i + 1], p) > 0)
          ++wn;
    }
    else {
      if (v[i+1].y <= p.y)
        if (isLeft(v[i], v[i + 1], p) < 0)
          --wn;
    }
  }
  return wn;
}

void traverse() {
  checkP.resize(ps);
  for (int i = 0; i < ps; ++i) {
    checkP[i] = vector<int>(grP[i].size(), 0);
  }

  for (int i = 0; i < ps; ++i) {
    for (int j = 0; j < grP[i].size(); ++j) {
      if (checkP[i][j] == 0) {
        int curP = i, curIdx = j;
        vector<Point> vp;

        while (checkP[curP][curIdx] == 0) {
          vp.push_back(P[curP]);
          checkP[curP][curIdx] = 1;
          int nextP = grP[curP][curIdx].first;
          int nextIdx = -1;
          for (int k = 0; k < grP[nextP].size(); ++k)
            if (grP[nextP][k].first == curP) {
              nextIdx = (k + 1) % grP[nextP].size();
              break;
            }

          assert( nextIdx != -1 );
          curP = nextP, curIdx = nextIdx;
        }

        double area = getArea(vp);
        if (area > 0) {
          int par = setP[i];

          poly.push_back(vp);
          graph.push_back( Node( "white", area ) );
          graph[par].add( graph.size() - 1 );
          graph[graph.size() - 1].add( par );
          graph[par].area -= area;

#ifdef LOCAL
          for (auto& t: vp) {
            printf("[%.2f,%.2f]->", t.x, t.y);
          }
          printf(" area = %.2f\n", area);
          printf("tot poly: %d\n", poly.size());
#endif
        }
      }
    }
  }
  for (int i = 1; i <= c; ++i) {
    int fa = 0;
    for (int j = (int)poly.size() - 1; j > c; --j) {
      if (wn_pnpoly(arb[i], poly[j])) {
        fa = j;
        break;
      }
    }
    graph[fa].conn.push_back(i);
    graph[i].conn.push_back(fa);
    graph[fa].area += graph[i].area;
#ifdef LOCAL
    printf("fa[%d]: %d\n", i, fa);
#endif
  }

#ifdef LOCAL
  for (auto& t: graph) {
    printf("-> area: %f\n", t.area);
  }
#endif
}

void init() {
  make_point_set();
  calc_angle_and_sort_point();
  calc_segment_set();
#ifdef LOCAL
  for (int i = 0; i < ps; ++i) {
    printf("<%.2f,%.2f> : ", P[i].x, P[i].y);
    for (int j = 0; j < grP[i].size(); ++j)
      printf("(%d,%.1f) ", grP[i][j].first, grP[i][j].second);
    printf("\n");
  }
#endif
  traverse();
}

void bfs(int k, string next_color) {
  string prev_color = graph[k].color;

  int gs = graph.size();
  vector<int> cc(gs, 0);

  queue<int> Q;
  cc[k] = 1;
  Q.push( k );
  while ( !Q.empty() ) {
    int now = Q.front(); Q.pop();
    for (int i = 0; i < graph[now].conn.size(); ++i) {
      if (cc[graph[now].conn[i]]) continue;
      if (graph[graph[now].conn[i]].color == prev_color) {
        Q.push( graph[now].conn[i] );
        cc[graph[now].conn[i]] = 1;
      }
    }
  }

  for (int i = 0; i < gs; ++i)
    if (cc[i]) graph[i].color = next_color;
}

void fill_board(int x, int y, const string& color) {
  Point p;
  p.x = x, p.y = y;

  for (int i = 0; i < ps; ++i) {
    for (int j = 0; j < grP[i].size(); ++j) {
      if (isOn(P[i], p, P[grP[i][j].first])) {
        bfs(setP[i], color);
        return;
      }
    }
  }

  for (int i = (int)poly.size() - 1; i > c; --i)
    if (poly[i].size() > 0)
      if (wn_pnpoly(p, poly[i]) == -1) {
#ifdef LOCAL
        printf("in poly %d\n", i);
#endif
        bfs(i, color);
        return;
      }

  bfs(0, color);
}

int main() {
  scanf("%d%d%d", &w, &h, &n);
  L.resize(n);
  for (int i = 0; i < n; ++i) {
    L[i].a.read();
    L[i].b.read();
  }

  init();

  int f;
  scanf("%d", &f);
  for (int i = 0; i < f; ++i) {
    int x, y;
    char tmp[100];
    scanf("%d%d%s", &x, &y, tmp);
    fill_board(x, y, tmp);
  }

  map<string, double> answer;
  for (auto& x: graph) {
    answer[x.color] += max(x.area, 0.0);
  }
  for (auto& x: answer) {
    printf("%s %.10f\n", x.first.c_str(), x.second);
  }
  return 0;
}
