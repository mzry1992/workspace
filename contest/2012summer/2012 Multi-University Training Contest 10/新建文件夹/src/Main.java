import java.io.*;
import java.util.*;
import java.math.*;

public class Main {

	static boolean[] isPrime = new boolean[1000];
	static int[] prime = new int[1000];
	static int L;
	static BigInteger goal;
	static long maxfactors;
	static BigInteger minnum;
	static int maxpos;
	static BigInteger[] preMult = new BigInteger[45];
	/**
	 * @param args
	 */
	
	public static void main(String[] args){
		// TODO Auto-generated method stub
		getPrime();
		
		try {
			PrintStream cout = new PrintStream("A.txt");
			cout.println("fuckaa");
			goal = BigInteger.valueOf(1);
			for (int i = 1;i <= 80;i++)
				goal = goal.multiply(BigInteger.valueOf(10));
			while (true)
			{
				maxfactors = 0;
				DFS(BigInteger.ONE,1,0,16);
				
				cout.println(minnum+" "+maxfactors);
				System.out.println(minnum+" "+maxfactors);
				
				goal = minnum.add(BigInteger.ONE.negate());
				
				if (goal.equals(BigInteger.ZERO))	break;
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		/*Scanner cin = new Scanner(System.in);
		while (cin.hasNext())
		{
			goal = cin.nextBigInteger();
			maxfactors = 0;
			DFS(BigInteger.ONE,1,0,16);
			System.out.println(minnum+" "+maxfactors);
		}*/
	}
	
	private static void DFS(BigInteger num, long factors, int pos,int last) {
		// TODO Auto-generated method stub
		if (num.multiply(BigInteger.valueOf(prime[pos])).compareTo(goal) > 0)
		{
			if (factors > maxfactors || (factors == maxfactors && num.compareTo(minnum) < 0))
			{
				minnum = num;
				maxfactors = factors;
			}
			return;
		}
		int cnt = 0;
		BigInteger tmp = num;
		while (true)
		{
			tmp = tmp.multiply(BigInteger.valueOf(prime[pos]));
			if (tmp.compareTo(goal) > 0)
				break;
			cnt++;
		}
		
		if (cnt <= 62)
		{
			if (maxfactors/factors > ((long)1<<cnt))
				return;
		}
		
		cnt = Math.min(cnt,last);
		long mut = 1;
		for (int i = 1;i <= (cnt+1)/2;i++)
		{
			mut *= prime[pos];
			if (mut > 256)	return;
		}
		
		for (int i = 1;i <= cnt;i++)
		{
			num = num.multiply(BigInteger.valueOf(prime[pos]));
			DFS(num,factors*(i+1),pos+1,i);
		}
	}

	private static void getPrime() {
		// TODO Auto-generated method stub
		for (int i = 2;i < 1000;i++)
			isPrime[i] = true;
		L = 0;
		for (int i = 2;i < 1000;i++)
			if (isPrime[i] == true)
			{
				for (int j = i+i;j < 1000;j += i)
					isPrime[j] = false;
				prime[L++] = i;
			}
	}

}
