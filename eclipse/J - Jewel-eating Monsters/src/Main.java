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
		BigInteger x,a,n,c,res1,res2,res3,res4;
		while (true)
		{
			x = cin.nextBigInteger();
			a = cin.nextBigInteger();
			n = cin.nextBigInteger();
			c = cin.nextBigInteger();
			if (x.compareTo(BigInteger.ZERO) == 0)	break;
			res1 = (x.multiply(a.modPow(n, c))).mod(c);
			res2 = (a.add(BigInteger.ONE.negate())).multiply(c);
			System.out.println(a+" "+a.modPow(n, res2).add(BigInteger.ONE.negate())+" "+res2);
			BigInteger res22 = ((a.multiply(a.modPow(n, res2).add(BigInteger.ONE.negate()))).mod(res2));
			res3 = res22.divide(a.add(BigInteger.ONE.negate()));
			res4 = (res1.add(res3.negate()).add(c)).mod(c);
	        System.out.println(res1+" "+res2+" "+res22+" "+res3+" "+res4);
		}
	}

}
