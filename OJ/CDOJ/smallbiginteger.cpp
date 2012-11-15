#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int sbi_length = 4;
const int sbi_bit_length = 32768;
struct sbi
{
    int num[sbi_length],length,sgn;
    sbi(){}
    sbi(long long a)
        {
            sgn = length = 0;
            if (a < 0)
            {
                sgn = 1;
                a = -a;
            }
            while (a > 0)
            {
                num[length++] = a%sbi_bit_length;
                a /= sbi_bit_length;
            }
        }
};

int main()
{

}
