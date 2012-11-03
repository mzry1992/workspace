import java.io.*;
import java.util.*;
import java.math.*;

public class Solution  {
    static BigInteger Length[];
    public static void main(String[] args) throws IOException
    {
         Scanner cin = new Scanner(System.in);
         int N = cin.nextInt();
         Length = new BigInteger[N];
         for (int i = 0; i < N; i++)
         {
             Length[i] = cin.nextBigInteger();
         }
         Arrays.sort(Length);
         boolean yes = false;
         for (int i = 0; i + 2 < N; i++)
         {
             if (Length[i].add(Length[i + 1]).compareTo(Length[i + 2]) > 0)
             {
                 yes = true;
                 System.out.println(Length[i] + " " + Length[i + 1] + " " + Length[i + 2]);
             }
         }
         if (yes == false)
         {
             System.out.println("0 0 0");
         }
    }
}
