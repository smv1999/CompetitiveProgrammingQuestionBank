/* 


Write a Person class with an instance variable,age , and a constructor that takes an integer,initialAge , as a parameter. The constructor must assign initialAge to age after confirming the argument passed as initialAge is not negative; if a negative argument is passed as , the constructor should set  to  and print Age is not valid, setting age to 0.. In addition, you must write the following instance methods:

yearPasses() should increase the  instance variable by .
amIOld() should perform the following conditional actions:
If , print You are young..
If  and , print You are a teenager..
Otherwise, print You are old..
To help you learn by example and complete this challenge, much of the code is provided for you, but you'll be writing everything in the future. The code that creates each instance of your Person class is in the main method. Don't worry if you don't understand it all quite yet!

Note: Do not remove or alter the stub code in the editor.

Input Format

Input is handled for you by the stub code in the editor.

The first line contains an integer,  (the number of test cases), and the  subsequent lines each contain an integer denoting the  of a Person instance.

Constraints

Output Format

Complete the method definitions provided in the editor so they meet the specifications outlined above; the code to test your work is already in the editor. If your methods are implemented correctly, each test case will print  or  lines (depending on whether or not a valid  was passed to the constructor).

Sample Input

4
-1
10
16
18
Sample Output

Age is not valid, setting age to 0.
You are young.
You are young.

You are young.
You are a teenager.

You are a teenager.
You are old.

You are old.
You are old.  */


public class Person {
    private int age;	
  
	public Person(int initialAge) {
  		// Add some more code to run some checks on initialAge
          if(initialAge<0)
            {
            age=0;
            System.out.println("Age is not valid, setting age to 0.");
            
        }
        else
            {
            age=initialAge;
        }
	}

	public void amIOld() {
  		// Write code determining if this person's age is old and print the correct statement:
           if(age<13)
            {
            System.out.println("You are young.");
            }
        else if(age>=13 && age<18)
            {
        System.out.println("You are a teenager.");
        }
        else
            {
            System.out.println("You are old.");
        }
    
 
       
	}

	public void yearPasses() {
  		// Increment this person's age.
          age++;
	}

