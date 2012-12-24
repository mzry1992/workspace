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
		int base;
		String a,b,res;
		BigInteger na,nb,nc;
		while (cin.hasNext())
		{
			base = cin.nextInt();
			if (base == 0)	break;
			a = cin.next();
			b = cin.next();
			na = new BigInteger(a,base);
			nb = new BigInteger(b,base);
			nc = na.mod(nb);
			res = nc.toString(base);
			System.out.println(res);
		}
	}

}
