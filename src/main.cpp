#include <iostream>
#include <chrono>
#include "board.h"
#include "solver.h"

void SolveSudoku(SudokuBoard& board, const SudokuSolver& solver)
{
    const auto start = std::chrono::steady_clock::now();
    const bool result = solver.Solve(board);
    const auto end = std::chrono::steady_clock::now();
    const auto elapsed = (double)std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0;
    std::cout << (result ? "solved!" : "failed!") << " (" << elapsed << " ms)" << std::endl;
    board.Print();
}

int main()
{
    SudokuSolver solver;

    const char values_4[] = 
    {
        ' ', ' ', '3', '2',
        '3', '2', '1', '4',
        '4', '1', '2', ' ',
        '2', '3', '4', '1'  
    };
    SudokuBoard board4(4, {2, 2}, values_4);
    SolveSudoku(board4, solver);

    const char values_4e[] = 
    {
        ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' '  
    };
    SudokuBoard board4e(4, {2, 2}, values_4e);
    SolveSudoku(board4e, solver);

    const char values_9[] = 
    {
        ' ', ' ', '3', ' ', ' ', ' ', '2', ' ', ' ',
        ' ', '6', ' ', '9', '8', ' ', ' ', '4', '3',
        '4', '9', ' ', ' ', '3', '1', ' ', ' ', '6',
        '9', ' ', '7', ' ', ' ', ' ', '8', '6', ' ',
        ' ', '4', ' ', ' ', '9', '8', ' ', ' ', ' ',
        ' ', ' ', '5', '4', ' ', '7', '1', ' ', '9',
        '6', ' ', ' ', ' ', ' ', '3', '9', ' ', '5',
        '5', ' ', '8', '1', ' ', ' ', ' ', '7', '2',
        '2', ' ', '9', ' ', '5', '6', ' ', '3', '8'
    };

    SudokuBoard board9(9, {3, 3}, values_9);
    SolveSudoku(board9, solver);

    const char values_9h[] = 
    {
        ' ', ' ', ' ', ' ', ' ', ' ', '2', ' ', ' ',
        ' ', ' ', ' ', ' ', '8', ' ', ' ', '4', '3',
        ' ', ' ', ' ', ' ', ' ', '1', ' ', ' ', '6',
        ' ', ' ', ' ', ' ', ' ', ' ', '8', '6', ' ',
        ' ', ' ', ' ', ' ', ' ', '8', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', '7', '1', ' ', '9',
        ' ', ' ', ' ', ' ', ' ', '3', '9', ' ', '5',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', '7', '2',
        '1', ' ', ' ', ' ', ' ', '6', ' ', '3', '8'
    };

    SudokuBoard board9h(9, {3, 3}, values_9h);
    SolveSudoku(board9h, solver);

    const char values_32e[] = 
    {
        ' ', '4', ' ', '1', '6', ' ',
        '2', ' ', '1', ' ', ' ', '5',
        ' ', ' ', ' ', ' ', '4', ' ',
        ' ', '3', ' ', ' ', ' ', ' ',
        '1', ' ', ' ', '3', ' ', '4',
        ' ', '2', '3', ' ', '5', ' '
    };
    SudokuBoard board32e(6, {3, 2}, values_32e);
    SolveSudoku(board32e, solver);
}