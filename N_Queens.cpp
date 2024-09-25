#include <stdio.h>
#include <stdbool.h>
#define MAX 20 // Maximum size of the chessboard
// Function to print the chessboard
void printSolution(int board[MAX][MAX], int N) {
 for (int i = 0; i < N; i++) {
 for (int j = 0; j < N; j++) {
 if (board[i][j])
 printf("Q ");
 else
 printf(". ");
 }
 printf("\n");
 }
 printf("\n");
}
// Function to check if a queen can be placed at board[row][col]
bool isSafe(int board[MAX][MAX], int row, int col, int N) {
 int i, j;
 // Check the left side of the current row
 for (i = 0; i < col; i++)
 if (board[row][i])
 return false;
 // Check the upper diagonal on the left side
 for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
 if (board[i][j])
 return false;
 // Check the lower diagonal on the left side
for (i = row, j = col; i < N && j >= 0; i++, j--)
 if (board[i][j])
 return false;
 return true;
}
// Function to solve N-Queens problem using backtracking
bool solveNQueensUtil(int board[MAX][MAX], int col, int N) {
 // If all queens are placed, return true
 if (col >= N)
 return true;
 // Try placing a queen in each row in the current column
 for (int i = 0; i < N; i++) {
 if (isSafe(board, i, col, N)) {
 // Place the queen at board[i][col]
 board[i][col] = 1;
 // Recur to place the rest of the queens
 if (solveNQueensUtil(board, col + 1, N))
 return true;
 // If placing queen at board[i][col] doesn't lead to a solution, backtrack
 board[i][col] = 0;
 }
 }
 // If the queen cannot be placed in any row in this column, return false
 return false;
}
// Function to solve the N-Queens problem
void solveNQueens(int N) {
 int board[MAX][MAX] = {0}; // Initialize the board with all zeros
 if (solveNQueensUtil(board, 0, N)) {
printSolution(board, N);
 } else {
 printf("Solution does not exist for N = %d\n", N);
 }
}
int main() {
 int N;
 printf("Enter the value of N (size of the chessboard): ");
 scanf("%d", &N);
 if (N <= 0 || N > MAX) {
 printf("Invalid input! N should be between 1 and %d.\n", MAX);
 return 1;
 }
 solveNQueens(N);
 return 0;
}
