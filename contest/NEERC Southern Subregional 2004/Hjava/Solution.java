import java.io.*;
import java.util.*;
import java.math.*;

public class Solution {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n,k;
		int[] sum = new int[250];
		BigInteger[][] dp = new BigInteger[251][251];
		Scanner cin = new Scanner(System.in);
		n = cin.nextInt();
		k = cin.nextInt();
		for (int i = 0;i < 250;i++)
			sum[i] = 0;
		for (int i = 0;i < n;i++)
		{
			int x = cin.nextInt();
			sum[x-1]++;
		}
		for (int i = 248;i >= 0;i--)
			sum[i] += sum[i+1];
		for (int i = 0;i <= 250;i++)
			for (int j = 0;j <= 250;j++)
				dp[i][j] = BigInteger.ZERO;
		for (int i = 0;i <= 250;i++)
			dp[i][0] = BigInteger.ONE;
		for (int i = 1;i <= k;i++)
			for (int j = 249;j >= 0;j--)
				dp[j][i] = dp[j+1][i].add(dp[j+1][i-1].multiply(BigInteger.valueOf(sum[j]-i+1)));
		System.out.println(dp[0][k]);
	}

}
