import java.io.*;
import java.math.*;
import java.util.*;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int prime[] = new int[100];
		int tot;
		Boolean isprime[] = new Boolean[300];
		tot = 0;
		for (int i = 2;i < 300;i++)
			isprime[i] = true;
		prime[tot++] = 1;
		for (int i = 2;i < 300;i++)
		{
			if (isprime[i] == true)
				prime[tot++] = i;
			for (int j = 1;j <= tot && i*prime[j] < 300;j++)
			{
				isprime[i*prime[j]] = false;
				if (i%prime[j] == 0)break;
			}
		}
		BigInteger pre[] = new BigInteger[100];
		pre[0] = BigInteger.ONE;
		for (int i = 1;i < 55;i++)
			pre[i] = pre[i-1].multiply(BigInteger.valueOf(prime[i]));
		Scanner cin = new Scanner(System.in);
		int T;
		T = cin.nextInt();
		BigInteger n;
		for (int ft = 1;ft <= T;ft++)
		{
			n = cin.nextBigInteger();
			for (int i = 1;i < 55;i++)
				if (n.compareTo(pre[i]) >= 0 && n.compareTo(pre[i+1]) < 0)
				{
					System.out.println(pre[i]);
					break;
				}
		}
	}

}
