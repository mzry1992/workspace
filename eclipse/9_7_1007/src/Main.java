import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws IOException
	{
		Scanner cin = new Scanner(System.in);
		long n;
		int k;
		while (cin.hasNext())
		{
			n = cin.nextLong();
			k = cin.nextInt();
			BigInteger a = BigInteger.valueOf(n);
			System.out.println(a.pow(k));
		}
	}
}
