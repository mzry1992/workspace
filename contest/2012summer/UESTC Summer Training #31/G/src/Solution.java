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
		BigInteger a,b;
		int vb;
		a = cin.nextBigInteger();
		vb = cin.nextInt();
		if (vb == 1)
			System.out.println(a);
		else
		{
			b = BigInteger.valueOf(vb);
			int[] c = new int[10000];
			int tot = 0;
			while (a.equals(BigInteger.ZERO) == false)
			{
				c[++tot] = a.mod(b).intValue();
				a = a.divide(b);
			}
			c[++tot]=0;
			int[][] dp = new int[10000][2];
			dp[0][0]=0;
			dp[0][1]=vb*100;
			int i;
			for(i=1;i<=tot;i++)
			{
				dp[i][0]=dp[i-1][0]+c[i];
				dp[i][0]=Math.min(dp[i][0],dp[i-1][1]+c[i]+1);
				
				dp[i][1]=dp[i-1][0]+vb-c[i];
				dp[i][1]=Math.min(dp[i][1],dp[i-1][1]-1+vb-c[i]);
				//System.out.println(i+" "+c[i]+" "+dp[i][0]+" "+dp[i][1]);
			}
			System.out.println(dp[tot][0]);
		}
	}

}
