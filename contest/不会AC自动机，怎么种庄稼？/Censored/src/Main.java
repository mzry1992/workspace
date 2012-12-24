import java.io.*;
import java.util.*;
import java.math.*;
import java.nio.charset.Charset;

class Matrix {
	public BigInteger[][] a = new BigInteger[110][110];
	public int n;
	
	public Matrix(int _n) {
		n = _n;
		for (int i = 0;i < n;i++)
			for (int j = 0;j < n;j++)
				a[i][j] = BigInteger.ZERO;
	}
	
	public Matrix multiply(Matrix b) {
		Matrix ret = new Matrix(n);
		for (int i = 0;i < n;i++)
			for (int j = 0;j < n;j++)
				for (int k = 0;k < n;k++)
					ret.a[i][j] = ret.a[i][j].add(a[i][k].multiply(b.a[k][j]));
		return ret;
	}

}

class trie {
	static int[][] next = new int[110][50];
	static int[] fail = new int[110];
	static Boolean[] end = new Boolean[110];
	static int root,L;
	static String charset;
	
	static int[] Q = new int[110];
	static int head,tail;

	public trie() {}
	
	public void build() {
		// TODO Auto-generated method stub
		head = tail = 0;
		for (int i = 0;i < charset.length();i++)
			if (next[root][i] == -1)
				next[root][i] = root;
			else
			{
				fail[next[root][i]] = root;
				Q[tail++] = next[root][i];
			}
		while (head < tail)
		{
			int now = Q[head++];
			if (end[fail[now]] == true)
				end[now] = true;
			for (int i = 0;i < charset.length();i++)
				if (next[now][i] == -1)
					next[now][i] = next[fail[now]][i];
				else
				{
					fail[next[now][i]] = next[fail[now]][i];
					Q[tail++] = next[now][i];
				}
		}
	}

	public void insert(String buf) {
		// TODO Auto-generated method stub
		int now = root;
		for (int i = 0;i < buf.length();i++)
		{
			int charindex = getindex(buf.charAt(i));
			if (next[now][charindex] == -1)
				next[now][charindex] = newnode();
			now = next[now][charindex];
		}
		end[now] = true;
	}

	public int getindex(char charAt) {
		// TODO Auto-generated method stub
		for (int i = 0;i < charset.length();i++)
			if (charset.charAt(i) == charAt)
				return i;
		return 0;
	}

	public void init(String buf) {
		// TODO Auto-generated method stub
		charset = buf;
		L = 0;
		root = newnode();
	}

	public int newnode() {
		// TODO Auto-generated method stub
		for (int i = 0;i < charset.length();i++)
			next[L][i] = -1;
		end[L++] = false;
		return L-1;
	}
	
	public Matrix getMatrix() {
		Matrix ret = new Matrix(L);
		for (int i = 0;i < L;i++)
			for (int j = 0;j < charset.length();j++)
				if (end[next[i][j]] == false)
					ret.a[next[i][j]][i] = ret.a[next[i][j]][i].add(BigInteger.ONE);
		return ret;
	}
	
}

public class Main {

	/**
	 * @param args
	 */
	static int n,m,p;
	static String buf;
	static trie ac = new trie();
	static Matrix base;
	static BigInteger res;
	
	public static String decoder(String buf)
	{
		String res = "";
		byte[] tmp = buf.getBytes();
		for (int i = 0;i < tmp.length;i++)
				res += (char)tmp[i];
		return res;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext())
		{
			n = cin.nextInt();
			m = cin.nextInt();
			p = cin.nextInt();
			buf = cin.nextLine();
			buf = decoder(cin.nextLine());
			ac.init(buf);
			for (int i = 0;i < p;i++)
			{
				buf = decoder(cin.nextLine());
				ac.insert(buf);
			}
			ac.build();
			base = ac.getMatrix();
			base = power(base,m);
			res = BigInteger.ZERO;
			for (int i = 0;i < base.n;i++)
				res = res.add(base.a[i][0]);
			System.out.println(res);
		}
	}

	private static Matrix power(Matrix x, int y) {
		// TODO Auto-generated method stub
	    Matrix ret = new Matrix(x.n);
	    for (int i = 0; i < ret.n; i++)
	        ret.a[i][i] = BigInteger.ONE;
	    for (Matrix a = x; y != 0; y >>= 1,a = a.multiply(a))
	        if (y%2 == 1)
	            ret = ret.multiply(a);
	    return ret;
	}

}
