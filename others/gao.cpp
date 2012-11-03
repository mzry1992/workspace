#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char buf[1000];
int main()
{
    freopen("data.txt","r",stdin);
	freopen("dataout.txt","w",stdout);
    int id = 1;
    while (scanf("%s",buf) != EOF)
    {
		printf("UPDATE `ranklist` SET `name` = '%s' WHERE `uid` = '%d';\n",buf,id);
        id++;
    }
    return 0;
}
