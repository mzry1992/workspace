#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

float Q_rsqrt( float number )
{
  long i;
  float x2, y;
  const float threehalfs = 1.5F;
  x2 = number * 0.5F;
  y  = number;
  i  = * ( long * ) &y;        // 浮点数按BIT强行赋给长整形
  i  = 0x5f3759df - ( i >> 1 ); //没天理！

  y  = * ( float * ) &i;
  y  = y * ( threehalfs - ( x2 * y * y ) ); // 第1次叠代
  // y  = y * ( threehalfs - ( x2 * y * y ) ); // 第2次叠代，可以删除
  #ifndef Q3_VM
  #ifdef __linux__
    assert( !isnan(y) ); // bk010122 - FPE?
  #endif
  #endif
  return y;
}

int main()
{
    float a;
    a = 25;
    printf("%.6f\n",1/Q_rsqrt(a));
}
