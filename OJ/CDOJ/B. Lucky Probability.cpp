#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int tot,num[2000],tnum;
int pl,pr,vl,vr,k,a[2000],b[2000];
long long resa,resb;

int main()
{
    tot = 0;
    for (int len = 1; len < 9; len++)
        for (int i = 0; i < (1<<len); i++)
        {
            tnum = 0;
            for (int j = 0; j < len; j++)
                if (((i>>j)&1) == 1)
                    tnum = tnum*10+4;
                else
                    tnum = tnum*10+7;
            num[tot++] = tnum;
        }
    sort(num,num+tot);
    while (scanf("%d%d%d%d%d",&pl,&pr,&vl,&vr,&k) != EOF)
    {
        double res;
        resb = 0;
        int l = 0;
        int restot = 0;
        a[restot] = 0;
        b[restot] = 0;
        restot++;
        for (int i = k-1; i < tot; i++)
        {
            a[restot] = num[l];
            b[restot] = num[i];
            restot++;
            l++;
        }
        a[restot] = 1000000001;
        b[restot] = 1000000001;
        restot++;
        int la,ra,lb,rb;
        for (int i = 1; i < restot-1; i++)
        {
            la = a[i-1]+1;
            ra = a[i];
            lb = b[i];
            rb = b[i+1]-1;
            //p < v
            if (ra >= pl && la <= pr && rb >= vl && lb <= vr)
            {
                //cout << resb << endl;
                resb += (long long)(min(pr,ra)-max(pl,la)+1)*
                        (long long)(min(vr,rb)-max(vl,lb)+1);
                //cout << la << ' ' << ra << ' ' << lb << ' ' << rb << endl;
                //cout << pl << ' ' << pr << ' ' << vl << ' ' << vr << endl;
                //cout << resb << endl;
            }
            //p > v
            if (ra >= vl && la <= vr && rb >= pl && lb <= pr)
            {
                //cout << resb << endl;
                resb += (long long)(min(vr,ra)-max(vl,la)+1)*
                        (long long)(min(pr,rb)-max(pl,lb)+1);
                //cout << la << ' ' << ra << ' ' << lb << ' ' << rb << endl;
                //cout << vl << ' ' << vr << ' ' << pl << ' ' << pr << endl;
                //cout << resb << endl;
            }
        }
        //del p == v
        for (int i = 1; i < restot--; i++)
            if (a[i] == b[i])
                if (pl <= a[i] && a[i] <= pr && vl <= b[i] && b[i] <= vr)
                    resb--;
        resa = (long long)(pr-pl+1)*(long long)(vr-vl+1);
        cout << resb << ' ' << resa << endl;
        res = (double)resb/(double)resa;
        printf("%.15f\n",res);
    }
    return 0;
}
