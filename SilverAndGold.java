/* ************
Problem statement:
SILVER AND GOLD

There are N coins kept in a line. 
Each coin has two sides - one is colored gold
and the other silver. You can flip two adjacent
coins any number of times. You need to make 
the gold-colored side of every coin facing up.
You are given the initial status of coins
in a binary string s where 1 represents the 
gold side facing up and 0 represents the silver
side facing up. If it is possible to make the
gold-colored side of every coin facing up,
return Yes, otherwise return No

Input:
N = 8, s = "11001100"
Output:
Yes
Explanation:
Flipping 3rd and 4th coin together and 7th
and 8th coin together will do the task.
********* */
public class SilverAndGold{
	//Silver and Gold Problem	
	public static String flipCoins(int N,String s) {
		// Code here
		int count0, count1;
	        count0 = count1 = 0;
        	for(int i = 0;i < N;i++){
		        int result = Character.compare('0',s.charAt(i));				
		        if(result == 0){
		            count0++;
		        }
		        else{
		            count1++;
		        }
		}   
                if(count0%2 == 0){
	            return "Yes";
        	}
	        else{
        	    return "No";
        	}
	}
	public static void main(String args[]){

		System.out.println(flipCoins(8,"10010100"));//test case 1
       		System.out.println(flipCoins(8,"11001100"));//test case 2
	        System.out.println(flipCoins(2,"00"));//test case 2

        

	
	}
}




