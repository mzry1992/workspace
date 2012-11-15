#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int sindex[8] = {0,1,2,7,16,21,22,23};
const int nindex[8] = {3,6,3,6,17,20,17,20};
const int mindex[16] = {3,4,5,6,8,9,10,11,12,13,14,15,17,18,19,20};
/*
 0  1
234567
 8901
 2345
678901
 2  3
*/
int a[24],b[24];

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        for (int i = 0; i < 24; i++)
            scanf("%d",&a[i]);
        for (int i = 0; i < 24; i++)
            scanf("%d",&b[i]);
        bool flag = true;
        for (int i = 0; i < 8; i++)
        {
            int cura = a[sindex[i]];
            int curb = b[sindex[i]];
            if (cura == 0)
                swap(a[sindex[i]],a[nindex[i]]);
            if (curb == 0)
                swap(b[sindex[i]],b[nindex[i]]);
            cura = a[sindex[i]];
            curb = b[sindex[i]];
            if (cura == curb)   continue;
            flag = false;
            break;
        }
        if (flag == true)
        {
            int ra,rb;
            ra = rb = 0;
            for (int i = 0; i < 16; i++)
                if (a[mindex[i]] != 0)
                    for (int j = 0; j < i; j++)
                        if (a[mindex[j]] != 0)
                            if (a[mindex[j]] < a[mindex[i]])
                                ra++;
            for (int i = 0; i < 16; i++)
                if (b[mindex[i]] != 0)
                    for (int j = 0; j < i; j++)
                        if (b[mindex[j]] != 0)
                            if (b[mindex[j]] < b[mindex[i]])
                                rb++;
            int pre,next;
            for (int i = 0;i < 16;i++)
                if (a[mindex[i]] == 0)
                    pre = i/4;
            for (int i = 0;i < 16;i++)
                if (b[mindex[i]] == 0)
                    next = i/4;
            ra += (next+pre)%2;
            if (ra%2 != rb%2)
                flag = false;
        }
        if (flag == false)
            puts("Y");
        else
            puts("N");
    }
    return 0;
}
