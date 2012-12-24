import java.io.*;
import java.util.*;
import java.math.*;

public class Main {

	/**
	 * @param args
	 */
	static int[] f = new int[110];
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int n,m;
		String buf;
		int[] p = new int[110];
		String[] tmp = new String[110];
		int totp;
		Boolean[][] ma = new Boolean[110][110];
		Boolean[][] mb = new Boolean[110][110];
		int[] ina = new int[110];
		int[] inb = new int[110];
		int[] outa = new int[110];
		int[] outb = new int[110];
		Boolean[] del = new Boolean[110];
		
		while (cin.hasNext())
		{
			n = cin.nextInt();
			if (n == 0)	break;
			buf = cin.nextLine();
			
			for (int i = 0;i < n;i++)
				for (int j = 0;j < n;j++)
					ma[i][j] = mb[i][j] = false;
			for (int i = 0;i < n;i++)
			{
				del[i] = false;
				ina[i] = inb[i] = outa[i] = outb[i] = 0;
				f[i] = i;
			}
			
			totp = cin.nextInt()+1;
			for (int i = totp-1;i >= 0;i--)
				p[i] = cin.nextInt();
			for (int i = 0;i < n;i++)
			{
				int res = 0,mutx = 1;
				for (int j = 0;j < totp;j++)
				{
					res = (res+mutx*p[j])%n;
					mutx = (mutx*i)%n;
				}
				ma[i][res] = true;
				ina[res]++;
				outa[i]++;
			}
			
			totp = cin.nextInt()+1;
			for (int i = totp-1;i >= 0;i--)
				p[i] = cin.nextInt();
			for (int i = 0;i < n;i++)
			{
				int res = 0,mutx = 1;
				for (int j = 0;j < totp;j++)
				{
					res = (res+mutx*p[j])%n;
					mutx = (mutx*i)%n;
				}
				mb[i][res] = true;
				inb[res]++;
				outb[i]++;
			}
			
			while (true)
			{
				int pos = -1;
				
				for (int i = 0;i < n;i++)
					if (del[i] == false)
					{
						if (ina[i] == 0 || inb[i] == 0)
						{
							pos = i;
							break;
						}
					}
				
				if (pos != -1)
				{
					del[pos] = true;
					for (int i = 0;i < n;i++)
					{
						if (ma[pos][i])
						{
							ma[pos][i] = false;
							ina[i]--;
							outa[pos]--;
						}
						if (ma[i][pos])
						{
							ma[i][pos] = false;
							ina[pos]--;
							outa[i]--;
						}
						if (mb[pos][i])
						{
							mb[pos][i] = false;
							inb[i]--;
							outb[pos]--;
						}
						if (mb[i][pos])
						{
							mb[i][pos] = false;
							inb[pos]--;
							outb[i]--;
						}
					}
				}
				else
					break;
			}
			
			for (int i = 0;i < n;i++)
				for (int j = 0;j < n;j++)
				{
					ma[j][i] |= ma[i][j];
					mb[j][i] |= mb[i][j];
				}
			
			for (int i = 0;i < n;i++)
				for (int j = 0;j < n;j++)
					ma[i][j] |= mb[i][j];
			
			/*for (int i = 0;i < n;i++)
			{
				for (int j = 0;j < n;j++)
					System.out.print(ma[i][j]+" ");
				System.out.println();
			}*/
			
			for (int i = 0;i < n;i++)
				for (int j = 0;j < n;j++)
					if (ma[i][j] == true)
					{
						int fi = findf(i);
						int fj = findf(j);
						f[fi] = fj;
					}
			int res = 0;
			for (int i = 0;i < n;i++)
				if (findf(i) == i && del[i] == false)
					res++;
			System.out.println(BigInteger.ONE.shiftLeft(res));
			
		}
	}

	private static int findf(int i) {
		// TODO Auto-generated method stub
		if (f[i] != i)	f[i] = findf(f[i]);
		return f[i];
	}

	private static int String2int(String str) {
		// TODO Auto-generated method stub
		int res = 0;
		for (int i = 0;i < str.length();i++)
			res = res*10+(int)(str.charAt(i)-'0');
		return res;
	}

}
