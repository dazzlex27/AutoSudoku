#pragma once

#include <string>
#include "structs.h"

class SudokuBoard
{
public:
    static char kEmptyValue;

private:
    const int _boardSize;
    const int _cellWidth;
    const int _cellHeight;
    const int _maxValue;
    const std::string _originalValues;
    
    std::string _values;
    int _emptyValues;

public:
    SudokuBoard(const int boardSize, const Size& cellSize, const char* values);

    const char GetElement(const int col, const int row) const { return _values[row * _boardSize + col]; }
    const int GetBoardSize() const { return _boardSize; }
    const int GetCellWidth() const { return _cellWidth; }
    const int GetCellHeight() const { return _cellHeight; }
    const int GetMaxValue() const { return _maxValue; }
    const int GetEmptyValues() const { return _emptyValues; }
    const bool IsCorrect() const;
    const bool IsComplete() const { return IsCorrect() && _emptyValues == 0; }

    void Print() const;
    void SetElement(const int col, const int row, const char value);
    void Reset();

private:
    void CalculateEmpty(); 
};