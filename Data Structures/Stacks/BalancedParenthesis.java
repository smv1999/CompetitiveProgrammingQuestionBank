import java.util.*;
import java.io.*;
import java.lang.*;

class BalancedParenthesis{
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);
		
		//Reading total number of testcases
		int t = scan.nextInt();
		while(t-->0){
			//reading the string
			String str = scan.next();
			
			//calling ispar() of Parenthesis class and printing "balanced" if it returns true else print "not balanced"
			if(new Solution().ispar(str) == true)
				System.out.println("balanced");
			else
				System.out.println("not balanced");
		}
	}
}

class Solution{
	//Function to check if brackets are balanced or not.
	static boolean ispar(String str){
	
	//if string is null or the length of string is not even then string is not balanced.
        if (str == null || ((str.length() % 2) != 0)) {
            return false;
        } 
        else {
        //if string entered is other than parenthesis, return false.
            char[] ch = str.toCharArray();
            for (char c : ch) {
                if (!(c == '{' || c == '[' || c == '(' || c == '}' || c == ']' || c == ')')) {
                    return false;
                }

            }
        }

        Deque<Character> deque = new LinkedList<>();
        //peekFirst() is used to retrieve or fetch the first element of the deque.
        
        for (char ch : str.toCharArray()) {
            if (ch == '{' || ch == '[' || ch == '(') {
                deque.addFirst(ch);
            } 
            else {
                if (!deque.isEmpty() && ((deque.peekFirst() == '{' && ch == '}') || (deque.peekFirst() == '[' && ch == ']') || (deque.peekFirst() == '(' && ch == ')'))) {
                    deque.removeFirst();
                } 
                else 
                    return false;
            }
        }

        return true;
    }
}

