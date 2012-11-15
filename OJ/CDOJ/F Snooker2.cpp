#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,now,s[2],p,totr,res,pre;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        s[0] = s[1] = p = totr = pre = 0;
        res = n;
        for (int i = 0;i < n;i++)
        {
            scanf("%d",&now);
            if (now == 0)
                p = 1-p;
            else if (now == 1)
            {
                totr++;
                s[p] += now;
            }
            else
                s[p] += now;
            if (totr < 15)
            {
                int tmp = s[p];
                if (now == 1)
                    tmp += 7+(15-totr)*8+2+3+4+5+6+7;
                else
                    tmp += (15-totr)*8+2+3+4+5+6+7;
                if (tmp < s[1-p])
                {
                    res = i;
                    cout << "( 0 " << tmp << ' ' << s[1-p] << ")" << endl;
                    break;
                }
            }
            else
            {
                int tmp = s[p];
                for (int j = now+1;j <= 7;j++)  tmp += j;
                if (tmp < s[1-p])
                {
                    res = i;
                    cout << "( 1 " << tmp << ' ' << s[1-p] << ")" << endl;
                    break;
                }
            }
            pre = now;
        }
        printf("%d\n",res);
    }
    return 0;
}
