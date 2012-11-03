import java.util.*;
import java.math.*;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BigInteger f[] = new BigInteger[1000];
		f[0] = f[1] = BigInteger.ONE;
		f[2] = BigInteger.valueOf(2);
		for (int i = 3;i < 1000;i++)
			f[i] = f[i-1].add(f[i-3]).add(BigInteger.ONE);
		Scanner cin = new Scanner(System.in);
		int n;
		while (cin.hasNext())
		{
			n = cin.nextInt();
			System.out.println(f[n-1]);
		}
	}

}
