#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<queue>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;

typedef double db;
const db PI = acos( - 1.0) ;
const db EPS = 1e-8;
#define mp make_pair
int sign(db x, db EPS = 1e-8){return x < - EPS ? - 1 : x > EPS;}

struct TPoint{
    db x, y;
    TPoint(){}
    TPoint(db x, db y):x(x),y(y){}
    db operator^(TPoint P){return x * P.y - y * P.x; }
    db operator*(TPoint P){return x * P.x + y * P.y;}
    TPoint operator-(const TPoint P){return TPoint(x - P.x, y - P.y);}
    bool operator<(const TPoint P)const{
        if(fabs(x- P.x) < EPS) return y  < P.y;
        return x  < P.x;
    }
    db len(){return sqrt(x * x + y * y);}
    int get(){return scanf("%lf%lf", &x, &y);}
    TPoint Rot(db k){return TPoint(-y*sin(k)+x*cos(k),y*cos(k)+x*sin(k));}
};
db cross( TPoint a, TPoint b, TPoint c){return (b-a)^(c-b);}
vector< pair<db, pair<db,TPoint> > > v;
vector< TPoint> h, P;
vector< db > JIAODU;

void tubao(vector< TPoint> P){
    if( P.size() <= 2) {
        h = P;
        return ;
    }
    int i, j, k = 0;
    v.clear();
    for(i = 1; i < P.size(); ++ i) if(P[i] < P[ k ])k = i;
    for(i = 0; i < P.size(); ++ i) if( i != k)
        v.push_back( mp(atan2(P[i].y-P[k].y,P[i].x-P[k].x), mp((P[i]-P[k]).len(),P[i])));
    sort(v.begin(), v.end());
    h.clear();
    h.push_back( P[ k ] );
    h.push_back( v[ 0 ].second.second) ;
    for(i = 1; i < v.size(); ++ i){
        TPoint c = v[ i ].second.second;
        while(h.size() >= 2 && sign(cross(h[h.size()-2],h.back(),c)) <= 0) h.pop_back();
        h.push_back( c ) ;
    }
    JIAODU.clear();
    for(i = 0; i < h.size(); ++ i) {
        TPoint a = h[ i ], b = h[(i+1)%h.size() ];
        JIAODU.push_back(atan2(b.y-a.y,b.x-a.x));
    }
}
vector< pair< db, pair<int,int> > > D;
inline db jiajiao( db a, db b) {
    if( a < b) return b - a;
    return 2.0 * PI - (a - b) ;
}
void kake(vector< TPoint> P ){
    if( P.size() <= 1) return ;
    db ra, rb;
    int i, j, k;
    db now = 0.0, jc;
    j = k = 0;
    D.clear();
    for(i = 1; i < P.size(); ++ i) {
        if( P[ i ].y > P[ j ].y) j = i;
        if( P[ i ].y < P[ k ].y) k = i;
    }

    ra = JIAODU[ j ] + PI;
    while( ra >= 2.0 * PI) ra -= 2.0 * PI ;
    rb = JIAODU[ k ];
    D.push_back ( mp(0.0, mp(j,k)) );
    for(i = 0; i < P.size(); ++i) {
        int nj, nk;
        nj = (j + 1) % P.size();
        nk = (k + 1) % P.size();
        jc = min( ra, rb);
        now += jc;
        if( now >= PI ) break ;
        ra -= jc;
        rb -= jc;
        if( fabs(ra) < EPS) ra = jiajiao( JIAODU[j], JIAODU[nj] ), j = nj;
        if( fabs(rb) < EPS) rb = jiajiao( JIAODU[k], JIAODU[nk] ), k = nk;
        D.push_back( mp( now, mp(j,k)));
    }
}
int n;
map< TPoint, bool> M ;

bool get(){
    if(1 != scanf("%d", &n)) return 0;
    int i;
    P.clear();
    M.clear();
    for(i = 0; i < n; ++ i) {
        TPoint now;
        now.get();
        M[ now ] = true ;
    }
    for( map<TPoint, bool>::iterator p= M.begin(); p != M.end(); ++ p) P.push_back( p-> first) ;
    return 1;
}

bool gao(int x, int y, int n, TPoint a, TPoint b) {
    int i, j, nj, nk;
    for(i = - 1; i <= 1; ++ i)
        for(j = -1; j <= 1; ++ j) {
            nj = ((x + i) % n + n) % n;
            nk = ((y + j) % n + n) % n;
            if( sign((a-h[nj])^(b-h[nj])) * sign((a-h[nk])^(b-h[nk])) <= 0 ) return true;
        }
        return false;
}
void work(){
    TPoint a, b;
    tubao( P ) ;
    kake( h );
    while(EOF != scanf("%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y)) {
        if( P.size() <= 1 ) {
            puts("GOOD");
            continue;
        }
        if(P.size() == 2) {
            if( sign((a-P[0])^(b-P[0])) * sign((a-P[1])^(b-P[1])) <= 0) puts("BAD");
            else puts("GOOD");
            continue;
        }
        db jiaodu = atan2( a.y - b.y, a.x - b.x) ;
        if( jiaodu < 0) jiaodu += 2.0 * PI;
        if( jiaodu >= PI) jiaodu -= PI;
        int id = lower_bound( D.begin(), D.end(), mp( jiaodu, mp(0,0)) ) - D.begin();
        if( id == D.size()) id --;
        int nj,nk;
        nj = D[id].second.first;
        nk = D[id].second.second;
        if( gao(nj, nk, h.size(), a, b)) puts("BAD");
        else puts("GOOD");
    }
}
int main(){
    get();
    work();
    return 0;
}
