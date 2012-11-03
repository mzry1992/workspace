import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	static int prime[] = new int[110000];
	static int tot;
	static int isprime[] = new int[1100000];
	static long a;
	static long c;
	static long phic;
	static long temp2;
	static long ans;
	static BigInteger b,temp;

	public static void main(String[] args) throws IOException
	{
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		getprime();
		while (cin.hasNext())
		{
			a = cin.nextLong();
			b = cin.nextBigInteger();
			c = cin.nextLong();
			phic = phi(c);
			temp = b.mod(BigInteger.valueOf(phic)).add(BigInteger.valueOf(phic));
			temp2 = temp.longValue();
			if (b.compareTo(BigInteger.valueOf(phic)) == -1)
				temp2 = b.longValue();
			solve(temp2);
			System.out.println(ans+" "+a+" "+c+" "+phic+" "+temp2);
		}
	}

	private static void solve(long n) {
		// TODO Auto-generated method stub
		if (n == 0)
		{
			ans = 1;
			return;
		}
		if (n == 1)
		{
			ans = a%c;
			return;
		}
		solve(n/2);
		ans = ((ans%c)*(ans%c))%c;
		if (n%2 == 1)
			ans = ((ans%c)*(a%c))%c;
	}

	private static long phi(long n) {
		// TODO Auto-generated method stub
		long res = n;
		for (int i = 1;i <= tot;i++)
		{
			if (n%prime[i] == 0)
			{
				while (n%prime[i] == 0)
					n /= prime[i];
				res = (res/prime[i])*(prime[i]-1);
			}
		}
		if (n != 1)
			res = (res/n)*(n-1);
		return res;
	}

	private static void getprime() {
		// TODO Auto-generated method stub
		tot = 0;
		for (int i = 1;i < 1000000;i++)
			isprime[i] = 0;
		for (int i = 2;i < 1000000;i++)
		{
			if (isprime[i] == 0)
			{
				tot++;
				prime[tot] = i;
			}
			for (int j = 1;j <= tot && i*prime[j] < 1000000;j++)
			{
				isprime[i*prime[j]] = 1;
				if (i%prime[j] == 0)
					break;
			}
		}
	}

}
