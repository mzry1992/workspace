#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int step[5][2] = {{0,0},{-1,0},{1,0},{0,1},{0,-1}};
int n,m,ma[20][20];
int a[400][401];

bool GS(int n)
{
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j <= n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
            if (a[j][i] != 0)
            {
                for (int k = i; k <= n; k++)
                    swap(a[j][k],a[i][k]);
                break;
            }
        if (a[i][i] == 0)
            continue;

        for (int j = 0; j < n; j++)
            if (i != j && a[j][i] != 0)
            {
                int tmp = a[j][i];
                for (int k = 0; k <= n; k++)
                    a[j][k] = ((a[j][k]*a[i][i]-a[i][k]*tmp)%4+4)%4;
            }
		puts("-----------");
		for (int j = 0;j < n;j++)
		{
			for (int k = 0;k <= n;k++)
				printf("%d ",a[j][k]);
			printf("\n");
		}
    }

    for (int i = 0; i < n; i++)
    {
		printf("a[i][i] = %d, a[i][n] = %d, ",a[i][i],a[i][n]);
        if (a[i][i] == 0)
        {
            if (a[i][n] == 0)
                return false;

            for (int j = 0; j < n; j++)
                a[j][i] = 0;
        }
        else
        {
            //a[i][i]

            if (a[i][i] == 2)
            {
                if (a[i][n]%2 == 1)	return false;
                a[i][n] = a[i][n]/a[i][i];
            }
            else if (a[i][i] == 3)
            {
                if (a[i][n] == 0)
                    a[i][n] = 0;
                else if (a[i][n] == 1)
                    a[i][n] = 3;
                else if (a[i][n] == 2)
                    a[i][n] = 2;
                else
                    a[i][n] = 1;
            }
        }

		if (a[i][n] == 0)
			a[i][n] = 4;
        printf("ret = %d\n",a[i][n]);
    }
    return true;
}

int b[20][20];
void check(int i,int j)
{
    for (int k = 0; k < 5; k++)
    {
        int ni = i+step[k][0];
        int nj = j+step[k][1];

        if (ni < 0 || ni >= n || nj < 0 || nj >= m)	continue;

		b[ni][nj]++;
		if (b[ni][nj] == 5)
			b[ni][nj] -= 4;
    }
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d",&ma[i][j]);
        memset(a,0,sizeof(a));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                a[i*m+j][n*m] = ma[i][j]%4;
                for (int k = 0; k < 5; k++)
                {
                    int ni = i+step[k][0];
                    int nj = j+step[k][1];

                    if (ni < 0 || ni >= n || nj < 0 || nj >= m)	continue;

                    a[i*m+j][ni*m+nj] = 1;
                }
            }

        if (GS(n*m))
        {
            memset(b,0,sizeof(b));
            puts("Yes");
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    for (int k = 0; k < a[i*m+j][n*m]; k++)
                    {
                        printf("%d %d\n",i+1,j+1);
                        check(i,j);
                    }

			for (int i = 0;i < n;i++)
			{
				for (int j = 0;j < m;j++)
					printf("%d ",b[i][j]);
				printf("\n");
			}
//			for (int i = 0;i < n;i++)
//				for (int j = 0;j < m;j++)
//					while (b[i][j] != ma[i][j])
//					{
//						puts("fuck");
//					}
        }
        else
            puts("No");
    }
    return 0;
}
