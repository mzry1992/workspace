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
		BigInteger a,b;
		int t = cin.nextInt();
		for (int ft = 1;ft <= t;ft++)
		{
			a = cin.nextBigInteger();
			b = cin.nextBigInteger();
			System.out.println("Case "+ft+": "+a.add(b.negate()));
		}
	}

}
