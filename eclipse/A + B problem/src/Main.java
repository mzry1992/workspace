import java.io.*;
import java.util.*;
import java.math.*;

public class Main {

	/**
	 * @param args
	 */
	static int n,tn;
	static BigInteger a[] = new BigInteger[16];
	static BigInteger val[][] = new BigInteger[16][16];
	static int len[][] = new int[16][16];
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext())
		{
			tn = n = cin.nextInt();
			for (int i = 0;i < n;i++)
				a[i] = cin.nextBigInteger();
			for (int i = 0;i < n;i++)
				for (int j = 0;j < n;j++)
					if (i != j)
						if (ainb(a[i],a[j]) == true)
						{
							BigInteger tmp = a[i];
							a[i] = a[n-1];
							a[n-1] = tmp;
							n--;
						}
			for (int i = 0;i < n;i++)
				for (int j = 0;j < n;j++)
					if (i != j)
						Gao(i,j);
			for (int i = 0;i < n;i++)
				for (int j = 0;j < n;j++)
					if (i != j)
						System.out.println(i+" "+j+" a[i] = "+a[i]+" a[j] = "+a[j]+" Len = "+len[i][j]+" Val = "+val[i][j]);
		}
	}

	private static void Gao(int x, int y) {
		// TODO Auto-generated method stub
		BigInteger tmpa,tmpb;
		tmpa = a[x];
		tmpb = a[y];
		int lena,lenb;
		lena = tmpa.bitLength();
		lenb = tmpb.bitLength();
		for (int i = 1;i < lenb;i++)
		{
			BigInteger tb = tmpb.shiftRight(i);
			BigInteger ta = tmpa;
			for (int j = lenb-i;j < lena;j++)
				ta = ta.clearBit(j);
			if (tb.compareTo(ta) == 0)
			{
				len[x][y] = lena-(lenb-i);
				tb = tmpb;
				for (int j = i;j < lenb;j++)
					tb = tb.clearBit(j);
				val[x][y] = tmpa.shiftRight(lenb-i);
				return;
			}
		}
		len[x][y] = lena;
		val[x][y] = tmpa;
	}

	private static boolean ainb(BigInteger a, BigInteger b) {
		// TODO Auto-generated method stub
		if (a.bitLength() > b.bitLength())return false;
		for (int i = 0;i <= b.bitLength()-a.bitLength();i++)
		{
			BigInteger tmpb = b.shiftRight(b.bitLength()-a.bitLength()-i);
			for (int j = a.bitLength();j < tmpb.bitLength();j++)
				tmpb = tmpb.clearBit(j);
			if (tmpb.compareTo(a) == 0)	return true;
		}
		return false;
	}

}
