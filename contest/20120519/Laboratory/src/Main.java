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
		BigDecimal a,b,c,d;
		String sa,sb,sc,sd;
		while (cin.hasNext())
		{
			sa = cin.next();
			sb = cin.next();
			sc = cin.next();
			sd = cin.next();
			a = new BigDecimal(sa);
			b = new BigDecimal(sb);
			c = new BigDecimal(sc);
			d = new BigDecimal(sd);			
			
			a = a.setScale(20,BigDecimal.ROUND_UP);
			b = b.setScale(20,BigDecimal.ROUND_UP);
			c = c.setScale(20,BigDecimal.ROUND_UP);
			d = d.setScale(20,BigDecimal.ROUND_UP);
			
			BigDecimal p1,p2,q1,q2,res;
			if (a.multiply(d).compareTo(c.multiply(b)) >= 0)
	        {
				if (b.multiply(b).compareTo(a.multiply(d)) <= 0 &&
						c.multiply(c).compareTo(a.multiply(d)) <= 0)
	            {
	                p1 = new BigDecimal(1);
	                p2 = sqrt(d.divide(a,20,BigDecimal.ROUND_UP));
	                q1 = a;
	                q2 = sqrt(a.multiply(d));
	                res=a.add(d).add(BigDecimal.valueOf(2).multiply(sqrt(a.multiply(d))));
	            }
	            else if (c.compareTo(b) > 0)
	            {
	                p1 = new BigDecimal(1);
	                p2 = c.divide(a,20,BigDecimal.ROUND_UP);
	                q1 = a;
	                q2 = a.multiply(d).divide(c,20,BigDecimal.ROUND_UP);
	                res = a.add(d).add(c).add(a.multiply(d).divide(c,20,BigDecimal.ROUND_UP));
	            }
	            else
	            {
	                p1 = new BigDecimal(1);
	                p2 = d.divide(b,20,BigDecimal.ROUND_UP);
	                q1 = a;
	                q2 = b;
	                res = a.add(d).add(b).add(a.multiply(d).divide(b,20,BigDecimal.ROUND_UP));
	            }
	        }
	        else
	        {
	        	if (a.multiply(a).compareTo(b.multiply(c)) <= 0 &&
	        			d.multiply(d).compareTo(b.multiply(c)) <= 0)
	            {
	                p1 = new BigDecimal(1);
	                p2=sqrt(c.divide(b,20,BigDecimal.ROUND_UP));
	                q1=sqrt(b.multiply(c));
	                q2=b;
	                res = b.add(c).add(BigDecimal.valueOf(2).multiply(sqrt(b.multiply(c))));
	            }
	            else if (a.compareTo(d) > 0)
	            {
	                p1 = new BigDecimal(1);
	                p2 = c.divide(a,20,BigDecimal.ROUND_UP);
	                q1 = a;
	                q2 = b;
	                res = b.add(c).add(a).add(b.multiply(c).divide(a,20,BigDecimal.ROUND_UP));
	            }
	            else
	            {
	            	p1 = b.divide(d,20,BigDecimal.ROUND_UP);
	                p2 = new BigDecimal(1);
	                q1 = c;
	                q2 = d;
	                res = b.add(c).add(d).add(b.multiply(c).divide(d,20,BigDecimal.ROUND_UP));
	            }
	        }

			res = res.setScale(20,BigDecimal.ROUND_UP);
			p1 = p1.setScale(20,BigDecimal.ROUND_UP);
			p2 = p2.setScale(20,BigDecimal.ROUND_UP);
			q1 = q1.setScale(20,BigDecimal.ROUND_UP);
			q2 = q2.setScale(20,BigDecimal.ROUND_UP);
			
			System.out.println(res);
			System.out.println(p1+" "+p2+" "+q1+" "+q2);
		}
	}

	private static BigDecimal sqrt(BigDecimal x) {
		// TODO Auto-generated method stub
		BigDecimal l,r,mid;
		l = new BigDecimal(0);
		r = x;
		if (x.compareTo(BigDecimal.ONE) < 0)
			r = BigDecimal.ONE;
		for (int tims = 0;tims <= 100;tims++)
		{
			mid = l.add(r).divide(BigDecimal.valueOf(2),20,BigDecimal.ROUND_UP);
			//System.out.println(x+" "+mid+" "+mid.multiply(mid));
			if (mid.multiply(mid).compareTo(x) < 0)
				l = mid;
			else
				r = mid;
		}
		return l.setScale(20,BigDecimal.ROUND_UP);
	}

}
