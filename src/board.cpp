#include "board.h"
#include <iostream>
#include <set>

char SudokuBoard::kEmptyValue = ' ';

SudokuBoard::SudokuBoard(const int boardSize, const Size& cellSize, const char* values)
: _boardSize(boardSize), _cellWidth(cellSize.width), _cellHeight(cellSize.height), 
  _maxValue(_cellWidth * _cellHeight), _originalValues(values), _values(values)
{
    CalculateEmpty();
    const bool isCorrect = IsCorrect();
    if (!isCorrect)
        std::cout << "warning! Incorrect sudoku" << std::endl;
}

const bool SudokuBoard::IsCorrect() const
{
    // horizontal check
    for (int j = 0; j < _boardSize; ++j)
    {
        std::set<char> set;

        for (int i = 0; i < _boardSize; ++i)
        {
            const char value = GetElement(i, j);
            if (value == SudokuBoard::kEmptyValue)
                continue;

            if (set.count(value) > 0)
                return false;

            set.insert(value);
        }
    }

    // vertical check
    for (int i = 0; i < _boardSize; ++i)
    {
        std::set<char> set;

        for (int j = 0; j < _boardSize; ++j)
        {
            const char value = GetElement(i, j);
            if (value == SudokuBoard::kEmptyValue)
                continue;

            if (set.count(value) > 0)
                return false;

            set.insert(value);
        }
    }

    // cell check
    for (int j = 0; j < _boardSize; j += _cellHeight)
    {
        for (int i = 0; i < _boardSize; i += _cellWidth)
        {
            std::set<char> set;

            for (int jCell = 0; jCell < _cellHeight; ++jCell)
            {
                for (int iCell = 0; iCell < _cellWidth; ++iCell)
                {
                    const char value = GetElement(iCell + i, jCell + j);  
                    if (value == SudokuBoard::kEmptyValue)
                        continue;

                    if (set.count(value) > 0)
                        return false;

                    set.insert(value);
                }
            }
        }
    }

    return true;
}

void SudokuBoard::Print() const
{
    std::cout << "--------------" << std::endl;
    for (int j = 0; j < _boardSize; ++j)
    {
        for (int i = 0; i < _boardSize; ++i)
        {
            std::cout << GetElement(i, j) << " ";
        }

        std::cout << std::endl;
    }
    const char* correct = IsCorrect() ? "y" : "n";
    std::cout << "empty = " << _emptyValues << ", correct = " << correct << std::endl;
    std::cout << "--------------" << std::endl;
}

void SudokuBoard::SetElement(const int col, const int row, const char value)
{
    _values[row * _boardSize + col] = value;

    if (value == SudokuBoard::kEmptyValue)
        _emptyValues++;
    else
        _emptyValues--;
}

void SudokuBoard::Reset()
{
    _values = std::string(_originalValues);
    CalculateEmpty();
}

void SudokuBoard::CalculateEmpty()
{
    _emptyValues = 0;

    for (int i = 0; i < _values.length(); ++i)
    {
        if (_values[i] == kEmptyValue)
            _emptyValues++;
    }
}