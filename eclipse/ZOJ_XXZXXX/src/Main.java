import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws IOException
	{
		Scanner cin = new Scanner(System.in);
		int n,m,a,b;
		int x[] = new int[100];
		BigInteger fm[][] = new BigInteger[100][100];
		BigInteger fz[][] = new BigInteger[100][100];
		while (cin.hasNext())
		{
			n = cin.nextInt();
			m = cin.nextInt();
			a = cin.nextInt();
			b = cin.nextInt();
			for (int i = 1;i <= n;i++)
				x[i] = cin.nextInt();
			for (int i = 0;i < 100;i++)
				for (int j = 0;j < 100;j++)
				{
					fz[i][j] = BigInteger.valueOf(0);
					fm[i][j] = BigInteger.valueOf(1);
				}
			for (int j = 0;j <= m;j++)
			{
				fz[1][j] = BigInteger.valueOf(min(b,x[1]+j)-max(a,x[1]-j)+1);
				fm[1][j] = BigInteger.valueOf(b-a+1);
			}
			for (int i = 2;i <= n;i++)
				for (int j = 0;j <= m;j++)
				{
					BigInteger tfz,tfm;
					tfz = fz[i-1][j-abs(max(a,x[i]-j)-x[i])];
					tfm = fm[i-1][j-abs(max(a,x[i]-j)-x[i])];
					for (int k = max(a,x[i]-j)+1;k <= min(b,x[i]+j);k++)
					{
						BigInteger kfz;
						kfz = tfz.add(fz[i-1][j-abs(k-x[i])]);
						tfz = kfz;
					}
					tfm = tfm.multiply(BigInteger.valueOf(b-a+1));
					fz[i][j] = tfz;
					fm[i][j] = tfm;
				}
			BigInteger tfz,tfm,tgcd;
			tfz = fz[n][m];
			tfm = fm[n][m];
			tgcd = tfz.gcd(tfm);
			tfz = tfz.divide(tgcd);
			tfm = tfm.divide(tgcd);
			System.out.println(tfz.toString()+'/'+tfm.toString());
		}
	}

	private static int abs(int a) {
		// TODO Auto-generated method stub
		if (a < 0)
			return -a;
		return a;
	}

	private static int max(int a, int b) {
		// TODO Auto-generated method stub
		if (a > b)
			return a;
		else
			return b;
	}

	private static int min(int a, int b) {
		// TODO Auto-generated method stub
		if (a > b)
			return b;
		else
			return a;
	}
}