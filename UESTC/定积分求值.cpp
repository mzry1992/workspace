#include"stdio.h"
#include"math.h"

#define A 0.//积分上界
#define B 1.//积分下界
#define EPS 1e-13//精度

double results[12];

double F(double x){//被积函数
       return 4/(1+x*x);}

double T2n(double a,double b,int n){//梯形递推算法
       int i;
       double sum=0,h=(b-a)/pow(2,n),start=a+h;
       for(i=0;i<pow(2,n-1);i++)sum+=F(start+i*h*2);
       return sum*h+results[0]/2;
}

int Romberg(double a,float b,double eps){//Romberg算法
       int i,j,ok=0;
       double t,s;
       t=(b-a)*(F(a)+F(b))/2;
       results[0]=t;
       printf("%0.8f ",results[0]);
       for(i=1;!ok&&i<20;i++){
          t=T2n(a,b,i);
          printf("\n%0.8f ",t);
          for(j=0;!ok&&j<i;j++){
            s=(pow(2,2*(j+1))*t-results[j])/(pow(2,2*(j+1))-1);
            printf("%0.8f ",s);
            if(fabs(t-results[j])/(pow(2,2*(j+1))-1)<eps)ok=1;
            results[j]=t;
            t=s;}
            results[j]=t;}
       return j;
}

int main(){
    printf("\n\nresult:%0.16f\n",results[Romberg(A,B,EPS)]);
    return 0;
}
