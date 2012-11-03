import java.io.*;
import java.util.*;
import java.awt.geom.*;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int t = cin.nextInt();
		RectangularShape[] a = new RectangularShape[3];
		Area res = new Area();
		double x0,y0,x1,y1;
		for (int ft = 1;ft <= t;ft++)
		{
			res.reset();
			for (int i = 0;i < 3;i++)
			{
				x0 = cin.nextDouble();
				y0 = cin.nextDouble();
				x1 = cin.nextDouble();
				y1 = cin.nextDouble();
				a[i].setFrame(x0,y0,x1-x0,y1-y0);
			}
		}
		System.out.println();
	}

}
