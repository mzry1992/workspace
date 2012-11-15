#include <iostream>
#define MIN(X,Y) (((X) < (Y)) ? (X) : (Y) )
#define MAX 5010
using namespace std;

short int n,i,j,k,ans[MAX][MAX];
char s[MAX];

int main()
{
    cin >> n;
    cin >> s;
    for (k = 2;k <= n;k++)
    for (i = 0;i <= n-k;i++)
    {
        j = i+k-1;
        if (s[i] == s[j])
           ans[i][j] = MIN(ans[i+1][j-1],1+MIN(ans[i+1][j],ans[i][j-1]));
        else
            ans[i][j] = MIN(1+ans[i+1][j],1+ans[i][j-1]);
    }
    cout << ans[0][n-1] << endl;
    return 0;
}
