

import java.math.BigInteger;
/*
 * multiply(res[], x)
1) Initialize carry as 0.
2) Do following for i = 0 to res_size – 1
….a) Find value of res[i] * x + carry. Let this value be prod.
….b) Update res[i] by storing last digit of prod in it.
….c) Update carry by storing remaining digits in carry.
3) Put all digits of carry in res[] and increase res_size by number of digits in carry.
 */
import java.util.Scanner;

 class ExtraLargeFactorials {

	private static Scanner sc;

	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int t = sc.nextInt();
		int x=200;
		int a []=new int[x];
		a[0]=1;
		int size=1;
		for(int i=2;i<=t;i++)
		{
			size=multiply1(i,size,a);
		}
		System.out.print("By Normal Method\nUsing String: ");
		for(int i=size-1;i>=0;i--)
			System.out.print(a[i]);
		System.out.println();
		System.out.println();
		//By BigInteger
		//BigInteger b= new BigInteger("1");
		
//		BigInteger b= new BigInteger.valueOf(x);//Not working
//		BigInteger b= new BigInteger.ONE;//Not working
		/*Working
		BigInteger b;
		b= BigInteger.valueOf(x);*/
		
//		BigInteger b;
//		b= new BigInteger("x");//Error can't have x
//		System.out.println(b);
		
//		BigInteger b;
//		b= BigInteger.ONE;
//		System.out.println(b);
		
//		String str = “123456789”;
//		BigInteger C = A.add(new BigInteger(str));
//		int val  = 123456789;
//		BigInteger C = A.add(BigInteger.valueOf(val)); 
		
//		Extraction of value from BigInteger:
//
//			int x   =  A.intValue();   // value should be in limit of int x
//			long y   = A.longValue();  // value should be in limit of long y
//			String z = A.toString();  
		/**/
		BigInteger b= new BigInteger("1");
		for(int i=2;i<=t;i++)
		{
			b=b.multiply(BigInteger.valueOf(i));//Need to convert to bigInteger
		}
		System.out.println("By BigInteger: "+b);
	}

	private static int multiply1(int x, int size,int []a) {
		int carry=0;
		for(int i=0;i<size;i++ )
		{
			a[i]=a[i]*x +carry;
			
			carry=a[i]/10;
			a[i]%=10;
		}
		while(carry>0)
		{
			a[size]=carry%10;
			carry/=10;
			size++;
		}
		return size;
	}
	
	
}
