// PROBLEM STATEMENT ALONG WITH TEST CASE
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows);
 

// Example 1:

// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
// Example 2:

// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
// Example 3:

// Input: s = "A", numRows = 1
// Output: "A"
 

// Constraints:

// 1 <= s.length <= 1000
// s consists of English letters (lower-case and upper-case), ',' and '.'.
// 1 <= numRows <= 1000

import java.util.*;
public class MyClass {
    public static String convert(String s, int numRows) {
        int flag = -1;
        HashMap < Integer, String > map = new HashMap < > ();
        int pos = 0;
        String word = "";
        if (numRows <= 1)
            return s;
        else {
            for (int x = 0; x < s.length(); x++) {
                char ch1 = s.charAt(x);
                String ch = Character.toString(ch1);

                if (pos == (numRows - 1) || flag == 1 && pos > 0) {
                    flag = 1;
                    if (map.containsKey(pos)) {
                        String a = map.get(pos);
                        String w = a + ch;
                        map.put(pos, w);
                    } else {
                        map.put(pos, ch);
                    }
                    pos--;

                } else if (pos == 0 || flag == 0) {
                    flag = 0;
                    if (map.containsKey(pos)) {
                        String a = map.get(pos);
                        String w = a + ch;

                        map.put(pos, w);
                    } else {
                        map.put(pos, ch);
                    }
                    pos++;
                }
            }
            for (Map.Entry < Integer, String > e: map.entrySet())
                word = word + e.getValue();

            return word;
        }
    }
    //main function
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int rows = sc.nextInt();
        System.out.println(convert(s, rows));

    }
}