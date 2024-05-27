#include<iostream>
#include<vector>
using namespace std;

#define UNASSIGNED 0
#define N 9

bool isValid(int grid[N][N], int row, int col, int num);
bool solve(int grid[N][N]);
bool findEmptyCell(int grid[N][N], int &row, int &col);
void printBoard(int grid[N][N]);
void getInput(int grid[N][N]);

int main()
{
    int grid[N][N];
    getInput(grid);

    if(solve(grid))
        printBoard(grid);
    else
        cout << "No solution exists" << endl;

    return 0;
}

void getInput(int grid[N][N])
{
    cout << "Enter the Sudoku puzzle (use 0 for empty cells) : " << endl;
    for(int row = 0; row < N; ++row)
    {
        for(int col = 0; col < N; ++col)
        {
            cin >> grid[row][col];
        }
    }
}

bool findEmptyCell(int grid[N][N], int &row, int &col)
{
    for(row = 0; row < N; row++)
        for(col = 0; col < N; col++)
            if(grid[row][col] == UNASSIGNED)
                return true;
    return false;
}

bool isValid(int grid[N][N], int row, int col, int num)
{
    for(int x = 0; x < N; x++)
        if(grid[row][x] == num || grid[x][col] == num)
            return false;

    int startRow = row - row % 3, startCol = col - col % 3;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

bool solve(int grid[N][N])
{
    int row, col;
    if(!findEmptyCell(grid, row, col))
        return true;

    for(int num = 1; num <= 9; num++)
    {
        if(isValid(grid, row, col, num))
        {
            grid[row][col] = num;
            if(solve(grid))
                return true;
            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}

void printBoard(int grid[N][N])
{
    cout << "Solution : " << endl;

    for(int row = 0; row < N; row++)
    {
        if(row % 3 == 0 && row != 0)
            cout << "---------------------" << endl;
        for(int col = 0; col < N; col++)
        {
            if(col % 3 == 0 && col != 0)
                cout << "| ";
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}


/*

Compile the program :

g++ -o sudoku Task2.cpp

Run the program :

./sudoku

For input values copy and paste it on terminal

    1 0 0 0 0 7 0 9 0
    0 3 0 0 2 0 0 0 8
    0 0 9 6 0 0 5 0 0
    0 0 5 3 0 0 9 0 0
    0 1 0 0 8 0 0 0 2
    6 0 0 0 0 4 0 0 0
    3 0 0 0 0 0 0 1 0
    0 4 0 0 0 0 0 0 7
    0 0 7 0 0 0 3 0 0

*/