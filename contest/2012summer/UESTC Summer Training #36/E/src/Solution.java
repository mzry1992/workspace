import java.io.*;
import java.util.*;
import java.math.*;

public class Solution {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int n,m;
		m = cin.nextInt();
		n = cin.nextInt();
		BigInteger[] f = new BigInteger[3];
		f[0] = BigInteger.valueOf(1);
		f[1] = BigInteger.valueOf(0);
		for (int i = 2;i <= n;i++)
			f[i%3] = f[(i-1)%3].multiply(BigInteger.valueOf(2)).add(f[(i-2)%3].multiply(BigInteger.valueOf(m)));
		System.out.println(f[n%3]);
	}

}
