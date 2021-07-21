/*Moving according to the rules of chess knight must visit each square exactly once. Print the order of each the cell in which they are visited.*/
import java.util.*;
public class MyClass {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        // provide start position
        int r = sc.nextInt();
        int c = sc.nextInt();
        int board[][] = new int[n][n];
        // The 8 possible moves where a knight can move from its current position
        int posx[] = {-1,-1,1,1,-2,-2,2,2};
        int posy[] = {-2,2,-2,2,-1,1,-1,1};
        path(board, r, c, 1, posx, posy);
    }
    public static boolean path(int board[][], int row, int col, int move, int posx[], int posy[]) {
        board[row][col] = move;
        // if all the positions are visited then print the result
        if (move == board.length*board.length) {
            // printing result in matrix form
            for (int i = 0; i < board.length; i++) {
                for (int j = 0; j < board.length; j++)
                    if (board[i][j] < 10)
                        System.out.print("0" + board[i][j] + " ");
                    else
                        System.out.print(board[i][j] + " ");
                System.out.println();
            }
            return true;
        }
        for (int i = 0; i < 8; i++) {
            int newx = row + posx[i];
            int newy = col + posy[i];
            // checking if the new position is a valid move and not visited yet
            if (validmove(newx, newy, board) && board[newx][newy] == 0) {
                if (path(board, newx, newy, move + 1, posx, posy)) {
                    return true;
                }
            }
        }
        // if position is not valid mark position as unvisited in the matrix
        board[row][col] = 0;
        return false;
    }
    // checks that the new position is not outside the matrix of n*n
    static boolean validmove(int newx, int newy, int board[][]) {
        if (newx >= 0 && newx < board.length && newy >= 0 && newy < board.length)
            return true;
        return false;
    }
}

/*Input
8
0 
0
Output
01 08 15 22 03 10 19 64 
16 23 02 09 18 21 04 11 
07 14 17 24 05 12 63 20 
34 25 06 13 44 27 52 61 
55 46 33 26 53 62 43 28 
32 35 54 45 40 29 60 51 
47 56 37 30 49 58 39 42 
36 31 48 57 38 41 50 59 */