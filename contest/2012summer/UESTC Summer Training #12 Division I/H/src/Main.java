import java.io.*;
import java.util.*;
import java.math.*;

public class Main {

	/**
	 * @param args
	 */
	static int p[] = new int[30001];
	static int next[][] = new int[30001][26];
	static BigInteger dp[][] = new BigInteger[30001][2];
	static int flag;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		String s = cin.next();
		for (int i = 0;i < s.length();i++)
		{
			for (int j = 0;j < n;j++)
				next[i][j] = -1;
			next[i][s.charAt(i)-'a'] = i+1;
		}
		for (int i = 0;i < n;i++)
			if (next[0][i] == -1)
				next[0][i] = 0;
			else
				p[next[0][i]] = 0;
		for (int i = 1;i < s.length();i++)
			for (int j = 0;j < n;j++)
				if (next[i][j] == -1)
					next[i][j] = next[p[i]][j];
				else
					p[next[i][j]] = next[p[i]][j];
		BigInteger bn = BigInteger.valueOf(n);
		dp[0][0] = BigInteger.ONE;
		dp[0][1] = BigInteger.ZERO;
		for (int i = 1;i <= s.length();i++)
		{
			dp[i][0] = dp[i-1][0].multiply(bn);
			dp[i][1] = dp[i-1][1].multiply(bn).add(bn.negate());
			for (int j = 0;j < n;j++)
				if (next[i-1][j] != i)
				{
					dp[i][0] = dp[i][0].add(dp[next[i-1][j]][0].negate());
					dp[i][1] = dp[i][1].add(dp[next[i-1][j]][1].negate());
				}
		}
		BigInteger res = dp[s.length()][1].divide(dp[s.length()][0]).negate();
		System.out.println(res);
	}

}
