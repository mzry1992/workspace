import java.io.*;
import java.util.*;
import java.math.*;

public class Main {

	/**
	 * @param args
	 */
	private static int n,m,k;
	private static boolean[][] map = new boolean[200][200];
	private static int sgt;
	private static int[] sgout = new int[200];
	private static int[] sgsort = new int[200];
	private static boolean[] use = new boolean[200];
	private static int[] sc = new int[200];
	private static int sct;
	private static int[] scin = new int[200];
	private static int[] scout = new int[200];
	private static int[] sccount = new int[200];
	private static BigInteger[][] dp = new BigInteger[200][200];
	private static BigInteger[] indp = new BigInteger[200];
	private static BigInteger[] outdp = new BigInteger[200];
	private static BigInteger[] dp0 = new BigInteger[200];
	private static BigInteger[][] cc = new BigInteger[200][200];
	
	public static void main(String[] args) throws IOException
	{
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
        for (int i = 0;i <= 150;i++)
        	for (int j = 0;j <= 150;j++)
        		cc[i][j] = BigInteger.valueOf(0);
        cc[0][0] = BigInteger.valueOf(1);
        for (int i = 1;i <= 150;i++)
        {
        	cc[i][0] = BigInteger.valueOf(1);
        	for (int j = 1;j <= i;j++)
        		cc[i][j] = cc[i-1][j-1].add(cc[i-1][j]);
        }        
		while (cin.hasNext())
	    {
			n = cin.nextInt();
			m = cin.nextInt();
			k = cin.nextInt();
			for (int i = 1;i <= n;i++)
				for (int j = 1;j <= n;j++)
					map[i][j] = false;
			for (int i = 1;i <= m;i++)
			{
				int u,v;
				u = cin.nextInt();
				v = cin.nextInt();
				map[u][v] = true;
			}
			sgt = 0;
			for (int i = 1;i <= n;i++)
				use[i] = false;
			for (int i = 1;i <= n;i++)
				if (use[i] == false)
					DFS_1(i);
			for (int i = 1;i <= n;i++)
				sgsort[sgout[i]] = i;
			for (int i = 1;i <= n;i++)
				use[i] = false;
	        sct = 0;
	        for (int i = n;i >= 1;i--)
	        if (use[sgsort[i]] == false)
	        {
	            sct++;
	            DFS_2(sgsort[i]);
	        }
	        int[] sc0 = new int[200];
	        int sc0t;
	        int totin0,totout0,tot0;
	        totin0 = totout0 = tot0 = 0;
	        for (int i = 1;i <= sct;i++)
	        	scout[i] = scin[i] = sccount[i] = 0;
	        for (int i = 1;i <= n;i++)
	            sccount[sc[i]]++;
	        for (int i = 1;i <= n;i++)
	        for (int j = 1;j <= n;j++)
	        if (sc[i] != sc[j])
	        if (map[i][j] == true)
	        {
	            scin[sc[j]]++;
	            scout[sc[i]]++;
	        }
	        
	        /*
	        for (int i = 1;i <= n;i++)
	        	System.out.print(sgout[i]+" ");
	        System.out.println();
	        for (int i = 1;i <= n;i++)
	        	System.out.print(sc[i]+" ");
	        System.out.println();
	        */
	        
	        for (int i = 0;i <= n;i++)
	        	for (int j = 0;j <= k;j++)
	        		dp[i][j] = BigInteger.valueOf(0);
	        sc0t = 0;
	        for (int i = 1;i <= sct;i++)
	        if (scin[i] == 0)
	        if (scout[i] != 0)
	        {
	            sc0t++;
	            sc0[sc0t] = i;
	            totin0 += sccount[i];
	        }        
	        dp[0][0] = BigInteger.valueOf(1);
	        for (int i = 1;i <= sc0t;i++)
	            for (int j = i;j <= k;j++)
	            {
	                dp[i][j] = BigInteger.valueOf(0);
	                for (int q = 1;q <= sccount[sc0[i]]&&j-q>=i-1;q++)
	                    dp[i][j] = dp[i][j].add(dp[i-1][j-q].multiply(cc[sccount[sc0[i]]][q]));
	            }
	        for (int i = 0;i <= k;i++)
	        	indp[i] = dp[sc0t][i];
	        
	        int sin = sc0t;
	        for (int i = 0;i <= n;i++)
		        	for (int j = 0;j <= k;j++)
		        		dp[i][j] = BigInteger.valueOf(0);
	        sc0t = 0;
	        for (int i = 1;i <= sct;i++)
		        if (scout[i] == 0)
		        if (scin[i] != 0)
		        {
		            sc0t++;
		            sc0[sc0t] = i;
		            totout0 += sccount[i];
		        } 
	        dp[0][0] = BigInteger.valueOf(1);
	        for (int i = 1;i <= sc0t;i++)
	        	for (int j = i;j <= k;j++)
	        	{
	        		dp[i][j] = BigInteger.valueOf(0);
	        		for (int q = 1;q <= sccount[sc0[i]]&&j-q>=i-1;q++)
	        			dp[i][j] = dp[i][j].add(dp[i-1][j-q].multiply(cc[sccount[sc0[i]]][q]));
	        	}
	        for (int i = 0;i <= k;i++)
	        	outdp[i] = dp[sc0t][i];
	        int sout = sc0t;
	        
	        for (int i = 0;i <= n;i++)
	        	for (int j = 0;j <= k;j++)
	        		dp[i][j] = BigInteger.valueOf(0);
	        sc0t = 0;
	        for (int i = 1;i <= sct;i++)
	        	if (scin[i] == 0)
	        		if (scout[i] == 0)
	        		{
	        			sc0t++;
	        			sc0[sc0t] = i;
	        			tot0 += sccount[i];
	        		}	        
	        dp[0][0] = BigInteger.valueOf(1);
	    	        for (int i = 1;i <= sc0t;i++)
	    	        	for (int j = i;j <= k;j++)
	    	        	{
	    	        		dp[i][j] = BigInteger.valueOf(0);
	    	        		for (int q = 1;q <= sccount[sc0[i]]&&j-q>=i-1;q++)
	    	        			dp[i][j] = dp[i][j].add(dp[i-1][j-q].multiply(cc[sccount[sc0[i]]][q]));
	    	        	}
	    	        for (int i = 0;i <= k;i++)
	    	        	dp0[i] = dp[sc0t][i];
	    	/*
	    	for (int i = 0;i <= k;i++)
	    		System.out.println(indp[i]+" "+outdp[i]+" "+dp0[i]);
	    		*/
	    	int s0 = sc0t;
	    	
	        BigInteger ans;
	        ans = BigInteger.valueOf(0);
	        for (int i = sin;i <= k;i++)
	        	for (int j = sout;i+j <= k;j++)
	        		for (int p = s0;i+j+p <= k;p++)
	        	{
	        		int tl,tk;
	        		tl = n-totin0-totout0-tot0;
	        		tk = k-i-j-p;
	        		ans = ans.add(indp[i].multiply(outdp[j]).multiply(dp0[p]).multiply(cc[tl][tk]));
	        	}
	        System.out.println(ans);
	        System.out.println();
	    }
	}

	private static void DFS_2(int now) {
		// TODO Auto-generated method stub
	    use[now] = true;
	    sc[now] = sct;
	    for (int i = 1;i <= n;i++)
	    if (use[i] == false)
	    if (map[i][now] == true)
	        DFS_2(i);
	}

	private static void DFS_1(int now) {
		// TODO Auto-generated method stub
	    use[now] = true;
	    for (int i = 1;i <= n;i++)
	    if (use[i] == false)
	    if (map[now][i] == true)
	        DFS_1(i);
	    sgt++;
	    sgout[now] = sgt;
	}
}