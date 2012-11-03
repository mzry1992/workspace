#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
int n,m;
int num[1000000];
int s[5005];
map<char,int> mp;
int main()
{
    mp['a']=mp['b']=mp['c']=2;
    mp['d']=mp['e']=mp['f']=3;
    mp['g']=mp['h']=mp['i']=4;
    mp['j']=mp['k']=mp['l']=5;
    mp['m']=mp['n']=mp['o']=6;
    mp['p']=mp['q']=mp['r']=mp['s']=7;
    mp['t']=mp['u']=mp['v']=8;
    mp['w']=mp['x']=mp['y']=mp['z']=9;
    int t;
    scanf("%d",&t);
	while(t--)
	{
	    scanf("%d%d",&n,&m);
	    int i;
	    for(i=0;i<n;i++)
	    {
            scanf("%d",&s[i]);
            num[s[i]]=0;
	    }
	    int j;
	    for(i=0;i<m;i++)
	    {
	        char ss[10];
	        scanf("%s",ss);
	        int len=strlen(ss),k=1,tmp=0;
	        for(j=len-1;j>=0;j--)
	        {
	            tmp+=mp[ss[j]]*k;
                k*=10;
	        }
	        num[tmp]++;
	    }
	    for(i=0;i<n;i++)
            printf("%d\n",num[s[i]]);
	}
	return 0;
}
