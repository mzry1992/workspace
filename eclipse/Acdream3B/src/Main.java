import java.util.*;
import java.math.*;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		int m = cin.nextInt();
		BigInteger ans = BigInteger.valueOf(24).multiply(calc(n)).multiply(calc(m)).mod(BigInteger.valueOf(1000000000+7));
		System.out.println(ans);
	}

	private static BigInteger calc(int n) {
		// TODO Auto-generated method stub
		BigInteger bn = BigInteger.valueOf(n);
		return bn.multiply(bn).divide(BigInteger.valueOf(4)).multiply(bn).divide(BigInteger.valueOf(2));
	}

}
