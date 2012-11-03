import java.io.*;
import java.util.*;

public class Main {

	/**
	 * @param args
	 */
	static double[] x = new double[50000];
	static double[] w = new double[50000];
	static int n;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int totcas = cin.nextInt();
		for (int cas = 1;cas <= totcas;cas++)
		{
			n = cin.nextInt();
			for (int i = 0;i < n;i++)
			{
				x[i] = cin.nextDouble();
				w[i] = cin.nextDouble();
			}
			double l = -1000000,r = 1000000,mid1,mid2;
			for (int times = 1;times <= 60;times++)
			{
				mid1 = l+(r-l)/3.0;
				mid2 = r-(r-l)/3.0;
				if (calc(mid1) < calc(mid2))
					r = mid2;
				else
					l = mid1;
			}
			System.out.println("Case #"+cas+": "+Math.round(calc(l)));
		}
	}

	private static double calc(double pos) {
		// TODO Auto-generated method stub
		double res = 0;
		for (int i = 0;i < n;i++)
			res += xxx(Math.abs(pos-x[i]))*w[i];
		return res;
	}

	private static double xxx(double x) {
		// TODO Auto-generated method stub
		return x*x*x;
	}

}
