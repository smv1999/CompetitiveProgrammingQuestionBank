/* Sample Input

Heraldo Memelli 8135627
2
100 80

Sample Output

 Name: Memelli, Heraldo
 ID: 8135627
 Grade: O 
 
 This student had  scores to average:100  and 80 . The student's average grade is (100+80)/2=90. An average grade of 90 corresponds to the letter grade O, so the calculate() method should return the character'O'.
*/

class Student extends Person 
{
    private int[] testScores;
    public Student(String firstName, String lastName, int id, int [] scores) 
    {
        super(firstName, lastName, id);
        testScores = scores;
    }
     public char calculate() 
     {
        double average = 0;
        for (int score : testScores) 
        {
            average += score;
        }
        average /= testScores.length;
        
        if  (average >= 90) 
        {
            return 'O';
        } 
        else if (average >= 80) 
        {
            return 'E';
        } 
        else if (average >= 70) 
        {
            return 'A';
        } 
        else if (average >= 55) 
        {
            return 'P';
        } 
        else if (average >= 40) 
        {
            return 'D';
        } 
        else 
        {
            return 'T';
        }}}
