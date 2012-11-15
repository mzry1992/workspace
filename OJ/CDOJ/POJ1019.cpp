#include <iostream>
using namespace std;

__int64 t,ft,n,len,lenk,k;

int lon(__int64 k)
{
	int len = 0;
	while(k != 0)
	{
		len++;
		k = k / 10;
	}
	return len;
}

 
int main()
{
    cin >> t;
    for (ft = 1;ft <= t;ft++)
    {
        cin >> n;
        len = lenk = 0;
        k = 1;
        while (n > len)
        {
              lenk += lon(k);
              k++;
              len += lenk;
        }
        len -= lenk;
        k = 1;
        while (n > len)
        {
              len += lon(k);
              k++;
        }
        k--;
        len -= lon(k);
        n -= len;
        len = lon(k)-n;
        while (len != 0)
        {
              k /= 10;
              len--;
        }
        k %= 10;
        cout << k << endl; 
        
    }
    return 0;
}
