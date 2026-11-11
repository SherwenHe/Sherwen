
/*
N-Queens problem: Place n queens on an n×n chessboard so that they do not attack each other,
i.e., no two queens share the same row, column, or diagonal.
*/
#include <stdio.h>
#include <string.h>

// Define the maximum board size; can be adjusted as needed
#define MAXN 20

// Global variables
int n;              // Board size
int tot = 0;        // Total number of solutions
int C[MAXN];        // C[i] = j means a queen is placed in row i, column j
int vis[3][MAXN * 2]; // Conflict detection array: vis[0] columns, vis[1] anti-diagonal, vis[2] main diagonal

// Print the current valid board layout
void print_board() {
    printf("Solution #%d:\n", tot);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (C[i] == j) {
                printf(" Q"); // Queen position
            } else {
                printf(" ."); // Empty square
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Core backtracking search function
// cur represents the row currently being attempted for queen placement
void search(int cur) {
    if (cur == n) {
        tot++;
        print_board(); // A valid solution is found; print it
        return;
    }

    // Try each column in the current row
    for (int i = 0; i < n; i++) {
        // Key optimization: O(1) time complexity for conflict checks
        // Check whether column i, anti-diagonal (cur + i), and main diagonal (cur - i + n) are occupied
        if (!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + n]) {
            
            // Place the queen
            C[cur] = i;
            // Mark the current column and diagonals as occupied
            vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 1;
            
            // Recursively try the next row
            search(cur + 1);
            
            // Backtracking: undo the marks so other columns in this row can be tried
            vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 0;
        }
    }
}

int main() {
    printf("Please enter the board size N (for example, 8): ");
    scanf("%d", &n);

    if (n <= 0 || n >= MAXN) {
        printf("The value of N must be between 1 and %d.\n", MAXN);
        return 1;
    }

    // Initialize the array to 0
    memset(vis, 0, sizeof(vis));
    
    // Start placing queens from row 0
    search(0);

    printf("The N-Queens problem (%dx%d) has %d different solutions in total.\n", n, n, tot);

    return 0;
}
