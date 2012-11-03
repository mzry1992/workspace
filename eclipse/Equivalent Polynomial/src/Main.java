import java.io.*;
import java.util.*;
import java.math.*;

public class Main {

	/**
	 * @param args
	 */
	public static class poly
	{
		BigInteger a[] = new BigInteger[500];
		int len;
	}
	
	public static void main(String[] args) throws IOException
	{
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int n,t;
		poly pa,pb,xt,xk;
		while (cin.hasNext())
		{
			n = cin.nextInt();
			t = cin.nextInt();
			pa = setzero(300);
			pa.len = n;
			for (int i = 0;i <= n;i++)
				pa.a[i] = cin.nextBigInteger();
			xt = setzero(300);
			xt.len = 1;
			xt.a[0] = BigInteger.valueOf(t);
			xt.a[1] = BigInteger.valueOf(1);
			xk = setzero(300);
			xk.len = 0;
			xk.a[0] = BigInteger.valueOf(1);
			pb = setzero(300);
			pb.len = 0;
			pb.a[0] = BigInteger.valueOf(0);
			for (int i = 0;i <= n;i++)
			{
				pb = add(pb,mult(xk,cons(pa.a[i])));
				xk = mult(xk,xt);
			}
			for (int i = 0;i < n;i++)
				System.out.print(pb.a[i].toString()+' ');
			System.out.println(pb.a[n].toString());
		}
	}

	private static poly setzero(int len) {
		// TODO Auto-generated method stub
		poly res;
		res = new poly();
		res.len = 0;
		for (int i = 0;i < len;i++)
			res.a[i] = BigInteger.ZERO;
		return res;
	}

	private static poly add(poly a, poly b) {
		// TODO Auto-generated method stub
		int la = a.len;
		int lb = b.len;
		poly res;
		res = setzero(300);
		res.len = max(la,lb);
		for (int i = 0;i <= res.len;i++)
			res.a[i] = a.a[i].add(b.a[i]);
		return res;
	}

	private static int max(int a, int b) {
		// TODO Auto-generated method stub
		if (a > b)	return a;
		return b;
	}

	private static poly mult(poly a, poly b) {
		// TODO Auto-generated method stub
		int la = a.len;
		int lb = b.len;
		poly res;
		res = setzero(300);
		res.len = la+lb;
		for (int i = 0;i <= la;i++)
			for (int j = 0;j <= lb;j++)
				res.a[i+j] = res.a[i+j].add(a.a[i].multiply(b.a[j]));
		return res;
	}

	private static poly cons(BigInteger val) {
		// TODO Auto-generated method stub
		poly res;
		res = new poly();
		res.len = 0;
		res.a[0] = val;
		return res;
	}
}
