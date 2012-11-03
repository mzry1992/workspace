import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws IOException
	{		
		Scanner cin = new Scanner(System.in);
		BigInteger Num,Res,a,b,c,jx;
		String ts,sRes;
		jx = new BigInteger("999999999999999");
		int t;
		t = cin.nextInt();
		ts = cin.nextLine();
		for (int ft = 1;ft <= t;ft++)
		{
			ts = cin.nextLine();
			Num = new BigInteger(ts);
			a = Num.pow(8);
			b = Num.pow(4);
			c = Num.pow(2);
			b = b.multiply(BigInteger.valueOf(17));
			c = c.multiply(BigInteger.valueOf(6));
			Res = BigInteger.valueOf(0);
			Res = Res.add(a);
			Res = Res.add(b);
			Res = Res.add(c);
			Res = Res.divide(BigInteger.valueOf(24));
			sRes = String.valueOf(Res);
			System.out.print("Case "+ft+": ");
			if (Res.compareTo(jx) == 1)
			{
				int l = sRes.length();
				System.out.println(sRes.substring(l-15,l));
			}
			else
			{
				System.out.println(sRes);
			}
		}
	}
}
