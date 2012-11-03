#include <cstdio>
#include <map>
using namespace std;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	map<int,int> num;
	for (int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		num[x]++;
	}
	int tot=0,times=0;
	for (map<int,int> :: iterator it=num.begin();it!=num.end();)
	{
		if (it->first*it->second>m)
			break;
		times++;
		int nowt=it->second;
		it++;
		while (it!=num.end() && (it->second+nowt)*it->first<=m)
		{
			nowt+=it->second;
			it++;
		}
		tot+=nowt;
	}
	printf("%d %d\n",tot,times);
}
