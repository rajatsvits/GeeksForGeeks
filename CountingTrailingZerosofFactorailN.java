

class CountingTrailingZeros {

	private static Scanner sc;

	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int n = sc.nextInt();
		int c=0,c1=0,c2=1,c3=0;
		for(int i=5;n/i>=1;i*=5)
		{
			c+=n/i;
			c1++;
		}
		System.out.println(c+" "+c1);
		while(n%Math.pow(5,c2)==0)//n/Math.pow(5,c2)>=1)//n/Math.pow(5,c2)>1)//n/Math.pow(5,c2)>0)//n%5==0)
		{
			c3+=n/Math.pow(5,c2);
			c2++;
			//n/=5;
		}
		
		System.out.println(c2-1+" "+c3);
		
		//100/5 = 20 + 4 (20/5==4) + 0(4/5==0.20==0{floor})
		int c4=0,c5=0;
		while(n>0)
		{
			c5++;
			c4+=n/5;
			n/=5;
		}
		System.out.println(c4+" "+c5);
		
			
	}
}
