import java.util.*;
public class homework1 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner ab = new Scanner(System.in);
		int[] a = new int[5];
		for (int i = 0;i < 5;i++)
			a[i] = ab.nextInt();
		int max = a[0];
		for (int i = 1;i < 5;i++)
			if (max < a[i])
				max = a[i];
		System.out.println(max);
	}

}
