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
		int n;
		BigInteger a,mut;
		while (cin.hasNext())
		{
			n = cin.nextInt();
			a = mut = BigInteger.valueOf(2);
			for (int i = 1;i <= n;i++)
			{
				System.out.println(a);
				a = mut.add(BigInteger.ONE);
				mut = mut.multiply(a);
			}
		}
	}

}
