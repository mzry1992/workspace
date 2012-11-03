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
		int t;
		t = cin.nextInt();
		BigInteger a,b,c,d;
		b = new BigInteger("3");
		c = new BigInteger("11");
		d = new BigInteger("0");
		for (int ft = 1;ft <= t;ft++)
		{
			a = cin.nextBigInteger();
			if (a.mod(b).compareTo(d) == 0)
				System.out.print("yes ");
			else
				System.out.print("no ");
			if (a.mod(c).compareTo(d) == 0)
				System.out.println("yes");
			else
				System.out.println("no");
		}
	}

}
