#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
pair<char,char> q[4];
struct N
{
    char card[15][3];
}pile[4];
int main()
{
	int i,j;
	for(i=0;i<4;i++)
	{
	    for(j=0;j<13;j++)
            scanf("%s",pile[i].card[j]);
	}
	int ans=0;
	for(i=11;i>=0;i--)
	{
	    int tmp=0;
	    for(j=0;j<4;j++)
            if(pile[j].card[i][1]!=pile[j].card[i+1][1])
                q[tmp++]=make_pair(pile[j].card[i][1],pile[j].card[i+1][1]);
        if(tmp>0)
        {
            ans+=tmp+1;
            if(tmp==4)
            {
                int k;
                bool flag=false;
                for(j=0;j<4;j++)
                    for(k=j+1;k<4;k++)
                        if(q[j].first==q[k].second&&q[k].first==q[j].second)
                            flag=true;
                if(flag)
                    ans++;
            }
        }
	}
	printf("%d\n",ans);
	return 0;
}
