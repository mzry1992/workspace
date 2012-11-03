import java.util.*;
import java.math.*;

class fs {
	public long a;
	public long b;
	
	public void init(long ta,long tb)
	{
		a = ta;
		b = tb;
		easy();
	}
	
	public long gcd(long a,long b)
	{
		if (b == 0)	return a;
		return gcd(b,a%b);
	}
	
	public void easy()
	{
		long tgcd;
		tgcd = gcd(abs(a),abs(b));
		a = a/tgcd;
		b = b/tgcd;
		if (b < 0)
		{
			a = -a;
			b = -b;
		}
	}
	
	private long abs(long b2) {
		// TODO Auto-generated method stub
		if (b2 < 0)return -b2;
		return b2;
	}

	public fs add(fs t)
	{
		this.easy();
		t.easy();
		fs res = new fs();
		res.a = a*t.b+b*t.a;
		res.b = b*t.b;
		res.easy();
		return res;
	}
	
	public fs negate()
	{
		this.easy();
		fs res = new fs();
		res.a = -a;
		res.b = b;
		res.easy();
		return res;
	}
	
	public fs multipy(fs t)
	{
		fs res = new fs();
		this.easy();
		t.easy();
		res.a = a*t.a;
		res.b = b*t.b;
		res.easy();
		//System.out.println("Mul "+res.a+" "+res.b+" "+a+" "+b+" "+t.a+" "+t.b);
		return res;
	}
	
	public fs divide(fs t)
	{
		this.easy();
		t.easy();
		fs res = new fs();
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
	
	public int compareTo(fs t)
	{
		this.easy();
		t.easy();
		fs res = new fs();
		res.a = a;
		res.b = b;
		res = res.add(t.negate());
		res.easy();
		if (res.a < 0)return -1;
		if (res.a == 0)return 0;
		return 1;
	}
	
}

public class Main {

	/**
	 * @param args
	 */
	public static int n;
	public static int m;
	public static fs a[][] = new fs[110][110];
	public static BigInteger temp;
	public static fs tfs;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		long tot[]= new long[100];
		long b[][]= new long[10][10];
		long ta[][][]= new long[100][100][2];
		BigDecimal res[]= new BigDecimal[100];
		int step[][] = new int[8][2];
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
					b[i][j] = cin.nextLong();
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
					a[i][j].init(ta[i][j][0],ta[i][j][1]);
				}
	        int minpos;
			for (int i = 1;i <= n;i++)
			{
				minpos = 0;
				for (int j = i;j <= n;j++)
					if (a[j][i].a != 0)
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
					if (a[j][i].a != 0)
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
					ka = BigDecimal.valueOf(a[i][m].a);
					kb = BigDecimal.valueOf(a[i][m].b);
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
