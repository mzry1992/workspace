import java.io.*;
import java.util.*;
import java.math.*;

public class Main {

	/**
	 * @param args
	 */
	static int n, m, tot;
	static BigInteger times;
	static String[] mp = new String[300];
	static int[][] a = new int[300][300];
	static int[] addtime = new int[300 * 300];
	static int[] newpos = new int[300 * 300];
	static int[] pos = new int[300 * 300];
	static int[] ppos = new int[300 * 300];
	static int[] num = new int[300 * 300];
	static int[] pnum = new int[300 * 300];
	static int mod = 100000;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Boolean first = true;
		Scanner cin = new Scanner(System.in);
		
		while (cin.hasNext()) {
		
			times = cin.nextBigInteger();
			n = cin.nextInt();
			System.out.println(times.divide(BigInteger.valueOf(n))+" "+times.mod(BigInteger.valueOf(n)));
			continue;
//			
//			if (!first)
//				System.out.println();
//			first = false;
//			
//			n = cin.nextInt();
//			m = cin.nextInt();
//			tot = n * m;
//			n--;
//			m--;
//			times = cin.nextBigInteger();
//
//			for (int i = 0; i < n; i++)
//				mp[i] = cin.next();
//
//			for (int i = 0; i <= n; i++)
//				for (int j = 0; j <= m; j++) {
//					a[i][j] = i * (m + 1) + j;
//					addtime[a[i][j]] = 0;
//				}
//
//			for (int i = 0; i < n; i++)
//				for (int j = 0; j < m; j++) {
//					addtime[a[i][j]]++;
//					if (addtime[a[i][j]] >= mod)
//						addtime[a[i][j]] -= mod;
//
//					if (mp[i].charAt(j) == 'R')
//						Rotate(i, j);
//					else if (mp[i].charAt(j) == 'L')
//						rRotate(i, j);
//				}
//			for (int i = 0; i <= n; i++)
//				for (int j = 0; j <= m; j++)
//					newpos[i * (m + 1) + j] = a[i][j];
//
//			for (int i = 0; i < tot; i++) {
//				pos[i] = i;
//				num[i] = 0;
//				pnum[i] = addtime[i];
//				ppos[i] = newpos[i];
//			}
//			int xx = times.mod(BigInteger.valueOf(n * m)).intValue();
//			times = times.divide(BigInteger.valueOf(n * m));
//
//			while (times.compareTo(BigInteger.ZERO) > 0) {
//				if (times.and(BigInteger.ONE).compareTo(BigInteger.ONE) == 0) {
//					for (int i = 0; i < tot; i++) {
//						num[i] += pnum[pos[i]];
//						if (num[i] >= mod)
//							num[i] -= mod;
//						pos[i] = ppos[pos[i]];
//					}
//				}
//				for (int i = 0; i < tot; i++) {
//					newpos[i] = ppos[ppos[i]];
//					addtime[i] = pnum[i] + pnum[ppos[i]];
//					if (addtime[i] >= mod)
//						addtime[i] -= mod;
//				}
//				for (int i = 0; i < tot; i++) {
//					ppos[i] = newpos[i];
//					pnum[i] = addtime[i];
//				}
//				times = times.shiftRight(1);
//			}
//
//			for (int i = 0; i <= n; i++)
//				for (int j = 0; j <= m; j++)
//					a[i][j] = pos[i * (m + 1) + j];
//
//			for (int i = 0; i < n && xx > 0; i++)
//				for (int j = 0; j < m && xx > 0; j++) {
//					num[a[i][j]]++;
//					if (num[a[i][j]] >= mod)
//						num[a[i][j]] -= mod;
//					if (mp[i].charAt(j) == 'R')
//						Rotate(i, j);
//					else if (mp[i].charAt(j) == 'L')
//						rRotate(i, j);
//					xx--;
//				}
//
//			for (int i = 0; i < tot; i++)
//				System.out.println(num[i]);
		}
	}

	private static void rRotate(int i, int j) {
		// TODO Auto-generated method stub
		int tmp = a[i][j];
		a[i][j] = a[i][j + 1];
		a[i][j + 1] = a[i + 1][j + 1];
		a[i + 1][j + 1] = a[i + 1][j];
		a[i + 1][j] = tmp;
	}

	private static void Rotate(int i, int j) {
		// TODO Auto-generated method stub
		int tmp = a[i][j];
		a[i][j] = a[i + 1][j];
		a[i + 1][j] = a[i + 1][j + 1];
		a[i + 1][j + 1] = a[i][j + 1];
		a[i][j + 1] = tmp;
	}

}
