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
		int t,n;
		t = cin.nextInt();
		BigInteger a,b,gcd;
		for (int ft = 1;ft <= t;ft++)
		{
			n = cin.nextInt();
			a = b = BigInteger.ONE;
			a = a.shiftLeft(n);
			for (int i = 1;i <= n;i++)
			{
				a = a.multiply(BigInteger.valueOf(i));
				b = b.multiply(BigInteger.valueOf(2*i-1));
			}
			gcd = a.gcd(b);
			a = a.divide(gcd);
			b = b.divide(gcd);
			System.out.println(b+"/"+a);
		}
	}

}
