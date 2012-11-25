#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

pair<int,int> pa[110000],pb[110000];
int n;

int main()
{
	int totcas;
	scanf("%d",&totcas);
	while (totcas--)
	{
	    scanf("%d",&n);
	    for (int i = 0;i < n;i++)
            scanf("%d%d",&pa[i].first,&pa[i].second);
	    for (int i = 0;i < n;i++)
            scanf("%d%d",&pb[i].first,&pb[i].second);
        sort(pa,pa+n);
        bool res = false;
        for (int i = 0;i < 4;i++)
        {
            sort(pb,pb+n);
            int dx = pa[0].first-pb[0].first;
            int dy = pa[0].second-pb[0].second;
            bool flag = true;
            for (int j = 0;j < n && flag;j++)
                if (pa[j].first-pb[j].first != dx || pa[j].second-pb[j].second != dy)
                    flag = false;
            if (flag)
            {
                res = true;
                break;
            }
            for (int j = 0;j < n;j++)
            {
                dx = pb[j].first;
                dy = pb[j].second;
                pb[j] = make_pair(-dy,dx);
            }
        }
        if (res)
            puts("MATCHED");
        else
            puts("NOT MATCHED");
	}
	return 0;
}
