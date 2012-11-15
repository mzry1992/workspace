#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct fs
{
	long long a;
	long long b;

	void init(long long ta,long long tb)
	{
		a = ta;
		b = tb;
		easy();
	}

    long long gcd(long long a,long long b)
    {
        if (b == 0) return a;
        return gcd(b,a%b);
    }

	void easy()
	{
		long long tgcd;
		tgcd = gcd(a,b);
		a = a/tgcd);
		b = b/tgcd);
	}

	fs add(fs t)
	{
		fs res;
		res.a = a*t.b+b*t.a;
		res.b = b*t.b;
		res.easy();
		return res;
	}

	fs negate()
	{
		fs res;
		res.a = -a;
		res.b = b;
		res.easy();
		return res;
	}

	fs multipy(fs t)
	{
		fs res;
		res.a = a*t.a;
		res.b = b*t.b;
		res.easy();
		return res;
	}

	fs divide(fs t)
	{
		fs res;
		res.a = a*t.b;
		res.b = b*t.a;
		if (res.b < 0)
		{
			res.b = -res.b;
			res.a = -res.a;
		}
		res.easy();
		return res;
	}

	int compareTo(fs t)
	{
		fs res = new fs();
		res.a = a;
		res.b = b;
		res = res.add(t.negate());
		res.easy();
		if (res.a < 0)  return -1;
		if (res.a == 0) return 0;
		return 1;
	}

};

int n;
int m;
fs a[110][110];
fs tfs;

int main()
{
		int tot[]= new int[100];
		int b[][]= new int[10][10];
		int ta[][][]= new int[100][100][2];
		BigDecimal res[]= new BigDecimal[100];
		int step[][] = int[8][2];
		step[0][0] = -1;	step[0][1] = -1;
		step[1][0] = -1;	step[1][1] = 0;
		step[2][0] = -1;	step[2][1] = 1;
		step[3][0] = 0;	step[3][1] = -1;
		step[4][0] = 0;	step[4][1] = 1;
		step[5][0] = 1;	step[5][1] = -1;
		step[6][0] = 1;	step[6][1] = 0;
		step[7][0] = 1;	step[7][1] = 1;
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext() == true)
		{
			for (int i = 1;i <= 8;i++)
				for (int j = 1;j <= 8;j++)
					b[i][j] = cin.nextInt();
	        for (int i = 1;i <= 8;i++)
	            for (int j = 1;j <= 8;j++)
	            {
	                tot[(i-1)*8+j] = 0;
	                for (int k = 0;k < 8;k++)
	                {
	                    int tx = i+step[k][0];
	                    int ty = j+step[k][1];
	                    if (tx >= 1 && tx <= 8 && ty >= 1 && ty <= 8)
	                        tot[(i-1)*8+j] += b[tx][ty];
	                }
	            }
	        for (int i = 1;i <= 64;i++)
	        	for (int j = 1;j <= 65;j++)
	        	{
	        		ta[i][j][0] = 0;
	        		ta[i][j][1] = 1;
	        	}
	        for (int i = 1;i <= 65;i++)
        	{
        		ta[1][i][0] = 1;
        		ta[1][i][1] = 1;
        	}
	        int nown = 2;
	        for (int i = 1;i <= 8;i++)
	        for (int j = 1;j <= 8;j++)
	        {
	            ta[nown][(i-1)*8+j][0] = 1;
	            ta[nown][(i-1)*8+j][1] = 1;
	            for (int k = 0;k < 8;k++)
	            {
	                int tx = i+step[k][0];
	                int ty = j+step[k][1];
	                if (tx >= 1 && tx <= 8 && ty >= 1 && ty <= 8)
	                {
	                	ta[nown][(tx-1)*8+ty][0] = -b[i][j];
	                	ta[nown][(tx-1)*8+ty][1] = tot[(tx-1)*8+ty];
	                }
	            }
	            nown++;
	        }
	        int n = 64;
	        int m = 65;
	        for (int i = 1;i <= n;i++)
				for (int j = 1;j <= m;j++)
				{
					a[i][j] = new fs();
					a[i][j].init(BigInteger.valueOf(ta[i][j][0]),BigInteger.valueOf(ta[i][j][1]));
				}
	        int minpos;
			for (int i = 1;i <= n;i++)
			{
				minpos = 0;
				for (int j = i;j <= n;j++)
					if (a[j][i].a.compareTo(BigInteger.ZERO) != 0)
					{
						minpos = j;
						break;
					}
				for (int j = 1;j <= m;j++)
				{
					tfs = a[i][j];
					a[i][j] = a[minpos][j];
					a[minpos][j] = tfs;
				}
				for (int j = i+1;j <= n;j++)
					if (a[j][i].a.compareTo(BigInteger.ZERO) != 0)
					{
						tfs = a[j][i].divide(a[i][i]);
						for (int k = 1;k <= m;k++)
							a[j][k] = a[j][k].add(a[i][k].multipy(tfs).negate());
					}
			}
			BigDecimal ka,kb;
				for (int i = n;i >= 1;i--)
				{
					a[i][m] = a[i][m].divide(a[i][i]);
					a[i][i] = a[i][i].divide(a[i][i]);
					ka = new BigDecimal(a[i][m].a);
					kb = new BigDecimal(a[i][m].b);
					res[i] = ka.divide(kb,30,BigDecimal.ROUND_HALF_UP);
					for (int j = 1;j < i;j++)
					{
						a[j][m] = a[j][m].add(a[i][m].multipy(a[j][i]).negate());
						a[j][i] = a[j][i].add(a[j][i].negate());
					}
				}
			for (int i = 1;i <= n;i++)
			{
				System.out.print(res[i]+" ");
				if (i%8 == 0)
					System.out.println();
			}
		}
	}

}
