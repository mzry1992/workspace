import java.io.*;
import java.util.*;
import java.math.*;

public class Main {

	/**
	 * @param args
	 */
	static BigInteger[] res = new BigInteger[501];
	static int totres;
	static String now;
	static int totline;
	static BigInteger ten;
	static BigInteger[] num = new BigInteger[10];
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		totline = cin.nextInt();
		totres = 0;
		ten = BigInteger.valueOf(10);
		for (int i = 0;i < 10;i++)
			num[i] = BigInteger.valueOf(i);
		for (int i = 0;i < totline;i++)
		{
			now = cin.next();
			for (int j = 0;j < now.length();)
			{
				if (now.charAt(j) >= '0' && now.charAt(j) <= '9')
				{
					res[totres] = BigInteger.valueOf(0);
					for (int k = j;;k++)
						if (k < now.length() && now.charAt(k) >= '0' && now.charAt(k) <= '9')
						{
							res[totres] = res[totres].multiply(ten).add(num[now.charAt(k)-'0']);
						}
						else
						{
							totres++;
							j = k;
							break;
						}
				}
				else
					j++;
			}
		}
		for (int i = 0;i < totres;i++)
			for (int j = i+1;j < totres;j++)
				if (res[i].compareTo(res[j]) > 0)
				{
					ten = res[i];
					res[i] = res[j];
					res[j] = ten;
				}
		for (int i = 0;i < totres;i++)
			System.out.println(res[i]);
	}

}
