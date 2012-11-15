#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        int tot = 0;
        bool first = true;
        for (int i = 1;i <= n;i++)
        {
            int t;
            scanf("%d",&t);
            for (int j = tot+1;j <= t;j++)
            {
                if (first == false) printf(" ");
                first = false;
                printf("%d",i);
            }
            tot = t;
            //cout << endl << "tot = " << tot << endl;
        }
        printf("\n");
    }
}
