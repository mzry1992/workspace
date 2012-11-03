import java.io.*;
import java.util.*;
import java.math.*;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BigInteger a,b,res,now,nowstep,totstep,next,nextstep;
		Set<BigInteger> hash = new HashSet<BigInteger>();
		Queue<BigInteger> Q = new LinkedList<BigInteger>();
		Queue<BigInteger> Step = new LinkedList<BigInteger>();
		Scanner cin = new Scanner(System.in);
		while (true)
		{
			a = cin.nextBigInteger();
			b = cin.nextBigInteger();
			if (a.compareTo(BigInteger.ZERO) == 0 &&
					b.compareTo(BigInteger.ZERO) == 0)
						break;
			if (a.compareTo(b) <= 0)
				res = b.add(a.negate());
			else
			{
				res = a.add(b.negate());
				hash.clear();
				Q.clear();
				Q.add(a);
				Step.clear();
				Step.add(BigInteger.ZERO);
				hash.add(a);
				while (!Q.isEmpty())
				{
					now = Q.remove();
					nowstep = Step.remove();
					totstep = now.add(b.negate()).abs().add(nowstep);
					res = res.min(totstep);
					nextstep = nowstep.add(BigInteger.ONE);
					if (now.compareTo(b) < 0)	continue;
					if (now.and(BigInteger.ONE).compareTo(BigInteger.ZERO) == 0)
					{
						next = now.shiftRight(1);
						if (hash.contains(next) == false)
						{
							Q.add(next);
							hash.add(next);
							Step.add(nextstep);
						}
					}
					else
					{
						next = now.add(BigInteger.ONE);
						if (hash.contains(next) == false)
						{
							Q.add(next);
							hash.add(next);
							Step.add(nextstep);
						}
						next = now.add(BigInteger.ONE.negate());
						if (hash.contains(next) == false)
						{
							Q.add(next);
							hash.add(next);
							Step.add(nextstep);
						}
					}
				}
			}
			System.out.println(res);
		}
	}

}
