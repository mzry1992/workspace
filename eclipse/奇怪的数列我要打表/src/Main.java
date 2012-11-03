import java.io.*;
import java.util.*;
import java.math.*;

public class Main {

	private static BigInteger temp;
	private static int p;

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException
	{
		// TODO Auto-generated method stub
		BigInteger fact[] = new BigInteger[15]; 
		fact[0] = BigInteger.valueOf(1);
		for (int i = 1;i <= 12;i++)
			fact[i] = fact[i-1].multiply(BigInteger.valueOf(i));
		int prime[] = new int[10];
		prime[1] = 2;
		prime[2] = 3;
		prime[3] = 5;
		prime[4] = 7;
		prime[5] = 11;
		for (int forp = 4;forp <= 5;forp++)
		for (int form = 1;form <= 12;form++)
		{
			int m;
			p = prime[forp];
			m = form;
			System.out.println(p+" "+m);
			BigInteger fac,tmp;
			tmp = BigInteger.valueOf(p);
			fac = fact[m];
			for (int i = 2;tmp.compareTo(fac) < 1;i++)
			{
				solve(tmp);
				tmp = temp;
				//System.out.println(tmp.toString());
			}
			System.out.println(p+" "+m+" "+tmp.mod(fac).toString());
		}
	}

	private static void solve(BigInteger now) {
		// TODO Auto-generated method stub
		if (now.compareTo(BigInteger.valueOf(1)) == 0)
		{
			temp = BigInteger.valueOf(p);
			return;
		}
		solve(now.divide(BigInteger.valueOf(2)));
		temp = temp.multiply(temp);
		if (now.mod(BigInteger.valueOf(2)).compareTo(BigInteger.valueOf(1)) == 0)
			temp = temp.multiply(BigInteger.valueOf(p));
	}

}
