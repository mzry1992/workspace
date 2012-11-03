import java.io.*;
import java.util.*;
import java.math.*;

class fs {
	public BigInteger a;
	public BigInteger b;
	
	public void init(BigInteger ta,BigInteger tb)
	{
		a = ta;
		b = tb;
		easy();
	}
	
	public void easy()
	{
		BigInteger tgcd;
		tgcd = a.gcd(b);
		a = a.divide(tgcd);
		b = b.divide(tgcd);
	}
	
	public fs add(fs t)
	{
		fs res = new fs();
		res.a = a.multiply(t.b).add(b.multiply(t.a));
		res.b = b.multiply(t.b);
		res.easy();
		return res;
	}
	
	public fs negate()
	{
		fs res = new fs();
		res.a = a.negate();
		res.b = b;
		res.easy();
		return res;
	}
	
	public fs multipy(fs t)
	{
		fs res = new fs();
		res.a = a.multiply(t.a);
		res.b = b.multiply(t.b);
		res.easy();
		return res;
	}
	
	public fs divide(fs t)
	{
		fs res = new fs();
		res.a = a.multiply(t.b);
		res.b = b.multiply(t.a);
		if (res.b.compareTo(BigInteger.ZERO) < 0)
		{
			res.b = res.b.negate();
			res.a = res.a.negate();
		}
		res.easy();
		return res;
	}
	
	public int compareTo(fs t)
	{
		fs res = new fs();
		res.a = a;
		res.b = b;
		res = res.add(t.negate());
		res.easy();
		return res.a.compareTo(BigInteger.ZERO);
	}
	
	public void output()
	{
		if (b.compareTo(BigInteger.ONE) == 0)
			System.out.print(a);
		else
			System.out.print(a+"/"+b);
	}
	
	public void outputln()
	{
		if (b.compareTo(BigInteger.ONE) == 0)
			System.out.println(a);
		else
			System.out.println(a+"/"+b);
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
	
	public static void main(String[] args) throws IOException
	{
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int minpos;
		Boolean hasans;
		while (cin.hasNext())
		{
			n = cin.nextInt();
			m = n+1;
			for (int i = 1;i <= n;i++)
				for (int j = 1;j <= m;j++)
				{
					a[i][j] = new fs();
					temp = cin.nextBigInteger();
					a[i][j].init(temp,BigInteger.ONE);
				}
			hasans = true;
			for (int i = 1;i <= n;i++)
			{
				minpos = 0;
				for (int j = i;j <= n;j++)
					if (a[j][i].a.compareTo(BigInteger.ZERO) != 0)
					{
						minpos = j;
						break;
					}
				if (minpos == 0)
				{
					hasans = false;
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
			if (hasans == false)
				System.out.println("No solution.");
			else
			{
				for (int i = n;i >= 1;i--)
				{
					a[i][m] = a[i][m].divide(a[i][i]);
					a[i][i] = a[i][i].divide(a[i][i]);
					for (int j = 1;j < i;j++)
					{
						a[j][m] = a[j][m].add(a[i][m].multipy(a[j][i]).negate());
						a[j][i] = a[j][i].add(a[j][i].negate());
					}
				}
				for (int i = 1;i <= n;i++)
					a[i][m].outputln();
			}
			System.out.println();
		}
	}

}
