#include <iostream>
using namespace std;

int t;
int n;
int a[40],b[40],rank[40],x[40];

int main()
{
    int i,j;
    scanf("%d",&t);
    for (t;t > 0;t--)
    {
        scanf("%d",&n);
        for (i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        a[0] = 0;
        for (i = 1;i <= n;i++)
            b[i] = a[i]-a[i-1];
        for (i = 1;i <= n;i++)
        {
            x[i] = b[i];
            j = i;
            while (x[j] == 0) j--;
            rank[i] = x[j]+a[j-1];//求出第I个右括号所匹配的左括号是第几个，用栈来模拟。 
            x[j]--;
        }
        int sum;
        for (i = 1;i <= n;i++)
        {
            j = 0;   sum = 0;
            while (sum < rank[i])
            {
                  j++;
                  sum += b[j];
            }
            printf("%d ",i-j+1); 
        }
        printf("\n");
    }   
    return 0;
}
