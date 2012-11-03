import java.io.*;
import java.util.*;
import java.math.*;

public class Main {

	/**
	 * @param args
	 */
	static int n;
	static int a[] = new int[10010];
	static Boolean b[] = new Boolean[10010];
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int T = cin.nextInt();
		for (int ft = 1;ft <= T;ft++)
		{
			n = cin.nextInt();
			for (int i = 0;i < n;i++)
				a[i] = cin.nextInt();
			Boolean hasres = false;
			for (int i = 1;i <= n;i++)
				b[i] = false;
			for (int i = 0;i < n-1;i++)
			{
				if (i > 0)
					for (int j = 1;j < a[i];j++)
						if (a[i]*2-j<=n && ((b[j] == false && b[a[i]*2-j] == true) || (b[j] == true && b[a[i]*2-j] == false)))
						{
							hasres = true;
							break;
						}
				if (hasres == true)	break;
				b[a[i]] = true;
			}
			if (hasres == true)
				System.out.println("Y");
			else
				System.out.println("N");
		}
	}

}