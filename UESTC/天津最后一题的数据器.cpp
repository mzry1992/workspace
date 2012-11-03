#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<time.h>
using namespace std;

bool hash[123456];
int a[123456];

int main()
{
	freopen("in.txt","w",stdout);
	srand(time(NULL));
	puts("50000");
	memset(hash,false,sizeof(hash));
	int tot = 0;
	for (int i = 1;i <= 50000;i++)
	{
	    int type = rand()%10;
	    if ((type < 4) || (tot == 0))
	    {
	        int temp;
	        while (true)
	        {
	            temp = rand()%120000+1;
	            if (hash[temp] == false)
                    break;
	        }
	        tot++;
	        hash[temp] = true;
	        a[tot] = temp;
	        printf("Insert %d\n",1234567+temp);
	    }
	    else if (type < 6)
	    {
	        int ta,tb,tc;
            ta = rand()%(tot-1)+1;
            tb = ta+rand()%(tot-ta);
            tc = rand()%(tb-ta+1)+1;
	        printf("Query_1 %d %d %d\n",ta,tb,tc);
	    }
	    else if (type < 8)
	    {
	        int ta;
	        ta = rand()%tot+1;
	        printf("Query_2 %d\n",1234567+a[ta]);
	    }
	    else
	    {
	        int ta;
	        ta = rand()%tot+1;
	        printf("Query_3 %d\n",ta);
	    }
	}
}
