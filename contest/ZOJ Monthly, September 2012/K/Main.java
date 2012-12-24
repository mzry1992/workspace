import java.io.*;
import java.util.*;
import java.math.*;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int[] oper = new int[1000];
		int totoper;
		String s;
		String[] num;
		BigInteger resa,resb,nine;
		nine = BigInteger.valueOf(9);
		while (cin.hasNext())
		{
			s = cin.next();
			
			resa = cin.nextBigInteger();
			resb = cin.nextBigInteger();
			
			if (resa.compareTo(nine) == 0)
			{
				System.out.println("A");
				continue;
			}
			if (resb.compareTo(nine) == 0)
			{
				System.out.println("B");
				continue;
			}
			
			totoper = 0;
			for (int i = 0;i < s.length();i++)
				if (s.charAt(i) == '+')
					oper[totoper++] = 1;
				else if (s.charAt(i) == '-')
					oper[totoper++] = -1;
			
			
			num = s.split("[+-]");
			
			BigInteger res = new BigInteger(num[0]);
				
			for (int i = 1;i < num.length;i++)
			{
				BigInteger val = new BigInteger(num[i]);
				if (oper[i-1] == 1)
					res = res.add(val);
				else
					res = res.add(val.negate());
			}
			
			if (resa.compareTo(res) != 0)
				System.out.println("A");
			else
				System.out.println("B");
		}
	}

}
