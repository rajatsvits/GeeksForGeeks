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
		int a[] = {2,4,6};
		int n=6;
		ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
		ArrayList<Integer> output = new ArrayList<Integer>(); 
		c(res,a,n,0,output);
        System.out.println(res);
	}
	
	static void c(ArrayList<ArrayList<Integer>> res,int a[],int target,int index,ArrayList<Integer> output ){
        if(target<0)
        	return;
        if(target==0)
        {
            ArrayList<Integer> temp = new ArrayList<Integer>(output);
            res.add(temp);
            return;
        }
        
        for(int i=0;i<a.length;i++){
            if(target<a[i])
                return;
            output.add(a[i]);
            c(res,a,target-a[i],i,output);
            output.remove(output.size()-1);
        }
    }
}
