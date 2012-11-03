import java.io.*;
import java.util.*;
import java.math.*;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException
	{
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int n,k;
		BigInteger fb[] = new BigInteger[60];
		BigInteger fa[][] = new BigInteger[60][60];
		fa[1][0] = BigInteger.valueOf(0);
		fa[1][1] = BigInteger.valueOf(1);
		for (int i = 2;i <= 50;i++)
		{
			fa[i][0] = BigInteger.valueOf(0);
			for (int j = 1;j < i;j++)
				fa[i][j] = fa[i-1][j-1].add(fa[i-1][j].multiply(BigInteger.valueOf(i-1)));
			fa[i][i] = BigInteger.valueOf(1);
		}
		fb[1] = BigInteger.valueOf(1);
		for (int i = 2;i <= 50;i++)
			fb[i] = fb[i-1].multiply(BigInteger.valueOf(i));
		while (cin.hasNext())
		{
			n = cin.nextInt();
			k = cin.nextInt();
			BigInteger ta,tb,tc;
			ta = BigInteger.valueOf(0);
			for (int i = 1;i <= k;i += 2)
				ta = ta.add(fa[n][i]);
			tb = fb[n];
			tc = ta.gcd(tb);
			ta = ta.divide(tc);
			tb = tb.divide(tc);
			System.out.println(ta.toString()+'/'+tb.toString());
		}
	}

}
