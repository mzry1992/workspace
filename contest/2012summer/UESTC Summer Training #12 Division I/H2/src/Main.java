import java.util.*;
import java.math.*;
import java.io.*;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		String s = cin.next();
		int A[] = new int[30001];
		int pj = 0;
		while (pj+1 < s.length() && s.charAt(pj) == s.charAt(pj+1))
			pj++;
		A[1] = pj;
		int k = 1;
		for (int i = 2;i < s.length();i++)
		{
			int Len = k+A[k]-1,L = A[i-k];
			if (L < Len-i+1)
				A[i] = L;
			else
			{
				pj = Math.max(0,Len-i+1);
				while (i+pj < s.length() && s.charAt(i+pj) == s.charAt(pj))
					pj++;
				A[i] = pj;
				k = i;
			}
		}
		BigInteger res = BigInteger.ZERO;
		BigInteger bn = BigInteger.valueOf(n);
		for (int i = 0;i < s.length();i++)
		{
			if (i == 0 || i+A[i] == s.length())
				res = res.add(BigInteger.ONE);
			res = res.multiply(bn);
		}
		System.out.println(res);
	}

}
