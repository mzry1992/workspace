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
		int n;
		String a,b;
		BigInteger ta,tb,tc;
		while (true)
		{
			n = cin.nextInt();
			if (n == 0)
				break;
			a = cin.next();
			b = cin.next();
			ta = new BigInteger(a,n);
			tb = new BigInteger(b,n);
			tc = ta.mod(tb);
			System.out.println(tc.toString(n));
		}
	}
}
