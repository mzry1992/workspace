import java.io.*;
import java.math.*;
import java.util.*;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		BigInteger[][][] dp = new BigInteger[101][51][51];
		for (int i = 0;i < 101;i++)
			for (int j = 0;j < 51;j++)
				for (int k = 0;k < 51;k++)
					dp[i][j][k] = BigInteger.ZERO;
		dp[0][0][0] = BigInteger.ONE;
		for (int i = 0;i < 50*2;i++)
			for (int j = 0;j <= 50;j++)
				for (int k = 0;k <= 50;k++)
					if (dp[i][j][k].compareTo(BigInteger.ZERO) > 0)
					{
						if (k < 50)
							dp[i+1][Math.max(j,k+1)][k+1] = dp[i+1][Math.max(j,k+1)][k+1].add(dp[i][j][k]);
						if (k > 0)
							dp[i+1][j][k-1] = dp[i+1][j][k-1].add(dp[i][j][k]);
					}
		int n,m,cas = 1;
		while (cin.hasNext())
		{
			n = cin.nextInt();
			m = cin.nextInt();
			if (n == 0)	break;
			if (cas > 1)	System.out.println("");
			System.out.printf("Case %d: ",cas++);
			System.out.println(dp[n*2][m][0]);
		}
	}

}
