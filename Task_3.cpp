#include <iostream>
using namespace std;

const int grid_size = 9;

// Function to print the Sudoku board with visual borders
void printBoard(const int board[grid_size][grid_size])
{
    cout << "------+------+--------\n";

    for (int row = 0; row < grid_size; row++) 
    {
        // Print horizontal dividers every 3 rows
        if (row % 3 == 0 && row != 0)
        {
            cout << "------+------+--------\n";
        }

        for (int col = 0; col < grid_size; col++)
        {
            // Print vertical dividers every 3 columns
            if (col % 3 == 0 && col != 0) {
                cout << "| ";
            }

            // Display '.' for empty cells (0), otherwise display the number
            if (board[row][col] == 0) {
                cout << ". ";
            }
            else {
                cout << board[row][col] << " ";
            }
        }

        cout << "\n";
    }
    cout << "------+------+--------\n";
}

// Checks if placing 'number' at board[row][col] violates Sudoku rules
bool isValid(const int board[grid_size][grid_size], int row, int col, int num) 
{
    //  Check the row
    for (int x = 0; x < grid_size; x++) 
    {
        if (board[row][x] == num)
        {
            return false;
        }
    }

    // 2. Check the column
    for (int x = 0; x < grid_size; x++)
    {
        if (board[x][col] == num)
        {
            return false;
        }
    }

    // Check the 3x3 sub-grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) 
            {
                return false;
            }
        }
    }

    return true; // The placement is safe
}

// Core Backtracking Algorithm
bool solveSudoku(int board[grid_size][grid_size]) 
{
    for (int row = 0; row < grid_size; row++) 
    {
        for (int col = 0; col < grid_size; col++) {

            // Look for an empty cell
            if (board[row][col] == 0) {

                // Try numbers 1 through 9
                for (int num = 1; num <= 9; num++) {
                    if (isValid(board, row, col, num)) {

                        // Make tentative assignment
                        board[row][col] = num;

                        // Recursively try to solve the rest of the board
                        if (solveSudoku(board))
                        {
                            return true;
                        }

                        // Backtrack: if it didn't lead to a solution, unset it
                        board[row][col] = 0;
                    }
                }
                // If no number 1-9 fits, this path is dead. Backtrack!
                return false;
            }
        }
    }
    return true; // Returned true when all cells are filled successfully
}
int main()
{
    int choice;

    // Sample Sudoku Puzzle
    int grid[grid_size][grid_size] =
    {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    do
    {

            cout << "\t\t\t ____  _   _ ____  _   _ _  _____  \n";
            cout << "\t\t\t/ ___|| | | |  _ \\| | | | |/ / _ \\ \n";
            cout << "\t\t\t\\___ \\| | | | | | | | | | ' / | | |\n";
            cout << "\t\t\t ___) | |_| | |_| | |_| | . \\ |_| |\n";
            cout << "\t\t\t|____/ \\___/|____/ \\___/|_|\\_\\___/ \n";

    
        cout << "1. DISPLAY PUZZLE\n";
        cout << "2. SOLVE PUZZLE\n";
        cout << "3. EXIT\n";
        cout << "=====================================\n";

        cout << "ENTER CHOICE: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nINVALID INPUT!\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            cout << "\nORIGINAL PUZZLE:\n";
            printBoard(grid);
            break;

        case 2:
        {
            int temp[grid_size][grid_size];

            // Copy puzzle so original remains unchanged
            for (int i = 0; i < grid_size; i++)
            {
                for (int j = 0; j < grid_size; j++)
                {
                    temp[i][j] = grid[i][j];
                }
            }

            cout << "\nSOLVING PUZZLE...\n";

            if (solveSudoku(temp))
            {
                cout << "\nSOLUTION FOUND:\n";
                printBoard(temp);
            }
            else
            {
                cout << "\nNO SOLUTION EXISTS!\n";
            }

            break;
        }

        case 3:
            cout << "\nPROGRAM EXITED SUCCESSFULLY!\n";
            break;

        default:
            cout << "\nINVALID CHOICE!\n";
        }

    } while (choice != 3);

    return 0;
}