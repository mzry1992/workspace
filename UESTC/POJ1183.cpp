#include <iostream>
using namespace std;

__int64 a,b,c,m,n;

int main()
{
    cin >> a;
    for (m = a;m >= 1;m--)
    if ((a*a+1)%m == 0)
    {
                  n = (a*a+1)/m;
                  b = a+m;
                  c = a+n;
                  cout << b+c << endl;
                  break;
    }
    //system("pause");
    return 0;
}
                          
