import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
	static BigInteger Nu[];
	public static void main(String[] args) throws IOException
	{
		Scanner cin = new Scanner(System.in);
		Nu = new BigInteger[15];
		int i,j;
		for (i = 1;i <= 10;i++)
			Nu[i] = BigInteger.valueOf(1);
		while (cin.hasNext())
		{
			String ts = cin.nextLine();
			i = ts.charAt(0)-'A'+1;
			if (ts.charAt(1) == '=')
			{
				j = ts.charAt(2)-'A'+1;
				Nu[i] = Nu[j];
			}
			else
			{
				j = ts.charAt(3)-'A'+1;
				if (ts.charAt(1) == '+')
					Nu[i] = Nu[i].add(Nu[j]);
				else
					Nu[i] = Nu[i].multiply(Nu[j]);
			}
		}
		for (i = 1;i <= 10;i++)
			System.out.println(Nu[i]);
	}
}