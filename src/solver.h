#pragma once

#include "board.h"

class SudokuSolver
{
public:
    bool Solve(SudokuBoard& board) const;

private:
    const std::pair<int, int> FindEmptyElement(const SudokuBoard& board) const;
    const bool Check(const SudokuBoard& board,const int col, const int row, const char value) const;
};