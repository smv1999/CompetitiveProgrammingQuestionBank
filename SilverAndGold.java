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




