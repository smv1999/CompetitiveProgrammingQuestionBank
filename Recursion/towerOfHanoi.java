//Tower of Hanoi
//O(2^n)

/*
Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules: 

1. Only one disc move at time
2. Follow order smaller always on the top of bigger
3. Only top disc must be move

Here we considered three poles 
s=source d=destination h=helper

i/p: 1
o/p: Move disc 1 from s to d

i/p: 2
o/p: Move disc 1 from s to h
	 Move disc 2 from s to d
	 Move disc 1 from h to d

i/p: 3
o/p:Move disc 1 from s to d
	Move disc 2 from s to h
	Move disc 1 from d to h
	Move disc 3 from s to d
	Move disc 1 from h to s
	Move disc 2 from h to d
	Move disc 1 from s to d


No. of move : 2^n-1
*/

import java.util.Scanner;

class towerOfHanoi{
	static void toh(char s,char d,char h,int n){
		if(n==1){
			System.out.println("Move disc "+n+" from "+s+" to "+d+"\n");
			return;
		}
		toh(s,h,d,n-1);
		System.out.println("Move disc "+n+" from "+s+" to "+d+"\n");
		toh(h,d,s,n-1);
}
public static void main(String[] args) {
			System.out.println("Enter no. of discs\n");
			Scanner sc = new Scanner(System.in);
			int n =sc.nextInt();  
			sc.close();      
			toh('s','d','h',n);
			
		}
}



