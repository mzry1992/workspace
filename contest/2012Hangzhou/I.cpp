#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int val[7] = {16,7,8,1,1,2,3};
int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    char ch;
	    int n,va,vb;
	    va = vb = 0;
        bool ma,pao;

        ma = pao = false;
	    scanf("%d",&n);
	    for (int i = 0;i < n;i++)
	    {
            scanf(" %c",&ch);
            va += val[ch-'A'];
            if (ch == 'B')  ma = true;
            if (ch == 'C')  pao = true;
	    }
	    if (ma == false || pao == false)
            va--;
        va = max(va,1);

        ma = pao = false;
	    scanf("%d",&n);
	    for (int i = 0;i < n;i++)
	    {
            scanf(" %c",&ch);
            vb += val[ch-'A'];
            if (ch == 'B')  ma = true;
            if (ch == 'C')  pao = true;
	    }
	    if (ma == false || pao == false)
            vb--;
        vb = max(vb,1);

	    if (va > vb)
            puts("red");
        else if (va == vb)
            puts("tie");
        else
            puts("black");
	}
    return 0;
}

