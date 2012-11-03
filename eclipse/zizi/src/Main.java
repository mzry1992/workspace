import java.math.*;
import java.util.*;

public class Main {

	static BigInteger N;
	static int M;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n,m;
		Scanner cin=new Scanner(System.in);
		n=cin.nextInt();
		m=cin.nextInt();
	    N=BigInteger.ONE.shiftLeft(n).add(BigInteger.ONE.negate());
	    M=m;
	    BigInteger l=BigInteger.ZERO,r=N.multiply(N);
	    while (l.compareTo(r)<0)
	    {
	        BigInteger mid=l.add(r).shiftRight(1);
	        if (check(mid))
	            r=mid;
	        else
	            l=mid.add(BigInteger.ONE);
	    }
	    System.out.println(l);
	}
	private static boolean check(BigInteger x) {
		int i;
		BigInteger j;
	    for (i=0,j=BigInteger.ZERO;i<M && j.compareTo(N)<0;i++)
	    {
	        BigInteger l=j,r=N;
	        while (l.compareTo(r)<0)
	        {
	            BigInteger mid=l.add(r).add(BigInteger.ONE).shiftRight(1);
	            if (get(mid).add(get(j).negate()).compareTo(x)<=0)
	                l=mid;
	            else
	                r=mid.add(BigInteger.ONE.negate());
	        }
	        if (l==j) return false;
	        j=l;
	    }
	    if (j.compareTo(N)<0) return false;
	    else return true;
	}
	private static BigInteger get(BigInteger x) {
		BigInteger ret=BigInteger.ZERO;
	    for (BigInteger i=BigInteger.ONE;i.compareTo(x)<=0;i=i.shiftLeft(1))
	    	ret = ret.add(x.divide(i.shiftLeft(1)).multiply(i)).add(max(BigInteger.ZERO,x.mod(i.shiftLeft(1)).add(i.negate()).add(BigInteger.ONE)));
	    return ret;
	}
	private static BigInteger max(BigInteger x, BigInteger y) {
		if (x.compareTo(y)<=0) return y;
		else return x;
	}

}
