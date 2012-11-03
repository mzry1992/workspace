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
		String op,n;
		BigInteger c;
		int b;
		while (cin.hasNext())
		{
			op = cin.next();
			b = cin.nextInt();
			n = cin.next();
			c = BigInteger.valueOf(Long.valueOf(n,b));
			if (op.charAt(0) == '~')	c = c.not();
			if (op.charAt(0) == '!')	
				if (c.compareTo(BigInteger.ZERO) == 0)
					c = BigInteger.ONE;
				else
					c = BigInteger.ZERO;
			if (op.charAt(0) == '-')	c = c.negate();
			System.out.println(c);
		}
	}

}
