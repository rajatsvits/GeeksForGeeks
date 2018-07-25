/* Java implementation to convert infix expression to postfix*/
// Note that here we use Stack class for Stack operations

import java.util.Stack;

class Test
{

    static String infixToPostfix(String x){
        if(x=="")
            return x;
        Stack<Character> e = new Stack<>();
        String res="";
        for(int i=0;i<x.length();i++){
            char c = x.charAt(i);
            
            if(Character.isLetterOrDigit(c)){
                res+=c;
            }
            else if(c=='('){
                e.push(c);
            }
            else if(c==')'){
                while(!e.isEmpty()&&e.peek()!='('){
                    res+=e.pop();
                }
                if(!e.isEmpty()&&e.peek()!='('){
                    return "Invalid expression";
                }
                e.pop();
            }
            else{
                while(!e.isEmpty()&&prec(c)<=prec(e.peek())){
                    res+=e.pop();
                }
                e.push(c);
            }
            
            
        }
        
        while(!e.isEmpty()){
            res+=e.pop();
            
        }
        
        return res;
        
    }
        
    static int prec(char c){
        switch (c){
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
            case '^':
                return 3;
            default :
                return -1;
        }
    }
    
	// Driver method 
	public static void main(String[] args) 
	{
		String exp = "a+b*(c^d-e)^(f+g*h)-i";
		System.out.println(infixToPostfix(exp));
	}
}
