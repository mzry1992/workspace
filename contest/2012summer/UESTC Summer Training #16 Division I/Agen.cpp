#include "cstdio"
#include "cstdlib"
#include "ctime"

int main(int argc, char const *argv[])
{
	srand(time(0));
	freopen("A.in","w",stdout);
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
			printf("ahz");
		puts("");
	}
	return 0;
}