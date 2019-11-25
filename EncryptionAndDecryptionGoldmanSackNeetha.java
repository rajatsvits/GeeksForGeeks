/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		String s="Openrajat",key="1234",d="Oppeeennnnraajjjaaaat";
		
		s=encryption(s,key);
		d=decription(s,key);
		System.out.println(s+"\n"+d);
		
		
	}
	
	public static String encryption(String s , String key){
		String r="";
		char a[] = s.toCharArray();
		char b[] = key.toCharArray();
		int k=0;
		for(int i=0;i<a.length;i++){
			if(k==b.length)
				k=0;
			int j=b[k]-'0';
			while(j>0){
				r+=a[i];
				j--;
			}
			k++;
			
		}
		return r;
		
	}
	
	public static String decription(String s , String key){
		String r="";
		char a[] = s.toCharArray();
		char b[] = key.toCharArray();
		int k=0,getCharacterAt=0,size=a.length,i=0,count=-1;
		while(true){
			if(i>=b.length)
				i=0;
			count+=(b[i]-'0');
			// System.out.println(count+"\nb: "+b[i]);
			if(count>=size)
				break;
			r+=a[count];
			i++;
			
		}
		return r;
		
	}
}
