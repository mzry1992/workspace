import java.io.*;
import java.util.*;
import java.math.*;

public class Main {

	/**
	 * @param args
	 */
	private static int bel[] = new int[150];
	private static int state[] = new int[150];
	private static int low[] = new ;
	private static int id[];
	
	public static void main(String[] args) throws IOException
	{
		// TODO Auto-generated method stub
		int u,t,clr;
		clr = dfs(u,t);
	}

	private static int dfs(int u, int t) {
		// TODO Auto-generated method stub
		low[u] = id[u] = t++;
		state[u] = 1;
		return 0;
	}
}
