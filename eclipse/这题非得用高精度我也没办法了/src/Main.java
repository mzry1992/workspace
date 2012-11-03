import java.io.*;
import java.util.*;
import java.math.*;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException
	{
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		BigInteger n,m,gcd;
		boolean first = true;
		while (cin.hasNext())
		{
			if (!first)
				System.out.println();
			first = false;
			n = cin.nextBigInteger();
			m = cin.nextBigInteger();
			gcd = n.gcd(m);
			System.out.println(gcd.toString());
		}
	}

}
