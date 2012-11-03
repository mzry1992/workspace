import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws IOException
	{
		Scanner cin = new Scanner(System.in);
		BigInteger n,l,r;
		BigInteger mid,temp,powe;
		BigInteger mid2,powe2;
		String s;
		while (true)
		{
			s = cin.next();
			if (s.charAt(0) == '#')
				break;
			n = new BigInteger(s);
			l = new BigInteger("0");
			r = n;
			while (true)
			{
				temp = l.add(r);
				mid = temp.divide(new BigInteger("2"));
				mid2 = mid.add(new BigInteger("1"));
				powe = mid.multiply(mid);
				powe2 = mid2.multiply(mid2);
				int cc1 = powe.compareTo(n);
				int cc2 = powe2.compareTo(n);
				if (cc1 == 1)
					r = mid;
				else if (cc1 == -1)
					l = mid;
				if (cc1 == 0)
					cc1 = -1;
				if (cc2 == 0)
					cc2 = 1;
				if (powe.equals(n))
				{			
					System.out.println(mid.toString(2));
					break;
				}
				if (powe2.equals(n))
				{			
					System.out.println(mid2.toString(2));
					break;
				}
				if ((cc1 == -1) && (cc2 == 1))
				{			
					System.out.println(mid.toString(2));
					break;
				}
			}

		}
	}
}
