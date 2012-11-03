#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
using namespace std;

const double eps = 1e-12;
const double pi = acos( -1 );
typedef long long LL;

inline double sq( double x ) {
       return x*x;
}
struct circle{
       double  x, y , r;
       circle(){}
       circle( double xx,double yy,double  rr ){
               x = xx ;y = yy ; r = rr;
       }
       void read(){
            scanf("%lf%lf%lf",&x,&y,&r);
       }
       circle operator-( const circle& c ) const {
              return circle( x - c.x , y - c.y , r - c.r );
       }
       int isIn( const circle &s )const {
              double tr = r - s.r;
              if( tr <= 0 ) return 0;
              if( sq( s.x - x ) + sq( s.y - y ) >= sq( tr ) ) return 0 ;
              else return 1; 
       }
       void out(){
               cout<<x <<" "<<y<<" "<<r<<endl;
       }
};
circle small,big , change;

void translate(){
     change = big;
     change.r = small.r;
     big = big - change;
     small = small - change;
}

// ax^2 + bx + c = 0 get x
double get( double dx,double dy ) {
       double a = sq( dx ) + sq(dy);
       double b = 2.0*( 1.0*small.x*dx + 1.0*small.y*dy );
       double c =  sq( small.x ) + sq( small.y ) - sq( big.r );
       double delta = b*b - 4.0*a*c;
       if( delta <= 0 ) {
           cout<<" error "<<endl;
           system("pause");
       }else{
             return ( sqrt(delta) - b )/(2.0*a);
       }
}      

struct pt{
       double x, y ;
       pt(){}
       pt(double xx,double yy){
                 x = xx; y = yy;
       }
       pt operator-( const pt & a ) const {
          return pt( x - a.x ,y - a.y );
       }
       pt operator+( const pt & a ) const {
          return pt( x + a.x ,y + a.y );
       }
       pt operator*( double r ) const {
          return pt( r*x ,r*y );
       }
       void out(){
            printf(" %0.2lf %0.2lf \n",x, y );
       }
};

inline int zero( double x ) {
       if( x < eps && x >-eps ) return 1;
       else return 0;
}

//»¡¶È½øÖÆ 
double angle( pt a, pt b, pt c){
       b = pt(b.x-a.x,b.y-a.y);
       c = pt(c.x-a.x,c.y-a.y);
       double ans = b.x*c.x + b.y*c.y;
       double tmp = sqrt((b.x*b.x+b.y*b.y)*(c.x*c.x+c.y*c.y));
       if( zero( tmp ) ) {
           cout<<" div zero "<<endl;
           system("pause");
       } 
       ans /= tmp;
       return acos(ans);
}

int cross(pt a,pt b,pt c){
    double t = (b.y-a.y)*(c.x-a.x)-(b.x-a.x)*(c.y-a.y) ;
    if( t > eps ) return 1;
    else return -1;
}

void solve( int dx ,int dy ,double ft ,double T ){
     double speed = sqrt( sq(dx) + sq(dy) );
     pt a = pt( ft*dx + small.x , ft*dy + small.y );
     pt b = pt( small.x ,small.y );
     pt c = pt( big.x , big.y );   
     int flag = cross( c , a, b );
     double reflect = angle( a, b, c ); 
     
    // cout<<" reflect angle = "<<reflect*180/pi<<endl;
     double dist = cos( reflect ) * big.r * 2;
     double moveLength = T * speed;
     double dtimes = moveLength/dist;
     double unitT = dist/speed;
     LL itimes = (LL)( dtimes + eps );
     double leftT = ( T - unitT * itimes ) ;
     
     double totAngle = ( pi - 2*reflect ) * itimes; 
     double stAngle = atan2( a.y , a.x );
     //if( stAngle < 0 ) stAngle += pi*2;
     stAngle += totAngle * flag ;
     
     pt now = pt( cos( stAngle )*big.r , sin( stAngle)*big.r );
     double tmp  = stAngle  + ( pi - 2*reflect ) * flag ;
     pt next = pt( cos( tmp )*big.r , sin( tmp )*big.r );  
    // now.out() ; next.out();
     double rate = leftT/unitT;
     pt vec = next - now;
     now = now + ( vec * rate ); 
     if( big.isIn( circle( now.x,now.y,0 ) ) == 0 ){
         cout<<" your code is wrong "<<endl;
     }
     printf("%0.1lf %0.1lf\n",now.x + change.x , now.y + change.y );
}

int main(){
    int test;
    double T, dx , dy ;
    freopen("where am i.in","r",stdin);
    freopen("where am i.out","w",stdout); 
    scanf("%d",&test);
    while( test-- ) {
           big.read();
           small.read();
           if( big.isIn( small ) == 0 ) {
               cout<<" data error "<<endl;
           }
           scanf("%lf%lf%lf",&dx,&dy,&T);
           translate();
           double firstT = get( dx , dy );
           if( firstT > T ) {
               printf("%0.1lf %0.1lf\n",small.x + change.x + T*dx ,small.y + change.y + T*dy);
           }else{
                 solve( dx , dy , firstT, T-firstT);
           }
    }
    while(1);
    return 0;
}
