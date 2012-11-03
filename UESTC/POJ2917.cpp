#include <iostream>
using namespace std;

int t,ft,n,ans,tot,prime[50100];
bool isprime[50100];

void getprime()
{
     int i,j,max;
     for (i = 1;i <= 50000;i++)
         isprime[i] = true;
     for (i = 3;i <= 500;i += 2)
     if (isprime[i] == true)
     {
                    max = 50000/i;
                    for (j = 3;j <= max;j += 2)
                    isprime[i*j] = false;
     }
     tot = 0;
     prime[tot++] = 2;
     for (i = 3;i <= 50000;i += 2)
     if (isprime[i] == true)
        prime[tot++] = i;
}
    
int solve(int n)
{
    int i,j,ans;
    ans = 1;
    if (n == 1) return 1;
    for (i = 0;((i < tot) && (prime[i]*prime[i] <= n));i++)
    {
        j = 0;
        while (n%prime[i] == 0)
        {
              n /= prime[i];
              j++;
        }
        ans *= 2*j+1;
    }
    if ((ans == 1) || (n != 1))
       ans *= 3;
    ans = (ans+1)/2;
    return ans;
}


int main()
{
    getprime();
    cin >> t;
    for (ft = 1;ft <= t;ft++)
    {
        cin >> n;
        cout << "Scenario #" << ft << ":" << endl;
        ans = solve(n);
        cout << ans << endl;
        cout << endl;
    }
    return 0;
}
