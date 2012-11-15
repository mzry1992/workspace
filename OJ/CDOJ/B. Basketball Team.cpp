#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,h,s[1000];

int main()
{
    while (scanf("%d%d%d",&n,&m,&h) != EOF)
    {
        h--;
        for (int i = 0;i < m;i++)
            scanf("%d",&s[i]);
        int others = 0;
        for (int i = 0;i < m;i++)
            others += s[i];
        double res;
        if (others-1 < n-1)
            res = -1;
        else if (others-s[h] < n-1)
            res = 1.0;
        //else if (s[h] == 1)
        //    res = 0.0;
        else
        {
            res = 1.0;
            double tres = 1.0;
            int la,ra,lb,rb;
            la = others-s[h]-n+2;
            ra = others-s[h];
            lb = others-n+1;
            rb = others-1;
            //cout << la << ' ' << ra << ' ' << lb << ' ' << rb << endl;
            for (int i = la,j = ra+1;i < lb;i++,j++)
                tres *= (double)i/(double)j;
            res -= tres;
        }
        printf("%.9f\n",res);
    }
    return 0;
}

