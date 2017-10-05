
import java.math.BigInteger;
import java.util.Scanner;

class LargeFibonacciNumber {

	private static Scanner sc;

	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int t = sc.nextInt();
		//int a=0,b=1,c=0;
		BigInteger x = BigInteger.ZERO;
		BigInteger y = BigInteger.ONE;
		BigInteger z = x.add(y);
		System.out.print(x+" "+y+" ");
		int c=0;
		for(int i=0;i<t-2;i++)
		{
			z=x.add(y);
			x=y;
			y=z;
			System.out.print(z+" ");
			c++;
			if(c==20)
			{
				c=0;
				System.out.println();
			}
		}
		//System.out.println(z);
	}
}
