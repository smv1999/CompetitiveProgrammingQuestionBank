// 7X7
// Problem Description
// CODU is solving a 7x7 sudoku. Help him in solving the unique Sudoku.

// Rules are as follows

// 1. There are 7 regions coloured differently. Each region must have a single occurrence of numbers between range [1, 7].

// 2. Regions don't have a fix shape and it can change from input to input.

// 3. Each row must have a single occurrence of numbers between range [1, 7] across all input.

// 4. Each column must have a single occurrence of numbers between range [1, 7] across all input.

// Some numbers in some rows, columns and regions will be given. These will be between [1, 7].

// Zero (0) denotes that the number is covered. Uncovering it will give a number between [1, 7].

// Your task is to fill the numbers [1,7] where there is a 0 such that the 7x7 Sudoku is solved.

// 7x7 Sudoku is said to be solved when every region, every column, every row has exactly one occurrence of numbers [1,7].

// Constraints
// 7 < Known/Given numbers in Entire Sudoku < 14

// Input
// Input consists of 14 lines.

// First 7 lines denote the positions of numbers [1,7] in respective row and column.

// Next 7 lines denote the shape of the regions inside the Sudoku. These will be denoted by 7 unique characters between alphabets [a-z].

// Output
// Print the solved Sudoku.

// 7 lines, each line containing 7 space separated integers honoring all the conditions.

// Time Limit
// 1

// Examples
// Example 1

// Input

// 0 0 0 0 0 6 0

// 0 0 0 0 0 0 0

// 2 6 5 1 7 4 3

// 0 0 0 3 0 0 0

// 0 0 0 0 0 0 0

// 0 0 0 0 0 0 0

// 0 0 0 0 0 0 0

// a a a b b b b

// a a a a b b c

// d d d e e b c

// d d d d e e c

// f f f h e e c

// f f h h e c c

// f f h h h h c

// Output

// 1 2 4 5 3 6 7

// 3 5 6 7 1 2 4

// 2 6 5 1 7 4 3

// 4 7 1 3 2 5 6

// 7 1 2 6 4 3 5

// 5 4 3 2 6 7 1

// 6 3 7 4 5 1 2

// Explanation

// There could be many different solutions. Producing any solution as output is acceptable.

