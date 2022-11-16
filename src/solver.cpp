#include "solver.h"
#include <iostream>

bool SudokuSolver::Solve(SudokuBoard& board) const
{
    if (board.GetEmptyValues() == 0)
        return true;

    const auto empty = FindEmptyElement(board);

    for (int i = 1; i <= board.GetMaxValue(); ++i)
    {
        const char valueChar = std::to_string(i)[0];
        if (Check(board, empty.first, empty.second, valueChar))
        {
            board.SetElement(empty.first, empty.second, valueChar);
            
            if (Solve(board))
                return true;

            board.SetElement(empty.first, empty.second, SudokuBoard::kEmptyValue);
        }
    }

    return false;
}

const std::pair<int, int> SudokuSolver::FindEmptyElement(const SudokuBoard& board) const
{
    for (int j = 0; j < board.GetBoardSize(); ++j)
    {
        for (int i = 0; i < board.GetBoardSize(); ++i)
        {
            if (board.GetElement(i, j) == SudokuBoard::kEmptyValue)
                return std::pair<int, int>(i, j);
        }
    }

    return std::pair<int, int>(-1, -1);
}

const bool SudokuSolver::Check(const SudokuBoard& board, const int col, const int row, const char value) const
{
    // column is correct
    for (int i = 0; i < board.GetBoardSize(); ++i)
    {
        if (board.GetElement(i, row) == value)
            return false;
    }

    // row is correct
    for (int i = 0; i < board.GetBoardSize(); ++i)
    {
        if (board.GetElement(col, i) == value)
            return false;
    }

    // cell is correct
    const int cellWidth = board.GetCellWidth();
    const int cellHeight = board.GetCellHeight();
    const int startCol = col / cellWidth * cellWidth;    
    const int startRow = row / cellHeight * cellHeight;

    for (int j = 0; j < cellHeight; ++j)
    {
        for (int i = 0; i < cellWidth; ++i)
        {
            if (board.GetElement(startCol + i, startRow + j) == value)
                return false;
        }
    }

    return true;
}