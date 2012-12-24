import java.io.*;
import java.util.*;
import java.math.*;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int n,k;
		BigInteger a[] = new BigInteger[100];
		PriorityQueue<BigInteger> Q = new PriorityQueue<BigInteger>();
		BigInteger resmax,resmin,ta,tb;
		while (cin.hasNext())
		{
			n = cin.nextInt();
			k = cin.nextInt();
			Q.clear();
			for (int i = 0;i < n;i++)
			{
				a[i] = cin.nextBigInteger();
				Q.add(a[i]);
			}
			while (Q.size() > 1)
			{
				ta = Q.remove();
				tb = Q.remove();
				Q.add(ta.multiply(tb).add(BigInteger.ONE));
			}
			resmax = Q.remove();
			for (int i = 0;i < n;i++)
				for (int j = i+1;j < n;j++)
					if (a[i].compareTo(a[j]) > 0)
					{
						ta = a[i];
						a[i] = a[j];
						a[j] = ta;
					}
			while (n > 1)
			{
				ta = BigInteger.ONE;
				if (k > n)
					k = n;
				for (int i = 0;i < k;i++)
					ta = ta.multiply(a[n-1-i]);
				ta = ta.add(BigInteger.ONE);
				n -= k;
				a[n++] = ta;
			}
			resmin = a[0];
			System.out.println(resmax.add(resmin.negate()));
		}
	}

}
